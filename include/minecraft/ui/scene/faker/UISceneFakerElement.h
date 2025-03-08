#pragma once

#include <mc/utils.h>

namespace mc {
    class UISceneFakerElement {
    public:
        enum ElementType {
            ELEMENT_TYPE_LABEL,
            ELEMENT_TYPE_BUTTON,
            ELEMENT_TYPE_CHECKBOX,
            ELEMENT_TYPE_SLIDER
        };

        UISceneFakerElement(wchar_t *_txt, int32_t _id, ElementType _type) : txt(_txt), id(_id), type(_type), enabled(false) {
        }

        wchar_t *getTxt() const noexcept {
            return this->txt;
        }

        int32_t getId() const noexcept {
            return this->id;
        }

        ElementType getType() const noexcept {
            return this->type;
        }

        bool isEnabled() const noexcept {
            return this->enabled;
        }

        void setEnabled(bool _enabled) noexcept {
            this->enabled = _enabled;
        }
    
    private:
        wchar_t *txt;
        int32_t id;
        ElementType type;

        bool enabled;
    };
}