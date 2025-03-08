#pragma once

#include <minecraft/utils.h>

#include <minecraft/ui/control/UIControl_List.h>
#include <minecraft/ui/scene/UIScene.h>

namespace mc_link {
    uint32_t __ct__28UIControl_CheckboxButtonListFv = 0x02DC59D4;
    uint32_t setupControl__28UIControl_CheckboxButtonListFP7UISceneP13fuiRenderNodeRCQ2_3std78basic_string__tm__58_cQ2_3std20char_traits__tm__2_cQ2_3std18allocator__tm__2_c = 0x02DC5A40;
    uint32_t AddNewItem__28UIControl_CheckboxButtonListFRCQ2_3std78basic_string__tm__58_wQ2_3std20char_traits__tm__2_wQ2_3std18allocator__tm__2_wibT1 = 0x02DC5A70;
}

namespace mc {
    class UIControl_CheckBoxButtonList : public UIControl_List {
    public:
        UIControl_CheckBoxButtonList()                                    { call_func(void, mc_link::__ct__28UIControl_CheckboxButtonListFv, UIControl_CheckBoxButtonList*)(this); }
        UIControl_CheckBoxButtonList(UIControl_CheckBoxButtonList *_this) { call_func(void, mc_link::__ct__28UIControl_CheckboxButtonListFv, UIControl_CheckBoxButtonList*)(_this); }

        void setupControl(UIScene *scene, uint32_t fuiNode, mstd::wstring *str)          { call_func(void, mc_link::setupControl__28UIControl_CheckboxButtonListFP7UISceneP13fuiRenderNodeRCQ2_3std78basic_string__tm__58_cQ2_3std20char_traits__tm__2_cQ2_3std18allocator__tm__2_c, UIControl_CheckBoxButtonList*, UIScene*, uint32_t, mstd::wstring*)(this, scene, fuiNode, str); }
        void addItem(mstd::wstring *str, uint32_t id, bool checked, mstd::wstring *icon) { call_func(void, mc_link::AddNewItem__28UIControl_CheckboxButtonListFRCQ2_3std78basic_string__tm__58_wQ2_3std20char_traits__tm__2_wQ2_3std18allocator__tm__2_wibT1, UIControl_CheckBoxButtonList*, mstd::wstring*, uint32_t, bool, mstd::wstring*)(this, str, id, checked, icon); }
    };
}