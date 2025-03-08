#pragma once

#include <minecraft/utils.h>

#include <minecraft/client/resource/wstring.h>
#include <minecraft/ui/control/UIControl_List.h>
#include <minecraft/ui/fui/fuiRenderNode.h>
#include <minecraft/ui/scene/UIScene.h>

namespace mc_link {
	uint32_t __ct__20UIControl_ButtonListFv = 0x02DC0580;
	uint32_t addItem__20UIControl_ButtonListFRCQ2_3std78basic_string__tm__58_wQ2_3std20char_traits__tm__2_wQ2_3std18allocator__tm__2_wi = 0x02DC0604;
	uint32_t setupControl__20UIControl_ButtonListFP7UISceneP13fuiRenderNodeRCQ2_3std78basic_string__tm__58_cQ2_3std20char_traits__tm__2_cQ2_3std18allocator__tm__2_c = 0x02DC05EC;
}

namespace mc {
    class UIControl_ButtonList : public UIControl_List {
    public:
        UIControl_ButtonList()                            { call_func(void, mc_link::__ct__20UIControl_ButtonListFv, UIControl_ButtonList*)(this); }
        UIControl_ButtonList(UIControl_ButtonList *_this) { call_func(void, mc_link::__ct__20UIControl_ButtonListFv, UIControl_ButtonList*)(_this); }
        
        void addItem(mstd::wstring *str, uint32_t i)                                  { call_func(void, mc_link::addItem__20UIControl_ButtonListFRCQ2_3std78basic_string__tm__58_wQ2_3std20char_traits__tm__2_wQ2_3std18allocator__tm__2_wi, UIControl_ButtonList*, mstd::wstring*, uint32_t)(this, str, i); }
        void setupControl(UIScene *scene, fuiRenderNode *fuiNode, mstd::wstring *str) { call_func(void, mc_link::setupControl__20UIControl_ButtonListFP7UISceneP13fuiRenderNodeRCQ2_3std78basic_string__tm__58_cQ2_3std20char_traits__tm__2_cQ2_3std18allocator__tm__2_c, UIControl_ButtonList*, UIScene*, fuiRenderNode*, mstd::wstring*)(this, scene, fuiNode, str); }

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
    };
}