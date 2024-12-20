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
#include "quantum.h"

uint8_t current_channel;

void multiplexer_init(void);

bool select_mux(uint8_t channel);

typedef struct {
    uint8_t row;
    uint8_t col;
} mux_t;

extern const pin_t mux_pins[MUXES];
extern const pin_t mux_selector_pins[MUX_SELECTOR_BITS];
extern const mux_t mux_index[MUXES][MUX_CHANNELS];
extern const mux_t NC;
