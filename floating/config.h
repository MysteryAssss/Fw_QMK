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

// Matrix Configuration
#define MATRIX_ROWS 2
#define MATRIX_COLS 5

#define MUXES 2
#define MUX_PINS { A1, A2 }

#define MUX_SELECTOR_BITS 4
#define MUX_SELECTOR_PINS { C6, C7, C8, C9 }

#define MUX_CHANNELS (1 << MUX_SELECTOR_BITS)

// ADC Driver
#define ADC_RESOLUTION ADC_CFGR1_RES_12BIT
#define ADC_RESOLUTION_MAX  1 << 12

// Debug Settings
#define DEBUG_ENABLE
#define DEBUG_MATRIX_SCAN_RATE

// 8k config
 #define USB_DRIVER USBD2
 

