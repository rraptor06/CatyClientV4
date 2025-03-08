#pragma once

#include <mc.h>

#define WIDTH 640.0f
#define HEIGHT 360.0f

class Drawer {
public:
    static void renderSetup(bool disableTex = true) {
        mc::GlStateManager::matrixMode(1);
        mc::GlStateManager::loadIdentity();
        mc::GlStateManager::ortho(0.0f, WIDTH, HEIGHT, 0.0f, -1.0f, 3000.0f);
        mc::GlStateManager::matrixMode(0);
        mc::GlStateManager::loadIdentity();
        mc::GlStateManager::translatef(0.0f, 0.0f, 0.0f);
        mc::GlStateManager::scalef(1.0f, 1.0f, 1.0f);
        mc::GlStateManager::disableCull();
        mc::GlStateManager::disableLighting();
        mc::GlStateManager::disableDepthTest();
        if (disableTex) mc::GlStateManager::disableTexture();
        else            mc::GlStateManager::enableTexture();
        mc::GlStateManager::enableBlend();
        mc::GlStateManager::blendFunc(4, 5);
        mc::GlStateManager::color4f(1, 1, 1, 1);
        mc::GlStateManager::disableFog();
    }

    static void CreateNewText(mc::Font* font, const mc::mstd::wstring& text, float size, float x, float y, uint32_t color = 0xFFFFFFFF, bool normal = true) {
        mc::GlStateManager::enableTexture();
        mc::GlStateManager::pushMatrix();
        mc::GlStateManager::translatef(x, y, 0);
        mc::GlStateManager::scalef(size, size, 0);
        if (normal)  font->drawShadow(text, 0, 0, color);
        else         font->draw      (text, 0, 0, color);
        mc::GlStateManager::popMatrix();
    }

    static void drawRoundedBox(float x, float y, float width, float height, float cornerRadius, int rgb, int a, int seg = 20) {
        float startX = x;
        float startY = y;
        float sizeX = width;
        float sizeY = height;
        float angle = cornerRadius;
        int segments = seg;

        mc::BufferBuilder* builder = mc::Tesselator::getInstance()->getBuilder();
        mc::GlStateManager::disableTexture();
        mc::GlStateManager::pushMatrix();
        mc::GlStateManager::color4f(1, 1, 1, 1);
        builder->begin(0);
        builder->color(rgb, a);

        float step = 90.0f / mc::toFloat(segments);
        for (int i = 0; i < segments; i++) {
            float  _x = sinf(degToRad(step * mc::toFloat(i)))     * angle;
            float  _y = cosf(degToRad(step * mc::toFloat(i)))     * angle;
            float __x = sinf(degToRad(step * mc::toFloat(i + 1))) * angle;	
            float __y = cosf(degToRad(step * mc::toFloat(i + 1))) * angle;

            // BOTTOM RIGHT
            builder->vertex(startX + ((sizeX / 2.0f) - angle),       startY + ((sizeY / 2.0f) - angle));
            builder->vertex(startX + ((sizeX / 2.0f) - angle) + _x,  startY + ((sizeY / 2.0f) - angle) + _y);
            builder->vertex(startX + ((sizeX / 2.0f) - angle) + __x, startY + ((sizeY / 2.0f) - angle) + __y);

            // TOP LEFT
            builder->vertex(startX - ((sizeX / 2.0f) - angle),       startY - ((sizeY / 2.0f) - angle));
            builder->vertex(startX - ((sizeX / 2.0f) - angle) - _x,  startY - ((sizeY / 2.0f) - angle) - _y);
            builder->vertex(startX - ((sizeX / 2.0f) - angle) - __x, startY - ((sizeY / 2.0f) - angle) - __y);

             _x = sinf(degToRad(180.0f + (step * mc::toFloat(i))))     * angle;
             _y = cosf(degToRad(180.0f + (step * mc::toFloat(i))))     * angle;
            __x = sinf(degToRad(180.0f + (step * mc::toFloat(i + 1)))) * angle;
            __y = cosf(degToRad(180.0f + (step * mc::toFloat(i + 1)))) * angle;

            // BOTTOM LEFT
            builder->vertex(startX - ((sizeX / 2.0f) - angle),       startY + ((sizeY / 2.0f) - angle));
            builder->vertex(startX - ((sizeX / 2.0f) - angle) + _x,  startY + ((sizeY / 2.0f) - angle) - _y);
            builder->vertex(startX - ((sizeX / 2.0f) - angle) + __x, startY + ((sizeY / 2.0f) - angle) - __y);

            // TOP RIGHT
            builder->vertex(startX + ((sizeX / 2.0f) - angle),       startY - ((sizeY / 2.0f) - angle));
            builder->vertex(startX + ((sizeX / 2.0f) - angle) - _x,  startY - ((sizeY / 2.0f) - angle) + _y);
            builder->vertex(startX + ((sizeX / 2.0f) - angle) - __x, startY - ((sizeY / 2.0f) - angle) + __y);
        }    
        builder->end();

        builder->begin();
        builder->color(rgb, a);
        builder->vertex(startX - (sizeX / 2.0f),  startY + (sizeY / 2.0f) - angle);
        builder->vertex(startX + (sizeX / 2.0f),  startY + (sizeY / 2.0f) - angle);
        builder->vertex(startX + (sizeX / 2.0f),  startY - (sizeY / 2.0f) + angle);
        builder->vertex(startX - (sizeX / 2.0f),  startY - (sizeY / 2.0f) + angle);
        builder->end();

        builder->begin();
        builder->color(rgb, a);
        builder->vertex(startX - (sizeX / 2.0f) + angle,  startY + (sizeY / 2.0f));
        builder->vertex(startX + (sizeX / 2.0f) - angle,  startY + (sizeY / 2.0f));
        builder->vertex(startX + (sizeX / 2.0f) - angle,  startY - (sizeY / 2.0f));
        builder->vertex(startX - (sizeX / 2.0f) + angle,  startY - (sizeY / 2.0f));
        builder->end();
        mc::GlStateManager::popMatrix();
    }
};