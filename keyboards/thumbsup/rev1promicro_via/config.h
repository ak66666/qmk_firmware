/*
Copyright 2019 Bubnick

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

#include "config_common.h"


/* USB Device descriptor parameter */
/* Deprecated, is specified in the JSON file*/
#define VENDOR_ID       0xFEED
#define PRODUCT_ID      0x0000 
#define DEVICE_VER      0x0001
#define MANUFACTURER    Alexander (Sasha) Karmanov
#define PRODUCT         Thumbs Up!
/* */

/* key matrix size */
#define MATRIX_ROWS 4
#define MATRIX_COLS 12

/* key matrix pins */
#define MATRIX_ROW_PINS { D3, D2, D4, C6 }
#define MATRIX_COL_PINS { B2, B6, B5, B4, E6, D7, B3, F4, F5, F6, F7, B1 }
 
/* COL2ROW or ROW2COL */
#define DIODE_DIRECTION COL2ROW



/* Set 0 if debouncing isn't needed */
#define DEBOUNCE 5
