#pragma once

#include "config_common.h"

/* Debounce reduces chatter (unintended double-presses) - set 0 if debouncing is not needed */
/* #define DEBOUNCE 5 */

#define SPLIT_WPM_ENABLE
#define SPLIT_USB_DETECT

//#define SOFT_SERIAL_PIN A9         // USART TX pin
//#define USART1_REMAP             // Remap USART TX and RX pins on STM32F103 MCUs, see table below.
#define SELECT_SOFT_SERIAL_SPEED 1 // or 0, 2, 3, 4, 5
                                   //  0: about 460800 baud
                                   //  1: about 230400 baud (default)
                                   //  2: about 115200 baud
                                   //  3: about 57600 baud
                                   //  4: about 38400 baud
                                   //  5: about 19200 baud
#define SERIAL_USART_DRIVER SD1    // USART driver of TX pin. default: SD1
#define SERIAL_USART_TX_PAL_MODE 7 // Pin "alternate function", see the respective datasheet for the appropriate values for your MCU. default: 7
#define SERIAL_USART_TIMEOUT 100    // USART driver timeout. default 20
#define OLED_DISPLAY_128X32
// RGB configuration
#define SPLIT_TRANSPORT_MIRROR
#define SPLIT_LAYER_STATE_ENABLE
#define SPLIT_LED_STATE_ENABLE
#define SPLIT_MODS_ENABLE

/* Top left key on left half */
#define BOOTMAGIC_LITE_ROW    0
#define BOOTMAGIC_LITE_COLUMN 0
/* Top right key on right half */
#define BOOTMAGIC_LITE_ROW_RIGHT    0
#define BOOTMAGIC_LITE_COLUMN_RIGHT 0

#define I2C_DRIVER I2CD2
#define I2C2_SCL_PIN B13
#define I2C2_SDA_PIN B15
#define I2C2_SCL_PAL_MODE 5
#define I2C2_SDA_PAL_MODE 5
#define I2C2_CLOCK_SPEED  400000
#define I2C2_DUTY_CYCLE FAST_DUTY_CYCLE_16_9

// Define DMA streams for I2C2
#define STM32_I2C_I2C2_RX_DMA_STREAM STM32_DMA_STREAM_ID(1, 5) // DMA1 Channel 5
#define STM32_I2C_I2C2_TX_DMA_STREAM STM32_DMA_STREAM_ID(1, 4) // DMA1 Channel 4

#define STM32_DMA_REQUIRED TRUE