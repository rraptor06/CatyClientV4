#pragma once

#include <inttypes.h>

#include <coreinit/memheap.h>

#include "utils/input.h"

#define CONFIG_STUB_DISPLAY_CLIENT "Client Working!"

extern int32_t gHaxHandle;
extern bool    gShouldLeaveThread; // Doesn't work currently