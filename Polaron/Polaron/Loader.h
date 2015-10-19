#pragma once

struct Class
{
	u4 magic;
	u2 minor_version;
	u2 major_version;
	u2 constant_pool_count;
};

s32 load(std::string in, std::string out);