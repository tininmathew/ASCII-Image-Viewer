#define STB_IMAGE_IMPLEMENTATION
#define STB_IMAGE_RESIZE_IMPLEMENTATION
#include<iostream>
#include<string>
#include<vector>
#include"stb_image.h"
#include"stb_image_resize2.h"
#include"renderer.h"
#include<sys/ioctl.h>
#include<unistd.h>
#include<cstdlib>
#include<filesystem>
#include<fstream>

int main(int argc, char* argv[])
{
	int writeTo = -1;
	if(argc == 1)
	{
		std::cout << "Enter the path to an image" << std::endl;
		return 1;
	}
	int width, height, channels;
	unsigned char* initialImg = stbi_load(argv[1], &width, &height, &channels, 3);
	if (!initialImg) 
	{
		std::cout << "Error: " << stbi_failure_reason() << std::endl;
		return 1;
	}
	int w, h;

	struct winsize wi;
	ioctl(STDOUT_FILENO, TIOCGWINSZ, &wi);
	if(wi.ws_col >= width*2)
	{
		w = width;
		h = height;
	}
	else
	{
		w = wi.ws_col/2;
		h = (wi.ws_col * height) / (width * 2);
	}
	for(int i = 2; i < argc; i++)
	{
		if(std::string(argv[i]) == "--size")
		{
			char* firstDigit = nullptr;
			char* secondDigit = nullptr;
			if(i+1 >= argc)
			{
				std::cout << "Error: Incorrect size!" << std::endl;
				return 1;
			}
			std::strtod(argv[i+1], &firstDigit);
			if(i+2 < argc)
			{
				std::strtod(argv[i+2], &secondDigit);
			}
			
			w = std::atoi(argv[i+1]);
			if(secondDigit != nullptr && *secondDigit == '\0')
			{
					h = std::atoi(argv[i+2]);
			}
			else
			{
				h = (w * height)/width;
			}
		}
		if(std::string(argv[i]) == "--colorless")
		{
			no_bg = true;
			no_col = true;
		}
		if(std::string(argv[i]) == "--symbols")
		{
			no_bg = true;
		}
		if(std::string(argv[i]) == "--out")
		{
			no_bg = true;
			no_col = true;
			if(i+1 >= argc || !std::filesystem::exists(argv[i+1]))
			{
				std::cout << "Incorrect out: " << argv[i+1] << std::endl;
			}
			else
			{
				writeTo = i+1;
			}
		}
	}
	unsigned char* img = (unsigned char*)malloc(w*h*3);

	stbir_resize_uint8_linear(initialImg, width, height, 0, 
                             img, w, h, 0, 
                             (stbir_pixel_layout)3);
	stbi_image_free(initialImg); 
	std::vector<std::string> ascii = toAscii(w, h, img);
	free(img);
	for(int i = 0; i < ascii.size(); i++)
	{
		std::cout << ascii[i] << std::endl;
	}
	std::cout << "\033[0m" << std::endl;
	if(writeTo != -1)
	{
		std::fstream out(argv[writeTo]);
		if(!out.is_open())
		{
			std::cout << "Error in opening file" << std::endl;
			return 1;
		}
		for(int i = 0; i < ascii.size(); i++)
		{
			out << ascii[i] << std::endl;
		}
		out << "\033[0m" << std::endl;
		out.close();
	}
	return 0;
}

