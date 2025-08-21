#pragma once

#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET_TIMEOUT 500 // Timeout window in ms in which the double tap can occur.

#define TAPPING_TERM 150 //170 //170 // 200 //120 //00 //90 //200 // how long before a tap becomes a hold

//#define PERMISSIVE_HOLD                                                                                                  
#define HOLD_ON_OTHER_KEY_PRESS


#define MOUSEKEY_DELAY             150 //200
#define MOUSEKEY_INTERVAL          60 //50
#define MOUSEKEY_MAX_SPEED         5  //10
#define MOUSEKEY_TIME_TO_MAX       7 //20
#define MOUSEKEY_WHEEL_MAX_SPEED   5	//8
#define MOUSEKEY_WHEEL_TIME_TO_MAX 40
 

#define USB_POLLING_INTERVAL_MS 1


//The number of layers for VIA/REMAP
#define DYNAMIC_KEYMAP_LAYER_COUNT 10

//This disables the auto-repeat for the double-action keys (e.g. S+LAlt)
#define QUICK_TAP_TERM 0


#define POINTING_DEVICE_ROTATION_90
#define CIRQUE_PINNACLE_TAP_ENABLE

// Limits the frequency that the sensor is polled for motion.
#define POINTING_DEVICE_TASK_THROTTLE_MS 10
#define CIRQUE_PINNACLE_SECONDARY_TAP_ENABLE

// Circular scroll
// Isn't it making the cursor jittering?
#define POINTING_DEVICE_GESTURES_SCROLL_ENABLE

//#define CIRQUE_PINNACLE_POSITION_MODE CIRQUE_PINNACLE_RELATIVE_MODE
#define CIRQUE_PINNACLE_POSITION_MODE CIRQUE_PINNACLE_ABSOLUTE_MODE

#define I2C_DRIVER I2CD1
#define I2C1_SDA_PIN GP18
#define I2C1_SCL_PIN GP19

//from ...\keyboards\bastardkb\dilemma\3x5_2\splinky 
#undef RP_I2C_USE_I2C1
#define RP_I2C_USE_I2C1 TRUE
