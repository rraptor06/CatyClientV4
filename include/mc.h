#pragma once

#include "minecraft/client/app/ConsoleUIController.h"
#include "minecraft/client/resource/texture/Textures.h"
#include "minecraft/client/resource/shared_ptr.h"
#include "minecraft/client/resource/vector.h"
#include "minecraft/client/resource/wstring.h"
#include "minecraft/client/MinecraftClient.h"

#include "minecraft/rendering/BufferBuilder.h"
#include "minecraft/rendering/Font.h"
#include "minecraft/rendering/GlStateManager.h"
#include "minecraft/rendering/Tesselator.h"

#include "minecraft/ui/control/UIControl_Base.h"
#include "minecraft/ui/control/UIControl_ButtonList.h"
#include "minecraft/ui/control/UIControl_CheckBoxButtonList.h"
#include "minecraft/ui/control/UIControl_GridList.h"
#include "minecraft/ui/control/UIControl_List.h"
#include "minecraft/ui/control/UIControl_MultiList.h"
#include "minecraft/ui/control/UIControl_SlotList.h"
#include "minecraft/ui/control/UIControl.h"
#include "minecraft/ui/fui/fuiFile.h"
#include "minecraft/ui/fui/fuiRenderNode.h"
#include "minecraft/ui/logic/MultiListSliderLogic.h"
#include "minecraft/ui/scene/UIScene_TestMenu.h"
#include "minecraft/ui/scene/UIScene.h"
#include "minecraft/ui/UIGroup.h"
#include "minecraft/ui/UILayer.h"

#include "minecraft/util/enum/EUIScene.h"
#include "minecraft/util/vtable/VTable_TelemetryManager.h"
#include "minecraft/util/vtable/VTable_UIScene.h"
#include "minecraft/util/vtable/VTable.h"
#include "minecraft/util/FloatConverter.h"
#include "minecraft/util/pair.h"
#include "minecraft/util/TelemetryManager.h"
#include "minecraft/util/unordered_map.h"

#include "curl.h"

static float degToRad(float deg) {
    return (deg * M_PI / 180.0f);
}

static float radToDeg(float rad) {
    return (rad * 180.0f / M_PI);
}