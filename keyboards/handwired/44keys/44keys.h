#pragma once
 /*
#ifndef LETS_SPLIT_H
#define LETS_SPLIT_H
#endif
*/
#include "quantum.h"

//#ifdef KEYBOARD_lets_split_rev1
//    #include "rev1.h"
//#elif KEYBOARD_lets_split_rev2
    #include "rev2.h"
//#elif KEYBOARD_lets_split_sockets
//    #include "sockets.h"
//#endif


// Used to create a keymap using only KC_ prefixed keys
#define LAYOUT_kc( \
    L00, L01, L02, L03, L04, L05, R00, R01, R02, R03, R04, R05, \
    L10, L11, L12, L13, L14, L15, R10, R11, R12, R13, R14, R15, \
    L20, L21, L22, L23, L24, L25, R20, R21, R22, R23, R24, R25, \
    L30, L31, L32, L33, L34, L35, R30, R31, R32, R33, R34, R35, \
    L40, L41, L42, L43, L44, L45, R40, R41, R42, R43, R44, R45 \
    ) \
    LAYOUT( \
        KC_##L00, KC_##L01, KC_##L02, KC_##L03, KC_##L04, KC_##L05, KC_##R00, KC_##R01, KC_##R02, KC_##R03, KC_##R04, KC_##R05, \
        KC_##L10, KC_##L11, KC_##L12, KC_##L13, KC_##L14, KC_##L15, KC_##R10, KC_##R11, KC_##R12, KC_##R13, KC_##R14, KC_##R15, \
        KC_##L20, KC_##L21, KC_##L22, KC_##L23, KC_##L24, KC_##L25, KC_##R20, KC_##R21, KC_##R22, KC_##R23, KC_##R24, KC_##R25, \
        KC_##L30, KC_##L31, KC_##L32, KC_##L33, KC_##L34, KC_##L35, KC_##R30, KC_##R31, KC_##R32, KC_##R33, KC_##R34, KC_##R35, \
        KC_##L40, KC_##L41, KC_##L42, KC_##L43, KC_##L44, KC_##L45, KC_##R40, KC_##R41, KC_##R42, KC_##R43, KC_##R44, KC_##R45 \
    )

#define LAYOUT_kc_ortho_4x12 LAYOUT_kc


/* From Georgi.h
#define LAYOUT_georgi(                                            \
    L00,L01,L02,L03,L04,L05,            R00,R01,R02,R03,R04,R05,  \
    L10,L11,L12,L13,L14,L15,            R10,R11,R12,R13,R14,R15,  \
               	L20,L21,L22,            R20,R21,R22)              \
                                                                  \
    {                         \
    { KC_NO,  R00,   R10,   R21},     \
    { KC_NO,  R01,   R11,   R20},     \
    { KC_NO,  R02,   R12,   R22},     \
    { KC_NO,  R03,   R13,   KC_NO},   \
    { KC_NO,  R04,   R14,   KC_NO},   \
    { KC_NO,  R05,   R15,   KC_NO},   \
    { KC_NO,  KC_NO, KC_NO, KC_NO},     \
							  \
    { KC_NO,  L05,   L15,   L22},     \
    { KC_NO,  L04,   L14,   L21},     \
    { KC_NO,  L03,   L13,   L20},     \
    { KC_NO,  L02,   L12,   KC_NO},   \
    { KC_NO,  L01,   L11,   KC_NO},   \
    { KC_NO,  L00,   L10,   KC_NO},   \
    { KC_NO,  KC_NO, KC_NO, KC_NO},     \
                              \
}
*/


#define LAYOUT_georgi(                                          \
    L00, L01, L02, L03, L04, L05, R00, R01, R02, R03, R04, R05, \
    L10, L11, L12, L13, L14, L15, R10, R11, R12, R13, R14, R15, \
    L20, L21, L22, L23, L24, L25, R20, R21, R22, R23, R24, R25, \
    L30, L31, L32, L33, L34, L35, R30, R31, R32, R33, R34, R35, \
    L40, L41, L42, L43, L44, L45, R40, R41, R42, R43, R44, R45 \
    ) \
    KEYMAP( \
        KC_NO,	  KC_NO,    KC_NO,    KC_NO,	KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    \
        L15,      L14,      L13,      L12,      L11,      L10,      R10,      R11,      R12,      R13,      R14,      R15, \
        L25,      L24,      L23,      L22,      L21,      L20,      R20,      R21,      R22,      R23,      R24,      R25, \
        KC_NO,	  KC_NO,    KC_NO,    KC_NO,	KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    \
        L45,      L44,      KC_NO,    KC_NO,    KC_NO,    KC_NO,    R40,      R41,      KC_NO,    KC_NO,    KC_NO,    KC_NO     \
    )
