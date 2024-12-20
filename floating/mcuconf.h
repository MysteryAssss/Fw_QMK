/* Copyright 2024 HorrorTroll <https://github.com/HorrorTroll>
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

#include_next <mcuconf.h>

#undef STM32_ADC_USE_ADC1 
#define STM32_ADC_USE_ADC1 TRUE

#undef STM32_USB_USE_OTG1
#define STM32_USB_USE_OTG1 FALSE

#undef STM32_USB_USE_OTG2
#define STM32_USB_USE_OTG2 TRUE

#undef STM32_USE_USB_OTG2_HS
#define STM32_USE_USB_OTG2_HS TRUE

#undef STM32_PLLM_VALUE
#define STM32_PLLM_VALUE 50

#define STM32_HSE_BYPASS
#undef STM32_HSECLK
#define STM32_HSECLK 50000000U

