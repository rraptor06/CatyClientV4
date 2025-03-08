#include "client.h"
#include "drawer.h"

#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>

#include <mc.h>

#include "../utils/MinecraftPatcher.h"

DECL_HOOK(void, hook_FrameInWorld) {
    Drawer::renderSetup();
    mc::Font* font = mc::Minecraft::GetInstance()->font;
    Drawer::CreateNewText(font, L"CatyClient V4", 2.0f, 5, 5, 0xFF6729d4, true);
}

DECL_HOOK(void, hook_FrameNotInWorld) {
    // TODO: Add items here
}

void clientThread(CThread *thread, void *arg) {
    MINECRAFT_HOOK(0x02D9CAC0, hook_FrameInWorld);
    MINECRAFT_HOOK(0x02D9C8B0, hook_FrameNotInWorld);
}