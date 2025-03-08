#pragma once

#include <minecraft/utils.h>

#include <minecraft/client/resource/vector.h>
#include <minecraft/ui/fui/fuiFile.h>
#include <minecraft/ui/UILayer.h>
#include <minecraft/util/enum/EUIScene.h>
#include <minecraft/util/vtable/VTable_UIScene.h>

namespace mc_link {
	uint32_t __ct__7UISceneFiP7UILayer = 0x02E39FD8;
	uint32_t __dt__7UISceneFv = 0x02E30050;
	uint32_t initialiseMovie__7UISceneFv = 0x02E3A79C;
	uint32_t doHorizontalResizeCheck__7UISceneFv = 0x02E637C0;
	uint32_t setBackScene__7UISceneFP7UIScene = 0x02E84614;
	uint32_t setOpacity__7UISceneFf = 0x02E89B38;
	uint32_t navigateBack__7UISceneFv = 0x02E365B4;
	uint32_t sendInputToMovie__7UISceneFibN22 = 0x02E3CBD0;
}

namespace mc {
    class UIScene {
    public:
        UIScene()                           { call_func(void, mc_link::__ct__7UISceneFiP7UILayer, UIScene*)(this); }
        UIScene(int32_t id, UILayer *layer) { call_func(void, mc_link::__ct__7UISceneFiP7UILayer, UIScene*, int32_t, UILayer*)(this, id, layer); }
		~UIScene()                          { call_func(void, mc_link::__dt__7UISceneFv, UIScene*)(this); }

        void initialiseMovie()                											  { call_func(void, mc_link::initialiseMovie__7UISceneFv, UIScene*)(this); }
        void doHorizontalResizeCheck()        											  { call_func(void, mc_link::doHorizontalResizeCheck__7UISceneFv, UIScene*)(this); }
        void SetBackScene(UIScene *backScene) 											  { call_func(void, mc_link::setBackScene__7UISceneFP7UIScene, UIScene*, UIScene*)(this, backScene); }
		void setOpacity(float opacity)        											  { call_func(void, mc_link::setOpacity__7UISceneFf, UIScene*, float)(this, opacity); }
		void navigateBack()                   											  { call_func(void, mc_link::navigateBack__7UISceneFv, UIScene*)(this); }
		void sendInputToMovie(uint32_t param_1, bool param_2, bool param_3, bool param_4) { call_func(void, mc_link::sendInputToMovie__7UISceneFibN22, UIScene*, int32_t, bool, bool, bool)(this, param_1, param_2, param_3, param_4); }

        uint32_t unk_0x0;
		uint32_t UISControl;
		uint32_t unk_0x8;
		uint32_t unk_0xC;
		uint32_t unk_0x10;
		uint32_t unk_0x14;
		uint32_t unk_0x18;
		uint32_t unk_0x1C;
		fuiFile *fuiFile;
		uint32_t unk_0x24;
		uint32_t unk_0x28;
		uint32_t unk_0x2C;
		uint32_t unk_0x30;
		uint32_t unk_0x34;
		uint32_t unk_0x38;
		uint32_t unk_0x3C;
		uint32_t unk_0x40;
		uint32_t unk_0x44;
		uint32_t unk_0x48;
		uint32_t unk_0x4C;
		uint32_t unk_0x50;
		uint32_t unk_0x54;
		uint32_t unk_0x58;
		uint32_t unk_0x5C;
		uint32_t unk_0x60;
		float opacity;
		uint32_t unk_0x68;
		UIScene *backScene;
		uint32_t unk_0x70;
		uint32_t unk_0x74;
		uint32_t unk_0x78;
		uint32_t unk_0x7C;
		uint32_t unk_0x80;
		uint32_t unk_0x84;
		uint32_t unk_0x88;
		mstd::vector<uint32_t> UIControlVector;
		UILayer *_UILayer;
		uint32_t unk_0xA0;
		EUIScene UISceneId;
		uint32_t unk_0xA8;
		uint32_t unk_0xAC;
		uint32_t unk_0xB0;
		uint32_t unk_0xB4;
		uint32_t unk_0xB8;
		uint32_t unk_0xBC;
		uint32_t unk_0xC0;
		VTable_UIScene *vtbl;
    };
}