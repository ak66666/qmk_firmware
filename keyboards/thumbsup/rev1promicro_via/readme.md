This is a default layout for ThumbsUp! v2 with ProMicro soldered/socketed on the PCB.
ProMicro pins laid out like this:

#define MATRIX_ROW_PINS {D3,D2,D4,C6}
#define MATRIX_COL_PINS {B2, B6, B5, B4,E6, D7, B3, F4, F5,F6, F7, B1}
#define DIODE_DIRECTION COL2ROW

Note in this initial revision the thumb keys are swapped in error.
I temporarily swapped them in info.json file.
The next revision will put in the right spots.   




This folder contains a version with VIA support enabled.
The STENO support is removed as there are not enough endpoints for it.
Compile it with this keymap:

	qmk compile -km default_via

