#pragma once

#include <minecraft/utils.h>

#include <minecraft/client/resource/vector.h>
#include <minecraft/util/unordered_map.h>
#include <minecraft/util/pair.h>
#include <minecraft/ui/UIGroup.h>

namespace mc_link {
    uint32_t updateFocusState__7UILayerFb = 0x02E7F95C;
}

namespace mc {
    class UILayer {
    public:
        void updateFocusState(bool state) { call_func(void, mc_link::updateFocusState__7UILayerFb, UILayer*, bool)(this, state); }

        mstd::vector<struct UIScene*> scenes;
        mstd::vector<struct UIScene*> components;
        mstd::vector<struct UIScene*> unk_0x20;
        mstd::vector<struct UIScene*> unk_0x30;
        boost::unordered_map<int32_t, mstd::pair<int32_t, bool>> componentVisibility;
        bool unk_0x58;
        bool unk_0x59;
        bool unk_0x5A;
        bool unk_0x5B;
        int32_t unk_0x5C;
        int32_t unk_0x60;
        UIGroup *group;
    };
}