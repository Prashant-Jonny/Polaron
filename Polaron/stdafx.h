#pragma once

#include <stdarg.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <conio.h>
#include <iostream>

#ifdef _WIN32
#include "Shlwapi.h"
#undef ERROR
#endif

using s64 = std::int64_t;
using s32 = std::int32_t;
using s16 = std::int16_t;
using s8 =  std::int8_t;
using u64 = std::uint64_t;
using u32 = std::uint32_t;
using u16 = std::uint16_t;
using u8 =  std::uint8_t;

#include "Logger.h"
#include "Common.h"