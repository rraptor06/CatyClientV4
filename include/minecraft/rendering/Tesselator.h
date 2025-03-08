#pragma once

#include <minecraft/utils.h>

#include <minecraft/rendering/BufferBuilder.h>

namespace mc_link {
    uint32_t getInstance__10TesselatorSFv = 0x03337EF0;
    uint32_t getBuilder__10TesselatorFv = 0x03337EE8;
}

namespace mc {
    class Tesselator {
    public:
        static Tesselator *getInstance() { return call_func(Tesselator*, mc_link::getInstance__10TesselatorSFv)(); }
        BufferBuilder *getBuilder()      { return call_func(BufferBuilder*, mc_link::getBuilder__10TesselatorFv, Tesselator*)(this); }
    };
}