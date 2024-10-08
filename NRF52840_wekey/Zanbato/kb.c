#include "quantum.h"

#ifdef RGB_MATRIX_ENABLE
led_config_t g_led_config = { {
  //Key Matrix to LED Index
  {0,  1,  2,  3,  4,  5,  6,  7,  8},
  {9, 10, 11, 12, 13, 15, 15, 16, 17},
  {18, 19, 20, 21, 22, 23, 24, 25, 26},
  {27, 28, 29, 30, 31, 32, 33, 34, 35},
  {36, 37, 38, 39, 40, 41, 42, 43, 44},
  {45, 46, 47, NO_LED, NO_LED, 48, NO_LED, NO_LED, NO_LED},
  {49, 50, 51, 52, 53, NO_LED, 54, 55, 56},
  {NO_LED, NO_LED, NO_LED, NO_LED, 57, 58, 59, 60, 61},
  {62, 63, 64, 65, 66, 67, 68, 69, 70},
  {71, 72, 73, 74, 75, 76, 77, 78, 79},
  {80, 81, 82, NO_LED, 83, 84, 85, 86, NO_LED},
  {87, 88, 89, NO_LED, 90, 91, 92, 93, 94},
  {95, 96, 97, 98, 99, 100, 101, 102, NO_LED}
}, {
  //LED Index to Physical Positon
    {0, 0},  {0, 12},  {0, 24},  {0, 36},  {0, 48},  {0, 60},  {0, 72},  {0, 84},  {0, 96}, 
    {13, 0}, {13, 12}, {13, 24}, {13, 36}, {13, 48}, {13, 60}, {13, 72}, {13, 84}, {13, 96}, 
    {26, 0}, {26, 12}, {26, 24}, {26, 36}, {26, 48}, {26, 60}, {26, 72}, {26, 84}, {26, 96}, 
    {39, 0}, {39, 12}, {39, 24}, {39, 36}, {39, 48}, {39, 60}, {39, 72}, {39, 84}, {39, 96}, 
    {52, 0}, {52, 12}, {52, 24}, {52, 36}, {52, 48}, {52, 60}, {52, 72}, {52, 84}, {52, 96}, 
    {64, 0}, {64, 12}, {64, 24},                     {64, 60},

    {0, 108}, {0, 120}, {0, 132}, {0, 144}, {0, 156},          {0, 180}, {0, 200}, {0, 224},  
                                                {8, 156}, {8, 168}, {8, 180}, {8, 200}, {8, 224}, 
    {13, 108}, {13, 120}, {13, 132}, {13, 144}, {13, 156}, {13, 168}, {13, 180}, {13, 200}, {13, 224},
    {26, 108}, {26, 120}, {26, 132}, {26, 144}, {26, 156}, {26, 168}, {26, 180}, {26, 200}, {26, 224},
    {39, 108}, {39, 120}, {39, 132},            {39, 156}, {39, 168}, {39, 180}, {39, 200}, 
    {52, 108}, {52, 120}, {52, 132},            {52, 156}, {52, 168}, {52, 180}, {52, 200}, {52, 224}, 
    {64, 108}, {64, 120}, {64, 132}, {64, 144}, {64, 156}, {64, 168}, {64, 180}, {64, 200}
}, {
  1, 1, 1, 1, 1, 1, 1, 1, 1, 
  1, 1, 1, 1, 1, 1, 1, 1, 1, 
  1, 1, 1, 1, 1, 1, 1, 1, 1, 
  1, 1, 1, 1, 1, 1, 1, 1, 1, 
  1, 1, 1, 1, 1, 1, 1, 1, 1, 
  1, 1, 1, 1, 
  1, 1, 1, 1, 1, 1, 1, 1, 
  1, 1, 1, 1, 1, 
  1, 1, 1, 1, 1, 1, 1, 1, 1, 
  1, 1, 1, 1, 1, 1, 1, 1, 1, 
  1, 1, 1, 1, 1, 1, 1, 
  1, 1, 1, 1, 1, 1, 1, 1, 
  1, 1, 1, 1, 1, 1, 1, 1
} };

bool rgb_matrix_indicators_kb(void) {
    if (!rgb_matrix_indicators_user()) {
        return false;
    }

    if (host_keyboard_led_state().caps_lock) {
        rgb_matrix_set_color(27, 255, 255, 255);
    }
    return true;
}
#endif