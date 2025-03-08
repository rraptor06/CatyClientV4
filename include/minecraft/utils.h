#pragma once

#include <inttypes.h>
#include <string.h>
#include <wchar.h>
#include <math.h>
#include <vector>

#define get_value(address,offset) (*( (uint32_t*) ((address)+(offset)) ));

#define call_func(ret, addr, ...) ((ret(*)(__VA_ARGS__))addr)

#define MC_VFUNC(returnType, classType, functionName, ...) int flag_##functionName; \
                                                           returnType(*functionName)(classType *_this, ##__VA_ARGS__)

#define mc_swprintf ((int32_t(*)(wchar_t*, int32_t, const wchar_t*, ...))0x0382C8C0)
#define _sprintf  ((int32_t(*)(char*, const char*, ...))0x0382E03C)
#define swscanf  ((int32_t(*)(const wchar_t*, const wchar_t*, ...))0x0382B610)
#define _sscanf ((int32_t(*)(const char*, const char*, ...))0x0382F634)

typedef uint8_t*  Ptr8;
typedef uint16_t* Ptr16;
typedef uint32_t* Ptr32;
typedef uint64_t* Ptr64;