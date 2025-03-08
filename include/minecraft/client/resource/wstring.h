#pragma once

#include <minecraft/utils.h>

namespace mc_link {
    uint32_t __ct__Q2_3std78basic_string__tm__58_wQ2_3std20char_traits__tm__2_wQ2_3std18allocator__tm__2_wFPCZ1Z = 0x020B08D4;
    uint32_t assign__Q2_3std78basic_string__tm__58_wQ2_3std20char_traits__tm__2_wQ2_3std18allocator__tm__2_wF = 0x030E8BC4;
    uint32_t assign__Q2_3std78basic_string__tm__58_cQ2_3std20char_traits__tm__2_cQ2_3std18allocator__tm__2_cF = 0x02E33E08;
}

namespace mc::mstd {
    class wstring {
    public:
        wstring(const wchar_t *str) { call_func(void, mc_link::__ct__Q2_3std78basic_string__tm__58_wQ2_3std20char_traits__tm__2_wQ2_3std18allocator__tm__2_wFPCZ1Z, wstring*, const wchar_t*)(this, str); }
        wstring() = default;

        const wchar_t *c_str() const { return (length > 7) ? pointer : str; }

        const wstring &assign(const wchar_t *_str, int32_t _length) {
            str[0]  = 0;
            length2 = 7;
            length  = 0;

            return call_func(const wstring&, mc_link::assign__Q2_3std78basic_string__tm__58_wQ2_3std20char_traits__tm__2_wQ2_3std18allocator__tm__2_wF, wstring*, const wchar_t*, int32_t)(this, _str, _length);
        }

        const wstring &assign(const char *_str, int32_t _length) {
            str[0]  = 0;
            length2 = 7;
            length  = 0;

            return call_func(const wstring&, mc_link::assign__Q2_3std78basic_string__tm__58_cQ2_3std20char_traits__tm__2_cQ2_3std18allocator__tm__2_cF, wstring*, const char*, int32_t)(this, _str, _length);
        }

        bool operator==(const wchar_t *_str) {
            const wchar_t *__str = c_str();
            return wcscmp(__str, _str);
        }

        uint32_t unk_0x0;
        wchar_t str[8];
        wchar_t *pointer;
        uint32_t length;
        uint32_t length2;
    };
};