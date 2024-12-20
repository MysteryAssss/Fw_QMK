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

#pragma once

#include <stdint.h>
#include "quantum.h"
#include "analog_keys.h"

void update_extremum(analog_key_t *key);

void register_key(matrix_row_t *current_row, uint8_t current_col);

void deregister_key(matrix_row_t *current_row, uint8_t current_col);

void get_sensor_offsets(void);

void matrix_read_cols_rapid_trigger(matrix_row_t *current_row, uint8_t current_col, analog_key_t *key);

void matrix_read_cols_continuous_rapid_trigger(matrix_row_t *current_row, uint8_t current_col, analog_key_t *key);

void matrix_read_cols_static_actuation(matrix_row_t *current_row, uint8_t current_col, analog_key_t *key);
