#include"renderer.h"
#include<iostream>
#include<vector>
#include<string>

std::vector<std::string> toAscii (int w, int h, unsigned char* img)
{
	std::vector<std::string> out;
	for(int y = 0; y < h; y++)
	{
		std::string line = "";
		for(int x = 0; x < w; x ++)
		{
			float colBright = 0;
			std::vector<int> rgb;
			for(int i = 0; i < 3; i++)
			{
				int color = img[((y * w + x) * 3) + i];
				colBright += color;
				rgb.push_back(color);
			}
			colBright /= 3;
			colBright = (colBright / 255.0f) * (charset.size() - 1);
			if(!no_col)
			{
			 	line += "\033[38;2;" + 
				std::to_string(rgb[0]) + ";" + 
				std::to_string(rgb[1]) + ";" +
				std::to_string(rgb[2]) + "m";
				if(!no_bg)
				{
					line += "\033[48;2;" +
					std::to_string(rgb[0]) + ";" + 
					std::to_string(rgb[1]) + ";" +
					std::to_string(rgb[2]) + "m";
				}
			}

			line += charset[colBright];
			line += charset[colBright];
		}
		line += "\033[0m";
		out.push_back(line);
	}
	return out;
}

