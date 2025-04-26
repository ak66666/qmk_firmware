/*
Copyright 2012 Jun Wako <wakojun@gmail.com>
Copyright 2013 Oleg Kostyuk <cub.uanic@gmail.com>
Copyright 2015 ZSA Technology Labs Inc (@zsa)
Copyright 2020 Christopher Courtney <drashna@live.com> (@drashna)
Copyright 2021 Gary Kong <kongkm88@gmail.com> (@garykong)

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

#include "a_ball.h"

// Which hand the bottom PCB is oriented for is defined by D0 pin, pulled up when not connected to ground.

 
void matrix_init_kb(void) {
    // D0 is used to define the hand used - high (default) for left hand, low (connected to ground) means right hand. 
    gpio_set_pin_input_high(D0);

    matrix_init_user();
}

report_mouse_t pointing_device_task_user(report_mouse_t mouse_report) {
    // Reverse mouse movement when switched to the right side: 
    uint8_t trackball_hand = gpio_read_pin(D0);
    if (trackball_hand == TRACKBALL_HAND_LEFT) {
        mouse_report.x = mouse_report.x;
        mouse_report.y = -mouse_report.y;
    } else {
        mouse_report.x = -mouse_report.x;
        mouse_report.y = mouse_report.y;

    }
    return mouse_report;
}

uint8_t pointing_device_handle_buttons(uint8_t buttons, bool pressed, pointing_device_buttons_t button) {
    // swap left & right buttons if the lower PCB rotated to be used with right hand
    uint8_t trackball_hand = gpio_read_pin(D0);
    if (trackball_hand == TRACKBALL_HAND_LEFT) {
    switch (button) {
       case POINTING_DEVICE_BUTTON1:
          button = POINTING_DEVICE_BUTTON2;
          break;

       case POINTING_DEVICE_BUTTON2:
          button = POINTING_DEVICE_BUTTON1;
          break;

       default:
          break;
       }
    }

    if (pressed) {
        buttons |= 1 << (button);
    } else {
        buttons &= ~(1 << (button));
    }
    return buttons;
}
