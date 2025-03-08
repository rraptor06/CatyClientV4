#pragma once

#include <minecraft/utils.h>

#include <minecraft/ui/control/UIControl_Base.h>
#include <minecraft/ui/scene/UIScene.h>

namespace mc_link {
    uint32_t __ct__18UIControl_SlotListFv = 0x02E57E3C;
    uint32_t setupControl__18UIControl_SlotListFP7UISceneP13fuiRenderNodeRCQ2_3std78basic_string__tm__58_cQ2_3std20char_traits__tm__2_cQ2_3std18allocator__tm__2_c = 0x02E8B7A0;
    uint32_t addSlot__18UIControl_SlotListFUi = 0x02E2F28C;
}

namespace mc {
    class UIControl_SlotList : public UIControl_Base {
    public:
        UIControl_SlotList()                          { call_func(void, mc_link::__ct__18UIControl_SlotListFv, UIControl_SlotList*)(this); }
        UIControl_SlotList(UIControl_SlotList *_this) { call_func(void, mc_link::__ct__18UIControl_SlotListFv, UIControl_SlotList*)(_this); }

        void setupControl(UIScene *scene, uint32_t fuiNode, mstd::wstring *str) { call_func(void, mc_link::setupControl__18UIControl_SlotListFP7UISceneP13fuiRenderNodeRCQ2_3std78basic_string__tm__58_cQ2_3std20char_traits__tm__2_cQ2_3std18allocator__tm__2_c, UIControl_SlotList*, UIScene *scene, uint32_t, mstd::wstring*)(this, scene, fuiNode, str); }
        void addSlot(uint32_t param_1)                                          { call_func(void, mc_link::addSlot__18UIControl_SlotListFUi, UIControl_SlotList*, uint32_t)(this, param_1); }
    };
}