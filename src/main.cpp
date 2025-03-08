#include <vector>
#include <string>
#include <cstdint>
#include <cstdio>

#include <wups.h>

#include <coreinit/title.h>
#include <coreinit/ios.h>

#include <mocha/mocha.h>

#include <sys/iosupport.h>

#include "utils/logger.h"
#include "utils/config.h"
#include "utils/CThread.h"
#include "globals.h"

#include "client/client.h"
#include "plugin.h"

WUPS_PLUGIN_NAME(PLUGIN_NAME);
WUPS_PLUGIN_DESCRIPTION(PLUGIN_DESCRIPTION);
WUPS_PLUGIN_VERSION(PLUGIN_VERSION);
WUPS_PLUGIN_AUTHOR(PLUGIN_AUTHOR);
WUPS_PLUGIN_LICENSE(PLUGIN_LICENSE);

WUPS_USE_WUT_DEVOPTAB();
WUPS_USE_STORAGE(PLUGIN_STORAGE);

INITIALIZE_PLUGIN() {
    initLogging();
    initStorageAndConfig();
}

DEINITIALIZE_PLUGIN() {
    deinitLogging();
}

bool isMCTitleId() {
    uint64_t titleId = OSGetTitleID();
    return titleId == 0x00050000101DBE00 || titleId == 0x00050000101D9D00 || titleId == 0x00050000101D7500;
}

CThread *_clientThread = nullptr;

ON_APPLICATION_START() {
    initLogging();

    DEBUG_FUNCTION_LINE("Getting Hax Handle");
    gHaxHandle = IOS_Open((char*)("/dev/iosuhax"), (IOSOpenMode)0);

    DEBUG_FUNCTION_LINE("Init Mocha");
    MochaUtilsStatus mocha = Mocha_InitLibrary();
    if (mocha != MOCHA_RESULT_SUCCESS) {
        DEBUG_FUNCTION_LINE("Failed to init Mocha: %d", mocha);

        return;
    }

    gShouldLeaveThread = false;

    DEBUG_FUNCTION_LINE("Title ID Checks");
    DEBUG_FUNCTION_LINE("Title ID is %016llX", OSGetTitleID());
    if (isMCTitleId()) {
        DEBUG_FUNCTION_LINE("Starting Client Thread");

        _clientThread = CThread::create(clientThread, nullptr, CThread::eAttributeDetach | CThread::eAttributeAffCore1 | CThread::eAttributePinnedAff);
        if (_clientThread) {
            _clientThread->resumeThread();
        }
    }
}

ON_APPLICATION_ENDS() {
    gShouldLeaveThread = true;

    deinitLogging();
    Mocha_DeInitLibrary();
}