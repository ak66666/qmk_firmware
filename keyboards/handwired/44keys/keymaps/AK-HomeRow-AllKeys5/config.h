/*
This is the c configuration file for the keymap

Copyright 2012 Jun Wako <wakojun@gmail.com>
Copyright 2015 Jack Humbert

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once
//#include "../../config.h"

/* Use I2C or Serial, not both */

#define USE_SERIAL
// #define USE_I2C

/* Select hand configuration */

//#define MASTER_LEFT
//#define MASTER_RIGHT
#define EE_HANDS



#define MOUSEKEY_DELAY             150 //200
#define MOUSEKEY_INTERVAL          60 //50
#define MOUSEKEY_MAX_SPEED         4 //10
#define MOUSEKEY_TIME_TO_MAX       7 //20
#define MOUSEKEY_WHEEL_MAX_SPEED   5	//8
#define MOUSEKEY_WHEEL_TIME_TO_MAX 40

// AK20190524 - this timing is required - the default one is too long for me
// AK20200728 - 120 is too short for Matiaeses, returning back to 200
// AK20201021 - 200 is too long for the RPi/Linux computer, bringing it down to 150.
#define TAPPING_TERM 170 // 200 //120 //00 //90 //200 // how long before a tap becomes a hold

// does not seem doing any good... #define PREVENT_STUCK_MODIFIERS //when switching layers, this will release all mods

// This is to make Shift/Space keys to work as wanted:
// This is to make Shift/Space keys to work as wanted:
// AK20190523 - since shift/space is no longer combined this is not required
//#undef  PERMISSIVE_HOLD

#define INGNORE_MOD_TAP_INTERRUPT
#undef PERMISSIVE_HOLD
#define  PREVENT_STUCK_MODIFIERS
