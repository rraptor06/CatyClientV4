#pragma once

#include <minecraft/utils.h>

#include <minecraft/client/resource/texture/Textures.h>
#include <minecraft/client/resource/shared_ptr.h>
#include <minecraft/client/resource/vector.h>
#include <minecraft/rendering/Font.h>
#include <minecraft/ui/Gui.h>

namespace mc_link {
    uint32_t GetString__4L10NSFi = 0x02F24864;
    uint32_t GetInstance__9MinecraftSFv = 0x03166818;
}

namespace mc {
    class Minecraft {
    public:
        static Minecraft *GetInstance() { return call_func(Minecraft*, mc_link::GetInstance__9MinecraftSFv)(); }

        static wchar_t *GetString(uint32_t id) { return call_func(wchar_t*, mc_link::GetString__4L10NSFi, uint32_t)(id); }

        uint32_t fixerUpper; // FixerUpper*
        uint32_t unk_0x4;
		uint32_t unk_0x8;
		uint32_t unk_0xC;
		uint32_t unk_0x10;
		uint32_t unk_0x14;
		uint32_t unk_0x18;
		uint32_t unk_0x1c;
        uint32_t timer; // Timer*
        uint32_t unk_0x24;
        uint32_t unk_0x28;
        uint32_t unk_0x2C;
        uint32_t levelRenderer; // LevelRenderer*
        uint32_t thePlayer; // LocalPlayer*
        uint32_t unk_0x38;
        uint32_t level; // Level*
        int32_t playerCount;
        boost::shared_ptr<uint32_t> localPlayers[4]; // boost::shared_ptr<LocalPlayer>
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
		int32_t unk_0xBC;
		uint32_t unk_0xC0;
		uint32_t unk_0xC4;
		uint32_t unk_0xC8;
		uint32_t unk_0xCC;
        uint32_t particleEngine; // ParticleEngine*
        uint32_t unk_0xD4;
		uint32_t unk_0xD8;
		uint32_t unk_0xDC;
		uint32_t unk_0xE0;
		uint32_t unk_0xE4;
		uint32_t unk_0xE8;
		uint32_t unk_0xEC;
		uint32_t unk_0xF0;
		uint32_t unk_0xF4;
		uint32_t unk_0xF8;
		uint32_t unk_0xFC;
        Textures *textures;
        Font *font;
        Font *altFont;
        uint32_t unk_0x10C;
        uint32_t progressRenderer; // ProgressRenderer*
        uint32_t gameRenderer; // GameRednerer*
        uint32_t entityRenderDispatcher; // EntityRenderDispatcher*
        uint32_t itemInHandRenderer; // ItemInHandRenderer*
        uint32_t blockColors; // BlockColors*
        uint32_t itemColors; // ItemColors*
        uint32_t blockTextureAtlas; // TextureAtlas*
        uint32_t itemRenderer; // ItemRenderer*
        uint32_t blockRenderDispatcher; // BlockRenderDispatcher*
        uint32_t unk_0x134;
        uint32_t unk_0x138;
        uint32_t unk_0x13C;
        uint32_t unk_0x140;
        Gui *gui;
        uint32_t unk_0x148;
        uint32_t unk_0x14C;
        uint32_t options; // Options*
        uint32_t unk_0x154;
        uint32_t soundEngine; // SoundEngine*
        uint32_t unk_0x15C;
        uint32_t texturePackRepository; // TexturePackRepository*
        uint32_t file; // File*
        uint32_t unk_0x168;
        uint32_t unk_0x16C;
        uint32_t unk_0x170;
        uint32_t unk_0x178;
        uint32_t unk_0x17C;
        uint32_t unk_0x180;
        uint32_t regionLevelStorage; // DirectoryLevelStorage*
        uint32_t statsCounters[4]; // StatsCounter*
        uint32_t unk_0x198;
		uint32_t unk_0x19C;
		uint32_t unk_0x1A0;
		uint32_t unk_0x1A4;
		uint32_t unk_0x1A8;
		uint32_t unk_0x1AC;
		uint32_t unk_0x1B0;
		uint32_t unk_0x1B4;
		uint32_t unk_0x1B8;
		uint32_t unk_0x1BC;
		uint32_t unk_0x1C0;
		uint32_t unk_0x1C4;
		uint32_t unk_0x1C8;
		uint32_t unk_0x1CC;
		uint32_t unk_0x1D0;
		uint32_t unk_0x1D4;
		uint32_t unk_0x1D8;
		uint32_t unk_0x1DC;
        int32_t unk_0x1E0;
        int32_t unk_0x1E4;
        uint32_t unk_0x1E8;
        uint32_t frameTimer; // FrameTimer*
        uint32_t unk_0x1F0;
		uint32_t unk_0x1F4;
		uint32_t unk_0x1F8;
		uint32_t unk_0x1FC;
		uint32_t unk_0x200;
		uint32_t unk_0x204;
		uint32_t unk_0x208;
		uint32_t unk_0x20C;
		uint32_t unk_0x210;
		uint32_t unk_0x214;
		uint32_t unk_0x218;
		uint32_t unk_0x21C;
		uint32_t unk_0x220;
		uint32_t unk_0x224;
		uint32_t unk_0x228;
        mstd::vector<void> wVec1;
        mstd::vector<void> wVec2;
        uint32_t minigame; // MiniGameDef*
        uint32_t clientMasterGameMode; // ClientMasterGameMode*
        uint32_t unk_0x254;
        uint32_t unk_0x258;
        uint32_t unk_0x25C;
        uint32_t unk_0x260;
        uint32_t unk_0x264;
    };
}