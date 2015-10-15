#include "stdafx.h"
#include "Loader.h"

std::string getAbsolutePath(std::string relative)
{
	char cpath[256];
#ifdef _WIN32
	_fullpath(cpath, relative.c_str(), 256);
	std::string path(cpath);
#else
	std::string path(realpath(relative.c_str(), NULL));
#endif
	return path;
}

bool checkExistence(std::string path)
{
	return PathFileExists(s2ws(path.c_str()).c_str());
}

s32 checkExtension(std::string in, std::string* out)
{
	log(DEBUG, in);
	log(DEBUG, *out);
	std::string fileType = in.substr(in.find_last_of(".") != std::string::npos);
	
	if (fileType == "class")
	{
		return 1;
	}
	else if (fileType == "jar")
	{
		return 2;
	}
	else
	{
		log(FATAL, "Unknown file type. (%s)", fileType);
	}

	return 0;
}

s32 load(std::string in, std::string out)
{
	std::string path = getAbsolutePath(in);
	s32 fileType = checkExtension(path, &out);

	if (!(fileType > 0))
	{
		log(ERROR, "Unknown file type.");
		return 1;
	}

	return 0;
}