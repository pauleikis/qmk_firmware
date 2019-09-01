/* Copyright 2015-2017 Jack Humbert
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include QMK_KEYBOARD_H
#include "muse.h"

extern keymap_config_t keymap_config;

enum planck_layers {
  _PAULEMAK,
  _QWERTY,

  _LOWER,
  _RAISE,
  _ADJUST
};

enum planck_keycodes {
  QWERTY = SAFE_RANGE,
  PAULEMAK
};

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)

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
    ZH_C
};


const uint32_t PROGMEM unicode_map[] = {
    // [BANG]  = 0x203D,  // ‽
    // [IRONY] = 0x2E2E,  // ⸮
    // [SNEK]  = 0x1F40D, // 🐍

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
    [ZH_C]  = 0x017d
};

    // case PKC_IA:
    //   if (record->event.pressed) {
    //     SHIFTED ? SEND_STRING(SS_LALT("00c4")) : SEND_STRING(SS_LALT("00e4"));
    //   }
    //   return true;
    //   break;
    // case PKC_IO:
    //   if (record->event.pressed) {
    //     SHIFTED ? SEND_STRING(SS_LALT("00d6")) : SEND_STRING(SS_LALT("00f6"));
    //   }
    //   return true;
    //   break;
    // case PKC_IU:
    //   if (record->event.pressed) {
    //     SHIFTED ? SEND_STRING(SS_LALT("00dc")) : SEND_STRING(SS_LALT("00fc"));
    //   }
    //   return true;
    //   break;

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Esc  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  "   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Brite| Ctrl | Alt  | GUI  |Lower |    Space    |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = LAYOUT_planck_grid(
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
    KC_ESC,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT ,
    KC_HYPR, KC_LCTL, KC_LALT, KC_LGUI, LOWER,   KC_SPC,  KC_SPC,  RAISE,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
),

/* Paulemak
 * ,-----------------------------------------------------------------------------------.
 * |   ,  |   Y  |   O  |   U  |   H  | Bksp | Esc  |   C  |   D  |   B  |   W  |   .  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |   '  |   I  |   A  |   E  |   R  |Enter |   F  |   S  |   T  |   N  |   K  |   ;  |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Q  |   X  |   Z  |   L  | Tab  |   J  |   V  |   M  |   P  |   G  |   /  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      | Ctrl | Alt  | GUI  |Lower |    Space    |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_PAULEMAK] = LAYOUT_planck_grid(
    KC_COMM,    KC_Y,    KC_O,    KC_U,    KC_H, KC_BSPC,  KC_ESC,    KC_C,    KC_D,    KC_B,    KC_W,  KC_DOT,
    KC_QUOT,    KC_I,    KC_A,    KC_E,    KC_R,  KC_ENT,    KC_F,    KC_S,    KC_T,    KC_N,    KC_K, KC_SCLN,
    KC_LSFT,    KC_Q,    KC_X,    KC_Z,    KC_L,  KC_TAB,    KC_J,    KC_V,    KC_M,    KC_P,    KC_G, KC_SLSH,
    KC_HYPR, KC_LCTL, KC_LALT, KC_LGUI,   LOWER,  KC_SPC,  KC_SPC,   RAISE, KC_LEFT, KC_DOWN,   KC_UP, KC_RGHT
),

/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |   ~  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Del  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   _  |   +  |   {  |   }  |  |   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |ISO ~ |ISO | | Home | End  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = LAYOUT_planck_grid(
    KC_TILD, KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_BSPC,
     KC_DEL,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6, KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE,
    _______,   KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,  KC_F12, _______, _______, KC_HOME,  KC_END, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY
),

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |   į  |   ą  |   ę  |   ė  |      |   -  |   š  |   č  |   [  |   ]  |  \   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |   ž  |      |      |      |      |   =  |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Del  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   -  |   =  |   [  |   ]  |  \   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |ISO # |ISO / |Pg Up |Pg Dn |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = LAYOUT_planck_grid(
    KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
    KC_DEL,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS,
    _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_NUHS, KC_NUBS, KC_PGUP, KC_PGDN, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY
),

/* Adjust (Lower + Raise)
 * ,-----------------------------------------------------------------------------------.
 * |      | Reset|      |      |      |      |      |      |      |      |      |  Del |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |Aud on|Audoff|AGnorm|AGswap|Qwerty|Colemk|Dvorak|Plover|      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |Voice-|Voice+|Mus on|Musoff|MIDIon|MIDIof|      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
//  */
// [_ADJUST] = LAYOUT_planck_grid(
//     _______, RESET,   DEBUG,   RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD,  RGB_VAI, RGB_VAD, KC_DEL ,
//     _______, _______, MU_MOD,  AU_ON,   AU_OFF,  AG_NORM, AG_SWAP, QWERTY,  COLEMAK,  DVORAK,  PLOVER,  _______,
//     _______, MUV_DE,  MUV_IN,  MU_ON,   MU_OFF,  MI_ON,   MI_OFF,  TERM_ON, TERM_OFF, _______, _______, _______,
//     _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______, _______
// )

[_ADJUST] = LAYOUT_planck_grid(
    _______,_______,_______,_______,_______,_______,_______,RGB_TOG,RGB_VAI,RGB_VAD,_______,_______, 
    _______,_______,  AU_ON, AU_OFF, AU_TOG,_______,_______,RGB_MOD,RGB_HUI,RGB_HUD,_______,  RESET,
    _______, QWERTY,  MU_ON, MU_OFF, MU_TOG,_______,_______,_______,_______,PAULEMAK,_______,_______,
    _______,_______,_______,_______,_______,_______,KC_NO,_______,_______,_______,_______,_______
)
};

uint32_t layer_state_set_user(uint32_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_QWERTY);
      }
      return false;
      break;
    case PAULEMAK:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_PAULEMAK);
      }
      return false;
      break;
  }
  return true;
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
