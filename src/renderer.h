#pragma once
#include<string>
#include<vector>

inline std::string charset = " .:-=+*%#";
inline bool no_col = false;
inline bool no_bg = false;

std::vector<std::string> toAscii (int w, int h, unsigned char* img); 
