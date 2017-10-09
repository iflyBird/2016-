#pragma once
#include <iostream>
class XCUtil
{
public:
	XCUtil();
	~XCUtil();

	static std::string Wchart2string(wchar_t* wz);
	static wchar_t* string2Wchart(std::string str);
};

