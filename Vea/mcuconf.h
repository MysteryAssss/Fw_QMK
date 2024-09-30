#pragma once

#include_next <mcuconf.h>

#undef STM32_PWM_USE_TIM3
#define STM32_PWM_USE_TIM3 TRUE

#undef STM32_SERIAL_USE_USART1
#define STM32_SERIAL_USE_USART1 TRUE

#undef STM32_I2C_USE_I2C1
#define STM32_I2C_USE_I2C1 FALSE

#undef STM32_I2C_USE_I2C2
#define STM32_I2C_USE_I2C2 TRUE

// // Define DMA streams for I2C2
// #define STM32_I2C_I2C2_RX_DMA_STREAM STM32_DMA_STREAM_ID(1, 5) // DMA1 Channel 5
// #define STM32_I2C_I2C2_TX_DMA_STREAM STM32_DMA_STREAM_ID(1, 4) // DMA1 Channel 4

// #define STM32_DMA_REQUIRED TRUE