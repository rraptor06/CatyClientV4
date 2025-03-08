#pragma once

#include <minecraft/utils.h>

namespace mc_link {
    uint32_t bind__8TexturesFi = 0x0338EE78;
}

namespace mc {
    class Textures {
    public:
        void bind(int32_t id) { call_func(void, mc_link::bind__8TexturesFi, Textures*, int32_t)(this, id); }
    };
}