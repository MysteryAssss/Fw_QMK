#pragma once

#define HAL_USE_SERIAL TRUE
#define HAL_USE_I2C TRUE
#define SERIAL_USB_BUFFERS_SIZE 256
#define PAL_USE_CALLBACKS TRUE

#include_next <halconf.h>