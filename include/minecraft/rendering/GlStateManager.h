#pragma once

#include <minecraft/utils.h>

#define MC_GL_ZERO                0
#define MC_GL_ONE                 1
#define MC_GL_SRC_ALPHA           4
#define MC_GL_ONE_MINUS_SRC_ALPHA 5

#define MC_GL_TRIANGLES    0
#define MC_GL_TRIANGLE_FAN 1
#define MC_GL_QUADS        2
#define MC_GL_QUADS_STRIP  3
#define MC_GL_LINES        4
#define MC_GL_LINES_STRIP  5

#define MC_GL_MODELVIEW  0
#define MC_GL_PROJECTION 1
#define MC_GL_TEXTURE    2

namespace mc_link {
    uint32_t disableDepthTest__14GlStateManagerSFv = 0x030E9B9C;
    uint32_t enableDepthTest__14GlStateManagerSFv = 0x030E9BB8;
    uint32_t pushMatrix__14GlStateManagerSFv = 0x030E4B3C;
    uint32_t scalef__14GlStateManagerSFfN21 = 0x030E4B6C;
    uint32_t translatef__14GlStateManagerSFfN21 = 0x30E4B54;
    uint32_t rotatef__14GlStateManagerSFfN31 = 0x030E4B84;
    uint32_t popMatrix__14GlStateManagerSFv = 0x030E4BD8;
    uint32_t disableTexture__14GlStateManagerSFv = 0x030E6268;
    uint32_t enableTexture__14GlStateManagerSFv = 0x030E6294;
    uint32_t depthMask__14GlStateManagerSFb = 0x030E52FC;
    uint32_t ortho__14GlStateManagerSFdN51 = 0x03110D4C;
    uint32_t matrixMode__14GlStateManagerSFi = 0x03103064;
    uint32_t loadIdentity__14GlStateManagerSFv = 0x03103080;
    uint32_t disableCull__14GlStateManagerSFv = 0x030F974C;
    uint32_t enableCull__14GlStateManagerSFv = 0x030f9768;
    uint32_t enableBlend__14GlStateManagerSFv = 0x030E5284;
    uint32_t disableBlend__14GlStateManagerSFv = 0x030E5328;
    uint32_t blendFunc__14GlStateManagerSFiT1 = 0x030E52A0;
    uint32_t disableLighting__14GlStateManagerSFv = 0x030E4B24;
    uint32_t color4f__14GlStateManagerSFfN31 = 0x030E4BA8;
    uint32_t disableFog__14GlStateManagerSFv = 0x03108C44;
}

namespace mc {
    class GlStateManager {
    public:
        static void disableDepthTest()                            { call_func(void, mc_link::disableDepthTest__14GlStateManagerSFv)(); }
        static void enableDepthTest()                             { call_func(void, mc_link::enableDepthTest__14GlStateManagerSFv)(); }
        static void pushMatrix()                                  { call_func(void, mc_link::pushMatrix__14GlStateManagerSFv)(); }
        static void scalef(float x, float y, float z)             { call_func(void, mc_link::scalef__14GlStateManagerSFfN21, float, float, float)(x, y, z); }
        static void translatef(float x, float y, float z)         { call_func(void, mc_link::translatef__14GlStateManagerSFfN21, float, float, float)(x, y, z); }
        static void rotatef(float x, float y, float z, float w)   { call_func(void, mc_link::rotatef__14GlStateManagerSFfN31, float, float, float, float)(x, y, z, w); }
        static void popMatrix()                                   { call_func(void, mc_link::popMatrix__14GlStateManagerSFv)(); }
        static void disableTexture()                              { call_func(void, mc_link::disableTexture__14GlStateManagerSFv)(); }
        static void enableTexture()                               { call_func(void, mc_link::enableTexture__14GlStateManagerSFv)(); }
        static void depthMask(bool param_1)                       { call_func(void, mc_link::depthMask__14GlStateManagerSFb, bool)(param_1); }
        static void ortho(double param_1, double param_2,
                          double param_3, double param_4,
                          double param_5, double param_6)         { call_func(void, mc_link::ortho__14GlStateManagerSFdN51, double, double, double, double, double, double)(param_1, param_2, param_3, param_4, param_5, param_6); }
        static void matrixMode(uint32_t mode)                     { call_func(void, mc_link::matrixMode__14GlStateManagerSFi, uint32_t)(mode); }
        static void loadIdentity()                                { call_func(void, mc_link::loadIdentity__14GlStateManagerSFv)(); }
        static void disableCull()                                 { call_func(void, mc_link::disableCull__14GlStateManagerSFv)(); }
        static void enableCull()                                  { call_func(void, mc_link::enableCull__14GlStateManagerSFv)(); }
        static void enableBlend()                                 { call_func(void, mc_link::enableBlend__14GlStateManagerSFv)(); }
        static void disableBlend()                                { call_func(void, mc_link::disableBlend__14GlStateManagerSFv)(); }
        static void blendFunc(uint32_t param_1, uint32_t param_2) { call_func(void, mc_link::blendFunc__14GlStateManagerSFiT1, uint32_t, uint32_t)(param_1, param_2); }
        static void disableLighting()                             { call_func(void, mc_link::disableLighting__14GlStateManagerSFv)(); }
        static void color4f(double r, double g, double b,
                            double a)                             { call_func(void, mc_link::color4f__14GlStateManagerSFfN31, double, double, double, double)(r, g, b, a); }
        static void disableFog()                                  { call_func(void, mc_link::disableFog__14GlStateManagerSFv)(); }
    };
}