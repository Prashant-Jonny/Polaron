#include "stdafx.h"
#include "Loader.h"

void printUsage()
{
	log(INFO, "Too few arguments.");
	log(INFO, "");
	log(INFO, "Usage:");
	log(INFO, "polaron <in> (<out>)");
}

void exit()
{
	printf("Press any key to exit...");
	_getch();
}

s32 main(s32 argc, char* argv[])
{
	if (initLogging() != 0)
	{
		printf("Fatal error during logging intialization.");
		return 1;
	}

	if (argc < 2)
	{
		printUsage();
		exit();
		return 1;
	}

	s32 ret = load(argv[1], argv[2] ? argv[2] : "");
	if (ret != 0)
	{
		log(ERROR, "Loading failed.");
	}

	finalizeLogging();
	exit();
	return 0;
}