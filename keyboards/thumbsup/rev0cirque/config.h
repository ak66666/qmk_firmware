#pragma once



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


#define POINTING_DEVICE_ROTATION_90
#define CIRQUE_PINNACLE_TAP_ENABLE
// Limits the frequency that the sensor is polled for motion.
#define POINTING_DEVICE_TASK_THROTTLE_MS 10
//#define CIRQUE_PINNACLE_SECONDARY_TAP_ENABLE

// Circular scroll
// Isn't it making the cursor jittering?
#define POINTING_DEVICE_GESTURES_SCROLL_ENABLE

//#define CIRQUE_PINNACLE_POSITION_MODE CIRQUE_PINNACLE_RELATIVE_MODE
#define CIRQUE_PINNACLE_POSITION_MODE CIRQUE_PINNACLE_ABSOLUTE_MODE

//#define CIRQUE_PINNACLE_SECONDARY_TAP_ENABLE
//#define POINTING_DEVICE_GESTURES_SCROLL_ENABLE
//#define POINTING_DEVICE_GESTURES_CURSOR_GLIDE_ENABLE 

