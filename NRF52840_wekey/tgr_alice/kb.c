#include "quantum.h"

#ifdef RGB_MATRIX_ENABLE
led_config_t g_led_config = { {
  //Key Matrix to LED Index
  {0,         1,         2,           3,          4,          5,          6,          7,          8,          9,          10,          11,          12,          13},
  {14,        15,        16,          17,         18,         19,         20,         21,         22,         23,         24,          25,          26,          27},
  {28,        29,        30,          31,         32,         33,         34,         35,         36,         37,         38,          39,          40,      NO_LED},
  {41,        42,        43,          44,         45,         46,         47,         48,         49,         50,         51,          52,          53,          54},
  {55,    NO_LED,        56,          NO_LED,     57,         58,     NO_LED,         59,     NO_LED,         60,     NO_LED,      NO_LED,      NO_LED,          61},
  {62,        63,        64,          NO_LED,     NO_LED,     NO_LED,     NO_LED,     NO_LED,     NO_LED,     NO_LED,     NO_LED,      NO_LED,      NO_LED,      NO_LED}
}, {
  //LED Index to Physical Positon
  {  0,  0},  { 32, 0 },  { 48, 0 },  { 64, 0},   { 80, 0},   { 96, 0},   { 112, 0},  { 128, 0},  { 144, 0},  { 160, 0},  { 176, 0},    {192,  0},   {208,  0},  {216, 0},
  {  0, 16},  { 32, 16},  { 48, 16},  { 64, 16},  { 80, 16},  { 96, 16},  { 112, 16}, { 128, 16}, { 144, 16}, { 160, 16}, { 176, 16},   {192, 16},   {208, 16},  {216, 16},
  {  0, 32},  { 32, 32},  { 48, 32},  { 64, 32},  { 80, 32},  { 96, 32},  { 112, 32}, { 128, 32}, { 144, 32}, { 160, 32}, { 176, 32},   {192, 32},   {216, 32},
  {  0, 48},  { 32, 48},  { 48, 48},  { 64, 48},  { 80, 48},  { 96, 48},  { 112, 48}, { 128, 48}, { 144, 48}, { 160, 48}, { 176, 48},   {192, 48},   {208, 48},  {216, 48},
  {  0, 64},              { 32, 64},              { 64, 64},  { 80, 64},              { 112, 64},             { 144, 64},                                        {216, 64},
  {  0,  0},  { 0, 16 },  { 0, 32 },
}, {
  1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 
  1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
  1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
  1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
  1, 1, 1, 1, 1, 1, 1,
  1, 1, 1,
} };

bool rgb_matrix_indicators_kb(void) {
    if (!rgb_matrix_indicators_user()) {
        return false;
    }

    if (host_keyboard_led_state().caps_lock) {
        rgb_matrix_set_color(28, 255, 255, 255);
    }
    return true;
}
#endif