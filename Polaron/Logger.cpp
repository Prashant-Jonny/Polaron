#include "stdafx.h"
#include <fstream>
#include "Logger.h"

std::ofstream logFile;

s32 initLogging()
{
	logFile.open("Polaron.log");
	
	if (!logFile)
	{
		return 1;
	}

	logFile.clear();
	return 0;
}

void finalizeLogging()
{
	logFile.close();
}

void log(LogLevel level, const std::string format, ...)
{
	va_list args;
	std::string fmt;

	switch (level)
	{
	case INFO:    fmt += "I: "; break;
	case WARNING: fmt += "W: "; break;
	case ERROR:   fmt += "E: "; break;
	case FATAL:   fmt += "F: "; break;
	case DEBUG:   fmt += "D: "; break;
	}

	va_start(args, format);
	fmt += format + "\n";
	char* buffer = new char[strlen(fmt.c_str())];
	snprintf(buffer, sizeof(buffer), fmt.c_str(), args);

	if (level == ERROR)
	{
		fprintf(stderr, fmt.c_str(), args);
	}
	else
	{
		fprintf(stdout, fmt.c_str(), args);
	}

	logFile << format.c_str();
	va_end(args);
}