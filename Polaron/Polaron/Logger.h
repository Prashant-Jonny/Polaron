#pragma once

enum LogLevel
{
	FATAL,
	ERROR,
	WARNING,
	INFO,
	DEBUG,
};

s32 initLogging(s32 logLevel);
void finalizeLogging();
void log(LogLevel level, const std::string format, ...);