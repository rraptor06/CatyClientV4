/**
 * Might be some bugs in here, atleast I've experienced some already
 */

 #pragma once

 #include <inttypes.h>
 
 #include <vpad/input.h>
 #include <padscore/kpad.h>
 
 //! Struct to store data in for the input functions.
 typedef struct {
     //! Flag for the buttons to make sure it does not constantly repeat.
     bool buttonFlag;
     //! The amount of frames that are happening while holding the buttons down.
     int32_t pressedForXFrames;
     //! Amount of frames for the speed.
     int32_t framesPressedForSpeed;
     //! VPAD data.
     VPADStatus vpadData;
     //! VPAD error.
     VPADReadError vpadError;
 } InputVPADState;
 
 //! Struct to store data in for the input functions.
 typedef struct {
     //! Flag for the buttons to make sure it does not constantly repeat.
     bool buttonFlag;
     //! KPAD data.
     KPADStatus kpadData;
     //! KPAD error.
     KPADError kpadError;
 } InputKPADState;
 
 typedef void(*InputPressedCallback)(InputVPADState *vpadState, InputKPADState *KPADState, void *data);
 
 /**
  * Checks if the given buttons are pressed and if so, activates the callback.
  * VPAD has to be initialized for this to work.
  *
  * \param buttonCombo
  * The buttons needed to be pressed to activate the callback.
  * 
  * \param useFlag
  * If the InpudVPADState:buttonFlag can be used.
  * 
  * \param state
  * A struct to store information about the state of the buttons.
  * This struct needs to be static/global or something that exists across calls of the function.
  * 
  * \param framesNeededForRepeat
  * The frames needed to repeat the callback.
  * If repeatSpeed is set below 0 or higher than 50, this parameter is ignored.
  * 
  * \param repeatSpeed
  * The speed of repeating the callback, the higher the faster, maximum: 500, minimum: 0.
  * If set to 0, the callback will only be called once.
  * 
  * \param callback
  * The function that activates after pressing the buttons or repeat gets activated.
  * 
  * \param data
  * An additional argument for giving the callback specific data incase its needed.
  */
 void
 InputVPAD_CheckButtonCombo(uint32_t buttonCombo,
                            bool useFlag,
                            InputVPADState *state,
                            int32_t framesNeededForRepeat,
                            int32_t repeatSpeed,
                            InputPressedCallback callback,
                            void *data);
 
 /**
  * Checks if the given buttons are pressed and if so, activates the callback.
  * KPAD has to be initialized for this to work.
  *
  * \param buttonCombo
  * The buttons needed to be pressed to activate the callback.
  * 
  * \param useFlag
  * If the InpudVPADState:buttonFlag can be used.
  * 
  * \param state
  * A struct to store information about the state of the buttons.
  * This struct needs to be static/global or something that exists across calls of the function.
  * 
  * \param callback
  * The function that activates after pressing the buttons or repeat gets activated.
  * 
  * \param data
  * An additional argument for giving the callback specific data incase its needed.
  */
 void
 InputKPAD_CheckButtonCombo(uint32_t buttonCombo,
                            bool useFlag,
                            InputKPADState *state,
                            InputPressedCallback callback,
                            void *data);
 
 /**
  * Uses the rumble motor on the Gamepad.
  * VPAD has to be initialized for this to work.
  * 
  * \param length
  * Represents how long it should rumble.
  */
 void
 Input_RumbleGamePad(uint8_t length);