#pragma once

#include <minecraft/utils.h>

namespace mc_link {
    uint32_t begin__13BufferBuilderFi = 0x02FD1FB4;
    uint32_t end__13BufferBuilderFv = 0x02FD2288;
    uint32_t color__13BufferBuilderFiT1 = 0x02FD36C4;
    uint32_t vertexUV__13BufferBuilderFfN41 = 0x02FD2AF4;
    uint32_t vertex__13BufferBuilderFfN21 = 0x02FD2A34;
}

namespace mc {
    class BufferBuilder {
    public:
        void begin(int32_t mode = 3)                               { call_func(void, mc_link::begin__13BufferBuilderFi, BufferBuilder*, int32_t)(this, mode); }
        void end()                                                 { call_func(void, mc_link::end__13BufferBuilderFv, BufferBuilder*)(this); }
        void color(int32_t color, int32_t alpha)                   { call_func(void, mc_link::color__13BufferBuilderFiT1, BufferBuilder*, int32_t, int32_t)(this, color, alpha); }
        void vertexUV(float x, float y, float z, float u, float v) { call_func(void, mc_link::vertexUV__13BufferBuilderFfN41, BufferBuilder*, float, float, float, float, float)(this, x, y, z, u, v); }

        void vertex(float x, float y, float z = 0.0f, bool fixCoords3D = false) {
            double fx = fixCoords3D ? (x - *(double*)0x109CCC18) : x;
            double fy = fixCoords3D ? (y - *(double*)0x109CCC20) : y;
            double fz = fixCoords3D ? (z - *(double*)0x109CCC28) : z;

            call_func(void, mc_link::vertex__13BufferBuilderFfN21, BufferBuilder*, float, float, float)(this, fx, fy, fz);
        }
    };
}