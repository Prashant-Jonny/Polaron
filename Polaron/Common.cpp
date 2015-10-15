#include "Common.h"

#ifdef _WIN32
std::wstring s2ws(const std::string& string)
{
	s32 slength = (s32)string.length() + 1;
	s32 len = MultiByteToWideChar(CP_ACP, 0, string.c_str(), slength, 0, 0);
	wchar_t* buf = new wchar_t[len];
	MultiByteToWideChar(CP_ACP, 0, string.c_str(), slength, buf, len);
	std::wstring r(buf);
	delete[] buf;
	return r;
}
#endif