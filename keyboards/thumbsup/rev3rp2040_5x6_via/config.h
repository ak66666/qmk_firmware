/*
 * Copyright 2022 Kevin Gee <info@controller.works>
 * 
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

#include "config_common.h"

/* Debounce reduces chatter (unintended double-presses) - set 0 if debouncing is not needed */
/* #define DEBOUNCE 5 */

//#define WS2812_PIO_USE_PIO1

#define SPLIT_TRANSPORT_MIRROR
#define SPLIT_LAYER_STATE_ENABLE
//#define SPLIT_LED_STATE_ENABLE
#define SPLIT_MODS_ENABLE

//#undef I2C_DRIVER
//#define I2C_DRIVER I2CD1
//#undef I2C1_SCL_PIN
//#define I2C1_SCL_PIN GP25
//#undef I2C1_SDA_PIN
//#define I2C1_SDA_PIN GP24

/* #define EE_HANDS  */
/* #define MASTER_LEFT */
/* #define MASTER_RIGHT */
#define SPLIT_HAND_PIN GP18

/* Top left key on left half */
//#define BOOTMAGIC_LITE_ROW    0
//#define BOOTMAGIC_LITE_COLUMN 0
/* Top right key on right half */
//#define BOOTMAGIC_LITE_ROW_RIGHT    0
//#define BOOTMAGIC_LITE_COLUMN_RIGHT 0
/*
 * Feature disable options
 *  These options are also useful to firmware size reduction.
 */

/* disable debug print */
//#define NO_DEBUG

/* disable print */
//#define NO_PRINT

/* disable action features */
//#define NO_ACTION_LAYER
//#define NO_ACTION_TAPPING
//#define NO_ACTION_ONESHOT



#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET_TIMEOUT 500 // Timeout window in ms in which the double tap can occur.


#define TAPPING_TERM 200 //170 // 200 //120 //00 //90 //200 // how long before a tap becomes a hold



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






/* key matrix size */
#define MATRIX_ROWS 10
#define MATRIX_COLS 6

#define DIRECT_PINS { \
            {GP19, GP20, GP22, GP23, GP16,  GP17 }, \
            {GP15, GP14, GP13, GP12, GP8,  GP9 },   \
            {GP27, GP26, GP25, GP24, GP7,  GP10},   \
            {GP6,  GP5,  GP4,  GP3,  GP2,  GP11},   \
            {GP0,  GP1,  GP29, GP28, NO_PIN, NO_PIN} \
}

#define DIRECT_PINS_RIGHT { \
	            {GP9, GP23,  GP10, GP11, GP16, GP17}, \
	            {GP3,  GP6,  GP2,  GP1,  GP0,  GP22}, \
	            {GP4,  GP8,  GP29, GP28, GP27, GP26}, \
	            {GP5,  GP7,  GP15, GP14, GP13, GP12}, \
	            {GP24, GP25, GP19, GP20, NO_PIN, NO_PIN} \
}
