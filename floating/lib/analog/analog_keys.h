/* Copyright 2023..2024 RephlexZero (@RephlexZero)
 * Copyright 2024 HorrorTroll <https://github.com/HorrorTroll>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#include <stdint.h>
#include <stdbool.h>

enum analog_key_modes {rapid_trigger = 0, continuous_rapid_trigger, static_actuation};

/* global struct to save keypress logic params */
typedef struct {
    uint8_t mode;
    uint8_t actuation_point;
    uint8_t press_sensitivity;
    uint8_t release_sensitivity;
    uint8_t press_hysteresis;
    uint8_t release_hysteresis;
    uint8_t reset_keyboard;
    uint8_t flash_firmware;
} analog_config; /* 8 bytes */
_Static_assert(sizeof(analog_config) == EECONFIG_KB_DATA_SIZE, "Size mismatch");
extern analog_config g_config;

typedef struct {
    /* For individual analog key data */
    uint8_t value;
    uint8_t extremum;
    int16_t offset;
    bool continuous_rapid_trigger;
} analog_key_t;
extern analog_key_t keys[MATRIX_ROWS][MATRIX_COLS];
