#pragma once

#include <stdarg.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <fstream>

#ifdef _WIN32
#include <conio.h>
#include "Shlwapi.h"
#pragma comment(lib, "shlwapi.lib")
#undef ERROR
#endif

using s64 = int64_t;
using s32 = int32_t;
using s16 = int16_t;
using s8  = int8_t;
using s4  = int;
using s2  = short;
using s1  = char;
using u64 = uint64_t;
using u32 = uint32_t;
using u16 = uint16_t;
using u8  = uint8_t;
using u4  = unsigned int;
using u2  = unsigned short;
using u1  = unsigned char;

#include "Polaron/Logger.h"
#include "Polaron/Common.h"