/* Copyright 2022  
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
#include QMK_KEYBOARD_H


// Defines names for use in layer keycodes and the keymap
enum layer_names {
    _PLOVER,
    _STENO_TXBOLT
};

// Defines the keycodes used by our macros in process_record_user
enum custom_keycodes {
    PLOVER,
    STENO_TXBOLT
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {


/* Plover layer (http://opensteno.org)
This layer remains on until EXIT key is pressed or the keyboard is reconnected.
No other layers/modifiers to be used with it - it is self-sufficient.
All other STENO/PLOVER layers defind below implement the same map with minor variances:
	- TX Bolt protocol over COM port is used instead of acting as a regular keyboard.
        - NumBar keys are moved below the alpha-keys.

 * ,-----------------------------------------------------------------------------------.
 * | EXIT |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | xxxx |   S  |   T  |   P  |   H  |   *  |   *  |   F  |   P  |   L  |   T  |   D  |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | xxxx |   S  |   K  |   W  |   R  |   *  |   *  |   R  |   B  |   G  |   S  |   Z  |
 * +------+------+------+------+------+------+------+------+------+------+------+------+
		 | xxxx | xxxx |      |      ||      |      | xxxx| xxx  |
 	         +------+------+      |      ||      |      +-----+------+               
  		               |   A  |   O  ||   E  |   U  |
		               +------+------||------+------+
 */

[_PLOVER] = LAYOUT_ortho_3x12( \
  KC_1,	   KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                      KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, \
  KC_1,    KC_A,    KC_S,    KC_D,    KC_F,    KC_C,    KC_V,    KC_N,    KC_M,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT
),

/* Plover Layer via TX Bolt interface.
   The layout is the same as for Plover above, just different key codes
*/

[_STENO_TXBOLT] = LAYOUT_ortho_3x12( \
   STN_NUM,  STN_SL,  STN_TL,  STN_PL,  STN_HL,  STN_ST1,                  STN_ST3, STN_FR,  STN_PR,  STN_LR,  STN_TR,  STN_DR,  \
   STN_NUM,  STN_SL,  STN_KL,  STN_WL,  STN_RL,  STN_A,  STN_O,    STN_E,  STN_U,  STN_RR,  STN_BR,  STN_GR,  STN_SR,  STN_ZR  \
 )
 
};

void matrix_init_user() {
//   persistent_default_layer_set(1UL<<_QWERTY);
  steno_set_mode(STENO_MODE_BOLT); // or STENO_MODE_BOLT
}

void keyboard_post_init_user(void) {
  // Customise these values to desired behaviour
//  debug_enable=false;
//  debug_matrix=false;
//  debug_keyboard=false;
  //debug_mouse=true;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  return true;
}
