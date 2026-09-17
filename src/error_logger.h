#pragma once

namespace error_logger
{
	void fileError();
	void stbError(const char* error);
	void incorrectSize();
	void incorrectOut();
	void outFileError();
	void helpOut();
}
