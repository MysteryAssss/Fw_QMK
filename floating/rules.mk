SRC += matrix.c
SRC += lib/analog/lut.c
SRC += lib/analog/scan_functions.c
SRC += lib/matrix/multiplexer.c

CUSTOM_MATRIX = lite

KEYBOARD_SHARED_EP = yes

ANALOG_DRIVER_REQUIRED = yes

DEBOUNCE_TYPE = sym_eager_pk
