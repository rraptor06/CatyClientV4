#pragma once

#include <minecraft/utils.h>

#include <minecraft/client/resource/wstring.h>

namespace mc_link {
    uint32_t getName__10SoundEventCFv = 0x028E11EC;
}

namespace mc {
    class SoundEvent {
    public:
        static SoundEvent *ambient_cave_cave               asm("0x109c6158");
        static SoundEvent *random_successful_hit           asm("0x104C3FAC + 0x502200");
        static SoundEvent *random_bow                      asm("0x104C3FB0 + 0x502200");
        static SoundEvent *random_click                    asm("0x104C4060 + 0x502200");
        static SoundEvent *random_door_close               asm("0x104C4024 + 0x502200");
        static SoundEvent *random_fuse                     asm("0x104C4080 + 0x502200");
        static SoundEvent *random_explode                  asm("0x104C40E0 + 0x502200");
        static SoundEvent *random_fizz                     asm("0x104C430C + 0x502200");
        static SoundEvent *random_breath                   asm("0x104C4478 + 0x502200");
        static SoundEvent *random_break                    asm("0x104C453C + 0x502200");
        static SoundEvent *mob_bat_idle                    asm("0x104C3FB4 + 0x502200");
        static SoundEvent *mob_bat_death                   asm("0x104C3FB8 + 0x502200");
        static SoundEvent *mob_bat_hurt                    asm("0x104C3FBC + 0x502200");
        static SoundEvent *mob_bat_takeoff                 asm("0x104C3FC0 + 0x502200");
        static SoundEvent *mob_blaze_breath                asm("0x104C3FC4 + 0x502200");
        static SoundEvent *mob_blaze_death                 asm("0x104C3FCC + 0x502200");
        static SoundEvent *mob_blaze_hit                   asm("0x104C3FD0 + 0x502200");
        static SoundEvent *mob_ghast_fireball              asm("0x104C3FD4 + 0x502200");
        static SoundEvent *mob_cat_meow                    asm("0x104C4008 + 0x502200");
        static SoundEvent *mob_cat_hit                     asm("0x104C400C + 0x502200");
        static SoundEvent *mob_cat_hiss                    asm("0x104C4010 + 0x502200");
        static SoundEvent *mob_cat_purr                    asm("0x104C4018 + 0x502200");
        static SoundEvent *mob_cat_purreow                 asm("0x104C401C + 0x502200");
        static SoundEvent *mob_chicken_idle                asm("0x104C402C + 0x502200");
        static SoundEvent *mob_chicken_hurt                asm("0x104C4030 + 0x502200");
        static SoundEvent *mob_chicken_plop                asm("0x104C4034 + 0x502200");
        static SoundEvent *mob_chicken_step                asm("0x104C403C + 0x502200");
        static SoundEvent *mob_endermen_portal             asm("0x104C4048 + 0x502200");
        static SoundEvent *mob_endermen_scream             asm("0x109c6308");
        static SoundEvent *mob_endermen_stare              asm("0x109c630c");
        static SoundEvent *mob_cow_idle                    asm("0x104C4064 + 0x502200");
        static SoundEvent *mob_cow_hurt                    asm("0x104C4068 + 0x502200");
        static SoundEvent *mob_cow_step                    asm("0x104C4074 + 0x502200");
        static SoundEvent *mob_creeper_death               asm("0x104C4078 + 0x502200");
        static SoundEvent *mob_creeper_hurt                asm("0x104C407C + 0x502200");
        static SoundEvent *mob_horse_donkey_idle           asm("0x104C4090 + 0x502200");
        static SoundEvent *mob_horse_donkey_angry          asm("0x104C4094 + 0x502200");
        static SoundEvent *mob_horse_donkey_death          asm("0x104C409C + 0x502200");
        static SoundEvent *mob_horse_donkey_hit            asm("0x104C40A0 + 0x502200");
        static SoundEvent *mob_guardian_elder_idle         asm("0x104C40A8 + 0x502200");
        static SoundEvent *mob_guardian_land_idle          asm("0x104C40AC + 0x502200");
        static SoundEvent *mob_guardian_curse              asm("0x104C40B0 + 0x502200");
        static SoundEvent *mob_guardian_elder_death        asm("0x104C40B4 + 0x502200");
        static SoundEvent *mob_guardian_land_death         asm("0x104C40B8 + 0x502200");
        static SoundEvent *mob_guardian_flop               asm("0x104C40BC + 0x502200");
        static SoundEvent *mob_guardian_elder_hit          asm("0x104C40C0 + 0x502200");
        static SoundEvent *mob_guardian_land_hit           asm("0x104C40C4 + 0x502200");
        static SoundEvent *mob_enderdragon_growl           asm("0x104C40D8 + 0x502200");
        static SoundEvent *mob_enderdragon_end             asm("0x104C40DC + 0x502200");
        static SoundEvent *mob_enderdragon_wings           asm("0x104C40E4 + 0x502200"); 
        static SoundEvent *mob_wolf_howl                   asm("0x104C4728 + 0x502200");
        static SoundEvent *mob_wolf_hurt                   asm("0x109C692C");
        static SoundEvent *mob_wolf_panting                asm("0x109C6930");
        static SoundEvent *mob_wolf_shake                  asm("0x109C6934");
        static SoundEvent *mob_wolf_step                   asm("0x109C6938");
        static SoundEvent *mob_wolf_whine                  asm("0x109C693C");
        static SoundEvent *mob_zombie_idle                 asm("0x109C6974");
        static SoundEvent *mob_zombie_wood                 asm("0x109C6978");
        static SoundEvent *mob_zombie_metal                asm("0x109C697C");
        static SoundEvent *mob_zombie_woodbreak            asm("0x109C6980");
        static SoundEvent *mob_zombie_death                asm("0x109C6984");
        static SoundEvent *mob_horse_zombie_death          asm("0x109C698C");
        static SoundEvent *mob_witherboss_death            asm("0x109C68FC");
        static SoundEvent *mob_witherboss_ambient          asm("0x109C68F4");
        static SoundEvent *mob_witherboss_hurt             asm("0x109C6900");
        static SoundEvent *entity_bobber_throw             asm("0x104C3FD8 + 0x502200");
        static SoundEvent *entity_bobber_retrieve          asm("0x104C3FDC + 0x502200");
        static SoundEvent *entity_cow_milk                 asm("0x104C4070 + 0x502200");
        static SoundEvent *item_bottle_empty               asm("0x104C3FE0 + 0x502200");
        static SoundEvent *item_bottle_fill                asm("0x104C3FE4 + 0x502200");
        static SoundEvent *item_bottle_fill_dragonbreath   asm("0x104C3FE8 + 0x502200");
        static SoundEvent *item_bucket_empty               asm("0x104C3FF0 + 0x502200");
        static SoundEvent *item_bucket_empty_lava          asm("0x104C3FF4 + 0x502200");
        static SoundEvent *item_bucket_fill                asm("0x104C3FF8 + 0x502200");
        static SoundEvent *item_bucket_fill_lava           asm("0x104C3FFC + 0x502200");
        static SoundEvent *item_bucket_fill_fish           asm("0x104C4000 + 0x502200");
        static SoundEvent *item_bucket_empty_fish          asm("0x104C4004 + 0x502200");
        static SoundEvent *item_elytra_flying              asm("0x104C40C8 + 0x502200");
        static SoundEvent *item_trident_riptide2           asm("0x104C4954 + 0x502200");
        static SoundEvent *item_trident_return             asm("0x109C6B4C");
        static SoundEvent *block_brewing_stand_brew        asm("0x104C3FEC + 0x502200");
        static SoundEvent *block_chest_close               asm("0x104C4020 + 0x502200");
        static SoundEvent *block_chest_open                asm("0x104C4028 + 0x502200");
        static SoundEvent *block_chorus_flower_death       asm("0x104C4040 + 0x502200");
        static SoundEvent *block_chorus_flower_grow        asm("0x104C4044 + 0x502200");
        static SoundEvent *block_enchantment_table_enchant asm("0x104C40CC + 0x502200");
        static SoundEvent *block_enderchest_close          asm("0x104C40D0 + 0x502200");
        static SoundEvent *block_enderchest_open           asm("0x104C40D4 + 0x502200");
        static SoundEvent *block_note_xylophone            asm("0x104C488C + 0x502200");
        static SoundEvent *block_note_bell                 asm("0x104C4890 + 0x502200");
        static SoundEvent *block_note_chime                asm("0x104C4894 + 0x502200");
        static SoundEvent *block_note_flute                asm("0x104C4898 + 0x502200");
        static SoundEvent *block_note_guitar               asm("0x104C489C + 0x502200");
        static SoundEvent *block_wooden_door_close         asm("0x109C6940");
        static SoundEvent *block_wooden_door_open          asm("0x109C6944");
        static SoundEvent *block_wooden_trapdoor_close     asm("0x109C6948");
        static SoundEvent *block_wooden_trapdoor_open      asm("0x109C694C");
        static SoundEvent *block_end_portal_frame_fill     asm("0x109C6AAC");
        static SoundEvent *block_end_portal_spawn          asm("0x109C6ab0");
        static SoundEvent *block_beacon_activate           asm("0x109C6B0C");
        static SoundEvent *block_beacon_deactivate         asm("0x109C6B18");
        static SoundEvent *note_bd                         asm("0x104C439C + 0x502200");
        static SoundEvent *note_bassattack                 asm("0x104C43A0 + 0x502200");
        static SoundEvent *note_harp                       asm("0x104C43A4 + 0x502200");
        static SoundEvent *note_hat                        asm("0x104C43A8 + 0x502200");
        static SoundEvent *note_pling                      asm("0x104C43AC + 0x502200");
        static SoundEvent *note_snare                      asm("0x104C43B0 + 0x502200");
        static SoundEvent *ambient_weather_thunder         asm("0x104C4324 + 0x502200");
        static SoundEvent *MG01_celebration                asm("0x104C47CC + 0x502200");
        static SoundEvent *MG01_death                      asm("0x104C47D4 + 0x502200");
        static SoundEvent *MG01_gracezero                  asm("0x104C47DC + 0x502200");
        static SoundEvent *MG01_lobby                      asm("0x104C47E0 + 0x502200");
        static SoundEvent *MG01_lobbyaccent                asm("0x104C47E4 + 0x502200");
        static SoundEvent *MG01_lobbyzero                  asm("0x104C47E8 + 0x502200");
        static SoundEvent *MG01_gamestart                  asm("0x104C47EC + 0x502200");
        static SoundEvent *MG01_showdown                   asm("0x109C69C8");
        static SoundEvent *MG01_chest                      asm("0x109C69D0");
        static SoundEvent *MG02_gamestart                  asm("0x104C47F8 + 0x502200");
        static SoundEvent *MG03_emeraldPointTick           asm("0x104C4864 + 0x502200");
        static SoundEvent *MG03_checkpoint                 asm("0x109C6A10");
        static SoundEvent *MG03_mboost                      asm("0x109C6A14");
        static SoundEvent *MG03_bestTime                   asm("0x109C6A18");
        static SoundEvent *MG03_finishLine                 asm("0x109C6A1C");
        static SoundEvent *MG03_winner                     asm("0x109C6A50");
        static SoundEvent *MG03_winnerAnnounce             asm("0x109C6A54");
        static SoundEvent *MG03_emeraldPointTok            asm("0x109C6A68");
        static SoundEvent *MG03_goldPointTick              asm("0x109C6A6C");
        static SoundEvent *MG03_goldPointTok               asm("0x109C6A70");
        static SoundEvent *MG03_diamondPoint               asm("0x109C6A74");
        static SoundEvent *MG03_respawn                    asm("0x109C6A78");
        static SoundEvent *dig_cloth                       asm("0x104C404C + 0x502200");
        static SoundEvent *step_cloth                      asm("0x104C4050 + 0x502200");
        static SoundEvent *fire_fire                       asm("0x104C3FC8 + 0x502200");
        static SoundEvent *portal_trigger                  asm("0x109c66c4");
        static SoundEvent *portal_travel                   asm("0x109c66c0");
        static SoundEvent *portal_portal                   asm("0x109c66bc");
        static SoundEvent *fireworks_twinkle               asm("0x109c637c");
        static SoundEvent *fireworks_twinkle_far           asm("0x109c6380");
        static SoundEvent *ward                            asm("0x109c6708");
        static SoundEvent *where_are_we_now                asm("0x109c6704");
        static SoundEvent *strad                           asm("0x109c6700");
        static SoundEvent *stal                            asm("0x109c66fc");
        static SoundEvent *mellohi                         asm("0x109c66f8");
        static SoundEvent *mall                            asm("0x109c66f4");
        static SoundEvent *far                             asm("0x109c66f0");
        static SoundEvent *chirp                           asm("0x109c66ec");
        static SoundEvent *cat                             asm("0x109c66e8");
        static SoundEvent *blocks                          asm("0x109c66e4");
        static SoundEvent *thirteen                        asm("0x109c66e0");
        static SoundEvent *eleven                          asm("0x109c66dc");
        static SoundEvent *button                          asm("0x109C6570");
        static SoundEvent *unk                             asm("0x109C6ACC");

        void getName(const mstd::wstring& name) { call_func(void, mc_link::getName__10SoundEventCFv, SoundEvent*, const mstd::wstring&)(this, name); }
    };
}