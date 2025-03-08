#pragma once

#include <minecraft/utils.h>

namespace mc::mstd {
    template<typename T>
    class vector {
    public:
        typedef       T *iter;
        typedef const T *citer;

        iter  begin()       { return &start[0]; }
        citer begin() const { return &start[0]; }
        iter  end()         { return &start[size()]; }
        citer end() const   { return &start[size()]; }

        T operator[](int32_t i) { return start[i]; }

        int32_t size() { return ((int32_t)finish - (int32_t)start) / sizeof(T); }

        uint32_t unk_0x0;
        T *start;
        T *finish;
        T *endOfStorage;
    };
}