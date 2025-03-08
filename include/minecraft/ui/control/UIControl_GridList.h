#pragma once

#include <minecraft/utils.h>

#include <minecraft/ui/control/UIControl_Base.h>
#include <minecraft/ui/scene/UIScene.h>

namespace mc_link {
    uint32_t __ct__18UIControl_GridListFv = 0x02DC4DC4;
    uint32_t setupControl__18UIControl_GridListFP7UISceneP13fuiRenderNodeRCQ2_3std78basic_string__tm__58_cQ2_3std20char_traits__tm__2_cQ2_3std18allocator__tm__2_c = 0x02DC5020;
    uint32_t addElement__18UIControl_GridListFQ2_9UIControl14eUIControlTypei= 0x02DC4A94;
    uint32_t init__18UIControl_GridListFi = 0x02DC5084;
}

namespace mc {
    class UIControl_GridList : public UIControl_Base {
    public:
        UIControl_GridList()                          { call_func(void, mc_link::__ct__18UIControl_GridListFv, UIControl_GridList*)(this); }
        UIControl_GridList(UIControl_GridList *_this) { call_func(void, mc_link::__ct__18UIControl_GridListFv, UIControl_GridList*)(_this); }

        void setupControl(UIScene *scene, uint32_t fuiNode, mstd::wstring *str) { call_func(void, mc_link::setupControl__18UIControl_GridListFP7UISceneP13fuiRenderNodeRCQ2_3std78basic_string__tm__58_cQ2_3std20char_traits__tm__2_cQ2_3std18allocator__tm__2_c, UIControl_GridList*, UIScene *scene, uint32_t, mstd::wstring*)(this, scene, fuiNode, str); }
        void addElement(int32_t controlType, int32_t param_2)                   { call_func(void, mc_link::addElement__18UIControl_GridListFQ2_9UIControl14eUIControlTypei, UIControl_GridList*, int32_t, int32_t)(this, controlType, param_2); }
        void init(int32_t param_1)                                              { call_func(void, mc_link::init__18UIControl_GridListFi, UIControl_GridList*, int32_t)(this, param_1); }
    };
}