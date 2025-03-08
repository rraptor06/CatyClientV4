#pragma once

#include <minecraft/utils.h>

#include <minecraft/ui/scene/UIScene.h>
#include <minecraft/util/enum/EUIScene.h>
#include <minecraft/util/SoundEvent.h>

namespace mc_link {
    uint32_t TouchBoxRebuild__19ConsoleUIControllerFP7UIScene = 0x02D9E69C;
    uint32_t NavigateToScene__19ConsoleUIControllerFi8EUIScenePv8EUILayer8EUIGroup = 0x02DA0254;
    uint32_t PlayUISFX__19ConsoleUIControllerFPC10SoundEvent = 0x02DA7918;
}

namespace mc {
    class ConsoleUIController {
    public:
        static ConsoleUIController *instance() { return (ConsoleUIController*)0x109F95E0; }

        void TouchBoxRebuild(UIScene *scene)                                                                           { call_func(void, mc_link::TouchBoxRebuild__19ConsoleUIControllerFP7UIScene, ConsoleUIController*, UIScene*)(this, scene); }
        int32_t NavigateToScene(int32_t param_1, EUIScene newScene, void* param_3, int32_t euilayer, int32_t euigroup) { call_func(void, mc_link::NavigateToScene__19ConsoleUIControllerFi8EUIScenePv8EUILayer8EUIGroup, ConsoleUIController*, int32_t, EUIScene, void*, int32_t, int32_t)(this, param_1, newScene, param_3, euilayer, euigroup); }
        void PlayUISFX(SoundEvent *sound)                                                                              { call_func(void, mc_link::PlayUISFX__19ConsoleUIControllerFPC10SoundEvent, ConsoleUIController*, SoundEvent*)(this, sound); }
    };
}