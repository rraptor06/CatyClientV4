#pragma once

#include <minecraft/utils.h>

#include <minecraft/ui/scene/faker/UISceneFakerElement.h>

#include <mc.h>

#include <vpad/input.h>

namespace mc {
    class UISceneFaker {
    public:
        enum Alignment : int32_t {
            ALIGNMENT_TOP = 0x1, ALIGNMENT_BOTTOM = 0x2,
            ALIGNMENT_LEFT = 0x4, ALIGNMENT_RIGHT = 0x8,
            ALIGNMENT_CENTER = 0x10
        };

        UISceneFaker(int32_t _alignment,
                     float _posX, float _posY,
                     float _minWidth, float _minHeight,
                     double _opacity,
                     bool _reverseShadow) : alignment(_alignment), posX(_posX), posY(_posY),
                                            minWidth(_minWidth), minHeight(_minHeight),
                                            opacity(_opacity), reverseShadow(_reverseShadow) 
        {
            this->calcPosX = 0.0f;
            this->calcPosY = 0.0f;

            this->buttonFlag = false;

            this->menuIndex = 0;
        }

        ~UISceneFaker() {
            elements.clear();

            VPADShutdown();
        }

        void init() noexcept {
            this->acquireSceneIds(sceneIds);
            this->calcPos();

            if (!this->selectablesEmpty()) {
                while (this->menuIndex < this->elements.size() && this->elements[this->menuIndex].getType() == UISceneFakerElement::ELEMENT_TYPE_LABEL) {
                    this->menuIndex++;
                }
            }

            VPADInit();
        }

        void render() {
            GlStateManager::matrixMode(MC_GL_PROJECTION);
            GlStateManager::loadIdentity();
            GlStateManager::ortho(0.0, 640.0, 360.0, 0.0, -1.0f, 3000.0);
            GlStateManager::matrixMode(MC_GL_MODELVIEW);
            GlStateManager::loadIdentity();
            GlStateManager::translatef(0.0f, 0.0f, -2500.0f);
            GlStateManager::scalef(1.0f, 1.0f, 1.0f);
            GlStateManager::disableCull();
            GlStateManager::disableLighting();
            GlStateManager::disableDepthTest();
            GlStateManager::enableTexture();
            GlStateManager::enableBlend();
            GlStateManager::blendFunc(MC_GL_SRC_ALPHA, MC_GL_ONE_MINUS_SRC_ALPHA);
            GlStateManager::color4f(1.0, 1.0, 1.0, this->opacity);
            GlStateManager::disableFog();

            float cornerWidth  = 12.0f;
            float cornerHeight = 12.0f;
            float fillerWidth  = 203.0f;
            float fillerHeight = 12.0f;
            float middleWidth  = floor(this->width  - 2.0f * cornerWidth);
            float middleHeight = this->height - 2.0f * cornerHeight;

            float leftPosX = this->calcPosX;
            float rightPosX = this->calcPosX + cornerWidth + middleWidth;

            if (reverseShadow) {
                std::swap(leftPosX, rightPosX);
            }

            renderScenePart(leftPosX,                     this->calcPosY, cornerWidth, cornerHeight, this->sceneIds.Corner.Top.left);
            renderScenePart(this->calcPosX + cornerWidth, this->calcPosY, middleWidth, fillerHeight, this->sceneIds.Filler.top);
            renderScenePart(rightPosX,                    this->calcPosY, cornerWidth, cornerHeight, this->sceneIds.Corner.Top.right);

            renderScenePart(leftPosX,                     this->calcPosY + cornerHeight, cornerWidth, middleHeight, this->sceneIds.Filler.Middle.left);
            renderScenePart(this->calcPosX + cornerWidth, this->calcPosY + cornerHeight, middleWidth, middleHeight, this->sceneIds.Filler.Middle.middle);
            renderScenePart(rightPosX,                    this->calcPosY + cornerHeight, cornerWidth, middleHeight, this->sceneIds.Filler.Middle.right);

            renderScenePart(leftPosX,                     this->calcPosY + cornerHeight + middleHeight, cornerWidth, cornerHeight, this->sceneIds.Corner.Bottom.left);
            renderScenePart(this->calcPosX + cornerWidth, this->calcPosY + cornerHeight + middleHeight, middleWidth, fillerHeight, this->sceneIds.Filler.bottom);
            renderScenePart(rightPosX,                    this->calcPosY + cornerHeight + middleHeight, cornerWidth, cornerHeight, this->sceneIds.Corner.Bottom.right);

            for (int32_t i = 0; i < elements.size(); i++) {
                UISceneFakerElement element = elements[i];

                wchar_t elementTxt[0xFF];
                mc_swprintf(elementTxt, 0xFF, L"%ls%ls%ls",
                            (this->menuIndex == i && element.getType() != UISceneFakerElement::ELEMENT_TYPE_LABEL) ? L"> " : L"",
                            element.getTxt(), element.getType() == UISceneFakerElement::ELEMENT_TYPE_CHECKBOX ? (
                                element.isEnabled() ? L" [ON]" : L" [OFF]"
                            ) : L"");

                GlStateManager::pushMatrix();
                GlStateManager::translatef(leftPosX + 8.25f, (this->calcPosY + 8.25f) + (i * 13.0f), 0.0f);
                GlStateManager::scalef(1.2f, 1.2f, 0.0f);
                Font::instance()->draw(elementTxt, 0, 0, 0xFF4D4D4D);
                GlStateManager::popMatrix();
            }
        }

        void addNewLabel(wchar_t *txt, int32_t id) {
            elements.push_back(UISceneFakerElement(txt, id, UISceneFakerElement::ELEMENT_TYPE_LABEL));
        }

        void addNewCheckbox(wchar_t *txt, int32_t id) {
            elements.push_back(UISceneFakerElement(txt, id, UISceneFakerElement::ELEMENT_TYPE_CHECKBOX));
        }

        void removeElement(int32_t id) {
            for (int32_t i = elements.size() - 1; i >= 0; i--) {
                if (elements[i].getId() == id) {
                    elements.erase(elements.begin() + i);
                }
            }
        }

        void handleInput() {
            if (this->selectablesEmpty()) {
                return;
            }

            VPADRead(VPADChan::VPAD_CHAN_0, &vpadData, 1, &vpadError);
            bool buttonDown = ((vpadData.hold & 0x000FFFFF) & VPAD_BUTTON_DOWN) == VPAD_BUTTON_DOWN;
            bool buttonUp   = ((vpadData.hold & 0x000FFFFF) & VPAD_BUTTON_UP)   == VPAD_BUTTON_UP;

            if (!this->buttonFlag) {
                if (buttonDown) {
                    this->menuIndex++;
                    while (this->menuIndex < this->elements.size() && this->elements[this->menuIndex].getType() == UISceneFakerElement::ELEMENT_TYPE_LABEL) {
                        this->menuIndex++;
                    }

                    if (this->menuIndex >= this->elements.size()) {
                        this->menuIndex = 0;
                        while (this->menuIndex < this->elements.size() && this->elements[this->menuIndex].getType() == UISceneFakerElement::ELEMENT_TYPE_LABEL) {
                            this->menuIndex++;
                        }
                    }

                    this->buttonFlag = true;
                } else if (buttonUp) {
                    if (this->menuIndex == 0) {
                        this->menuIndex = this->elements.size() - 1;
                    } else {
                        this->menuIndex--;
                    }

                    while (this->menuIndex >= 0 && this->elements[this->menuIndex].getType() == UISceneFakerElement::ELEMENT_TYPE_LABEL) {
                        if (this->menuIndex == 0) {
                            this->menuIndex = this->elements.size() - 1;
                        } else {
                            this->menuIndex--;
                        }
                    }

                    this->buttonFlag = true;
                }
            } else if (this->buttonFlag && !buttonDown && !buttonUp) {
                this->buttonFlag = false;
            }
        }

        void doHorizontalResizeCheck() {
            float maxTextWidth = this->minWidth;
            
            for (int32_t i = 0; i < elements.size(); i++) {
                UISceneFakerElement element = elements[i];

                if (element.getType() == UISceneFakerElement::ELEMENT_TYPE_LABEL) {
                    float textWidth = Font::instance()->width(element.getTxt());
                    textWidth *= 1.2f;
                    if (textWidth > maxTextWidth) {
                        maxTextWidth = textWidth;
                    }
                }
            }

            this->width = maxTextWidth + 17.0f;
            if (this->width < this->minWidth) {
                this->width = this->minWidth;
            }

            this->calcPos();
        }

        void doVerticalResizeCheck() noexcept {
            float scaleFactor = 1.2f;
            float labelHeight = 10.75f;
            float padding = 6.5f;
            this->height = (elements.size() * (labelHeight * scaleFactor)) + (2.0f * padding);
            if (this->height < this->minHeight) {
                this->height = this->minHeight;
            }

            this->calcPos();
        }

        int32_t getAlignment() const noexcept {
            return this->alignment;
        }

        float getPosX() const noexcept {
            return this->posX;
        }

        float getPosY() const noexcept {
            return this->posY;
        }

        float getCalcPosX() const noexcept {
            return this->calcPosX;
        }

        float getCalcPosY() const noexcept {
            return this->calcPosY;
        }

        float getWidth() const noexcept {
            return this->width;
        }

        float getHeight() const noexcept {
            return this->height;
        }

        float getMinWidth() const noexcept {
            return this->minWidth;
        }

        float getMinHeight() const noexcept {
            return this->minHeight;
        }

        double getOpacity() const noexcept {
            return this->opacity;
        }

        bool getReverseShadow() const noexcept {
            return this->reverseShadow;
        }

        void setAlignment(int32_t _alignment) noexcept {
            this->alignment = _alignment;
        }

        void setPosition(float _posX, float _posY) noexcept {
            this->posX = _posX;
            this->posY = _posY;
        }

        void setCalcPosition(float _calcPosX, float _calcPosY) noexcept {
            this->calcPosX = _calcPosX;
            this->calcPosY = _calcPosY;
        }

        void setSize(float _width, float _height) noexcept {
            this->width  = _width;
            this->height = _height;
        }

        void setMinSize(float _minWidth, float _minHeight) noexcept {
            this->minWidth  = _minWidth;
            this->minHeight = _minHeight;
        }

        void setOpacity(double _opacity) noexcept {
            this->opacity = _opacity;
        }

        void setReverseShadow(bool _reverseShadow) noexcept {
            this->reverseShadow = _reverseShadow;
        }

    private:
        struct SceneIds {
            struct Corner {
                struct Top {
                    int32_t left;
                    int32_t right;
                } Top;

                struct Bottom {
                    int32_t left;
                    int32_t right;
                } Bottom;
            } Corner;

            struct Filler {
                int32_t top;
                int32_t bottom;

                struct Middle {
                    int32_t left;
                    int32_t middle;
                    int32_t right;
                } Middle;
            } Filler;
        };

        void acquireSceneIds(SceneIds &ret) noexcept {
            ret.Corner.Top.left = 0x119;
            ret.Filler.top = 0x11A;
            ret.Corner.Top.right = 0x11B;
            ret.Filler.Middle.left = 0x11C;
            ret.Filler.Middle.middle = 0x11D;
            ret.Filler.Middle.right = 0x11E;
            ret.Corner.Bottom.left = 0x11F;
            ret.Filler.bottom = 0x120;
            ret.Corner.Bottom.right = 0x121;
        }

        void renderScenePart(float _posX, float _posY, float _width, float _height, int32_t id) {
            Minecraft::GetInstance()->textures->bind(id);
            GlStateManager::pushMatrix();
            BufferBuilder *builder = Tesselator::getInstance()->getBuilder();

            float u0 = reverseShadow ? 0.0f : 1.0f;
            float u1 = reverseShadow ? 1.0f : 0.0f;

            builder->begin(MC_GL_ONE);
            builder->color(0xFFFFFF, 0xFF);
            builder->vertexUV(_posX,         _posY + _height,  0.0f, u1, 1.0f);
            builder->vertexUV(_posX + _width, _posY,           0.0f, u0, 0.0f);
            builder->vertexUV(_posX + _width, _posY + _height, 0.0f, u0, 1.0f);
            builder->end();

            builder->begin(MC_GL_ONE);
            builder->color(0xFFFFFF, 0xFF);
            builder->vertexUV(_posX,         _posY,           0.0f, u1, 0.0f);
            builder->vertexUV(_posX + _width, _posY,          0.0f, u0, 0.0f);
            builder->vertexUV(_posX,         _posY + _height, 0.0f, u1, 1.0f);
            builder->end();

            GlStateManager::popMatrix();
        }

        void calcPos() noexcept {
            if (alignment & ALIGNMENT_TOP) {
                calcPosY = 360.0f - this->height - posY;
            } else if (alignment & ALIGNMENT_BOTTOM) {
                calcPosY = posY;
            } else if (alignment & ALIGNMENT_CENTER) {
                calcPosY = (360.0f - this->height) / 2.0f + posY;
            }

            if (alignment & ALIGNMENT_LEFT) {
                calcPosX = posX;
            } else if (alignment & ALIGNMENT_RIGHT) {
                calcPosX = 640.0f - this->width - posX;
            } else if (alignment & ALIGNMENT_CENTER) {
                calcPosX = (640.0f - this->width) / 2.0f + posX;
            }
        }

        bool selectablesEmpty() {
            if (elements.empty()) {
                return true;
            }

            for (int32_t i = 0; i < elements.size(); i++) {
                if (elements[i].getType() != UISceneFakerElement::ELEMENT_TYPE_LABEL) {
                    return false;
                }
            }

            return true;
        }

        int32_t alignment;
        float posX;
        float posY;
        float calcPosX;
        float calcPosY;
        float width;
        float height;
        float minWidth;
        float minHeight;
        double opacity;
        bool reverseShadow;
        SceneIds sceneIds;
        VPADStatus vpadData;
        VPADReadError vpadError;
        bool buttonFlag;
        int32_t menuIndex;
        std::vector<UISceneFakerElement> elements;
    };
}
