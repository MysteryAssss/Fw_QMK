#pragma once

#include_next <board.h>

#define BOARD_OTG2_USES_ULPI

#undef STM32_HSECLK
#define STM32_HSECLK 50000000