#pragma once

#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

#include <coreinit/debug.h>

#include <nn/act.h>

#include "../globals.h"

#define OSSleepMillis(millis) OSSleepTicks(OSMillisecondsToTicks(millis))

#define ALIGN(align) __attribute__((aligned(align)));

#define IOCTL_SVC 0x02

#define _PP_CAT(a, b) a ## b

void _hp_assert_fail(const char *fmt, ...);

#define ASSERT_OPERATION(a, op, b, fmt, ...) if (!(a op b)) {                  \
                                                _hp_assert_fail(fmt, __VA_ARGS__); \
                                            }

#define ASSERT_HIGHER_THAN (a, b, fmt, ...) ASSERT_OPERATION(a, >,  b, fmt, __VA_ARGS__)
#define ASSERT_LESS_THAN(a, b, fmt, ...)    ASSERT_OPERATION(a, <,  b, fmt, __VA_ARGS__)
#define ASSERT_HIGHER_EQUAL(a, b, fmt, ...) ASSERT_OPERATION(a, >=, b, fmt, __VA_ARGS__)
#define ASSERT_LESS_EQUAL(a, b, fmt, ...)   ASSERT_OPERATION(a, <=, b, fmt, __VA_ARGS__)
#define ASSERT_EQUAL(a, b, fmt, ...)        ASSERT_OPERATION(a, ==, b, fmt, __VA_ARGS__)
#define ASSERT_NOT_EQUAL(a, b, fmt, ...)    ASSERT_OPERATION(a, !=, b, fmt, __VA_ARGS__)

namespace nn::boss {
    class Task {
    public:
        Task() {
            asm("__ct__Q3_2nn4boss4TaskFv");
        }

        ~Task() {
            asm("__dt__Q3_2nn4boss4TaskFv");
        }

        uint32_t Initialize(const char*, uint32_t) {
            asm("Initialize__Q3_2nn4boss4TaskFPCcUi");
        }

        uint32_t Unregister() {
            asm("Unregister__Q3_2nn4boss4TaskFv");
        }

        uint32_t StartScheduling(bool queueTaskOnCall) {
            asm("StartScheduling__Q3_2nn4boss4TaskFb");
        }

        uint32_t GetState(uint32_t *outExecCount) {
            asm("GetState__Q3_2nn4boss4TaskCFPUi");
        }

        uint32_t Run(bool) {
            asm("Run__Q3_2nn4boss4TaskFb");
        }

        uint32_t UpdateIntervalSec(uint32_t seconds) {
            asm("UpdateIntervalSec__Q3_2nn4boss4TaskFUi");
        }

        bool IsRegistered() {
            asm("IsRegistered__Q3_2nn4boss4TaskCFv");
        }

        nn::act::PersistentId persistentId;
        uint32_t unk_0x8;
        char task_name[8];
        uint64_t title_id;
        uint32_t unk_0x14;
        uint32_t unk_0x18;
    };

    static_assert(sizeof(Task) == 32, "nn::boss::Task must be 32 bytes.");
}

extern "C" int MCP_GetDeviceId(int handle, uint64_t *deviceId);

extern "C" void OSVReport(const char *fmt, ...);