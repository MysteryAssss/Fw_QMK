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
#include <stdio.h>
#include <stdbool.h>
#include "floating.h"
#include "quantum.h"
#include "analog.h"
#include "eeprom.h"
#include "print.h"
#include "lib/analog/scan_functions.h"
#include "lib/matrix/multiplexer.h"

analog_config g_config = {
    .mode = rapid_trigger,
    .actuation_point = 159,
    .press_sensitivity = 32,
    .release_sensitivity = 32,
    .press_hysteresis = 0,
    .release_hysteresis = 5,
    .reset_keyboard = 0,
    .flash_firmware = 0,
};

#ifdef DEFERRED_EXEC_ENABLE
#    ifdef DEBUG_ENABLE
deferred_token debug_token;
bool debug_print(void) {
    static char rowBuffer[MATRIX_COLS * 6 + 1]; // +1 for '\0'
    static char temp[8];
    static uint8_t row = 0;
    rowBuffer[0] = '\0'; // Initialize the row buffer

    for (uint8_t col = 0; col < MATRIX_COLS; col++) {
        analog_key_t *key;
        key = &keys[row][col];

        if(!key->value) {
            snprintf(temp, sizeof(temp), "nul");
        } else {
            snprintf(temp, sizeof(temp), "%5u  ", (key->value)); // Include a space for separation
        }

        strcat(rowBuffer, temp);
    }

    strcat(rowBuffer, "\n");
    uprintf("%s", rowBuffer);
    row++;

    if (row >= MATRIX_ROWS) {
        row = 0;
        uprintf("\n");
        return false;
    }
    return true;
}

uint32_t debug_print_callback(uint32_t trigger_time, void *cb_arg) {
    debug_print();
    return 150;
}
#    endif

deferred_token idle_recalibrate_token;
bool process_record_kb(uint16_t keycode, keyrecord_t *record) {
    extend_deferred_exec(idle_recalibrate_token, 300000);
    return true;
}

uint32_t idle_recalibrate_callback(uint32_t trigger_time, void *cb_arg) {
    get_sensor_offsets();
    return 10000;
}
#endif

void values_load(void) {
    eeconfig_read_kb_datablock(&g_config);
}

void values_save(void) {
    eeconfig_update_kb_datablock(&g_config);
}

void eeconfig_init_kb() {
    values_save();
}

void housekeeping_task_kb(void) {
    if (g_config.reset_keyboard) {
        eeconfig_disable();
        soft_reset_keyboard();
    }
    if (g_config.flash_firmware) {
        eeconfig_disable();
        bootloader_jump();
    }
}

void keyboard_post_init_kb(void) {
#ifdef DEFERRED_EXEC_ENABLE
#    ifdef DEBUG_ENABLE
    debug_token = defer_exec(1000, debug_print_callback, NULL);
#    endif
    idle_recalibrate_token = defer_exec(300000, idle_recalibrate_callback, NULL);
#endif
    values_load();
}

#ifdef VIA_ENABLE
void via_custom_value_command_kb(uint8_t *data, uint8_t length) {
    /* data = [ command_id, channel_id, value_id, value_data ] */
    uint8_t *command_id        = &(data[0]);
    uint8_t *channel_id        = &(data[1]);
    uint8_t *value_id_and_data = &(data[2]);

    if (*channel_id == id_custom_channel) {
        switch (*command_id) {
            case id_custom_set_value: {
                via_config_set_value(value_id_and_data);
                break;
            }
            case id_custom_get_value: {
                via_config_get_value(value_id_and_data);
                break;
            }
            case id_custom_save: {
                values_save();
                break;
            }
            default: {
                /* Unhandled message */
                *command_id = id_unhandled;
                break;
            }
        }
        return;
    }

    /* Return the unhandled state */
    *command_id = id_unhandled;

    /* DO NOT call raw_hid_send(data,length) here, let caller do this */
}

enum via_analog_setting {
    id_mode = 1,
    id_actuation_point,
    id_press_sensitivity,
    id_release_sensitivity,
    id_press_hysteresis,
    id_release_hysteresis,
    id_reset_keyboard,
    id_flash_firmware,
};

void via_config_set_value(uint8_t *data) {
    /* data = [ value_id, value_data ] */
    uint8_t *value_id   = &(data[0]);
    uint8_t *value_data = &(data[1]);

    switch (*value_id) {
        case id_mode:
            g_config.mode = *value_data;
            break;
        case id_actuation_point:
            g_config.actuation_point = *value_data * 255 / 100;
            break;
        case id_press_sensitivity:
            g_config.press_sensitivity = *value_data * 255 / 100;
            break;
        case id_release_sensitivity:
            g_config.release_sensitivity = *value_data * 255 / 100;
            break;
        case id_press_hysteresis:
            g_config.press_hysteresis = *value_data * 255 / 100;
            break;
        case id_release_hysteresis:
            g_config.release_hysteresis = *value_data * 255 / 100;
            break;
        case id_reset_keyboard:
            g_config.reset_keyboard = *value_data;
            break;
        case id_flash_firmware:
            g_config.flash_firmware = *value_data;
            break;
    }
}

void via_config_get_value(uint8_t *data) {
    uint8_t *value_id   = &(data[0]);
    uint8_t *value_data = &(data[1]);

    switch (*value_id) {
        case id_mode:
            *value_data = g_config.mode;
            break;
        case id_actuation_point:
            *value_data = g_config.actuation_point * 100 / 255;
            break;
        case id_press_sensitivity:
            *value_data = g_config.press_sensitivity * 100 / 255;
            break;
        case id_release_sensitivity:
            *value_data = g_config.release_sensitivity * 100 / 255;
            break;
        case id_press_hysteresis:
            *value_data = g_config.press_hysteresis * 100 / 255;
            break;
        case id_release_hysteresis:
            *value_data = g_config.release_hysteresis * 100 / 255;
            break;
        case id_reset_keyboard:
            *value_data = g_config.reset_keyboard;
            break;
        case id_flash_firmware:
            *value_data = g_config.flash_firmware;
            break;
    }
}
#endif

#ifdef RGB_MATRIX_ENABLE
led_config_t g_led_config = { {
  //Key Matrix to LED Index
    { 0, 1, 2, 3, NO_LED },
    { 4, 5, 6, 7, 8 }
}, {
  //LED Index to Physical Positon
    { 0,  0 },  { 112, 0  }, { 224, 0  }, { 0,  32 },
    { 112, 32 }, { 224, 32 }, { 0,  64 }, { 112, 64 }, { 224, 64 },
    
}, {
    1, 1, 1, 1,
    1, 1, 1, 1, 1
} };
#endif

// 8khz
#define ULPI_PIN_MODE (PAL_MODE_ALTERNATE(10) | PAL_STM32_OTYPE_PUSHPULL | PAL_STM32_OSPEED_HIGHEST | PAL_STM32_PUPDR_FLOATING)

#define ULPI_STP_PIN C0
#define ULPI_DIR_PIN C2
#define ULPI_NXT_PIN C3
#define ULPI_CLK_PIN A5
#define ULPI_D0_PIN A3
#define ULPI_D1_PIN B0
#define ULPI_D2_PIN B1
#define ULPI_D3_PIN B10
#define ULPI_D4_PIN B11
#define ULPI_D5_PIN B12
#define ULPI_D6_PIN B13
#define ULPI_D7_PIN B5

// #define ULPI_RST_PIN A6

void board_init(void) {
    palSetLineMode(ULPI_STP_PIN, ULPI_PIN_MODE);
    palSetLineMode(ULPI_DIR_PIN, ULPI_PIN_MODE);
    palSetLineMode(ULPI_NXT_PIN, ULPI_PIN_MODE);
    palSetLineMode(ULPI_CLK_PIN, ULPI_PIN_MODE);
    palSetLineMode(ULPI_D0_PIN, ULPI_PIN_MODE);
    palSetLineMode(ULPI_D1_PIN, ULPI_PIN_MODE);
    palSetLineMode(ULPI_D2_PIN, ULPI_PIN_MODE);
    palSetLineMode(ULPI_D3_PIN, ULPI_PIN_MODE);
    palSetLineMode(ULPI_D4_PIN, ULPI_PIN_MODE);
    palSetLineMode(ULPI_D5_PIN, ULPI_PIN_MODE);
    palSetLineMode(ULPI_D6_PIN, ULPI_PIN_MODE);
    palSetLineMode(ULPI_D7_PIN, ULPI_PIN_MODE);

    // gpio_set_pin_output(ULPI_RST_PIN);
    // gpio_write_pin_low(ULPI_RST_PIN);
}