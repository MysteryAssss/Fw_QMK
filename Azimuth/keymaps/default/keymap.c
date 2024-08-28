// Copyright 2024 (@LQT)

#include QMK_KEYBOARD_H

enum { _FUNC };

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_FUNC] = LAYOUT(
        KC_INS,   KC_HOME, KC_PGUP, 
        KC_DEL,   KC_END,  KC_PGDN, 
        KC_ENT,   KC_UP,   KC_ENT, 
        KC_LEFT,  KC_DOWN, KC_RGHT
    )
};