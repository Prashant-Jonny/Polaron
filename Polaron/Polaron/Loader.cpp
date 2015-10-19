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

s32 checkExtension(std::string in)
{
	std::string fileType = in.substr(strlen(in.c_str()) - 5);
	
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

s32 loadClass(std::string path)
{
	// Open the file
	std::ifstream file(path, std::ios::binary);

	if (!file)
	{
		log(FATAL, "Failed to open the class file.");
		return 1;
	}

	// Get the length of the class file
	file.seekg(0, std::ios::end);
	s32 length = file.tellg();
	file.seekg(0, std::ios::beg);

	// Read in the class fully
	u1* data = new u1[length];

	// Read in as unsigned char array (u1), instead of file.read(), which reads in as signed.
	for (s32 c = 0; c < length; c++)
	{
		data[c] = file.get();
	}

	// How to compare data[0 to 4] != 0xCAFEBABE?
	// (data[0] != 0xCA) && (data[1] != 0xFE) && ... Doesn't look very nice.
	if (data[0] != 0xCAFEBABE)
	{
		log(FATAL, "Class magic invalid. (0x%hhx)", data[0]);
		return 1;
	}

	return 0;
}

s32 load(std::string in, std::string out)
{
	std::string path = getAbsolutePath(in);
	std::ifstream file(path, std::ios::binary);
	s32 fileType;

	if (file)
	{
		file.close();
		if ((fileType = checkExtension(path)) == 0)
		{
			return 1;
		}
	}
	else
	{
		file.close();
		log(FATAL, "The file doesn't exist.");
		return 1;
	}

	if (fileType == 1)
	{
		if (loadClass(path) != 0)
		{
			return 1;
		}
	}
	else
	{
		log(FATAL, ".jar files aren't supported yet.");
		return 1;
	}

	return 0;
}