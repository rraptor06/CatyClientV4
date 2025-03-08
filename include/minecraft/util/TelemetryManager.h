#pragma once

#include <minecraft/utils.h>

#include <minecraft/util/vtable/VTable_TelemetryManager.h>

namespace mc {
    class TelemetryManager {
    public:
		static TelemetryManager *instance() { return *(TelemetryManager**)0x109F8B70; }

        uint32_t unk_0x0;
		uint32_t unk_0x4;
		uint32_t unk_0x8;
		uint32_t unk_0xC;
		uint32_t unk_0x10;
		uint32_t unk_0x14;
		uint32_t unk_0x18;
		uint32_t unk_0x1C;
		uint32_t unk_0x20;
		VTable_TelemetryManager *vtbl;
    };
}