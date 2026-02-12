// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later
// enter this into the terminal to build the firmware "qmk compile -kb rpk_southpaw -km default"

#include QMK_KEYBOARD_H 

enum my_keycodes {
  YTUP = SAFE_RANGE,
  YTDWN,
  CPY,
  PST,
  GOODBYE,
  SHTDWN,
  LOGOUT,
  SELECT,
  TERMINAL,
  WORKUP,
  WORKDWN,
  APPS
};

//https://docs.qmk.fm/feature_macros

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    case YTUP:
        if (record->event.pressed) {
            SEND_STRING(SS_DOWN(X_RSFT) SS_TAP(X_DOT) SS_UP(X_RSFT));
        }
        break;

    case YTDWN:
        if (record->event.pressed) {
            SEND_STRING(SS_DOWN(X_RSFT) SS_TAP(X_COMM) SS_UP(X_RSFT));
        }
        break;

    case CPY:
        if (record->event.pressed) {
            SEND_STRING(SS_LCTL("c"));
        }
        break;

    case PST:
        if (record->event.pressed) {
            SEND_STRING(SS_LCTL("v"));
        }
        break;

    case GOODBYE:
        if (record->event.pressed) {
            SEND_STRING(SS_DOWN(X_LALT) SS_TAP(X_F4) SS_UP(X_LALT));
        }
        break;

    case SHTDWN:
        if (record->event.pressed) {
            SEND_STRING(SS_DOWN(X_LALT) SS_DOWN(X_LCTL) SS_TAP(X_END) SS_UP(X_LALT) SS_UP(X_LCTL));
        }
        break;

    case LOGOUT:
        if (record->event.pressed) {
            SEND_STRING(SS_DOWN(X_LALT) SS_DOWN(X_LCTL) SS_TAP(X_DEL) SS_UP(X_LALT) SS_UP(X_LCTL) SS_DELAY(100) SS_TAP(X_ENT));
        }
        break;

    case SELECT: //Shift + Print Screen to select a specific area to capture
        if (record->event.pressed) {
            SEND_STRING(SS_DOWN(X_RSFT) SS_TAP(X_PSCR) SS_UP(X_RSFT));
        }
        break;

    case TERMINAL:
        if (record->event.pressed) {
            SEND_STRING(SS_DOWN(X_LALT) SS_DOWN(X_LCTL) SS_TAP(X_T) SS_UP(X_LALT) SS_UP(X_LCTL));
        }
        break;

    case WORKUP:
        if (record->event.pressed) {
            SEND_STRING(SS_DOWN(X_LALT) SS_DOWN(X_LCTL) SS_TAP(X_RGHT) SS_UP(X_LALT) SS_UP(X_LCTL));
        }
        break;

    case WORKDWN:
        if (record->event.pressed) {
            SEND_STRING(SS_DOWN(X_LALT) SS_DOWN(X_LCTL) SS_TAP(X_LEFT) SS_UP(X_LALT) SS_UP(X_LCTL));
        }
        break;

    case APPS:
        if (record->event.pressed) {
            SEND_STRING(SS_DOWN(X_LALT) SS_DOWN(X_LCTL) SS_TAP(X_DOWN) SS_UP(X_LALT) SS_UP(X_LCTL));
        }
        break;
    }
    return true;
};

enum layers {
     _BASE,
     _LIGHTS
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_BASE] = LAYOUT(

    //            ┌────────┬────────┬────────┬────────┐ ┌────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬──────────────────┐ ┌────────┐ ┌────────┬────────┐
    //            │        │        │        │        │ │        │        │        │        │        │        │        │        │        │        │        │        │        │                  │ │        │ │        │        │
                    KC_MRWD, KC_MPLY, KC_MFFD,  KC_GRV,   KC_ESC,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,  KC_F12,      KC_BSPC,         KC_DEL,    SELECT, TERMINAL,
    //            │        │        │        │        │ │        │        │        │        │        │        │        │        │        │        │        │        │        │                  │ │        │ │        │        │
    //            └────────┴────────┴────────┴────────┘ └────────┴────────┴────────┴────────┴────────┴────────┴────────┴────────┴────────┴────────┴────────┴────────┴────────┴──────────────────┘ └────────┘ └────────┴────────┘
    // ┌────────┐ ┌────────┬────────┬────────┬────────┐ ┌─────────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬─────────────┐            ┌────────┬────────┐
    // │        │ │        │        │        │        │ │             │        │        │        │        │        │        │        │        │        │        │        │        │             │            │        │        │
          CPY,       KC_7,    KC_8,    KC_9,   KC_PAST,     KC_TAB,      KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,   KC_LBRC, KC_RBRC,   KC_BSLS,                  APPS,   KC_END,
    // │        │ │        │        │        │        │ │             │        │        │        │        │        │        │        │        │        │        │        │        │             │            │        │        │
    // ├────────┤ ├────────┼────────┼────────┼────────┤ ├─────────────┴─┬──────┴─┬──────┴─┬──────┴─┬──────┴─┬──────┴─┬──────┴─┬──────┴─┬──────┴─┬──────┴─┬──────┴─┬──────┴─┬──────┴─────────────┤            ├────────┼────────┤
    // │        │ │        │        │        │        │ │               │        │        │        │        │        │        │        │        │        │        │        │                    │            │        │        │
          PST,       KC_4,    KC_5,    KC_6,   KC_PSLS,      KC_CAPS,      KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,   KC_SCLN, KC_QUOT,       KC_ENT,                     WORKUP, KC_PAUS,
    // │        │ │        │        │        │        │ │               │        │        │        │        │        │        │        │        │        │        │        │                    │            │        │        │
    // ├────────┤ ├────────┼────────┼────────┼────────┤ ├───────────────┴─┬──────┴─┬──────┴─┬──────┴─┬──────┴─┬──────┴─┬──────┴─┬──────┴─┬──────┴─┬──────┴─┬──────┴─┬──────┴────────────────────┤ ┌────────┐ ├────────┼────────┤
    // │        │ │        │        │        │        │ │                 │        │        │        │        │        │        │        │        │        │        │                           │ │        │ │        │        │
          YTUP,      KC_1,    KC_2,    KC_3,   KC_EQL,        KC_LSFT,       KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,   KC_COMM,  KC_DOT, KC_SLSH,          KC_RSFT,              KC_UP,    WORKDWN, MO (_LIGHTS),
    // │        │ │        │        │        │        │ │                 │        │        │        │        │        │        │        │        │        │        │                           │ │        │ │        │        │
    // ├────────┤ ├────────┼────────┼────────┼────────┤ ├──────────┬──────┴───┬────┴─────┬──┴────────┴────────┴────────┴────────┴────────┴────────┴───┬────┴─────┬──┴───────┬──────────┬─┬──────┴─┼────────┼─┴──────┬─┼────────┤
    // │        │ │        │        │        │        │ │          │          │          │                                                            │          │          │          │ │        │        │        │ │        │
         YTDWN,      KC_0,   KC_PDOT, KC_PENT, KC_MINS,   KC_LCTL,   KC_LGUI,   KC_LALT,                            KC_SPC,                             KC_RALT,   KC_RGUI,   KC_RCTL,     KC_LEFT, KC_DOWN, KC_RGHT,   KC_INS
    // │        │ │        │        │        │        │ │          │          │          │                                                            │          │          │          │ │        │        │        │ │        │
    // └────────┘ └────────┴────────┴────────┴────────┘ └──────────┴──────────┴──────────┴────────────────────────────────────────────────────────────┴──────────┴──────────┴──────────┘ └────────┴────────┴────────┘ └────────┘

	),

   [_LIGHTS] = LAYOUT(

    //            ┌────────┬────────┬────────┬────────┐ ┌────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬──────────────────┐ ┌────────┐ ┌────────┬────────┐
    //            │        │        │        │        │ │        │        │        │        │        │        │        │        │        │        │        │        │        │                  │ │        │ │        │        │
                    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,     XXXXXXX,         SHTDWN,    KC_PSCR, GOODBYE,
    //            │        │        │        │        │ │        │        │        │        │        │        │        │        │        │        │        │        │        │                  │ │        │ │        │        │
    //            └────────┴────────┴────────┴────────┘ └────────┴────────┴────────┴────────┴────────┴────────┴────────┴────────┴────────┴────────┴────────┴────────┴────────┴──────────────────┘ └────────┘ └────────┴────────┘
    // ┌────────┐ ┌────────┬────────┬────────┬────────┐ ┌─────────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬─────────────┐            ┌────────┬────────┐
    // │        │ │        │        │        │        │ │             │        │        │        │        │        │        │        │        │        │        │        │        │             │            │        │        │
        XXXXXXX,    RM_HUED, RM_SATU, RM_HUEU, XXXXXXX,     XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,   XXXXXXX,                 XXXXXXX, LOGOUT,
    // │        │ │        │        │        │        │ │             │        │        │        │        │        │        │        │        │        │        │        │        │             │            │        │        │
    // ├────────┤ ├────────┼────────┼────────┼────────┤ ├─────────────┴─┬──────┴─┬──────┴─┬──────┴─┬──────┴─┬──────┴─┬──────┴─┬──────┴─┬──────┴─┬──────┴─┬──────┴─┬──────┴─┬──────┴─────────────┤            ├────────┼────────┤
    // │        │ │        │        │        │        │ │               │        │        │        │        │        │        │        │        │        │        │        │                    │            │        │        │
        XXXXXXX,    RM_PREV, RM_SATD, RM_NEXT, XXXXXXX,      XXXXXXX,     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,      XXXXXXX,                     XXXXXXX, XXXXXXX,
    // │        │ │        │        │        │        │ │               │        │        │        │        │        │        │        │        │        │        │        │                    │            │        │        │
    // ├────────┤ ├────────┼────────┼────────┼────────┤ ├───────────────┴─┬──────┴─┬──────┴─┬──────┴─┬──────┴─┬──────┴─┬──────┴─┬──────┴─┬──────┴─┬──────┴─┬──────┴─┬──────┴────────────────────┤ ┌────────┐ ├────────┼────────┤
    // │        │ │        │        │        │        │ │                 │        │        │        │        │        │        │        │        │        │        │                           │ │        │ │        │        │
        XXXXXXX,    RM_VALU, XXXXXXX, XXXXXXX, XXXXXXX,        XXXXXXX,     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX,             XXXXXXX,   XXXXXXX, XXXXXXX,
    // │        │ │        │        │        │        │ │                 │        │        │        │        │        │        │        │        │        │        │                           │ │        │ │        │        │
    // ├────────┤ ├────────┼────────┼────────┼────────┤ ├──────────┬──────┴───┬────┴─────┬──┴────────┴────────┴────────┴────────┴────────┴────────┴───┬────┴─────┬──┴───────┬──────────┬─┬──────┴─┼────────┼─┴──────┬─┼────────┤
    // │        │ │        │        │        │        │ │          │          │          │                                                            │          │          │          │ │        │        │        │ │        │
        XXXXXXX,    RM_VALD, XXXXXXX, XXXXXXX, XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,                           XXXXXXX,                             XXXXXXX,    XXXXXXX,   XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX,   XXXXXXX
    // │        │ │        │        │        │        │ │          │          │          │                                                            │          │          │          │ │        │        │        │ │        │
    // └────────┘ └────────┴────────┴────────┴────────┘ └──────────┴──────────┴──────────┴────────────────────────────────────────────────────────────┴──────────┴──────────┴──────────┘ └────────┴────────┴────────┘ └────────┘

	)

};

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [_BASE] = { ENCODER_CCW_CW(KC_KB_VOLUME_UP, KC_KB_VOLUME_DOWN) },
    [_LIGHTS] = { ENCODER_CCW_CW(RM_VALU, RM_VALD) },
};
#endif

