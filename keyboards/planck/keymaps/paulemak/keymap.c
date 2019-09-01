#include QMK_KEYBOARD_H
#include "muse.h"
#include "eeprom.h"
  
float qwerty_song[][2] = SONG(QWERTY_SOUND);
float paulemak_song[][2] = SONG(WORKMAN_SOUND);


//Tap Dance Declarations
enum {
  TD_CLN = 0,
  TD_QUOT = 1,
  TD_GRAVE = 2
};

void dance_cln_each(qk_tap_dance_state_t *state, void *user_data) {
  if (state->count == 1) {
    register_code (KC_RSFT);
    register_code (KC_SCLN);
  } else if (state->count == 2) {
    unregister_code (KC_SCLN);
    unregister_code (KC_RSFT);
    tap_code(KC_BSPC);
    register_code (KC_SCLN);
  }
}

void dance_cln_reset(qk_tap_dance_state_t *state, void *user_data) {
  if (state->count == 1) {
    unregister_code (KC_RSFT);
    unregister_code (KC_SCLN);
  } else {
    unregister_code (KC_SCLN);
  }
}

void dance_quot_each(qk_tap_dance_state_t *state, void *user_data) {
  if (state->count == 1) {
    tap_code (KC_QUOTE);
  } else if (state->count == 2) {
    tap_code(KC_QUOTE);
    tap_code(KC_LEFT);
  } else if (state->count == 3) {
    tap_code(KC_RIGHT);
    tap_code(KC_QUOTE);
    tap_code(KC_ENTER);
    tap_code(KC_ENTER);
    tap_code(KC_QUOTE);
    tap_code(KC_QUOTE);
    tap_code(KC_QUOTE);
    unregister_code(KC_RSFT);
    unregister_code(KC_LSFT);
    tap_code(KC_UP);
  }
}

void dance_grave_each(qk_tap_dance_state_t *state, void *user_data) {
  if (state->count == 1) {
    tap_code (KC_GRAVE);
  } else if (state->count == 2) {
    tap_code(KC_GRAVE);
    tap_code(KC_LEFT);
  } else if (state->count == 3) {
    tap_code(KC_RIGHT);
    tap_code(KC_GRAVE);
    tap_code(KC_ENTER);
    tap_code(KC_ENTER);
    tap_code(KC_GRAVE);
    tap_code(KC_GRAVE);
    tap_code(KC_GRAVE);
    unregister_code(KC_RSFT);
    unregister_code(KC_LSFT);
    tap_code(KC_UP);
  }
}

//Tap Dance Definitions
qk_tap_dance_action_t tap_dance_actions[] = {
  [TD_CLN]  = ACTION_TAP_DANCE_FN_ADVANCED (dance_cln_each, NULL, dance_cln_reset),
  [TD_QUOT] = ACTION_TAP_DANCE_FN_ADVANCED_TIME (dance_quot_each, NULL, NULL, 250),
  [TD_GRAVE] = ACTION_TAP_DANCE_FN_ADVANCED_TIME (dance_grave_each, NULL, NULL, 250),
// Other declarations would go here, separated by commas, if you have them
};


enum planck_keycodes {
  QWERTY = SAFE_RANGE + 0xf0,
  PAULEMAK,

  PKC_OFFA,

  // PKC_QUOT,
  PKC_BCKT,

  PKC_QU
};

enum planck_layers {
  _BASE,
  _QWERTY,
  _LOWER,
  _RAISE,
  _ADJUST,
  _FN
};


#define LOWER OSL(_LOWER)
#define RAISE OSL(_RAISE)
#define FUNCT OSL(_FN)

#define PKC_CLN  TD(TD_CLN)
#define PKC_QUOT TD(TD_QUOT)
#define PKC_BCKT TD(TD_GRAVE)

#define PKC_HYPR OSM(MOD_HYPR)
#define PKC_MEH  OSM(MOD_MEH)
#define PKC_SHFT OSM(MOD_LSFT)
#define PKC_CTRL OSM(MOD_LCTL)
#define PKC_ALT  OSM(MOD_LALT)
#define PKC_COMM OSM(MOD_LGUI)

#define PKC_CUT  LGUI(KC_X)
#define PKC_COPY LGUI(KC_C)
#define PKC_PSTE LGUI(KC_V)
#define PKC_UNDO LGUI(KC_Z)

#define PKC_AA   XP(AA, AA_C)
#define PKC_CH   XP(CH, CH_C)
#define PKC_EE   XP(EE, EE_C)
#define PKC_EH   XP(EH, EH_C)
#define PKC_II   XP(II, II_C)
#define PKC_SH   XP(SH, SH_C)
#define PKC_UU   XP(UU, UU_C)
#define PKC_UH   XP(UH, UH_C)
#define PKC_ZH   XP(ZH, ZH_C)
#define PKC_AE   XP(AE, AE_C)
#define PKC_OE   XP(OE, OE_C)
#define PKC_UE   XP(UE, UE_C)

#define CLR_SYMB {252,119,255}
#define CLR_ALPH {195,61,255}
#define CLR_NAVI {154,86,255}
#define CLR_MCRO {50,153,244}
#define CLR_MODS {20,177,225}
#define CLR_____ {0,0,0}

enum unicode_names {
    AA,
    AA_C,
    CH,
    CH_C,
    EE,
    EE_C,
    EH,
    EH_C,
    II,
    II_C,
    SH,
    SH_C,
    UU,
    UU_C,
    UH,
    UH_C,
    ZH,
    ZH_C,

    AE,
    AE_C,
    OE,
    OE_C,
    UE,
    UE_C
};

const uint32_t PROGMEM unicode_map[] = {
    [AA]    = 0x0105,
    [AA_C]  = 0x0104,
    [CH]    = 0x010d,
    [CH_C]  = 0x010c,
    [EE]    = 0x0119,
    [EE_C]  = 0x0118,
    [EH]    = 0x0117,
    [EH_C]  = 0x0116,
    [II]    = 0x012f,
    [II_C]  = 0x012e,
    [SH]    = 0x0161,
    [SH_C]  = 0x0160,
    [UU]    = 0x0173,
    [UU_C]  = 0x0172,
    [UH]    = 0x016b,
    [UH_C]  = 0x016a,
    [ZH]    = 0x017e,
    [ZH_C]  = 0x017d,

    [AE]    = 0x00e4,
    [AE_C]  = 0x00c4,
    [OE]    = 0x00f6,
    [OE_C]  = 0x00d6,
    [UE]    = 0x00fc,
    [UE_C]  = 0x00dc
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT_planck_grid(
      KC_COMMA,     KC_Y,     KC_O,     KC_U,     KC_H,  KC_BSPC,   KC_ESC,     KC_C,     KC_D,     KC_B,     KC_W,  PKC_CLN,
        KC_DOT,     KC_I,     KC_A,     KC_E,     KC_R, KC_ENTER,     KC_F,     KC_S,     KC_T,     KC_N,     KC_K, PKC_QUOT,
      PKC_SHFT,   PKC_QU,     KC_X,     KC_Z,     KC_L,   KC_TAB,     KC_J,     KC_V,     KC_M,     KC_P,     KC_G, KC_SLASH,
         FUNCT, PKC_CTRL,  PKC_ALT, PKC_COMM,    LOWER, KC_SPACE,    KC_NO,    RAISE,  KC_LEFT,  KC_DOWN,    KC_UP, KC_RIGHT
    ),

  [_QWERTY] = LAYOUT_planck_grid(
        KC_TAB,     KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,  KC_BSPC,
        KC_ESC,     KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,  KC_SCLN, KC_QUOTE,
       KC_LSFT,     KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M, KC_COMMA,   KC_DOT, KC_SLASH, KC_ENTER,
         FUNCT, KC_LCTRL,  KC_LALT,  KC_LGUI,    LOWER, KC_SPACE,    KC_NO,    RAISE,  KC_LEFT,  KC_DOWN,    KC_UP, KC_RIGHT
    ),

  [_LOWER] = LAYOUT_planck_grid(
      PKC_BCKT,     KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0, KC_MINUS,
       PKC_MEH, PKC_CTRL,  PKC_ALT, PKC_SHFT, PKC_COMM, PKC_HYPR,  XXXXXXX,  KC_LEFT,  KC_DOWN,    KC_UP, KC_RIGHT, KC_EQUAL,
       XXXXXXX,  XXXXXXX,  PKC_CUT, PKC_UNDO, PKC_COPY, PKC_PSTE,  XXXXXXX,  KC_LBRC,  KC_RBRC,  XXXXXXX,  XXXXXXX,  KC_BSLS,
       XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  _______, _______,     KC_NO,  _______,  KC_HOME,  KC_PGDN,  KC_PGUP,   KC_END
    ),

  [_RAISE] = LAYOUT_planck_grid(
       XXXXXXX,  XXXXXXX,   PKC_UH,   PKC_UU,  XXXXXXX,  _______,  XXXXXXX,   PKC_AE,   PKC_OE,   PKC_UE,  XXXXXXX,  KC_UNDS,
       XXXXXXX,   PKC_II,   PKC_AA,   PKC_EE,   PKC_EH,  _______,  XXXXXXX,   PKC_SH,   PKC_CH,   PKC_ZH,     KC_Q,  KC_PLUS,
      PKC_SHFT,  XXXXXXX,  XXXXXXX,  KC_LPRN,  KC_RPRN,  _______,  XXXXXXX,  KC_LCBR,  KC_RCBR,  XXXXXXX,  XXXXXXX,  KC_PIPE,
       XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  _______,  _______,    KC_NO,  _______, KC_MPLY,  KC_VOLD,  KC_VOLU,  KC_MNXT
    ),

  [_ADJUST] = LAYOUT_planck_grid(
       XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,TOGGLE_LAYER_COLOR,RGB_TOG,RGB_VAI,RGB_VAD,LED_LEVEL,XXXXXXX,
       XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  RGB_MOD,  RGB_HUI,  RGB_HUD,  XXXXXXX,    RESET,
       XXXXXXX,   QWERTY,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX, PAULEMAK,  XXXXXXX,  XXXXXXX,
       XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX, PKC_OFFA,    KC_NO,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX
    ),

  [_FN] = LAYOUT_planck_grid(
       XXXXXXX,    KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,   KC_F10,  XXXXXXX,
       XXXXXXX,   KC_F11,   KC_F12,   KC_F13,   KC_F14,   KC_F15,   KC_F16,   KC_F17,   KC_F18,   KC_F19,   KC_F20,  XXXXXXX,
       XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
       _______,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  _______,    KC_NO,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX
    ),


};


extern bool g_suspend_state;
extern rgb_config_t rgb_matrix_config;
bool disable_layer_color = 0;

void keyboard_post_init_user(void) {
  rgb_matrix_enable();
}

const uint8_t PROGMEM ledmap[][DRIVER_LED_TOTAL][3] = {
    [_BASE] = { 
      CLR_SYMB, CLR_ALPH, CLR_ALPH, CLR_ALPH, CLR_ALPH, CLR_NAVI, CLR_NAVI, CLR_ALPH, CLR_ALPH, CLR_ALPH, CLR_ALPH, CLR_SYMB,
      CLR_SYMB, CLR_ALPH, CLR_ALPH, CLR_ALPH, CLR_ALPH, CLR_NAVI, CLR_ALPH, CLR_ALPH, CLR_ALPH, CLR_ALPH, CLR_ALPH, CLR_SYMB, 
      CLR_MODS, CLR_ALPH, CLR_ALPH, CLR_ALPH, CLR_ALPH, CLR_NAVI, CLR_ALPH, CLR_ALPH, CLR_ALPH, CLR_ALPH, CLR_ALPH, CLR_SYMB,
      CLR_MCRO, CLR_MODS, CLR_MODS, CLR_MODS, CLR_MCRO,      CLR_____     , CLR_MCRO, CLR_NAVI, CLR_NAVI, CLR_NAVI, CLR_NAVI 
    },

    [_QWERTY] = { 
      CLR_NAVI, CLR_ALPH, CLR_ALPH, CLR_ALPH, CLR_ALPH, CLR_ALPH, CLR_ALPH, CLR_ALPH, CLR_ALPH, CLR_ALPH, CLR_ALPH, CLR_NAVI, 
      CLR_NAVI, CLR_ALPH, CLR_ALPH, CLR_ALPH, CLR_ALPH, CLR_ALPH, CLR_ALPH, CLR_ALPH, CLR_ALPH, CLR_ALPH, CLR_SYMB, CLR_SYMB, 
      CLR_MODS, CLR_ALPH, CLR_ALPH, CLR_ALPH, CLR_ALPH, CLR_ALPH, CLR_ALPH, CLR_ALPH, CLR_SYMB, CLR_SYMB, CLR_SYMB, CLR_NAVI, 
      CLR_MCRO, CLR_MODS, CLR_MODS, CLR_MODS, CLR_MCRO,      CLR_____     , CLR_MCRO, CLR_NAVI, CLR_NAVI, CLR_NAVI, CLR_NAVI 
    },

    [_LOWER] = { 
      CLR_SYMB, CLR_ALPH, CLR_ALPH, CLR_ALPH, CLR_ALPH, CLR_ALPH, CLR_ALPH, CLR_ALPH, CLR_ALPH, CLR_ALPH, CLR_ALPH, CLR_SYMB,
      CLR_MODS, CLR_MODS, CLR_MODS, CLR_MODS, CLR_MODS, CLR_MODS, CLR_____, CLR_NAVI, CLR_NAVI, CLR_NAVI, CLR_NAVI, CLR_SYMB, 
      CLR_____, CLR_____, CLR_MCRO, CLR_MCRO, CLR_MCRO, CLR_MCRO, CLR_____, CLR_SYMB, CLR_SYMB, CLR_____, CLR_____, CLR_SYMB, 
      CLR_____, CLR_____, CLR_____, CLR_____, CLR_____,      CLR_____     , CLR_____, CLR_NAVI, CLR_NAVI, CLR_NAVI, CLR_NAVI
    },

    [_RAISE] = {
      CLR_____, CLR_____, CLR_ALPH, CLR_ALPH, CLR_____, CLR_NAVI, CLR_____, CLR_ALPH, CLR_ALPH, CLR_ALPH, CLR_____, CLR_SYMB, 
      CLR_____, CLR_ALPH, CLR_ALPH, CLR_ALPH, CLR_ALPH, CLR_NAVI, CLR_____, CLR_ALPH, CLR_ALPH, CLR_ALPH, CLR_ALPH, CLR_SYMB, 
      CLR_MODS, CLR_____, CLR_____, CLR_SYMB, CLR_SYMB, CLR_NAVI, CLR_____, CLR_SYMB, CLR_SYMB, CLR_____, CLR_____, CLR_SYMB, 
      CLR_____, CLR_____, CLR_____, CLR_____, CLR_____,      CLR_____     , CLR_____, CLR_MCRO, CLR_MCRO, CLR_MCRO, CLR_MCRO
    },

    [_ADJUST] = { 
      CLR_____, CLR_____, CLR_____, CLR_____, CLR_____, CLR_____, CLR_MCRO, CLR_MCRO, CLR_MCRO, CLR_MCRO, CLR_MCRO, CLR_____, 
      CLR_____, CLR_____, CLR_____, CLR_____, CLR_____, CLR_____, CLR_____, CLR_MCRO, CLR_MCRO, CLR_MCRO, CLR_____, CLR_SYMB, 
      CLR_____, CLR_MODS, CLR_____, CLR_____, CLR_____, CLR_____, CLR_____, CLR_____, CLR_____, CLR_MODS, CLR_____, CLR_____, 
      CLR_____, CLR_____, CLR_____, CLR_____, CLR_____,      CLR_____     , CLR_____, CLR_____, CLR_____, CLR_____, CLR_____
    },

    [_FN] = { 
      CLR_____, CLR_SYMB, CLR_SYMB, CLR_SYMB, CLR_SYMB, CLR_SYMB, CLR_SYMB, CLR_SYMB, CLR_SYMB, CLR_SYMB, CLR_SYMB, CLR_____, 
      CLR_____, CLR_SYMB, CLR_SYMB, CLR_SYMB, CLR_SYMB, CLR_SYMB, CLR_SYMB, CLR_SYMB, CLR_SYMB, CLR_SYMB, CLR_SYMB, CLR_____, 
      CLR_____, CLR_____, CLR_____, CLR_____, CLR_____, CLR_____, CLR_____, CLR_____, CLR_____, CLR_____, CLR_____, CLR_____, 
      CLR_____, CLR_____, CLR_____, CLR_____, CLR_____,      CLR_____     , CLR_____, CLR_____, CLR_____, CLR_____, CLR_____
    },

};

void set_layer_color(int layer) {
  for (int i = 0; i < DRIVER_LED_TOTAL; i++) {
    HSV hsv = {
      .h = pgm_read_byte(&ledmap[layer][i][0]),
      .s = pgm_read_byte(&ledmap[layer][i][1]),
      .v = pgm_read_byte(&ledmap[layer][i][2]),
    };
    if (!hsv.h && !hsv.s && !hsv.v) {
        rgb_matrix_set_color( i, 0, 0, 0 );
    } else {
        RGB rgb = hsv_to_rgb( hsv );
        float f = (float)rgb_matrix_config.hsv.v / UINT8_MAX;
        rgb_matrix_set_color( i, f * rgb.r, f * rgb.g, f * rgb.b );
    }
  }
}

void rgb_matrix_indicators_user(void) {
  if (g_suspend_state || keyboard_config.disable_layer_led) { return; }
  switch (biton32(layer_state)) {
    case _QWERTY:
      set_layer_color(_QWERTY);
      break;
    case _BASE:
      set_layer_color(_BASE);
      break;
    case _LOWER:
      set_layer_color(_LOWER);
      break;
    case _RAISE:
      set_layer_color(_RAISE);
      break;
    case _ADJUST:
      set_layer_color(_ADJUST);
      break;
    case _FN:
      set_layer_color(_FN);
      break;
   default:
    if (rgb_matrix_get_flags() == LED_FLAG_NONE)
      rgb_matrix_set_color_all(0, 0, 0);
    break;
  }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
          PLAY_SONG(qwerty_song);
          layer_on(_QWERTY);
      }
      return false;
      break;
    case PAULEMAK:
      if (record->event.pressed) {
          PLAY_SONG(paulemak_song);
          layer_off(_QWERTY);
      }
      return false;
      break;
    case PKC_QU:
      if (record->event.pressed) {
        register_code(KC_Q);
        register_code(KC_U);
      } else {
        unregister_code(KC_Q);
        unregister_code(KC_U);
      }
      return false;
      break;

    case PKC_OFFA:
      if (record->event.pressed) {
        layer_off(_RAISE);
        layer_off(_LOWER);
      }
      return false;
      break;
  }
  return true;
}

uint16_t get_tapping_term(uint16_t keycode) {
  switch (keycode) {
    case LOWER:
    case RAISE:
      return 0;
    default:
      return TAPPING_TERM;
  }
}

bool muse_mode = false;
uint8_t last_muse_note = 0;
uint16_t muse_counter = 0;
uint8_t muse_offset = 70;
uint16_t muse_tempo = 50;

void matrix_scan_user(void) {
#ifdef AUDIO_ENABLE
    if (muse_mode) {
        if (muse_counter == 0) {
            uint8_t muse_note = muse_offset + SCALE[muse_clock_pulse()];
            if (muse_note != last_muse_note) {
                stop_note(compute_freq_for_midi_note(last_muse_note));
                play_note(compute_freq_for_midi_note(muse_note), 0xF);
                last_muse_note = muse_note;
            }
        }
        muse_counter = (muse_counter + 1) % muse_tempo;
    }
#endif
}

bool music_mask_user(uint16_t keycode) {
    switch (keycode) {
    case RAISE:
    case LOWER:
        return false;
    default:
        return true;
    }
}

uint32_t layer_state_set_user(uint32_t state) {
    return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

void eeconfig_init_user(void) {
    set_unicode_input_mode(UC_OSX);
}
