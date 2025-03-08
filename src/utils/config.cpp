#include "config.h"

#include "../globals.h"
#include "../plugin.h"
#include "logger.h"

#include <vpad/input.h>

#include <wups.h>
#include <wups/config/WUPSConfigItemStub.h>

#include <exception>

static WUPSConfigAPICallbackStatus configMenuOpenendCallback(WUPSConfigCategoryHandle rootHandle) {
    try {
        WUPSConfigCategory root = WUPSConfigCategory(rootHandle);
        WUPSConfigAPIStatus err;
        root.add(WUPSConfigItemStub::Create(CONFIG_STUB_DISPLAY_CLIENT));
    } catch (std::exception &e) {
        DEBUG_FUNCTION_LINE("Exception: %s\n", e.what());

        return WUPSCONFIG_API_CALLBACK_RESULT_ERROR;
    }

    return WUPSCONFIG_API_CALLBACK_RESULT_SUCCESS;
}

static void configMenuClosedCallback() {
    WUPSStorageError err;
    if ((err = WUPSStorageAPI::SaveStorage()) != WUPS_STORAGE_ERROR_SUCCESS) {
        DEBUG_FUNCTION_LINE("Failed to close storage: %s (%d)", WUPSStorageAPI_GetStatusStr(err), err);
    }
}

void initStorageAndConfig() {
    WUPSStorageError err;
    if ((err = WUPSStorageAPI::SaveStorage()) != WUPS_STORAGE_ERROR_SUCCESS) {
        DEBUG_FUNCTION_LINE("Failed to save storage: %s (%d)", WUPSStorageAPI_GetStatusStr(err), err);
    }

    WUPSConfigAPIOptionsV1 config_options = {.name = PLUGIN_NAME};
    WUPSConfigAPIStatus config_err;
    if ((config_err = WUPSConfigAPI_Init(config_options, configMenuOpenendCallback, configMenuClosedCallback)) != WUPSCONFIG_API_RESULT_SUCCESS) {
        DEBUG_FUNCTION_LINE("Failed to init config api: %s (%d)", WUPSConfigAPI_GetStatusStr(config_err), config_err);
    }
}