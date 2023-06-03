// Copyright 2023 ak66666 (@ak66666)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

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
