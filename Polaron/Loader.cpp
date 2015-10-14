#include "stdafx.h"
#include "Shlwapi.h"
#include "Loader.h"

s32 checkExtension(std::string in, std::string* out)
{
	log(DEBUG, in);
	log(DEBUG, *out);

	return 0;
}

s32 load(std::string in, std::string out)
{
	checkExtension(in, &out);

	return 0;
}