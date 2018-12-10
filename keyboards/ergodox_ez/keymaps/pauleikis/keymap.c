#include QMK_KEYBOARD_H
#include "action_layer.h"
#include "version.h"

#define BASE 0 // default layer
#define GAME 1 // LT letters replaced by numbers, GUI disabled
#define PLTF 2 // arrows and some numbers, most keys disabled
#define HATE 3 // qwerty
#define SYMB 4 // symbols
#define MCRO 5 // media keys
#define MAUS 6 // mouse


static bool is_mouse_repeat = false;

enum custom_keycodes {
  PLACEHOLDER = SAFE_RANGE, // can always be here
  EPRM,
  VRSN,
  RGB_SLD,

  PKC_AA,
  PKC_CH,
  PKC_EE,
  PKC_EH,
  PKC_II,
  PKC_SH,
  PKC_UU,
  PKC_UH,
  PKC_ZH,

  PKC_EURO,

  MOUSE_REPEAT
};

// ┌────┬───┬───┬───┬───┬───┬───┐                    ┌───┬───┬───┬───┬───┬───┬────┐
// │  ◆ │ ◆ │ ◆ │ Ū │ Ę │   │ ◆ │                    │ ◆ │ Ų │ Ž │ Č │ ◆ │ ◆ │  ◆ │
// ├────┼───┼───┼───┼───┼───┼───┤                    ├───┼───┼───┼───┼───┼───┼────┤
// │  ◆ │ ◆ │ Q │ O │ Y │ Ą │   │                    │   │ Z │ M │ L │ X │ ◆ │  ◆ │
// ├────┼───┼───┼───┼───┼───┤ ◆ │                    │ ◆ ├───┼───┼───┼───┼───┼────┤
// │  ◆ │ Š │ G │ A │ I │ Ė ├───┤                    ├───┤ B │ S │ R │ D │ J │  ◆ │
// ├────┼───┼───┼───┼───┼───┤ ◆ │                    │ ◆ ├───┼───┼───┼───┼───┼────┤
// │  ◆ │ H │ C │ W │ E │ Į │   │┌───┬───┐  ┌───┬───┐│   │ F │ N │ V │ P │ K │  ◆ │
// └┬───┼───┼───┼───┼───┼───┴───┘│ ◆ │ ◆ │  │ ◆ │ ◆ │└───┴───┼───┼───┼───┼───┼───┬┘
//  │ ◆ │ ◆ │ ◆ │ ◆ │ ◆ │    ┌───┼───┼───┤  ├───┼───┼───┐    │ ◆ │ ◆ │ ◆ │ ◆ │ ◆ │
//  └───┴───┴───┴───┴───┘    │   │   │ ◆ │  │ ◆ │   │   │    └───┴───┴───┴───┴───┘
//                           │ U │ ◆ ├───┤  ├───┤ ◆ │ T │
//                           │   │   │ ◆ │  │ ◆ │   │   │
//                           └───┴───┴───┘  └───┴───┴───┘

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[BASE] = LAYOUT_ergodox(  // layer 0 : default
        // left hand
        LGUI(KC_ESC), LGUI(KC_Z), LGUI(KC_S), PKC_UH, PKC_II, LGUI(KC_C), LGUI(KC_V),
         LCTL(KC_SPC), XXXXXXX, KC_Z, KC_O, KC_Y, PKC_AA, KC_BSPC,
         KC_ESC, PKC_EE, KC_G, KC_A, KC_I, PKC_EH,
        KC_TAB, KC_H, KC_C, KC_X, KC_E, PKC_UU, KC_ENT,
   KC_LCTL, KC_LALT, KC_LGUI, SH_MON, LT(SYMB, KC_COMM),
                                         XXXXXXX,  XXXXXXX,
                                                            XXXXXXX,
                                 MT(MOD_LSFT, KC_SPC), KC_U, KC_SLSH,
        // right hand
              TO(MAUS), PKC_CH, PKC_SH, PKC_ZH, KC_LEFT, KC_UP, KC_RIGHT,
             KC_BSPC, KC_W, KC_M, KC_L, KC_Q, KC_DOWN, KC_BSPC,
                           KC_B, KC_S, KC_R, KC_D, KC_J, LT(MCRO, KC_MPLY),
             KC_ENT, KC_F, KC_N, KC_V, KC_P, KC_K, XXXXXXX,
                           LT(SYMB, KC_DOT), SH_MON, KC_RGUI, KC_RALT, KC_RCTL,
             TO(GAME), XXXXXXX,
             XXXXXXX,
             KC_BSLS,     KC_T, MT(MOD_RSFT, KC_SPC)
    ),

[GAME] = LAYOUT_ergodox(  // layer 0 : default
        // left hand
        XXXXXXX,  KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5,    KC_F6,
         XXXXXXX, KC_KP_1, _______, _______, _______, KC_KP_2, _______,
         _______, KC_KP_3, _______, _______, _______, KC_KP_4,
        _______, _______, _______, _______, _______, KC_KP_5, _______,
         _______, _______, XXXXXXX, KC_LSFT, KC_COMM,
                                                        _______,  KC_TRNS,
                                                                XXXXXXX,
                                               KC_SPC, _______, _______,
        // right hand
              KC_F7,  KC_F8,   KC_F9,   KC_F10,  _______,  _______,   _______,
             _______, _______, _______, _______, _______, _______, XXXXXXX,
                           _______, _______, _______, _______, _______, XXXXXXX,
             _______, _______, _______, _______, _______, _______, XXXXXXX,
                           KC_DOT,  KC_RSFT,   XXXXXXX,  _______, _______,
             TO(PLTF), TO(BASE),
             XXXXXXX, 
             _______, _______, KC_SPC
    ),

[PLTF] = LAYOUT_ergodox(  // layer 0 : default
        // left hand
        XXXXXXX,  KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5, KC_F6,
         XXXXXXX, XXXXXXX, XXXXXXX, KC_UP, XXXXXXX, XXXXXXX, XXXXXXX,
         _______, XXXXXXX, KC_LEFT, KC_DOWN, KC_RGHT, XXXXXXX,
        XXXXXXX, KC_Z, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX,XXXXXXX, XXXXXXX, XXXXXXX,
                                                        XXXXXXX,  XXXXXXX,
                                                                            XXXXXXX,
                                               KC_SPC, KC_ENT, XXXXXXX,
        // right hand
              KC_F7,  KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12, XXXXXXX,
            XXXXXXX, XXXXXXX,   KC_7,   KC_8,   KC_9, XXXXXXX, XXXXXXX,
                     XXXXXXX,   KC_4,   KC_5,   KC_6, XXXXXXX, XXXXXXX,
            XXXXXXX, XXXXXXX,   KC_1,   KC_2,   KC_3,   KC_0, XXXXXXX,
                     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
             XXXXXXX, TO(GAME),
             XXXXXXX,
             XXXXXXX,             KC_B, KC_A
    ),

[HATE] = LAYOUT_ergodox(  // layer 0 : default
        // left hand
        KC_ESC,         KC_1,         KC_2,   KC_3,   KC_4,   KC_5,   XXXXXXX,
        XXXXXXX,        KC_Q,         KC_W,   KC_E,   KC_R,   KC_T,   _______,
        _______,        KC_A,         KC_S,   KC_D,   KC_F,   KC_G,
        KC_LSFT,        KC_Z,         KC_X,   KC_C,   KC_V,   KC_B,   _______,
        _______,XXXXXXX,      _______,  KC_LGUI,XXXXXXX,
                                              XXXXXXX,  KC_TRNS,
                                                              XXXXXXX,
                                               _______,XXXXXXX,_______,
        // right hand
             XXXXXXX,     KC_6,   KC_7,   KC_8,   KC_9,   KC_0,             XXXXXXX,
             _______,       KC_Y,   KC_U,   KC_I,   KC_O,   KC_P,             XXXXXXX,
                          KC_H,   KC_J,   KC_K,   KC_L,   KC_SCLN ,XXXXXXX,
             _______,KC_N,   KC_M,   KC_COMM,KC_DOT, KC_SLSH,   KC_RSFT,
                                  XXXXXXX,  XXXXXXX,KC_LBRC,KC_RBRC,          XXXXXXX,
             XXXXXXX,        XXXXXXX,
             TO(BASE),
             _______,XXXXXXX, _______
    ),
            
[SYMB] = LAYOUT_ergodox(
       // left hand
       KC_TILD, KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_PERC, KC_CIRC,
       _______, _______, KC_LCBR, KC_RCBR, KC_QUOT, KC_AMPR, _______,
       _______, KC_SCLN, KC_LPRN, KC_RPRN, KC_UNDS,  KC_GRV,
       _______, KC_COLN, KC_LBRC, KC_RBRC,  KC_DQT, KC_QUES, _______,
       _______, _______, _______, _______, _______,
                                       _______,_______,
                                               _______,
                               _______,_______,_______,
       // right hand
       _______, _______, _______, _______, _______, _______, _______,
       _______, KC_PMNS,   KC_P7,   KC_P8,   KC_P9, KC_PSLS, _______,
                KC_PPLS,   KC_P4,   KC_P5,   KC_P6, KC_PAST, _______,
       _______,  KC_EQL,   KC_P1,   KC_P2,   KC_P3,   KC_P0, _______,
                         _______, _______, _______, _______, _______,
       _______, _______,
       _______,
       _______, _______, _______
),

[MCRO] = LAYOUT_ergodox(
       TO(HATE), _______, _______, _______, _______, _______, _______,
       _______, _______, _______, _______, _______, _______, _______,
       _______, _______, _______, _______, _______, _______,
       _______, _______, _______, _______, _______, _______, _______,
       _______, _______, _______, _______, _______,
                                           KC_MFFD, KC_TRNS,
                                                    KC_VOLU,
                                  RGB_VAD, RGB_VAI, KC_VOLD,
    // right hand
         RESET,  _______, _______, _______, _______, _______,_______,
       _______,  _______, _______, _______, _______, _______, MOUSE_REPEAT,
                 _______, _______, _______, _______, _______, _______,
       _______,  _______, _______, _______, _______, _______, _______,
                          _______, _______, _______, _______, _______,
       RGB_TOG, RGB_SLD,
       _______,
       RGB_MOD, RGB_HUD, RGB_HUI
),

[MAUS] = LAYOUT_ergodox(
       _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
       _______, XXXXXXX, KC_BTN4, KC_MS_U, KC_WH_U, XXXXXXX, _______,
       _______, XXXXXXX, KC_MS_L, KC_MS_D, KC_MS_R, XXXXXXX,
       _______, KC_BTN3, KC_WH_L, KC_WH_R,  KC_WH_D, XXXXXXX, _______,
       _______, _______, _______, _______,  _______,
                                           _______, _______,
                                                    _______,
                                  KC_BTN1, KC_BTN2, KC_BTN5,
    // right hand
      TO(BASE),  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
       _______,   XXXXXXX, KC_WH_U,  KC_MS_U, KC_BTN4, XXXXXXX, _______,
                 XXXXXXX, KC_MS_L, KC_MS_D, KC_MS_R, XXXXXXX, _______,
       _______,  XXXXXXX, KC_WH_D, KC_WH_L, KC_WH_R, KC_BTN3, _______,
                          _______, _______, _______, _______, _______,
       _______, _______,
       _______,
       KC_BTN5, KC_BTN2, KC_BTN1
),

// [LTU2] = LAYOUT_ergodox(
//        _______, _______, _______, _______, _______, _______, _______,
//        _______, _______, _______, _______, _______, _______, _______,
//        _______, _______, _______,  PKC_AA,  PKC_II, _______,
//        _______, _______, _______, _______,  PKC_EH,  PKC_CH, _______,
//        _______, _______, _______, _______,  PKC_UH,
//                                            _______, _______,
//                                                     _______,
//                                   _______, _______, _______,
//     // right hand
//          _______,  _______, _______, _______, _______, _______, _______,
//        _______,  _______, _______, _______, _______, _______, _______,
//                  _______, _______, _______, _______, _______, _______,
//        _______,  _______, _______, _______, _______, _______, _______,
//                           _______, _______, _______, _______, _______,
//        _______, _______,
//        _______,
//        _______, _______, _______
// ),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  bool SHIFTED = keyboard_report->mods & MOD_BIT(KC_LSFT) || keyboard_report->mods & MOD_BIT(KC_RSFT);
  switch (keycode) {
    // dynamically generate these.
    case EPRM:
      if (record->event.pressed) {
        eeconfig_init();
      }
      return false;
      break;
    case VRSN:
      if (record->event.pressed) {
        SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
      }
      return false;
      break;
    case RGB_SLD:
      if (record->event.pressed) {
        #ifdef RGBLIGHT_ENABLE
          rgblight_mode(1);
        #endif
      }
      return false;
      break;


    case PKC_AA:
      if (record->event.pressed) {
        SHIFTED ? SEND_STRING(SS_LALT("0104")) : SEND_STRING(SS_LALT("0105"));
      }
      return false;
      break;
    case PKC_CH:
      if (record->event.pressed) {
        SHIFTED ? SEND_STRING(SS_LALT("010c")) : SEND_STRING(SS_LALT("010d"));
      }
      return false;
      break;
    case PKC_EE:
      if (record->event.pressed) {
        SHIFTED ? SEND_STRING(SS_LALT("0118")) : SEND_STRING(SS_LALT("0119"));
      }
      return false;
      break;
    case PKC_EH:
      if (record->event.pressed) {
        SHIFTED ? SEND_STRING(SS_LALT("0116")) : SEND_STRING(SS_LALT("0117"));
      }
      return false;
      break;
    case PKC_II:
      if (record->event.pressed) {
        SHIFTED ? SEND_STRING(SS_LALT("012e")) : SEND_STRING(SS_LALT("012f"));
      }
      return false;
      break;
    case PKC_SH:
      if (record->event.pressed) {
        SHIFTED ? SEND_STRING(SS_LALT("0160")) : SEND_STRING(SS_LALT("0161"));
      }
      return false;
      break;
    case PKC_UU:
      if (record->event.pressed) {
        SHIFTED ? SEND_STRING(SS_LALT("0172")) : SEND_STRING(SS_LALT("0173"));
      }
      return false;
      break;
    case PKC_UH:
      if (record->event.pressed) {
        SHIFTED ? SEND_STRING(SS_LALT("016a")) : SEND_STRING(SS_LALT("016b"));
      }
      return false;
      break;
    case PKC_ZH:
      if (record->event.pressed) {
        SHIFTED ? SEND_STRING(SS_LALT("017d")) : SEND_STRING(SS_LALT("017e"));
      }
      return false;
      break;
    case PKC_EURO:
      if (record->event.pressed) {
        SEND_STRING(SS_LALT("20ac"));
      }
      return false;
      break;
    case MOUSE_REPEAT:
      if (record->event.pressed) {
        is_mouse_repeat = !is_mouse_repeat;
        if (is_mouse_repeat) {
          ergodox_right_led_3_on();
        } else {
          ergodox_right_led_3_off();
        }
      }
      return false;
      break;
  }
  return true;
}

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {
#ifdef RGBLIGHT_COLOR_LAYER_0
  rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
#endif
  set_unicode_input_mode(UC_OSX);
};

// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {
  if (is_mouse_repeat) {
    register_code(KC_BTN1);
    unregister_code(KC_BTN1);
  }
};

// Runs whenever there is a layer state change.
uint32_t layer_state_set_user(uint32_t state) {

  uint8_t layer = biton32(state);
  switch (layer) {
      case BASE:
        rgblight_sethsv (  0,   0, 64);
        // ergodox_board_led_off();
        ergodox_right_led_1_off();
        // ergodox_right_led_2_off();
        // ergodox_right_led_3_off();
        break;
      case GAME:
        rgblight_sethsv_noeeprom_magenta();
        break;
      case PLTF:
        rgblight_sethsv_noeeprom_goldenrod();
        break;
      case HATE:
        ergodox_right_led_1_on();
        break;
      case MAUS:
        rgblight_sethsv_noeeprom_teal();
        break;
      // case 3:
      //   ergodox_right_led_3_on();
      //   #ifdef RGBLIGHT_COLOR_LAYER_3
      //     rgblight_setrgb(RGBLIGHT_COLOR_LAYER_3);
      //   #endif
      //   break;
      // case 4:
      //   ergodox_right_led_1_on();
      //   ergodox_right_led_2_on();
      //   #ifdef RGBLIGHT_COLOR_LAYER_4
      //     rgblight_setrgb(RGBLIGHT_COLOR_LAYER_4);
      //   #endif
      //   break;
      // case 5:
      //   ergodox_right_led_1_on();
      //   ergodox_right_led_3_on();
      //   #ifdef RGBLIGHT_COLOR_LAYER_5
      //     rgblight_setrgb(RGBLIGHT_COLOR_LAYER_5);
      //   #endif
      //   break;
      // case 6:
      //   ergodox_right_led_2_on();
      //   ergodox_right_led_3_on();
      //   #ifdef RGBLIGHT_COLOR_LAYER_6
      //     rgblight_setrgb(RGBLIGHT_COLOR_LAYER_6);
      //   #endif
      //   break;
      // case 7:
      //   ergodox_right_led_1_on();
      //   ergodox_right_led_2_on();
      //   ergodox_right_led_3_on();
      //   #ifdef RGBLIGHT_COLOR_LAYER_7
      //     rgblight_setrgb(RGBLIGHT_COLOR_LAYER_7);
      //   #endif
      //   break;
      default:
        break;
    }

  return state;
};
