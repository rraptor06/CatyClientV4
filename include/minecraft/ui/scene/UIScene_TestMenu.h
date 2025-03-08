#pragma once

#include <minecraft/utils.h>

#include <minecraft/client/app/ConsoleUIController.h>
#include <minecraft/client/resource/wstring.h>
#include <minecraft/client/MinecraftClient.h>
#include <minecraft/ui/control/UIControl_MultiList.h>
#include <minecraft/ui/logic/MultiListSliderLogic.h>
#include <minecraft/ui/scene/UIScene.h>
#include <minecraft/ui/UILayer.h>
#include <minecraft/util/enum/EUIScene.h>
#include <minecraft/util/vtable/VTable_UIScene.h>
#include <minecraft/util/SoundEvent.h>

namespace mc {
    struct MenuOption {
        const wchar_t *str;
        int32_t type;
        bool enabled;
        uint32_t idx;
        uint32_t min;
        uint32_t max;
    };

    class UIScene_TestMenu : public UIScene {
    public:
        UIScene_TestMenu(uint32_t id, uint32_t layer) {
            call_func(void, 0x02E39FD8, UIScene*, uint32_t, uint32_t)(this, id, layer);

            VTable_UIScene *_vtbl = new VTable_UIScene;
            memcpy(_vtbl, (VTable_UIScene*)0x1088794C, sizeof(VTable_UIScene));
            _vtbl->__dt                         = &__dt;
            _vtbl->getMoviePath                 = &getMoviePath;
            _vtbl->getSceneType                 = &getSceneType;
            _vtbl->mapElementsAndNames          = &mapElementsAndNames;
            // _vtbl->handleInput                  = &handleInput;
            _vtbl->handleCheckboxElementToggled = &handleCheckboxElementToggled;
            // _vtbl->handleSliderElementMove      = &handleSliderElementMove;
            this->vtbl = _vtbl;

            UIControl_MultiList(&this->list);
            this->initialiseMovie();

            this->list.init(0);
            
            this->list._AddNewSlider(L"heheha", true, 0xFF0, 0, 0, 3);

            this->doHorizontalResizeCheck();
            this->unk_0x17C = 0;

            ConsoleUIController::instance()->TouchBoxRebuild(this);
        }

        static void __dt(UIScene *scene) {
            // DEBUG_FUNCTION_LINE("deconstructor called");

            call_func(void, mc_link::__dt__7UISceneFv, UIScene*)(scene);
        }

        static void getMoviePath(UIScene *scene, mstd::wstring &str) { str.assign(L"DebugOptionsMenu", 16); }
        static int32_t getSceneType(UIScene *scene)                  { return EUIScene::DEBUG; }

        static bool mapElementsAndNames(UIScene *scene) {
            uint32_t fuiRoot = call_func(uint32_t, 0x02BA8144, uint32_t)((uint32_t)scene->fuiFile);

            mstd::wstring *str = new mstd::wstring(L"");
            str->assign("DebugOptionsList", 16);

            ((UIScene_TestMenu*)scene)->list.setupControl(scene, fuiRoot, str);

            UIControl_MultiList *control = &((UIScene_TestMenu*)scene)->list;

            call_func(void, 0x02E34E18, uint32_t*, UIControl_MultiList**)((uint32_t*)&scene->UIControlVector, &control);

            return true;
        }

        static void handleInput(UIScene *scene, uint32_t param_2, uint32_t param_3, int32_t param_4, int32_t param_5, uint32_t param_6) {
            if (param_3 > 3) {
                if (param_3 > 5) {
                    if (param_3 != 0x14) {
                        if (param_3 != 0x15) {
                            return;
                        }

                        if (param_5 == 0) {
                            return;
                        }

                        if (param_4 != 0) {
                            return;
                        }

                        scene->navigateBack();

                        return;
                    }

                    if (param_5 != 0) {
                        ConsoleUIController::instance()->PlayUISFX(SoundEvent::unk);
                    }
                }

                scene->sendInputToMovie(param_3, param_4, param_5, param_6);
            }
        }

        static void handleCheckboxElementToggled(UIScene *scene, int32_t param_2, uint32_t id, bool state) {
            // DEBUG_FUNCTION_LINE("%d %s", id, state ? "true" : "false");

            // ConsoleUIController::instance()->NavigateToScene(scene->UISceneId, mc::EUIScene::HOW_TO_PLAY, nullptr, 6, 7);
            scene->navigateBack();
        }

        static void handleSliderElementMove(UIScene *scene, uint32_t param_2, uint32_t param_3, uint32_t param_4) {
            // DEBUG_FUNCTION_LINE("%d %d %d", param_2, param_3, param_4);
        }

        UIControl_MultiList list;
        uint32_t unk_0x17C;
    };
}