This is the original version of ThumbsUp with Cirque Touchpad support.

I tried to use Planck/rev4 pinout.
Unfortunately I confused left and right and ordered column pins in the opposite order.
Also I had to relocate the top line pin from D0 to D3 to free up SDA and SCL pins for the Cirque Touchpad.

#define MATRIX_ROW_PINS { D3, D5, B5, B6 }
#define MATRIX_COL_PINS { F1, F0, B0, C7, F4, F5, F6, F7, D4, D6, B4, D7 }

#define DIODE_DIRECTION COL2ROW

