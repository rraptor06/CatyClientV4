/**
 * Might be some bugs in here, atleast I've experienced some already
 */

 #include "input.h"

 void
 InputVPAD_CheckButtonCombo(uint32_t buttonCombo,
                            bool useFlag,
                            InputVPADState *state,
                            int32_t framesNeededForRepeat,
                            int32_t repeatSpeed,
                            InputPressedCallback callback,
                            void *data)
 {
     bool noRepeat = false;
 
     if (!callback || !state) {
         return;
     }
 
     if (framesNeededForRepeat < 0 || repeatSpeed < 0 || repeatSpeed > 50) {
         noRepeat = true;
     }
 
     VPADRead(VPADChan::VPAD_CHAN_0, &state->vpadData, 1, &state->vpadError);
     if (((state->vpadData.hold & 0x000FFFFF) & buttonCombo) == buttonCombo) {
         if (!state->buttonFlag) {
             callback(state, nullptr, data);
 
             if (useFlag) {
                 state->buttonFlag = true;
             }
         }
 
         state->pressedForXFrames++;
     } else {
         if (state->buttonFlag) {
             state->buttonFlag = false;
         }
         
         state->pressedForXFrames = 0;
     }
 
     if (!noRepeat) {
         if (state->pressedForXFrames >= framesNeededForRepeat) {
             state->framesPressedForSpeed++;
             if (state->framesPressedForSpeed >= (50 - repeatSpeed)) {
                 callback(state, nullptr, data);
                 
                 state->framesPressedForSpeed = 0;
             }
         } else {
             state->framesPressedForSpeed = 0;
         }
     }
 }
 
 void
 InputKPAD_CheckButtonCombo(uint32_t buttonCombo,
                            bool useFlag,
                            InputKPADState *state,
                            InputPressedCallback callback,
                            void *data)
 {
     if (!callback || !state) {
         return;
     }
 
     for (int32_t i = 0; i < 6; i++) {
         KPADReadEx((KPADChan)i, &state->kpadData, 1, &state->kpadError);
         if (state->kpadError != KPAD_ERROR_OK || (state->kpadData.extensionType != WPAD_EXT_CLASSIC && state->kpadData.extensionType != WPAD_EXT_PRO_CONTROLLER)) {
             continue;
         }
 
         if (((state->kpadData.pro.hold) & buttonCombo) == buttonCombo) {
             if (!state->buttonFlag) {
                 callback(nullptr, state, data);
 
                 if (useFlag) {
                     state->buttonFlag = true;
                 }
             }
         } else if (state->buttonFlag) {
             state->buttonFlag = false;
         }
     }
 }
 
 void
 Input_RumbleGamePad(uint8_t length)
 {
     uint8_t pattern[length];
     for (int32_t i = 0; i < length; i++) {
         pattern[i] = 0xFF;
     }
 
     VPADControlMotor(VPADChan::VPAD_CHAN_0, pattern, length);
 }