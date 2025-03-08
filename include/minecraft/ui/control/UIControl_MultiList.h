#pragma once

#include <minecraft/utils.h>

#include <minecraft/client/resource/wstring.h>
#include <minecraft/ui/control/UIControl_List.h>
#include <minecraft/ui/fui/fuiRenderNode.h>
#include <minecraft/ui/scene/UIScene.h>

namespace mc_link {
    uint32_t __ct__19UIControl_MultiListFv = 0x02E67BD4;
    uint32_t setupControl__19UIControl_MultiListFP7UISceneP13fuiRenderNodeRCQ2_3std78basic_string__tm__58_cQ2_3std20char_traits__tm__2_cQ2_3std18allocator__tm__2_c = 0x02E8E86C;
    uint32_t AddNewCheckbox__19UIControl_MultiListFRCQ2_3std78basic_string__tm__58_wQ2_3std20char_traits__tm__2_wQ2_3std18allocator__tm__2_wib = 0x02E67CA8;
    uint32_t AddNewButton__19UIControl_MultiListFRCQ2_3std78basic_string__tm__58_wQ2_3std20char_traits__tm__2_wQ2_3std18allocator__tm__2_wib = 0x02E345EC;
    uint32_t AddNewLabel__19UIControl_MultiListFRCQ2_3std78basic_string__tm__58_wQ2_3std20char_traits__tm__2_wQ2_3std18allocator__tm__2_wi = 0x02E67C40;
    uint32_t AddNewSlider__19UIControl_MultiListFRCQ2_3std78basic_string__tm__58_wQ2_3std20char_traits__tm__2_wQ2_3std18allocator__tm__2_wiN32bN22 = 0x02E6CF88;
}

namespace mc {
    class UIControl_MultiList : public UIControl_List {
    public:
        UIControl_MultiList()                           { call_func(void, mc_link::__ct__19UIControl_MultiListFv, UIControl_MultiList*)(this); }
        UIControl_MultiList(UIControl_MultiList *_this) { call_func(void, mc_link::__ct__19UIControl_MultiListFv, UIControl_MultiList*)(_this); }

        void setupControl(UIScene *scene, fuiRenderNode *fuiNode, mstd::wstring *str) { call_func(void, mc_link::setupControl__19UIControl_MultiListFP7UISceneP13fuiRenderNodeRCQ2_3std78basic_string__tm__58_cQ2_3std20char_traits__tm__2_cQ2_3std18allocator__tm__2_c, UIControl_MultiList*, UIScene*, fuiRenderNode*, mstd::wstring*)(this, scene, fuiNode, str); }
        void setupControl(UIScene *scene, uint32_t fuiNode, mstd::wstring *str)       { call_func(void, mc_link::setupControl__19UIControl_MultiListFP7UISceneP13fuiRenderNodeRCQ2_3std78basic_string__tm__58_cQ2_3std20char_traits__tm__2_cQ2_3std18allocator__tm__2_c, UIControl_MultiList*, UIScene*, uint32_t, mstd::wstring*)(this, scene, fuiNode, str); }

        void AddNewCheckbox(const mstd::wstring &str, uint32_t id, bool enabled)                                         { call_func(void, mc_link::AddNewCheckbox__19UIControl_MultiListFRCQ2_3std78basic_string__tm__58_wQ2_3std20char_traits__tm__2_wQ2_3std18allocator__tm__2_wib, UIControl_MultiList*, const mstd::wstring&, uint32_t, bool)(this, str, id, enabled); }
        void AddNewButton(const mstd::wstring &str, uint32_t id, bool enabled)                                           { call_func(void, mc_link::AddNewButton__19UIControl_MultiListFRCQ2_3std78basic_string__tm__58_wQ2_3std20char_traits__tm__2_wQ2_3std18allocator__tm__2_wib, const mstd::wstring&, uint32_t, bool)(str, id, enabled); }
        void AddNewLabel(const mstd::wstring &str, uint32_t id)                                                          { call_func(void, mc_link::AddNewLabel__19UIControl_MultiListFRCQ2_3std78basic_string__tm__58_wQ2_3std20char_traits__tm__2_wQ2_3std18allocator__tm__2_wi, UIControl_MultiList*, const mstd::wstring&, uint32_t)(this, str, id); }
        void AddNewSlider(const mstd::wstring &str, bool enabled, uint32_t id, uint32_t idx, uint32_t min, uint32_t max) { call_func(void, mc_link::AddNewSlider__19UIControl_MultiListFRCQ2_3std78basic_string__tm__58_wQ2_3std20char_traits__tm__2_wQ2_3std18allocator__tm__2_wiN32bN22, UIControl_MultiList*, const mstd::wstring&, uint32_t, uint32_t, uint32_t, uint32_t, bool, uint32_t, uint32_t)(this, str, id, min, max, idx, enabled, max, min); }

        void _AddNewSlider(const mstd::wstring& string, bool Enabled, uint32_t ID, uint32_t Index, uint32_t Minimum, uint32_t Maximum)
        {
            call_func(void, 0x02E6CF88, UIControl_MultiList*, const mstd::wstring&, uint32_t, uint32_t, uint32_t, uint32_t, bool, uint32_t, uint32_t)(this, string, ID, Minimum, Maximum, Index, Enabled, Maximum, Minimum);
        }

        uint32_t unk_0x60;
        uint32_t unk_0x64;
        uint32_t unk_0x68;
        uint32_t unk_0x6C;
        uint32_t unk_0x70;
        uint32_t unk_0x74;
        uint32_t unk_0x78;
        uint32_t unk_0x7C;
        uint32_t unk_0x80;
        uint32_t unk_0x84;
        uint32_t unk_0x88;
        uint32_t unk_0x8C;
        uint32_t unk_0x90;
        uint32_t unk_0x94;
        uint32_t unk_0x98;
        uint32_t unk_0x9C;
        uint32_t unk_0xA0;
        uint32_t unk_0xA4;
        uint32_t unk_0xA8;
        uint32_t unk_0xAC;
        uint32_t unk_0xB0;
        uint32_t unk_0xB4;
        uint32_t unk_0xB8;
        uint32_t unk_0xBC;
    };
}