#include "utils.h"

void _hp_assert_fail(const char *fmt, ...) {
    va_list args;
    va_start(args, fmt);
    int bufferLen = vsnprintf(nullptr, 0, fmt, args) + 1;
    va_end(args);
    char *buffer = (char*)malloc(bufferLen);
    va_start(args, fmt);
    vsnprintf(buffer, bufferLen, fmt, args);
    va_end(args);
    OSFatal(buffer);
}