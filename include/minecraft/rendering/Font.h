#pragma once

#include <minecraft/utils.h>

#include <minecraft/client/resource/wstring.h>

#define MC_FONT_CHAR_HEIGHT 8

namespace mc_link {
    uint32_t width__4FontFRCQ2_3std78basic_string__tm__58_wQ2_3std20char_traits__tm__2_wQ2_3std18allocator__tm__2_w = 0x030E919C;
    uint32_t drawShadow__4FontFRCQ2_3std78basic_string__tm__58_wQ2_3std20char_traits__tm__2_wQ2_3std18allocator__tm__2_wiN22 = 0x03126B88;
    uint32_t draw__4FontFRCQ2_3std78basic_string__tm__58_wQ2_3std20char_traits__tm__2_wQ2_3std18allocator__tm__2_wiN22bT5 = 0x030E9A10;
}

namespace mc {
    class Font {
    public:
        static Font *instance() { return (Font*)(*(uint32_t*)(*(uint32_t*)0x109CD8E4 + 0x104)); }

        int32_t width(const mstd::wstring &str)                                           { return call_func(uint32_t, mc_link::width__4FontFRCQ2_3std78basic_string__tm__58_wQ2_3std20char_traits__tm__2_wQ2_3std18allocator__tm__2_w, Font*, const mstd::wstring&)(this, str); }
        void drawShadow(const mstd::wstring &str, uint32_t x, uint32_t y, uint32_t color) { call_func(void, mc_link::drawShadow__4FontFRCQ2_3std78basic_string__tm__58_wQ2_3std20char_traits__tm__2_wQ2_3std18allocator__tm__2_wiN22, Font*, const mstd::wstring&, uint32_t, uint32_t, uint32_t)(this, str, x, y, color); }
        void draw(const mstd::wstring &str, uint32_t x, uint32_t y, uint32_t color)       { call_func(void, mc_link::draw__4FontFRCQ2_3std78basic_string__tm__58_wQ2_3std20char_traits__tm__2_wQ2_3std18allocator__tm__2_wiN22bT5, Font*, const mstd::wstring&, uint32_t, uint32_t, uint32_t, uint32_t, uint32_t)(this, str, x, y, color, 0, 1); }
    };
}