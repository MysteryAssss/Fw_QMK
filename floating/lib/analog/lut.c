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

#include <math.h>
#include "scan_functions.h"
#include "util.h"

/* Equation parameters for the sensor-magnet linearity mapping */
const double a = 16654600.6755;
const double b = -0.00955994866577;
const double c = -1278.75103145;
const double d = 16652478.4163;

uint16_t distance_to_adc(uint8_t distance) {
    distance = MIN(MAX(distance, 0), 255);
    return a * (1 - exp(-b * (distance + c))) - d;
}

uint8_t adc_to_distance(uint16_t adc) {
    return MIN(MAX(((log(1 - ((adc + d) / a)) / -b) - c), 0), 255);
}

uint8_t lut[4096] = {0};

void generate_lut(void) {
    for (uint16_t i = 0; i < a - d; i++) {
        lut[i] = adc_to_distance(i);
    }
}
