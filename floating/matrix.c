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
#include "quantum.h"
#include "analog.h"
#include "lib/analog/lut.h"
#include "lib/analog/scan_functions.h"
#include "lib/matrix/multiplexer.h"

analog_key_t keys[MATRIX_ROWS][MATRIX_COLS] = {0};
adc_mux targets[MUXES];
uint32_t matrix_size;
matrix_row_t previous_matrix[MATRIX_ROWS];
static void update_keypress(matrix_row_t *current_row, uint8_t current_col, analog_key_t *key);

void matrix_init_custom(void) {
    generate_lut();
    multiplexer_init();

    for (uint8_t mux = 0; mux < MUXES; mux++) {
        targets[mux] = pinToMux(mux_pins[mux]);
    }

    get_sensor_offsets();
    matrix_size = sizeof(previous_matrix);
    wait_ms(100); // Let ADC reach steady state
    get_sensor_offsets();
}

bool matrix_scan_custom(matrix_row_t current_matrix[]) {
    memcpy(previous_matrix, current_matrix, matrix_size);

    for (uint8_t channel = 0; channel < MUX_CHANNELS; channel++) {
        uint8_t channel_greycoded = (channel >> 1) ^ channel;
        select_mux(channel_greycoded);

        for (uint8_t mux = 0; mux < MUXES; mux++) {
            analog_key_t *key;
            uint8_t current_row;
            uint8_t current_col;
            current_row = mux_index[mux][channel_greycoded].row;
            current_col = mux_index[mux][channel_greycoded].col;

            if (current_row == 255 || current_col == 255) continue; // NO_MUX mux pin

            key = &keys[current_row][current_col];
            key->value = lut[adc_read(targets[mux]) + key->offset];
            key->value = MIN((key->value << 8) / lut[1100 + key->offset], 255);
            update_keypress(&current_matrix[current_row], current_col, key);
        }
    }

    return memcmp(previous_matrix, current_matrix, matrix_size) != 0;
}

static void update_keypress(matrix_row_t *current_row, uint8_t current_col, analog_key_t *key) {
    switch (g_config.mode) {
        case rapid_trigger:
            matrix_read_cols_rapid_trigger(current_row, current_col, key);
            break;
        case continuous_rapid_trigger:
            matrix_read_cols_continuous_rapid_trigger(current_row, current_col, key);
            break;
        case static_actuation:
            matrix_read_cols_static_actuation(current_row, current_col, key);
            break;
    }
}
