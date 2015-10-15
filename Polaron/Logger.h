#pragma once

#include "stdafx.h"

enum LogLevel
{
	INFO,
	WARNING,
	ERROR,
	FATAL,
	DEBUG,
};

s32 initLogging();
void finalizeLogging();
void log(LogLevel level, const std::string format, ...);