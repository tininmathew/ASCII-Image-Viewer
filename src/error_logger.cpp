#include "error_logger.h"
#include <iostream>
#include <cstring>

namespace error_logger
{
	void fileError()
	{
		std::cout << "┌┴ERROR───────╖" << std::endl;
		std::cout << "│Invalid file!║" << std::endl;
		std::cout << "╘╤════════════╝" << std::endl;
	}
	void stbError(const char* error)
	{
		int size = strlen(error);
		std::cout << "┌┴ERROR";
		for(int i = 0; i < size-6; i++)
		{
			std::cout << "─";
		}
		std::cout << "╖" << std::endl;

		std::cout << "│" << error << "║" << std::endl;
		std::cout << "╘";
		for(int i = 0; i < size; i++)
		{
			std::cout << "═";
		}
		std::cout << "╝" << std::endl;
	}
	void incorrectSize()
	{
		std::cout << "┌┴ERROR───────╖" << std::endl;
		std::cout << "│Size argument║" << std::endl;
		std::cout << "│is invalid!╓─╜" << std::endl;
		std::cout << "└┬──────────╜" << std::endl;
	}
	void incorrectOut()
	{
		std::cout << "┌┴ERROR────────────╖" << std::endl;
		std::cout << "│Out file argument ║" << std::endl;
		std::cout << "│is invalid!╓──────╜" << std::endl;
		std::cout << "└┬──────────╜" << std::endl;
	}
	void outFileError()
	{
		std::cout << "┌┴ERROR───────────╖" << std::endl;
		std::cout << "│Out file opening ║" << std::endl;
		std::cout << "│error!╓──────────╜" << std::endl;
		std::cout << "└┬─────╜" << std::endl;
	}
	void helpOut()
	{
		std::cout << "┌┴HELP───────────╖" << std::endl;
		std::cout << "│\033[35m--size <X> <Y>\033[0m  ║" << std::endl;
		std::cout << "│quality of image╟─╮" << std::endl;
		std::cout << "┝━━━━━━━━━━━━━━━━╨─┴─────╖" << std::endl;
		std::cout << "│\033[35m--colorless\033[0m             ║" << std::endl;
		std::cout << "│draws the image as ASCII║" << std::endl;
		std::cout << "┝━━━━━━━━━━━━━━━━━━━━━━━━╢" << std::endl;
		std::cout << "│\033[35m--symbols\033[0m               ║" << std::endl;
		std::cout << "│draws the image as ASCII╟───╮" << std::endl;
		std::cout << "│but with colored symbols║   │" << std::endl;
		std::cout << "┝━━━━━━━━━━━━━━━━━━━━━━━━╢   │" << std::endl;
		std::cout << "│\033[35m--out <path>\033[0m            ╙───┴╖" << std::endl;
		std::cout << "│writes ASCII result in a file║" << std::endl;
		std::cout << "┝━━━━━━━━━━━━━━━━━╥─────┬─────╜" << std::endl;
		std::cout << "│\033[35m--help\033[0m           ╟─────╯" << std::endl;
		std::cout << "│draws this window║" << std::endl;
		std::cout << "└┬────────────────╜" << std::endl;
	}
}
