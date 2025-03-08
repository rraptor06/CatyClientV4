#pragma once

#include <minecraft/utils.h>

#include <minecraft/ui/control/UIControl.h>

namespace mc {
    class UIControl_Base : public UIControl {
    public:
        uint8_t filler[0xC];
    };
}