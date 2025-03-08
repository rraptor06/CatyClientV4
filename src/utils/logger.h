#pragma once

#include <string.h>
#include <stdio.h>

#include <coreinit/debug.h>

#include <whb/log.h>
#include <whb/log_cafe.h>
#include <whb/log_module.h>
#include <whb/log_udp.h>

#include "../plugin.h"

#ifdef __cplusplus
extern "C" {
#endif

void initLogging();
void deinitLogging();

#define __FILENAME_X__ (strrchr(__FILE__, '\\') ? strrchr(__FILE__, '\\') + 1 : __FILE__)
#define __FILENAME__   (strrchr(__FILE__, '/') ? strrchr(__FILE__, '/') + 1 : __FILENAME_X__)

#define DEBUG_FUNCTION_LINE(TXT, ...) WHBLogPrintf("%s: " TXT "", PLUGIN_NAME, ##__VA_ARGS__); \

#define OSFATAL_FUNCTION_LINE(TXT, ...) do { \
        char tmp[0x400]; \
        snprintf(tmp, 0x400, "%s" TXT "", PLUGIN_NAME, ##__VA_ARGS__); \
        OSFatal(tmp); \
    } while (0);

#define OSREPORT_FUNCTION_LINE(TXT, ...) do { \
        char tmp[0x400]; \
        snprintf(tmp, 0x400, "%s" TXT "", PLUGIN_NAME, ##__VA_ARGS__); \
        OSReport(tmp); \
    } while (0);

#ifdef __cplusplus
}
#endif