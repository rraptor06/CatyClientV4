#pragma once

#include "kernel.h"

#include <inttypes.h>

#define DECL_RHOOK(type, name, ...) type(*real_##name)(__VA_ARGS__); \
                                    type my_##name(__VA_ARGS__)
#define DECL_HOOK(type, name, ...)  type _hook_##name(__VA_ARGS__)

#define MINECRAFT_RHOOK(addr, name) real_##name = (decltype(real_##name))MinecraftPatcher::instance()->MinecraftRHook((void*)addr, (void*)&my_##name);
#define MINECRAFT_HOOK(addr, func)  uint32_t hook_##func[4] = { 0x3D800000UL | ((uint32_t)&_hook_##func >> 16), 0x618C0000UL | ((uint32_t)&_hook_##func & 0xFFFF), 0x7D8903A6UL, 0x4E800421UL }; \
                                    MinecraftPatcher::instance()->MinecraftHook((void*)addr, hook_##func, sizeof(hook_##func));

#define MINECRAFT_EXECUTABLE_SPACE_START (0x0384CC20 + 0x10000)

#define BRANCH_MAX_DISTANCE_POSITIVE 0x1FFFFFC
#define BRANCH_MAX_DISTANCE_NEGATIVE (-0x2000000)

#define INSTRUCTION_BRANCH 0x48000000
#define INSTRUCTION_BRANCH_OFFSET_BIT 0x3FFFFFC

class MinecraftDataProvider {
public:
    static MinecraftDataProvider *instance() {
        if (!_instance) {
            _instance = new MinecraftDataProvider();
        }

        return _instance;
    }

    void *allocateExecutable(uint32_t size) {
        int32_t ret = nextAddr;
        nextAddr += size;

        return (void*)ret;
    }

private:
    static MinecraftDataProvider *_instance;

    int32_t nextAddr = MINECRAFT_EXECUTABLE_SPACE_START;
};

class MinecraftPatcher {
public:
    static MinecraftPatcher *instance() {
        static MinecraftPatcher instance;
        return &instance;
    }

    void *ControlledHook(void *originFunc, void *myFunc) {
        if ((uint32_t)originFunc % sizeof(uint32_t) != 0 || (uint32_t)myFunc % sizeof(uint32_t) != 0) {
            return nullptr;
        }

        int32_t jmpLen = (int32_t)myFunc - (int32_t)originFunc;
        if (jmpLen > BRANCH_MAX_DISTANCE_POSITIVE || jmpLen < BRANCH_MAX_DISTANCE_NEGATIVE) {
            int32_t bigJmp[4];
            bigJmp[0] = 0x3D800000 | ((uint32_t)myFunc >> 16);    // lis r12, myFunc@h
            bigJmp[1] = 0x618C0000 | ((uint32_t)myFunc & 0xFFFF); // ori r12, r12, myFunc@l
            bigJmp[2] = 0x7D8903A6;                               // mtctr r12
            bigJmp[3] = 0x4E800420;                               // bctr

            void* destination = MinecraftDataProvider::instance()->allocateExecutable(sizeof(bigJmp));
            kernel_memcpy_flush(destination, bigJmp, sizeof(bigJmp));

            jmpLen = (int32_t)destination - (int32_t)originFunc;
        }

        int32_t realFuncBuf[2];
        void *realFunc = MinecraftDataProvider::instance()->allocateExecutable(sizeof(realFuncBuf));
        realFuncBuf[0] = *(int32_t*)originFunc;
        realFuncBuf[1] = INSTRUCTION_BRANCH | ((((int32_t)originFunc + sizeof(int32_t)) - ((int32_t)realFunc + sizeof(int32_t))) & INSTRUCTION_BRANCH_OFFSET_BIT);
        kernel_memcpy_flush(realFunc, realFuncBuf, sizeof(realFuncBuf));

        uint32_t instrJmpToMyFunc = INSTRUCTION_BRANCH | (jmpLen & INSTRUCTION_BRANCH_OFFSET_BIT);
        kernel_write_value<uint32_t>((uint32_t)originFunc, instrJmpToMyFunc);

        return realFunc;
    }

    void Hook(void *dst, void *instr, uint32_t instrSize) {
        if ((uint32_t)dst % 4 != 0 || instrSize % 4 != 0) {
            return;
        }

        int32_t injectionSize = instrSize + sizeof(int32_t) * 2;

        uint32_t *allocatedSpace = (uint32_t*)MinecraftDataProvider::instance()->allocateExecutable(injectionSize);
    
        int32_t jmpLen       = (uint32_t)allocatedSpace - (uint32_t)dst;
        int32_t jmpReturnLen = ((uint32_t)dst + sizeof(int32_t)) - (((uint32_t)allocatedSpace + sizeof(uint32_t) + instrSize));
        
        uint32_t instrJumpToInjected = INSTRUCTION_BRANCH | (jmpLen & INSTRUCTION_BRANCH_OFFSET_BIT);
        uint32_t instrReturnToOrigin = INSTRUCTION_BRANCH | (jmpReturnLen & INSTRUCTION_BRANCH_OFFSET_BIT);
        uint32_t instrReal =           *(int32_t*)dst;

        if (jmpLen > BRANCH_MAX_DISTANCE_POSITIVE || jmpLen < BRANCH_MAX_DISTANCE_NEGATIVE) {
            return;
        }

        if (jmpReturnLen > BRANCH_MAX_DISTANCE_POSITIVE || jmpReturnLen < BRANCH_MAX_DISTANCE_NEGATIVE) {
            return;
        }

        kernel_write_value<uint32_t>((uint32_t)allocatedSpace, instrReal);
        allocatedSpace++;

        kernel_memcpy_flush(allocatedSpace, instr, instrSize);
        allocatedSpace += instrSize / sizeof(uint32_t);

        kernel_write_value<uint32_t>((uint32_t)allocatedSpace, instrReturnToOrigin);
        kernel_write_value<uint32_t>((uint32_t)dst, instrJumpToInjected);
    }
};