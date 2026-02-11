// Enter this into the terminal to build the firmware "qmk compile -kb rpk_padnum_v1 -km default"
#include "quantum.h"
 
#ifdef RGB_MATRIX_ENABLE

led_config_t g_led_config = { 
    { // Key Matrix to LED Index 
    //            ┌────────┬────────┬────────┬────────┐ ┌────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬──────────────────┐ ┌────────┐ ┌────────┬────────┐
    //            │        │        │        │        │ │        │        │        │        │        │        │        │        │        │        │        │        │        │                  │ │        │ │        │        │
                  {   0,       1,       2,       3,         4,       5,       6,       7,       8,       9,       10,      11,      12,      13,      14,      15,      16,           17,             18,        19,      20   },
    //            │        │        │        │        │ │        │        │        │        │        │        │        │        │        │        │        │        │        │                  │ │        │ │        │        │
    //            └────────┴────────┴────────┴────────┘ └────────┴────────┴────────┴────────┴────────┴────────┴────────┴────────┴────────┴────────┴────────┴────────┴────────┴──────────────────┘ └────────┘ └────────┴────────┘
    // ┌────────┐ ┌────────┬────────┬────────┬────────┐ ┌─────────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬─────────────┐            ┌────────┬────────┐
    // │        │ │        │        │        │        │ │             │        │        │        │        │        │        │        │        │        │        │        │        │             │            │        │        │
       {   42,        41,      40,      39,      38,          37,         36,      35,      34,      33,      32,      31,      30,      29,      28,      27,      26,      25,        24,           23,        22,      21   },
    // │        │ │        │        │        │        │ │             │        │        │        │        │        │        │        │        │        │        │        │        │             │            │        │        │
    // ├────────┤ ├────────┼────────┼────────┼────────┤ ├─────────────┴─┬──────┴─┬──────┴─┬──────┴─┬──────┴─┬──────┴─┬──────┴─┬──────┴─┬──────┴─┬──────┴─┬──────┴─┬──────┴─┬──────┴─────────────┤            ├────────┼────────┤
    // │        │ │        │        │        │        │ │               │        │        │        │        │        │        │        │        │        │        │        │                    │            │        │        │
       {   43,        44,      45,      46,      47,           48,          49,      50,      51,      52,      53,      54,      55,      56,      57,      58,      59,            60,                         61,      62   },
    // │        │ │        │        │        │        │ │               │        │        │        │        │        │        │        │        │        │        │        │                    │            │        │        │
    // ├────────┤ ├────────┼────────┼────────┼────────┤ ├───────────────┴─┬──────┴─┬──────┴─┬──────┴─┬──────┴─┬──────┴─┬──────┴─┬──────┴─┬──────┴─┬──────┴─┬──────┴─┬──────┴────────────────────┤ ┌────────┐ ├────────┼────────┤
    // │        │ │        │        │        │        │ │                 │        │        │        │        │        │        │        │        │        │        │                           │ │        │ │        │        │
       {   82,        81,      80,      79,      78,             77,          76,      75,      74,      73,      72,      71,      70,      69,      68,      67,                66,                 65,        64,      63   },
    // │        │ │        │        │        │        │ │                 │        │        │        │        │        │        │        │        │        │        │                           │ │        │ │        │        │
    // ├────────┤ ├────────┼────────┼────────┼────────┤ ├──────────┬──────┴───┬────┴─────┬──┴────────┴────────┴────────┴────────┴────────┴────────┴───┬────┴─────┬──┴───────┬──────────┬─┬──────┴─┼────────┼─┴──────┬─┼────────┤
    // │        │ │        │        │        │        │ │          │          │          │                                                            │          │          │          │ │        │        │        │ │        │
       {   83,        84,      85,      86,      87,         88,        89,        90,                                 91,                                  92,       93,        94,         95,      96,      97,        98   },
    // │        │ │        │        │        │        │ │          │          │          │                                                            │          │          │          │ │        │        │        │ │        │
    // └────────┘ └────────┴────────┴────────┴────────┘ └──────────┴──────────┴──────────┴────────────────────────────────────────────────────────────┴──────────┴──────────┴──────────┘ └────────┴────────┴────────┘ └────────┘
    }, 
    { // LED Index to Physical Position
        { 12, 0}, { 22, 0}, { 32, 0}, { 41, 0}, { 54, 0}, { 63, 0}, { 73, 0}, { 83, 0}, { 93, 0}, {102, 0}, {112, 0}, {122, 0}, {131, 0}, {141, 0}, {151, 0}, {161, 0}, {170, 0}, {185, 0}, {202, 0}, {214, 0}, {224, 0}, 
        {224,19}, {214,19}, {202,19}, {187,19}, {175,19}, {166,19}, {156,19}, {146,19}, {136,19}, {127,19}, {117,19}, {107,19}, { 97,19}, { 88,19}, { 78,19}, { 68,19}, { 56,19}, { 41,19}, { 32,19}, { 22,19}, { 12,19}, {  0,19},  
        {  0,34}, { 12,34}, { 22,34}, { 32,34}, { 41,34}, { 57,34}, { 71,34}, { 80,34}, { 90,34}, {100,34}, {110,34}, {119,34}, {129,34}, {139,34}, {149,34}, {158,34}, {168,34}, {184,34}, {214,34}, {224,34}, 
        {224,49}, {214,49}, {202,49}, {181,49}, {163,49}, {153,49}, {144,49}, {134,49}, {124,49}, {114,49}, {105,49}, { 95,49}, { 85,49}, { 75,49}, { 60,49}, { 41,49}, { 32,49}, { 22,49}, { 12,49}, {  0,49}, 
        {  0,64}, { 12,64}, { 22,64}, { 32,64}, { 41,64}, { 55,64}, { 67,64}, { 79,64}, {117,64}, {155,64}, {167,64}, {179,64}, {192,64}, {202,64}, {212,64}, {224,64},
    },
    { // LED Index to Flag
  4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 2, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 
  4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4
    } 
};

#endif // RGB_MATRIX_ENABLE

enum rgb_matrix_effects {
    RGB_MATRIX_NONE = 0,
    RGB_MATRIX_SOLID_COLOR = 1,     // Static single hue, no speed support
    RGB_MATRIX_ALPHAS_MODS,         // Static dual hue, speed is hue for secondary hue
    RGB_MATRIX_GRADIENT_UP_DOWN,    // Static gradient top to bottom, speed controls how much gradient changes
    RGB_MATRIX_GRADIENT_LEFT_RIGHT,    // Static gradient left to right, speed controls how much gradient changes
    RGB_MATRIX_BREATHING,           // Single hue brightness cycling animation
    RGB_MATRIX_BAND_SAT,        // Single hue band fading saturation scrolling left to right
    RGB_MATRIX_BAND_VAL,        // Single hue band fading brightness scrolling left to right
    RGB_MATRIX_BAND_PINWHEEL_SAT,   // Single hue 3 blade spinning pinwheel fades saturation
    RGB_MATRIX_BAND_PINWHEEL_VAL,   // Single hue 3 blade spinning pinwheel fades brightness
    RGB_MATRIX_BAND_SPIRAL_SAT,     // Single hue spinning spiral fades saturation
    RGB_MATRIX_BAND_SPIRAL_VAL,     // Single hue spinning spiral fades brightness
    RGB_MATRIX_CYCLE_ALL,           // Full keyboard solid hue cycling through full gradient
    RGB_MATRIX_CYCLE_LEFT_RIGHT,    // Full gradient scrolling left to right
    RGB_MATRIX_CYCLE_UP_DOWN,       // Full gradient scrolling top to bottom
    RGB_MATRIX_CYCLE_OUT_IN,        // Full gradient scrolling out to in
    RGB_MATRIX_CYCLE_OUT_IN_DUAL,   // Full dual gradients scrolling out to in
    RGB_MATRIX_RAINBOW_MOVING_CHEVRON,  // Full gradient Chevron shapped scrolling left to right
    RGB_MATRIX_CYCLE_PINWHEEL,      // Full gradient spinning pinwheel around center of keyboard
    RGB_MATRIX_CYCLE_SPIRAL,        // Full gradient spinning spiral around center of keyboard
    RGB_MATRIX_DUAL_BEACON,         // Full gradient spinning around center of keyboard
    RGB_MATRIX_RAINBOW_BEACON,      // Full tighter gradient spinning around center of keyboard
    RGB_MATRIX_RAINBOW_PINWHEELS,   // Full dual gradients spinning two halves of keyboard
    RGB_MATRIX_FLOWER_BLOOMING,     // Full tighter gradient of first half scrolling left to right and second half scrolling right to left
    RGB_MATRIX_RAINDROPS,           // Randomly changes a single key's hue
    RGB_MATRIX_JELLYBEAN_RAINDROPS, // Randomly changes a single key's hue and saturation
    RGB_MATRIX_HUE_BREATHING,       // Hue shifts up a slight amount at the same time, then shifts back
    RGB_MATRIX_HUE_PENDULUM,        // Hue shifts up a slight amount in a wave to the right, then back to the left
    RGB_MATRIX_HUE_WAVE,            // Hue shifts up a slight amount and then back down in a wave to the right
    RGB_MATRIX_PIXEL_FRACTAL,       // Single hue fractal filled keys pulsing horizontally out to edges
    RGB_MATRIX_PIXEL_FLOW,          // Pulsing RGB flow along LED wiring with random hues
    RGB_MATRIX_PIXEL_RAIN,          // Randomly light keys with random hues
    RGB_MATRIX_TYPING_HEATMAP,      // How hot is your WPM!
    RGB_MATRIX_DIGITAL_RAIN,        // That famous computer simulation
    RGB_MATRIX_SOLID_REACTIVE_SIMPLE,   // Pulses keys hit to hue & value then fades value out
    RGB_MATRIX_SOLID_REACTIVE,      // Static single hue, pulses keys hit to shifted hue then fades to current hue
    RGB_MATRIX_SOLID_REACTIVE_WIDE,       // Hue & value pulse near a single key hit then fades value out
    RGB_MATRIX_SOLID_REACTIVE_MULTIWIDE,  // Hue & value pulse near multiple key hits then fades value out
    RGB_MATRIX_SOLID_REACTIVE_CROSS,      // Hue & value pulse the same column and row of a single key hit then fades value out
    RGB_MATRIX_SOLID_REACTIVE_MULTICROSS, // Hue & value pulse the same column and row of multiple key hits then fades value out
    RGB_MATRIX_SOLID_REACTIVE_NEXUS,      // Hue & value pulse away on the same column and row of a single key hit then fades value out
    RGB_MATRIX_SOLID_REACTIVE_MULTINEXUS, // Hue & value pulse away on the same column and row of multiple key hits then fades value out
    RGB_MATRIX_SPLASH,              // Full gradient & value pulse away from a single key hit then fades value out
    RGB_MATRIX_MULTISPLASH,         // Full gradient & value pulse away from multiple key hits then fades value out
    RGB_MATRIX_SOLID_SPLASH,        // Hue & value pulse away from a single key hit then fades value out
    RGB_MATRIX_SOLID_MULTISPLASH,   // Hue & value pulse away from multiple key hits then fades value out
    RGB_MATRIX_STARLIGHT,           // LEDs turn on and off at random at varying brightness, maintaining user set color
    RGB_MATRIX_STARLIGHT_SMOOTH,    // LEDs slowly increase and decrease in brightness randomly
    RGB_MATRIX_STARLIGHT_DUAL_HUE,  // LEDs turn on and off at random at varying brightness, modifies user set hue by +- 30
    RGB_MATRIX_STARLIGHT_DUAL_SAT,  // LEDs turn on and off at random at varying brightness, modifies user set saturation by +- 30
    RGB_MATRIX_RIVERFLOW,           // Modification to breathing animation, offset's animation depending on key location to simulate a river flowing
    RGB_MATRIX_EFFECT_MAX
};