#include QMK_KEYBOARD_H
#include "action_layer.h"
#include "version.h"

#define BASE 0 // default layer
#define ADVC 1 // advanced
#define GAME 2 // LT letters replaced by numbers, GUI disabled
#define PLTF 3 // arrows and some numbers, most keys disabled

#define EDIT_LOCKED 4

#define MDIA 6 // media keys

#define HATE 16 // qwerty

#define SYMB 14 // symbols
#define EDIT 15




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
  PKC_SSHT,

  PKC_MAUS,
  PKC_CTAB,
  PKC_SHRG,
  PKC_CD,

  MOUSE_REPEAT
};

// ┌────┬───┬───┬───┬───┬───┬───┐                    ┌───┬───┬───┬───┬───┬───┬────┐
// │  ◆ │ ◆ │ ◆ │ ◆ │ ◆ │ ◆ │ ◆ │                    │ ◆ │ ◆ │ ◆ │ ◆ │ ◆ │ ◆ │  ◆ │
// ├────┼───┼───┼───┼───┼───┼───┤                    ├───┼───┼───┼───┼───┼───┼────┤
// │  ◆ │ Č │ J │ M │ B │ Ę │   │                    │   │ ◆ │ D │ P │ Ė │ Q │  ◆ │
// ├────┼───┼───┼───┼───┼───┤ ◆ │                    │ ◆ ├───┼───┼───┼───┼───┼────┤
// │  Ž │ K │ L │ T │ A │ V ├───┤                    ├───┤ Ū │ S │ E │ I │ O │  Ą │
// ├────┼───┼───┼───┼───┼───┤ ◆ │                    │ ◆ ├───┼───┼───┼───┼───┼────┤
// │  ◆ │ W │ C │ G │ H │ Į │   │┌───┬───┐  ┌───┬───┐│   │ Ų │ R │ F │ Y │ Š │  ◆ │
// └┬───┼───┼───┼───┼───┼───┴───┘│ ◆ │ ◆ │  │ ◆ │ ◆ │└───┴───┼───┼───┼───┼───┼───┬┘
//  │ ◆ │ ◆ │ ◆ │ ◆ │ Z │    ┌───┼───┼───┤  ├───┼───┼───┐    │ X │ ◆ │ ◆ │ ◆ │ ◆ │
//  └───┴───┴───┴───┴───┘    │   │   │ ◆ │  │ ◆ │   │   │    └───┴───┴───┴───┴───┘
//                           │ ◆ │ U ├───┤  ├───┤ N │ ◆ │
//                           │   │   │ ◆ │  │ ◆ │   │   │
//                           └───┴───┴───┘  └───┴───┴───┘
// "◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆ČJMBĘ◆DPĖŪ◆◆◆ŽKLTAFVSEIOĄ◆◆◆WCGHĮQRŠYŲ◆◆◆◆◆◆◆◆◆ZX◆◆◆◆◆◆◆UN◆◆◆"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[BASE] = LAYOUT_ergodox(  // layer 0 : default
// left hand
     PKC_CTAB,            KC_LSFT,      OSM(MOD_LCTL),      OSM(MOD_LALT),      OSM(MOD_LGUI), XXXXXXX,   XXXXXXX,
 LCMD(KC_ESC),             PKC_CH,               KC_J,               KC_D,               KC_B,  PKC_EE,      KC_X,
       PKC_ZH,               KC_K,               KC_L,               KC_T,               KC_A,    KC_V,
      KC_LSFT,               KC_W,               KC_C,               KC_G,               KC_H,  PKC_II, OSL(SYMB),
      KC_LCTL,            KC_LALT,            KC_LGUI,               KC_X,           MO(EDIT),

                                 LT(MDIA, KC_MPLY),  RGB_TOG,
                                                    PKC_SSHT,
                         KC_SPC,              KC_U,  PKC_SHRG,
// right hand
  XXXXXXX, XXXXXXX,      OSM(MOD_RGUI),      OSM(MOD_RALT),      OSM(MOD_RCTL),            KC_RSFT,        XXXXXXX,
     KC_Z, KC_BSPC,               KC_M,               KC_P,             PKC_EH,               KC_Q,         KC_ENT,
            PKC_UH,               KC_S,               KC_E,               KC_I,               KC_O,         PKC_AA,
OSL(SYMB),  PKC_UU,               KC_R,               KC_F,               KC_Y,             PKC_SH,        KC_RSFT,
                              MO(EDIT),               KC_Z,            KC_RGUI,            KC_RALT,        KC_RCTL,

TO(GAME),       TO(SYMB),
TO(ADVC),
TO(EDIT),           KC_N,    KC_SPC
    ),

[ADVC] = LAYOUT_ergodox(  // layer 0 : default
// left hand
      _______,            _______,            _______,            _______,            _______, _______,   _______,
      _______,            _______,            _______,            _______,            _______, _______,   _______,
      _______, MT(MOD_LSFT, KC_K), MT(MOD_LCTL, KC_L), MT(MOD_LALT, KC_T), MT(MOD_LGUI, KC_A), _______,
      _______,            _______,            _______,            _______,            _______, _______,   _______,
      _______,            _______,            _______,            _______,            _______,

                                          _______,  _______,
                                                    _______,
               LT(EDIT, KC_SPC),          _______,  XXXXXXX,
// right hand
  _______, _______,            _______,            _______,            _______,            _______,        _______,
  _______, _______,            _______,            _______,            _______,            _______,        _______,
           _______, MT(MOD_RGUI, KC_S), MT(MOD_RALT, KC_E), MT(MOD_RCTL, KC_I), MT(MOD_RSFT, KC_O),        _______,
  _______, _______,            _______,            _______,            _______,            _______,        _______,
                               _______,            _______,            _______,            _______,        _______,

 XXXXXXX,       XXXXXXX,
TO(BASE),
 XXXXXXX,       _______, LT(EDIT, KC_SPC)

    ),

[GAME] = LAYOUT_ergodox(  // layer 0 : default
        // left hand
        XXXXXXX,  KC_1,  KC_2,  KC_3,  KC_4,  KC_5, XXXXXXX,  
        XXXXXXX, KC_F1, _______, _______, _______, KC_F2, _______,
         KC_F3, _______, _______, _______, _______, _______,
        KC_LSFT, _______, _______, _______, _______, KC_F5, _______,
         KC_LCTL, KC_LALT, KC_LGUI, _______, _______,
                                                        KC_TRNS,  KC_TRNS,
                                                                XXXXXXX,
                                               KC_SPC, KC_U, XXXXXXX,
        // right hand
              XXXXXXX,  KC_6, KC_7,  KC_8,   KC_9,   KC_0,  XXXXXXX,
             _______, _______, _______, _______, _______, _______, _______,
                      _______, _______, _______, _______, _______, _______,
             _______, _______, _______, _______, _______, _______, _______,
                               _______, _______, _______, _______, _______,
             TO(PLTF), TO(BASE),
             XXXXXXX, 
             XXXXXXX, _______, _______
    ),

[EDIT] = LAYOUT_ergodox(  // layer 0 : default
        // left hand
        XXXXXXX, KC_F1,              KC_F2,              KC_F3,              KC_F4,   KC_F5,     KC_F6,
         XXXXXXX, XXXXXXX, LGUI(KC_X), LGUI(KC_C), LGUI(KC_V), XXXXXXX, XXXXXXX,
         XXXXXXX, KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, LGUI(KC_SLSH), XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX,XXXXXXX, XXXXXXX,  LGUI(KC_Z),
                                                        XXXXXXX,  XXXXXXX,
                                                                            XXXXXXX,
                                               KC_SPC, XXXXXXX, XXXXXXX,
        // right hand
              KC_F7,   KC_F8,              KC_F9,             KC_F10,             KC_F11,             KC_F12, XXXXXXX,
              XXXXXXX, KC_TRNS,   KC_ESC,   KC_UP, KC_PGUP, XXXXXXX, XXXXXXX,
                     XXXXXXX,   KC_LEFT,   KC_DOWN,   KC_RIGHT, KC_ENT, XXXXXXX,
            XXXXXXX, XXXXXXX,   KC_TAB,   XXXXXXX,   KC_PGDN,  XXXXXXX, XXXXXXX,
                     LGUI(KC_X), XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
             XXXXXXX, XXXXXXX,
             XXXXXXX,
             TO(BASE),  XXXXXXX, KC_SPC
    ),

[PLTF] = LAYOUT_ergodox(  // layer 0 : default
        // left hand
        KC_ESC,  KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5, KC_F6,
         XXXXXXX, XXXXXXX, XXXXXXX, KC_UP, XXXXXXX, XXXXXXX, XXXXXXX,
         XXXXXXX, XXXXXXX, KC_LEFT, KC_DOWN, KC_RGHT, XXXXXXX,
        KC_ESC, KC_Z, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX,XXXXXXX, XXXXXXX, XXXXXXX,
                                                        XXXXXXX,  XXXXXXX,
                                                                            XXXXXXX,
                                               KC_SPC, KC_ENT, XXXXXXX,
        // right hand
              KC_F7,  KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12, XXXXXXX,
            XXXXXXX, XXXXXXX,   KC_7,   KC_8,   KC_9, XXXXXXX, XXXXXXX,
                     XXXXXXX,   KC_4,   KC_5,   KC_6, XXXXXXX, XXXXXXX,
            XXXXXXX, XXXXXXX,   KC_1,   KC_2,   KC_3,   KC_0, XXXXXXX,
                     XXXXXXX, XXXXXXX, XXXXXXX, KC_LSFT, KC_RSFT,
             XXXXXXX, TO(GAME),
             XXXXXXX,
             XXXXXXX,             KC_B, KC_A
    ),

[HATE] = LAYOUT_ergodox(  // layer 0 : default
        // left hand
        KC_ESC,         KC_1,         KC_2,   KC_3,   KC_4,   KC_5,   XXXXXXX,
        KC_TAB,        KC_Q,         KC_W,   KC_E,   KC_R,   KC_T,   XXXXXXX,
        XXXXXXX,        KC_A,         KC_S,   KC_D,   KC_F,   KC_G,
        KC_LSFT,        KC_Z,         KC_X,   KC_C,   KC_V,   KC_B,   XXXXXXX,
        KC_LCTL,KC_LALT, KC_LGUI, XXXXXXX, XXXXXXX,
                                              XXXXXXX,  XXXXXXX,
                                                              XXXXXXX,
                                               KC_SPC,XXXXXXX,XXXXXXX,
        // right hand
             XXXXXXX,     KC_6,   KC_7,   KC_8,   KC_9,   KC_0,      KC_BSPC,
             XXXXXXX,       KC_Y,   KC_U,   KC_I,   KC_O,   KC_P,    KC_BSLS,
                          KC_H,   KC_J,   KC_K,   KC_L,   KC_SCLN ,KC_ENT,
             XXXXXXX,KC_N,   KC_M,   KC_COMM, KC_DOT, KC_SLSH, KC_RSFT,
                                  KC_QUOT,  XXXXXXX,KC_LBRC,KC_RBRC, XXXXXXX,
             XXXXXXX,        XXXXXXX,
             TO(BASE),
             XXXXXXX,XXXXXXX, KC_SPC
    ),
            
[SYMB] = LAYOUT_ergodox(
       // left hand
       _______, KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_PERC, _______,
       _______, KC_PIPE, KC_LBRC, KC_RBRC,  KC_DQT, KC_TILD, _______,
         KC_LT, KC_LPRN, KC_RPRN, KC_COMM, KC_QUOT,  KC_GRV,
       _______, KC_LCBR, KC_RCBR,  KC_DOT, KC_COLN, KC_QUES, _______,
       _______, _______, _______, _______, KC_UNDS,
                                       _______,_______,
                                               _______,
                              KC_SPC, KC_BSLS, _______,       
       // right hand
       _______, KC_CIRC, KC_AMPR,  KC_ASTR, KC_LPRN, KC_RPRN, _______,
       _______, KC_TRNS,    KC_7,     KC_8,    KC_9, KC_PAST, _______,
                KC_PPLS,    KC_4,     KC_5,    KC_6, KC_MINS,   KC_GT,
       _______,  KC_EQL,    KC_1,     KC_2,    KC_3, KC_SCLN, _______,
                            KC_0, PKC_EURO, _______, _______, _______,
       TO(BASE), XXXXXXX,
       _______,
       _______, KC_SLSH, KC_SPC
),
// [SYMR] = LAYOUT_ergodox(
//        // left hand
//        _______, _______, _______, _______,  _______, _______, _______,
//        _______, _______, KC_DQT, KC_LBRC, KC_RBRC, _______, _______,
//        _______, KC_SCLN, KC_COMM, KC_UNDS, KC_QUOT, KC_GRV,
//        KC_LT, KC_LCBR, KC_RCBR, KC_DOT,  KC_COLN, KC_QUES, _______,
//        _______, KC_PIPE, _______, _______, PKC_EURO,
//                                        _______,_______,
//                                                _______,
//                             KC_SPC,  KC_BSLS, _______,       
//        // right hand
//          _______, _______, _______, _______, _______, _______, _______,
//        KC_BSPC, KC_TRNS, KC_7,   KC_8,   KC_9, _______, _______,
//                 KC_PPLS, KC_4,   KC_5,   KC_6, XXXXXXX, _______,
//        KC_ENT,  KC_EQL, KC_1,   KC_2,   KC_3, KC_MINS, KC_GT,
//                          KC_0, _______, _______, XXXXXXX, _______,
//        TO(SYML), XXXXXXX,
//        _______,
//        _______, KC_TRNS, KC_SPC
// ),

[MDIA] = LAYOUT_ergodox(
       TO(HATE), _______, _______, _______, _______, _______, _______,
       _______, _______, _______, _______, _______, _______, _______,
       _______, _______, _______, _______, _______, _______,
       _______, _______, _______, _______, _______, _______, _______,
       _______, _______, _______, _______, _______,
                                           XXXXXXX, KC_MFFD,
                                                    KC_VOLU,
                                  RGB_VAD, RGB_VAI, KC_VOLD,
    // right hand
         RESET,  _______, _______, _______, _______, _______,_______,
       _______,  _______, _______, _______, _______, _______, _______,
                 _______, _______, _______, _______, _______, _______,
       _______,  _______, _______, _______, _______, _______, _______,
                          _______, _______, _______, _______, _______,
       XXXXXXX, RGB_SLD,
       _______,
       RGB_MOD, RGB_HUD, RGB_HUI
)
// ,
// [MAUS] = LAYOUT_ergodox(
//        _______, _______, _______, _______, _______, _______, _______,
//        _______, _______, _______, _______, _______, _______, _______,
//        _______, _______, _______, _______, _______, _______,
//        _______, _______, _______, _______, _______, _______, _______,
//        _______, _______, _______, _______, _______,
//                                            _______, _______,
//                                                     _______,
//                                   _______, _______, _______,
//     // right hand
//       TO(BASE), _______, _______, _______, _______, _______, _______,
//        _______, _______, _______, KC_MS_U, _______, _______, _______,
//                 _______, KC_MS_L, KC_MS_D, KC_MS_R, _______, _______,
//        _______, _______, _______, _______, _______, _______, _______,
//                          _______, _______, _______, _______, _______,
//        _______, _______,
//        _______,
//        _______, KC_BTN2, KC_BTN1
// )
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
      return true;
      break;
    case PKC_CH:
      if (record->event.pressed) {
        SHIFTED ? SEND_STRING(SS_LALT("010c")) : SEND_STRING(SS_LALT("010d"));
      }
      return true;
      break;
    case PKC_EE:
      if (record->event.pressed) {
        SHIFTED ? SEND_STRING(SS_LALT("0118")) : SEND_STRING(SS_LALT("0119"));
      }
      return true;
      break;
    case PKC_EH:
      if (record->event.pressed) {
        SHIFTED ? SEND_STRING(SS_LALT("0116")) : SEND_STRING(SS_LALT("0117"));
      }
      return true;
      break;
    case PKC_II:
      if (record->event.pressed) {
        SHIFTED ? SEND_STRING(SS_LALT("012e")) : SEND_STRING(SS_LALT("012f"));
      }
      return true;
      break;
    case PKC_SH:
      if (record->event.pressed) {
        SHIFTED ? SEND_STRING(SS_LALT("0160")) : SEND_STRING(SS_LALT("0161"));
      }
      return true;
      break;
    case PKC_UU:
      if (record->event.pressed) {
        SHIFTED ? SEND_STRING(SS_LALT("0172")) : SEND_STRING(SS_LALT("0173"));
      }
      return true;
      break;
    case PKC_UH:
      if (record->event.pressed) {
        SHIFTED ? SEND_STRING(SS_LALT("016a")) : SEND_STRING(SS_LALT("016b"));
      }
      return true;
      break;
    case PKC_ZH:
      if (record->event.pressed) {
        SHIFTED ? SEND_STRING(SS_LALT("017d")) : SEND_STRING(SS_LALT("017e"));
      }
      return true;
      break;
    case PKC_EURO:
      if (record->event.pressed) {
        SEND_STRING(SS_LALT("20ac"));
      }
      return true;
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
    case PKC_SSHT:
      if (record->event.pressed) {
        SEND_STRING(SS_LSFT(SS_LGUI("4")));
      } else {
        SEND_STRING(" ");
      }
      return true;
      break;
    // case PKC_MAUS:
    //   if (record->event.pressed) {
    //     layer_on(EDIT);
    //     layer_on(MAUS);
    //   }
    //   return false;
    //   break;
    case PKC_CTAB:
      if (record->event.pressed) {
        register_code(KC_LCMD);
        register_code(KC_TAB);
        unregister_code(KC_TAB);
        layer_on(EDIT);
      } else {
        layer_off(EDIT);
        unregister_code(KC_LCMD);
      }
      return false;
      break;
    case PKC_CD:
      if (record->event.pressed) {
        SEND_STRING("cd ");
      }
      return false;
      break;
    case PKC_SHRG:
      if (record->event.pressed) {
        SEND_STRING(SS_LALT("00af")"\\_("SS_LALT("30c4")")_/"SS_LALT("00af"));
      }
      return true;
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
  ergodox_led_all_set(15);
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
      case GAME:
        rgblight_sethsv_noeeprom_magenta();
        ergodox_right_led_1_on();
        ergodox_right_led_2_on();
        ergodox_right_led_3_on();
        break;
      case ADVC:
        rgblight_sethsv_noeeprom_teal();
        ergodox_right_led_1_on();
        ergodox_right_led_2_off();
        ergodox_right_led_3_off();
        break;
      case PLTF:
        rgblight_sethsv_noeeprom_goldenrod();
        break;
      case HATE:
        rgblight_sethsv_noeeprom_red();
        break;
      // case MAUS:
      //   ergodox_right_led_1_on();
      //   break;
      case EDIT:
      case EDIT_LOCKED:
        ergodox_right_led_3_on();
        break;
      case SYMB:
        ergodox_right_led_2_on();
        break;
      default:
        rgblight_sethsv_white();
        ergodox_right_led_1_off();
        ergodox_right_led_2_off();
        ergodox_right_led_3_off();
        break;
    }

  return state;
};
