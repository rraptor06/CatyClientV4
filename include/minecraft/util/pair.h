#pragma once

#include <minecraft/utils.h>

namespace mc::mstd {
    template<typename T1, typename T2>
    struct pair {
    public:
        T1 t1;
        T2 t2;
    };
}