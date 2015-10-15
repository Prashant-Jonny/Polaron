#include "stdafx.h"
#include "Loader.h"

s32 checkArguments(s32 argc, char* argv[], s32* logLevel)
{
	if (argc < 2)
	{
		return 1;
	}

	// Optional arguments
	for (s32 c = 0; c < argc; c++)
	{
		if (strcmp(argv[c], "-l") || strcmp(argv[c], "--log"))
		{
			if (c + 2 <= argc - 1)
			{
				c++;
				if (strcmp(argv[c], "f") || strcmp(argv[c], "fatal"))
				{
					*logLevel = FATAL;
				}
				else if (strcmp(argv[c], "e") || strcmp(argv[c], "error"))
				{
					*logLevel = ERROR;
				}
				else if (strcmp(argv[c], "w") || strcmp(argv[c], "warning"))
				{
					*logLevel = WARNING;
				}
				else if (strcmp(argv[c], "i") || strcmp(argv[c], "info"))
				{
					*logLevel = INFO;
				}
				else if (strcmp(argv[c], "d") || strcmp(argv[c], "debug"))
				{
					*logLevel = DEBUG;
				}
			}
		}
	}
	
	return 0;
}

void printUsage()
{
	log(ERROR, "Too few arguments.");
	log(ERROR, "");
	log(ERROR, "Usage:");
	log(ERROR, "polaron <in> (<out>) (--log [f/e/w/i/d])");
}

void exit()
{
	printf("Press any key to exit...");
	_getch();
}

s32 main(s32 argc, char* argv[])
{
	s32 logLevel;

	s32 ret = checkArguments(argc, argv, &logLevel);
	if (ret != 0)
	{
		printUsage();
		exit();
		return 1;
	}

	if (initLogging(logLevel ? logLevel : DEBUG) != 0)
	{
		printf("Fatal error during logging intialization.");
		return 1;
	}

	ret = load(argv[1], argv[2] ? argv[2] : "");
	if (ret != 0)
	{
		log(ERROR, "Loading failed.");
	}

	finalizeLogging();
	exit();
	return 0;
}