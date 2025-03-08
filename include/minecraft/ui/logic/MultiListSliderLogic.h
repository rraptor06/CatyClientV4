#pragma once

#include <minecraft/utils.h>

#include <minecraft/ui/control/UIControl_MultiList.h>

namespace mc_link {
    uint32_t __ct__20MultiListSliderLogicFv = 0x02E6CB0C;
    uint32_t AddTo__20MultiListSliderLogicCFR19UIControl_MultiListi = 0x02E6CFF8;
}

namespace mc {
    class MultiListSliderLogic {
    public:
        MultiListSliderLogic() { call_func(void, mc_link::__ct__20MultiListSliderLogicFv, MultiListSliderLogic*)(this); }

        void AddTo(UIControl_MultiList &list, int32_t param_2) { call_func(void, mc_link::AddTo__20MultiListSliderLogicCFR19UIControl_MultiListi, MultiListSliderLogic*, UIControl_MultiList&, int32_t)(this, list, param_2); }

        uint32_t unk_0x0;
        uint32_t unk_0x4;
        uint32_t unk_0x8;
        uint32_t unk_0xC;
        uint32_t unk_0x10;
    };
}