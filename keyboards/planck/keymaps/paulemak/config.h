#pragma once

#ifdef AUDIO_ENABLE
    #define STARTUP_SONG SONG(PLANCK_SOUND)
    // #define STARTUP_SONG SONG(NO_SOUND)

    #define DEFAULT_LAYER_SONGS { SONG(QWERTY_SOUND), SONG(COLEMAK_SOUND) }
#endif

#define MIDI_BASIC

#define ENCODER_RESOLUTION 4

/*
  Set any config.h overrides for your specific keymap here.
  See config.h options at https://docs.qmk.fm/#/config_options?id=the-configh-file
*/
#define ONESHOT_TAP_TOGGLE 3
#define ONESHOT_TIMEOUT 2000

#define TAPPING_TERM 175
#define TAPPING_TERM_PER_KEY

#undef RGBLIGHT_BRI_STEP
#define RGBLIGHT_BRI_STEP 24

#define RGB_DISABLE_WHEN_USB_SUSPENDED true


#define ORYX_CONFIGURATOR
#define PLANCK_EZ_LED_LOWER 2
#define PLANCK_EZ_LED_RAISE 3
#define PLANCK_EZ_LED_ADJUST 4

