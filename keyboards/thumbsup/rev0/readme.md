This is the original version of ThumbsUp that tried to use Planck/rev4 pinout.
Unfortunately I confused left and right and ordered column pins in the opposite order:

#define MATRIX_ROW_PINS { D0, D5, B5, B6 }
#define MATRIX_COL_PINS { F1, F0, B0, C7, F4, F5, F6, F7, D4, D6, B4, D7 }

#define DIODE_DIRECTION COL2ROW

Note this version did not have the touchpad support.