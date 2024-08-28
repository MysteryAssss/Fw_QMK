// Copyright 2024 (@LQT)

#pragma once

#include "config_common.h"

#define USB_DRIVER USBD2

#define SPI_SCK_PIN C10
#define SPI_SCK_PAL_MODE 6
#define SPI_MOSI_PIN C12
#define SPI_MOSI_PAL_MODE 6
#define SPI_MISO_PIN C11
#define SPI_MISO_PAL_MODE 6
#define SPI_DRIVER SPID3

#define EXTERNAL_EEPROM_SPI_SLAVE_SELECT_PIN B3
#define EXTERNAL_EEPROM_SPI_CLOCK_DIVISOR 16
#define EXTERNAL_EEPROM_BYTE_COUNT 2048
#define EXTERNAL_EEPROM_PAGE_SIZE 16

#define MATRIX_SHIFT_REGISTER_COUNT 8
#define SPI_MATRIX_CHIP_SELECT_PIN B6
#define SPI_MATRIX_DIVISOR 15
#define SHIFTREG_MATRIX_LATCH B7

#define USB_MUX_SEL_PIN B14

//#define DEBUG_MATRIX_SCAN_RATE enable this when you use console 