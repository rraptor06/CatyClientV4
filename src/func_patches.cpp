#include "globals.h"

#include <inttypes.h>
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <string>

#include <coreinit/dynload.h>
#include <coreinit/memorymap.h>
#include <coreinit/screen.h>
#include <coreinit/ios.h>
#include <coreinit/cosreport.h>

#include <mocha/mocha.h>

#include <wups.h>

#include "utils/utils.h"
#include "utils/logger.h"

int16_t drc_copy[0x120] = {};
int16_t tv_copy[0x120] = {};

typedef void (*AIInitDMAfn)(int16_t *addr, uint32_t size);

void DoAudioMagic(int16_t *addr, uint32_t size, bool isDRC, AIInitDMAfn targetFunc, AIInitDMAfn otherFunc) {
    otherFunc(addr, size > 0x240 ? 0x240 : size);
}

extern "C" void (*real_AIInitDMA)(int16_t *addr, uint32_t size) __attribute__((section(".data")));
extern "C" void (*real_AIInitDMA2)(int16_t *addr, uint32_t size) __attribute__((section(".data")));

DECL_FUNCTION(void, AI2InitDMA, int16_t *addr, uint32_t size) {
    DoAudioMagic(addr, size, true, real_AI2InitDMA, real_AIInitDMA);
}

DECL_FUNCTION(void, AIInitDMA, int16_t *addr, uint32_t size) {
    DoAudioMagic(addr, size, false, real_AIInitDMA, real_AI2InitDMA);
}

DECL_FUNCTION(void, AI2InitDMA2, int16_t *addr, uint32_t size) {
    DoAudioMagic(addr, size, true, real_AI2InitDMA2, real_AIInitDMA2);
}

DECL_FUNCTION(void, AIInitDMA2, int16_t *addr, uint32_t size) {
    DoAudioMagic(addr, size, false, real_AIInitDMA2, real_AI2InitDMA2);
}

bool sAvoidRecursiveCall = false;
bool sAvoidRecursiveCall2 = false;

DECL_FUNCTION(void, AXUpdateDeviceModes) {
    sAvoidRecursiveCall = true;
    real_AXUpdateDeviceModes();
    sAvoidRecursiveCall = false;
}

DECL_FUNCTION(void, AXUpdateDeviceModes2) {
    sAvoidRecursiveCall2 = true;
    real_AXUpdateDeviceModes();
    sAvoidRecursiveCall2 = false;
}

void UpdateAudioMode() {
    OSDynLoad_Module module = nullptr;
    if (OSDynLoad_IsModuleLoaded("sndcore2", &module) == OS_DYNLOAD_OK && module) {
        if (real_AXUpdateDeviceModes2 && !sAvoidRecursiveCall2) {
            my_AXUpdateDeviceModes2();
        }
    } else if (OSDynLoad_IsModuleLoaded("snd_core", &module) == OS_DYNLOAD_OK && module) {
        if (real_AXUpdateDeviceModes && !sAvoidRecursiveCall) {
            my_AXUpdateDeviceModes();
        }
    }
}

DECL_FUNCTION(uint32_t, AVMGetTVAudioMode, uint32_t *mode) {
    uint32_t res = real_AVMGetTVAudioMode(mode);

    if (*mode != 1) {
        *mode = 1;

        UpdateAudioMode();
    }

    return res;
}

DECL_FUNCTION(void, FSInit) {
    real_FSInit();
}

DECL_FUNCTION(void, PPCHalt) {
    OSScreenInit();
    OSScreenEnableEx(SCREEN_TV,  TRUE);
    OSScreenEnableEx(SCREEN_DRC, TRUE);
    OSScreenSetBufferEx(SCREEN_TV,  (uint8_t*)0xF4000000);
    OSScreenSetBufferEx(SCREEN_DRC, (uint8_t*)0xF4000000 + OSScreenGetBufferSizeEx(SCREEN_TV));
    OSScreenClearBufferEx(SCREEN_TV,  0xFF0000FF);
    OSScreenClearBufferEx(SCREEN_DRC, 0xFF0000FF);
    OSScreenPutFontEx(SCREEN_TV,  0, 0, "[ " PLUGIN_NAME " ]\nDetected an Error in The Current Game or Application.\nThe Wii U Console will try to reboot in 5 seconds!");
    OSScreenPutFontEx(SCREEN_DRC, 0, 0, "[ " PLUGIN_NAME " ]\nDetected an Error in The Current Game or Application.\nThe Wii U Console will try to reboot in 5 seconds!");
    OSScreenFlipBuffersEx(SCREEN_TV);
    OSScreenFlipBuffersEx(SCREEN_DRC);
    OSSleepMillis(5000);
    ALIGN(0x40) uint32_t args[0x40 >> 2];
    args[0] = 0x74;

    ALIGN(0x40) int32_t result[0x40 >> 2];
    IOS_Ioctl(gHaxHandle, IOCTL_SVC, args, sizeof(uint32_t), result, sizeof(uint32_t));
}

/**
 * Hooks for swapping mono and stereo audio on the Wii U Gamepad and the TV
 */
WUPS_MUST_REPLACE_FOR_PROCESS(AIInitDMA,            WUPS_LOADER_LIBRARY_SND_CORE, AIInitDMA,           WUPS_FP_TARGET_PROCESS_ALL);
WUPS_MUST_REPLACE_FOR_PROCESS(AI2InitDMA,           WUPS_LOADER_LIBRARY_SND_CORE, AI2InitDMA,          WUPS_FP_TARGET_PROCESS_ALL);
WUPS_MUST_REPLACE_FOR_PROCESS(AIInitDMA2,           WUPS_LOADER_LIBRARY_SNDCORE2, AIInitDMA,           WUPS_FP_TARGET_PROCESS_ALL);
WUPS_MUST_REPLACE_FOR_PROCESS(AI2InitDMA2,          WUPS_LOADER_LIBRARY_SNDCORE2, AI2InitDMA,          WUPS_FP_TARGET_PROCESS_ALL);
WUPS_MUST_REPLACE_FOR_PROCESS(AVMGetTVAudioMode,    WUPS_LOADER_LIBRARY_AVM,      AVMGetTVAudioMode,   WUPS_FP_TARGET_PROCESS_ALL);
WUPS_MUST_REPLACE_FOR_PROCESS(AXUpdateDeviceModes,  WUPS_LOADER_LIBRARY_SND_CORE, AXUpdateDeviceModes, WUPS_FP_TARGET_PROCESS_ALL);
WUPS_MUST_REPLACE_FOR_PROCESS(AXUpdateDeviceModes2, WUPS_LOADER_LIBRARY_SNDCORE2, AXUpdateDeviceModes, WUPS_FP_TARGET_PROCESS_ALL);

/**
 * In FSInit you can set up some stuff here, haven't used it before though, only saw it in other plugins
 */
WUPS_MUST_REPLACE_FOR_PROCESS(FSInit,  WUPS_LOADER_LIBRARY_COREINIT, FSInit,  WUPS_FP_TARGET_PROCESS_ALL);

/**
 * Gets called once the Wii U crashes for example.
 * Used to automatically reboot the Wii U after crashes.
 * This might not always work.
 */
WUPS_MUST_REPLACE_FOR_PROCESS(PPCHalt, WUPS_LOADER_LIBRARY_COREINIT, PPCHalt, WUPS_FP_TARGET_PROCESS_ALL);