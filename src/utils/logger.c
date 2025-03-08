#include "logger.h"

#include <inttypes.h>

#include <whb/log_cafe.h>
#include <whb/log_module.h>
#include <whb/log_udp.h>

void initLogging() {
    WHBLogModuleInit();
    WHBLogCafeInit();
    WHBLogUdpInit();
}

void deinitLogging() {
    WHBLogModuleDeinit();
    WHBLogCafeDeinit();
    WHBLogUdpDeinit();
}