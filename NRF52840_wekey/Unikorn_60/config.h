// Copyright 2023 Uy Bui (@Uy Bui)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

/*
 * Feature disable options
 *  These options are also useful to firmware size reduction.
 */

/* disable action features */
//#define NO_ACTION_LAYER
//#define NO_ACTION_TAPPING
//#define NO_ACTION_ONESHOT

/* WEKEY Config PIN */

//#define CONFIG_PIN_SCL NO_PIN
//#define CONFIG_PIN_SDA NO_PIN
//#define CONFIG_PIN_SDB NO_PIN
//#define CONFIG_PIN_SDB_ON 1

#define LED_STATE_ON { 1, 1, 1, 1 }
#define LED_MONITOR_PINS { NO_PIN, NO_PIN, NO_PIN, NO_PIN } // 4 pin for: USB, BLE1, BLE2, BLE3
#define LED_MONITOR_TYPE SINGLE

#define VDIV_PIN F30         // VBAT -> analog
#define BAT_VDIV_R1 (832.0F)    // 802k
#define BAT_VDIV_R2 (2000.0F)   // 2M

//#define LED_CTRL_PIN NO_PIN       // CTRL EXT VCC
//#define LED_CTRL_PIN_ON 0         // 0 = Low; 1 = High

