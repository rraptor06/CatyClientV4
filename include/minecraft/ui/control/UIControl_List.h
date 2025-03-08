#pragma once

#include <minecraft/utils.h>

#include <minecraft/ui/control/UIControl_Base.h>

namespace mc_link {
    uint32_t init__14UIControl_ListFi = 0x02E5606C;
}

namespace mc {
    class UIControl_List : public UIControl_Base {
    public:
        void init(int param_1) { call_func(void, mc_link::init__14UIControl_ListFi, UIControl_List*, int32_t)(this, param_1); }

        uint32_t unk_0x5C;
    };
}