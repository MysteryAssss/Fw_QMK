// Copyright 2024 (@LQT)

#pragma once

#include_next <mcuconf.h>

#undef STM32_SPI_USE_SPI3
#define STM32_SPI_USE_SPI3                  TRUE

#undef STM32_USB_USE_OTG1
#define STM32_USB_USE_OTG1                  FALSE
#undef STM32_USB_USE_OTG2
#define STM32_USB_USE_OTG2                  TRUE



