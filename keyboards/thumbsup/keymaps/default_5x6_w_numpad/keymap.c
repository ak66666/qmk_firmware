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

#include "keymap_steno.h"


// Defines names for use in layer keycodes and the keymap
enum layer_names {
    _QWERTY,
    _NUMPAD,
    _CURSORRGHT,
    _CURSORLEFT,
    _NUMBERS,
    _EXTRARIGHT,
    _PLOVER,
    _STENO_TXBOLT,
    // These are the same plover/txbolt layers 
    // with the letters moved to the top two rows 
    // and the number bar pushed down to the third row.
    _PLOVER2,
    _STENO_TXBOLT2
};

// Defines the keycodes used by our macros in process_record_user
enum custom_keycodes {
    QWERTY = SAFE_RANGE,
    NUMPAD,
    // These three wiil work as RAISE, LOWER  and ADJUST in the original PLANCK
    CURSORRGHT = LT(_CURSORRGHT,KC_SPC),
    CURSORLEFT = LT(_CURSORLEFT,KC_SPC),
    NUMBERS,
    PLOVER,
    STENO_TXBOLT,
    PLOVER2,
    STENO_TXBOLT2,
    EXT_PLV,
    EXT_PLV2
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {


/* Qwerty                                 
 * ,-----------------------------------------++-----------------------------------------.
 * |  `   |   1  |   2  |   3  |   4  |   5  ||   6  |   7  |   8  |   9  |   0  | Del  |
 * |------+------+------+------+------+------++------+------+------+------+------+------|
 * | Esc  |   Q  |   W  |   E  |   R  |   T  ||   Y  |   U  |   I  |   O  |   P  |BackSp|
 * |------+------+------+------+------+------++------+------+------+------+------+------|
 * | Tab  |   A  |   S  |   D  |   F  |   G  ||   H  |   J  |   K  |   L  |   ;  |Enter |
Hold:
   Extra-Rt 
 * |------+------+------+------+------+------||------+------+------+------+------+------|
 * | Ctrl |   Z  |   X  |   C  |   V  |   B  ||   N  |   M  |   ,  |   .  |   /  |RCtrl |
 * +------+------+------+------+------+------++------+------+------+------+------+------+
		 |  GUI | Alt  |      |      ||      |      | RAlt | Menu |
	         +------+------+      |      ||      |      +------+------+               
Hold:  		               | LSft |CursLt||CursRt| RSft |
Single hit:		       |      |Space ||Space |      |
		               +------+------||------+------+

 */
[_QWERTY] = LAYOUT_ortho_4x12( \
  KC_GRV,                  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,       KC_6,       KC_7,    KC_8,    KC_9,   KC_0,    KC_DEL, \
  KC_ESC,                  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,       KC_Y,       KC_U,    KC_I,    KC_O,   KC_P,    KC_BSPC,  \
  LT(_EXTRARIGHT,KC_TAB),  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,       KC_H,       KC_J,    KC_K,    KC_L,   KC_SCLN, KC_ENT, \
  KC_LCTL,                 KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,       KC_N,       KC_M,    KC_COMM, KC_DOT, KC_SLSH, KC_RCTL, \
                  	            KC_LGUI, KC_LALT, KC_LSFT, CURSORLEFT, CURSORRGHT, KC_RSFT, KC_RALT, KC_APP                    \
),



/*

Layers below are used on top of QWERTY layer defined above.
(Except the PLOVER/STENO layers.)
                                           +-------+
The keys which are shown empty, like this: |       |, represent a transparent key,
                                           +-------+
meaning the key from the underlaying layer (i.e. QWERTY) will be used.
In the keymaps those keys are defined as "_______".

                                           +-------+         +-------+
The keys which are shown solid, like this: | XXXXX | or this |  ...  |, represent an opaque/blocking key?
                                           +-------+         +-------+
Such key is not doing anything in that layer nor allowing the key from the underlaying layer
to be invoked.
In the keymaps those keys are defined as "XXXXXXX".

Most of the modifiers are the same in all layers.
So in most layers they are defined as transparent keys,
letting the keys from QWERTY layer to do the work.

With that idea all the layers below leave the unmodified keys as transparent keys.
In the same time - the layers block the keys that have no sense to be used 
in that given layer. For instance in the cursor control layers 
some of the keys are not used in the layer, but they are blocked to avoid
alpha-keys from QWERTY layer to appear.

For the same reason the keymaps below are shown simplified,
without separate thumbcluster.

*/



/* Cursor Control on the right (Right Space)
 * ,-----------------------------------------------------------------------------------.
 * | Esc  |Break |WheelD|MousUp|WheelU| Del  |  Ins | Home |  Up  | End  |   `  | Del  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |SelAll|MousLt|MousDn|MousRt| ...  | PgUp | Left | Down |Right | ...  |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      | Undo | Cut  | Copy | Paste| ...  | PgDn |MsBtLe|MsBtMi|MsBtRt| ...  |      |
 * `------+------+------+------+------+------+------+------+------+------+------+------.
 *               |      |      |      |      |   X  |      |      |      |
 *               `-------------------------------------------------------'
 */
[_CURSORRGHT] = LAYOUT_ortho_4x12( \
  _______, _______,          _______,      _______,      _______,      _______,             _______,  _______, _______, _______, _______, _______, \
  _______, KC_BRK,           KC_WH_D,      KC_MS_U,      KC_WH_U,      KC_DEL,              KC_PGUP,  KC_HOME, KC_UP,   KC_END,  KC_GRV,  KC_DEL, \
  KC_ENT,  LCTL(KC_A),       KC_MS_L,      KC_MS_D,      KC_MS_R,      XXXXXXX,             KC_PGDN,  KC_LEFT, KC_DOWN, KC_RGHT, XXXXXXX, _______, \
  _______, LCTL(KC_Z),       LSFT(KC_DEL), LCTL(KC_INS), LSFT(KC_INS), XXXXXXX,             KC_INS,   KC_BTN1, KC_BTN3, KC_BTN2, XXXXXXX, _______, \
  	                     _______,      _______,      _______,      _______,             _______,  _______, _______, _______                    \
),



 /* Cursor Control on the left (Left Space)
 * ,-----------------------------------------------------------------------------------.
 * |      |Break | Home |  Up  | End  |  Ins | Del  |WheelU|MousUp|WheelD|   `  | Del  |
 * |------+------+------+------+------+------+-------------+------+------+------+------|
 * | Enter|SelAll|Right | Down | Left | PgUp | xxx  |MousLt|MousDn|MousRt| xxx  |Enter |
 * |------+------+------+------+------+------+------|------+------+------+------+------|
 * |      | xxx  |MsBtRt|MsBtMi|MsBtLe| PgDn | xxx  | Cut  | Copy | Paste| xxx  |      |
 * `------+------+------+------+------+------+------+------+------+------+------+------.
 *               |      |      |      |   X  |       |      |      |      |
 *               `-------------------------------------------------------'
 */
[_CURSORLEFT] = LAYOUT_ortho_4x12( \
  _______, _______,         _______, _______, _______, _______,       _______, _______,	     _______,      _______,      _______, _______, \
  _______, KC_BRK,          KC_HOME, KC_UP,   KC_END,  KC_PGUP,       KC_DEL,  KC_WH_U,      KC_MS_U,      KC_WH_D,      KC_GRV,  KC_DEL, \
  KC_ENT,  LCTL(KC_A),      KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN,       XXXXXXX, KC_MS_L,      KC_MS_D,      KC_MS_R,      XXXXXXX, _______, \
  _______, XXXXXXX,         KC_BTN2, KC_BTN3, KC_BTN1, KC_INS,        XXXXXXX, LCTL(KC_DEL), LCTL(KC_INS), LSFT(KC_INS), XXXXXXX, _______, \
    			    _______, _______, _______, _______,       _______, _______,      _______,      _______ 			   \

),


 /* Numbers on the home row, FNs on the top row, symbols in the second row
 * (Lower or Raise)
 * ,-----------------------------------------------------------------------------------.
 * |      |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  |BackSp|
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |   F1 |   F2 |   F3 |   F4 |   F5 |   F6 |   F7 |   F8 |   F9 |   F10| Enter|
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |  F11 |  F12 | LAlt |LShift| LAlt | RAlt |RShift|   ,  |   .  |   /  |      |
 * `------+------+------+------+------+------+------+------+------+------+------+------.
 *               |      |      |      |      |      |      |      |      |
 *               `-------------------------------------------------------'
 */
[_NUMBERS] = LAYOUT_ortho_4x12( \
  _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  _______, \
  _______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC, \
  LT(_EXTRARIGHT,KC_TAB), KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9, KC_F10,  _______, \
  _______, KC_F11,  KC_F12,  KC_LALT, KC_LSFT, KC_LALT, KC_RALT, KC_RSFT, KC_COMM, KC_DOT,  KC_SLSH, _______, \
                    _______, _______, _______, _______, _______, _______, _______, _______                    \
),

/* ExtraRightSide (the keys from the right side which did not fit into the matrix)
 * ,-----------------------------------------------------------------------------------.
 * | Esc  |BREAK |PLOVR2|PLOVER|TxBOLT|TxBlt2|   `  |   =  |   (  |   )  |   -  |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |******|      |      |      |      |      |      |      |      |      |  '   |      |
   This is the
   key turning
   this layer on
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |NUMPAD|      |      |      |      |   [  |   ]  |  \   |      |
 * `------+------+------+------+------+------+------+------+------+------+------+------.
 *               |      |      |      |      |      |      |      |      |
 *               `-------------------------------------------------------'
 */
[_EXTRARIGHT] = LAYOUT_ortho_4x12( \
  _______, _______, _______, _______, _______, 	_______,       _______, _______, _______,      _______,      _______, _______, \
  _______, KC_BRK,  PLOVER2,  PLOVER,  STENO_TXBOLT, STENO_TXBOLT2, KC_GRV,  KC_EQL,  KC_LPRN, KC_RPRN, KC_MINS, _______, \
  _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,      XXXXXXX,       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_QUOT, _______, \
  _______, XXXXXXX, XXXXXXX, TG(_NUMPAD), XXXXXXX,      XXXXXXX,       XXXXXXX, XXXXXXX, KC_LBRC, KC_RBRC, KC_BSLS, _______, \
                    _______, _______, _______, 	    _______,       _______, _______, _______, _______  \
 
),

/* The right side turned into a numpad, set as default layer.
 *
 * ,-----------------------------------------||-----------------------------------------.
 * |  Esc |      |      |      |      |      ||   /  |   7  |   8  |   9  |   -  |BackSp|
 * |------+------+------+------+------+------||------|------+------+------+------+------|
 * |      |      |      |      |      |      ||   *  |   4  |   5  |   6  |   +  |Enter |
Hold:
   Extra-Rt 
 * |------+------+------+------+------+------||-------------+------+------+------+------|
 * | Ctrl |      |      |      |      |      ||   ,  |   1  |   2  |   3  |   .  | Ctrl |
 * `------+------+------+------+------+------||------+------+------+------+------+------.
		 |  GUI | Alt  |      |      ||      |      |   0  |   .  |
	         +------+------+      |      ||      |      +------+------+               
Hold:  		               | LSft |CursLt||CursRt| RSft |
Single hit:		       |      |Space ||Space |      |
		               +------+------||------+------+
 */
[_NUMPAD] =  LAYOUT_ortho_4x12( \
  _______, _______, _______, _______, _______, 	_______,       _______, _______, _______,      _______,      _______, _______, \
  KC_ESC,                 XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    KC_KP_SLASH, KC_7,    KC_8, KC_9, KC_KP_MINUS, KC_BSPC, \
  LT(_EXTRARIGHT,KC_TAB), XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    KC_PAST,     KC_4,    KC_5, KC_6, KC_KP_PLUS,  KC_PENT, \
  KC_LCTL,                XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    KC_COMM,     KC_1,    KC_2, KC_3, KC_DOT,      KC_RCTL, \
                                   KC_LGUI, KC_LALT, KC_LSFT, CURSORLEFT, CURSORRGHT,  KC_RSFT, KC_0, KC_DOT                      \
),

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

[_PLOVER] = LAYOUT_ortho_4x12( \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
  EXT_PLV, KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1   , \
  XXXXXXX, KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, \
  XXXXXXX, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, \
                    XXXXXXX, XXXXXXX, KC_C,    KC_V,    KC_N,    KC_M,    XXXXXXX, XXXXXXX                    \
),
// The same as the one above, but the numbar moved down,
// and the CTRLs acting as O/E, ESC - as numbar, just want to try them in those positions, 
// like in the compact steno boards I saw on the internet.
[_PLOVER2] = LAYOUT_ortho_4x12( \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
  EXT_PLV, KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, \
  XXXXXXX, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, \
  KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1   , \
                    XXXXXXX, XXXXXXX, KC_C,    KC_V,    KC_N,    KC_M,    XXXXXXX, XXXXXXX                    \
),

/* Plover Layer via TX Bolt interface.
   The layout is the same as for Plover above, just different key codes
*/

[_STENO_TXBOLT] = LAYOUT_ortho_4x12( \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
   EXT_PLV2,STN_NUM, STN_NUM, STN_NUM, STN_NUM, STN_NUM,    STN_NUM, STN_NUM, STN_NUM, STN_NUM, STN_NUM, STN_NUM, \
   STN_SL,  STN_SL,  STN_TL,  STN_PL,  STN_HL,  STN_ST1,    STN_ST3, STN_FR,  STN_PR,  STN_LR,  STN_TR,  STN_DR,  \
   STN_SL,  STN_SL,  STN_KL,  STN_WL,  STN_RL,  STN_ST2,    STN_ST4, STN_RR,  STN_BR,  STN_GR,  STN_SR,  STN_ZR,  \
                     XXXXXXX, XXXXXXX, STN_A,   STN_O,      STN_E,   STN_U,   XXXXXXX, XXXXXXX                    \
 ), 

/*  TX Bolt with the alpha rows moved up, numbar below them. 
*/
[_STENO_TXBOLT2] = LAYOUT_ortho_4x12( \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
   EXT_PLV2,STN_SL,  STN_TL,  STN_PL,  STN_HL,  STN_ST1,    STN_ST3, STN_FR,  STN_PR,  STN_LR,  STN_TR,  STN_DR,  \
   STN_SL,  STN_SL,  STN_KL,  STN_WL,  STN_RL,  STN_ST2,    STN_ST4, STN_RR,  STN_BR,  STN_GR,  STN_SR,  STN_ZR,  \
   STN_NUM, STN_NUM, STN_NUM, STN_NUM, STN_NUM, STN_NUM,    STN_NUM, STN_NUM, STN_NUM, STN_NUM, STN_NUM, STN_NUM, \
                     XXXXXXX, XXXXXXX, STN_A,   STN_O,      STN_E,   STN_U,   XXXXXXX, XXXXXXX                    \
 )


};

void matrix_init_user() {
//   persistent_default_layer_set(1UL<<_QWERTY);
  steno_set_mode(STENO_MODE_BOLT); // or STENO_MODE_BOLT
}

void keyboard_post_init_user(void) {
  // Customise these values to desired behaviour
  debug_enable=true;
  debug_matrix=true;
  debug_keyboard=true;
  //debug_mouse=true;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {

  switch (keycode) {


     case NUMPAD:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          PLAY_NOTE_ARRAY(tone_qwerty, false, 0);
        #endif
	layer_invert(_QWERTY);
	layer_invert(_NUMPAD);
      }
      return false;
      break;

    case CURSORRGHT:
      if (record->event.pressed) {
        layer_on(_CURSORRGHT);
        update_tri_layer(_CURSORRGHT, _CURSORLEFT, _NUMBERS);
      } else {
        layer_off(_CURSORRGHT);
        update_tri_layer(_CURSORRGHT, _CURSORLEFT, _NUMBERS);
       }
      return true;// false;
      break;
    case CURSORLEFT:
      if (record->event.pressed) {
        layer_on(_CURSORLEFT);
        update_tri_layer(_CURSORRGHT, _CURSORLEFT, _NUMBERS);
      } else {
        layer_off(_CURSORLEFT);
        update_tri_layer(_CURSORRGHT, _CURSORLEFT, _NUMBERS);
      }
      return true;// 	false;
      break;





     case QWERTY:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          PLAY_NOTE_ARRAY(tone_qwerty, false, 0);
        #endif
        layer_off(_CURSORRGHT);
        layer_off(_CURSORLEFT);
        layer_off(_NUMBERS);
        layer_off(_EXTRARIGHT);
        layer_off(_NUMPAD);
        layer_off(_PLOVER);
        layer_off(_PLOVER2);
        layer_on(_QWERTY);

        //persistent_default_layer_set(1UL<<_QWERTY);
        set_single_persistent_default_layer(_QWERTY);
      }
      return false;
      break;

    case PLOVER:
      if (record->event.pressed) {
        layer_off(_QWERTY);
        layer_off(_CURSORRGHT);
        layer_off(_CURSORLEFT);
        layer_off(_NUMBERS);
        layer_off(_EXTRARIGHT);
        layer_off(_NUMPAD);
        layer_on(_PLOVER);
 
       if (!eeconfig_is_enabled()) {
            eeconfig_init();
        }
        keymap_config.raw = eeconfig_read_keymap();
        keymap_config.nkro = 1;
        eeconfig_update_keymap(keymap_config.raw);
      }
      return false;
      break;

    case PLOVER2:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          stop_all_notes();
          PLAY_NOTE_ARRAY(tone_plover, false, 0);
        #endif
        layer_off(_CURSORRGHT);
        layer_off(_CURSORLEFT);
        layer_off(_NUMBERS);
        layer_off(_EXTRARIGHT);
        layer_off(_NUMPAD);
        layer_off(_STENO_TXBOLT);
        layer_on(_PLOVER2);

        if (!eeconfig_is_enabled()) {
            eeconfig_init();
        }
        keymap_config.raw = eeconfig_read_keymap();
        keymap_config.nkro = 1;
        eeconfig_update_keymap(keymap_config.raw);

      }
      return false;
      break;



     case EXT_PLV:
      if (record->event.pressed) {
        layer_off(_PLOVER);
        layer_on(_QWERTY);
      }
      return false;
      break;

    case STENO_TXBOLT:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          stop_all_notes();
          PLAY_NOTE_ARRAY(tone_plover, false, 0);
        #endif
        layer_off(_CURSORRGHT);
        layer_off(_CURSORLEFT);
        layer_off(_NUMBERS);
        layer_off(_EXTRARIGHT);
        layer_off(_NUMPAD);
        layer_off(_PLOVER);
        layer_off(_STENO_TXBOLT2);
        layer_on(_STENO_TXBOLT);
       if (!eeconfig_is_enabled()) {
            eeconfig_init();
        }
        keymap_config.raw = eeconfig_read_keymap();
        keymap_config.nkro = 1;
        eeconfig_update_keymap(keymap_config.raw);
      }
      return false;
      break;

    case STENO_TXBOLT2:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          stop_all_notes();
          PLAY_NOTE_ARRAY(tone_plover, false, 0);
        #endif
        layer_off(_CURSORRGHT);
        layer_off(_CURSORLEFT);
        layer_off(_NUMBERS);
        layer_off(_EXTRARIGHT);
        layer_off(_NUMPAD);
        layer_off(_PLOVER);
        layer_off(_STENO_TXBOLT);
        layer_on(_STENO_TXBOLT2);
       if (!eeconfig_is_enabled()) {
            eeconfig_init();
        }
        keymap_config.raw = eeconfig_read_keymap();
        keymap_config.nkro = 1;
        eeconfig_update_keymap(keymap_config.raw);
      }
      return false;
      break;

     case EXT_PLV2:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          PLAY_NOTE_ARRAY(tone_plover_gb, false, 0);
        #endif
        layer_off(_STENO_TXBOLT);
        layer_off(_STENO_TXBOLT2);
        layer_on(_QWERTY);
      }
      return false;
      break;

 }
  return true;
}
