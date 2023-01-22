#pragma once

#define DIRECT_PINS       {{GP15, GP14, GP13, GP12, GP7, GP9}, {GP27, GP26, GP25, GP24, GP8, GP10}, {GP18, GP18, GP18, GP18, GP6, GP11}, {GP0, GP1, GP29, GP28, GP28, GP28}}
#define DIRECT_PINS_RIGHT {{GP4, GP8, GP2, GP1, GP0, GP22},    {GP3, GP7, GP29, GP28, GP27, GP26},  {GP5, GP6, GP18, GP18, GP18, GP18},  {GP24, GP25, GP19, GP20, GP20, GP20}}    

//#define USE_SERIAL
#define MASTER_RIGHT
#define SOFT_SERIAL_PIN GP21

#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET_TIMEOUT 200 // Timeout window in ms in which the double tap can occur.


#define TAPPING_TERM 170 //170 // 200 //120 //00 //90 //200 // how long before a tap becomes a hold



//#define RETRO_TAPPING
//#define INGNORE_MOD_TAP_INTERRUPT
//#undef PERMISSIVE_HOLD                                                                                                  
//#define  PREVENT_STUCK_MODIFIERS


#define MOUSEKEY_DELAY             150 //200
#define MOUSEKEY_INTERVAL          60 //50
#define MOUSEKEY_MAX_SPEED         5  //10
#define MOUSEKEY_TIME_TO_MAX       7 //20
#define MOUSEKEY_WHEEL_MAX_SPEED   5	//8
#define MOUSEKEY_WHEEL_TIME_TO_MAX 40
 

#define USB_POLLING_INTERVAL_MS 1


//#define POINTING_DEVICE_ROTATION_90
//#define CIRQUE_PINNACLE_TAP_ENABLE
//#define CIRQUE_PINNACLE_SECONDARY_TAP_ENABLE
//#define POINTING_DEVICE_GESTURES_SCROLL_ENABLE

//#define CIRQUE_PINNACLE_POSITION_MODE CIRQUE_PINNACLE_ABSOLUTE_MODE

