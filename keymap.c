#include "lets_split.h"
#include "action_layer.h"
#include "eeconfig.h"

extern keymap_config_t keymap_config;
extern rgblight_config_t rgblight_config;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _QWERTY 0
#define _LOWER 1
#define _RAISE 2
#define _FUNCT 3
#define _ARROW 4
#define _ADJUST 5
#define _ADMINI 6
#define _FROGLK 7
#define _FROGOP 8
#define _FROGNM 9
#define _FROGSM 10

#define _______ KC_TRNS
#define XXXXXXX KC_NO

#define WINUNDO ACTION_MODS_KEY(MOD_LCTL, KC_Z)
#define WINCUT ACTION_MODS_KEY(MOD_LCTL, KC_X)
#define WINCOPY ACTION_MODS_KEY(MOD_LCTL, KC_C)
#define WINPASTE ACTION_MODS_KEY(MOD_LCTL, KC_V)
#define WINFIND ACTION_MODS_KEY(MOD_LCTL, KC_F)
#define MACUNDO ACTION_MODS_KEY(MOD_LGUI, KC_Z)
#define MACCUT ACTION_MODS_KEY(MOD_LGUI, KC_X)
#define MACCOPY ACTION_MODS_KEY(MOD_LGUI, KC_C)
#define MACPASTE ACTION_MODS_KEY(MOD_LGUI, KC_V)
#define MACFIND ACTION_MODS_KEY(MOD_LGUI, KC_F)
#define ROFI ACTION_MODS_KEY(MOD_LGUI, KC_D)

#define SCR_BR_UP KC_PAUS
#define SCR_BR_DOWN KC_SLCK

// macros
#define SEND_KEYMAP_URI 0
#define MAC_COPY_PASTE 1
#define WIN_COPY_PASTE 2

// TAP DANCE
enum {
    TD_CTL_ROFI = 0
};

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  FUNCT,
  ARROW,
  ADJUST,
  ADMINI,
  FROGLK,
  FROGOP,
  FROGNM,
  FROGSM,
  DYNAMIC_MACRO_RANGE
};

#include "dynamic_macro.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------. ,-----------------------------------------.
 * | Tab  |   Q  |   W  |   E  |   R  |   T  | |   Y  |   U  |   I  |   O  |   P  |  \   |
 * |------+------+------+------+------+------| |------+------+------+------+------+------|
 * |TD_ROF|      |      |      |      |      | |      |      |      |      | Arrow|  '   |
 * | Ctrl |   A  |   S  |   D  |   F  |   G  | |   H  |   J  |   K  |   L  |   ;  | Ctrl |
 * |------+------+------+------+------+------| |------+------+------+------+------+------|
 * |  [   |   Z  |      |      |      |      | |      |      |      |      |   /  |   ]  |
 * | Shift| Raise|   X  |   C  |   V  |   B  | |   N  |   M  |   ,  |   .  | Lower| Shift|
 * |------+------+------+------+------+------| |------+------+------+------+------+------|
 * | Left | Right|      |      |      | BS   | | Esc  |      |      |      | Down |  Up  |
 * |Adjust| Func | Alt  | GUI  |Space | Lower| | Raise| Enter|   (  |   )  | Func | Arrow|
 * `-----------------------------------------' `-----------------------------------------'
 */
[_QWERTY] = LAYOUT( \
  KC_TAB,  KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_BSLS, \
  TD(TD_CTL_ROFI), KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, LT(_ARROW, KC_SCLN), CTL_T(KC_QUOT), \
  SFT_T(KC_LBRC), LT(_RAISE, KC_Z), KC_X, KC_C, KC_V, KC_B, \
  KC_N, KC_M, KC_COMM, KC_DOT, LT(_LOWER, KC_SLSH), SFT_T(KC_RBRC), \
  LT(_ADJUST, KC_LEFT), LT(_FUNCT, KC_RGHT), KC_LALT, KC_LGUI, KC_SPC, LT(_LOWER, KC_BSPC), \
  LT(_RAISE, KC_ESC), KC_ENT, KC_LPRN, KC_RPRN, LT(_FUNCT, KC_DOWN), LT(_ARROW, KC_UP) \
),

/* Lower
 * ,-----------------------------------------. ,-----------------------------------------.
 * |   ~  |   !  |   @  |   #  |   $  |   %  | |   ^  |   &  |   *  |   (  |   )  | Bksp |
 * |------+------+------+------+------+------| |------+------+------+------+------+------|
 * |      |      |      |      |W FIND|      | |      |   _  |   +  |   {  |   }  | Del  |
 * |------+------+------+------+------+------| |------+------+------+------+------+------|
 * |      |W UNDO|W CUT |W COPY|WPASTE|      | |      |      |      |      |XXXXXX|      |
 * |------+------+------+------+------+------| |------+------+------+------+------+------|
 * |      |      |      |      |      |XXXXXX| |      |      |      |      |      |      |
 * `-----------------------------------------' `-----------------------------------------'
 */
[_LOWER] = LAYOUT( \
  KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_BSPC, \
  _______, _______, _______, _______, WINFIND, _______, _______, KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_DEL, \
  _______, WINUNDO, WINCUT,  WINCOPY, WINPASTE, _______, _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______ \
),

/* Raise
 * ,-----------------------------------------. ,-----------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  | |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+------| |------+------+------+------+------+------|
 * |      |      |      |      |W FIND|      | |      |   -  |   =  |   [  |   ]  | Del  |
 * |------+------+------+------+------+------| |------+------+------+------+------+------|
 * |      |XXXXXX|W CUT |W COPY|WPASTE|      | |      |      |      |      |      |      |
 * |------+------+------+------+------+------| |------+------+------+------+------+------|
 * |      |      |      |      |      |      | |XXXXXX|      |      |      |      |      |
 * `-----------------------------------------' `-----------------------------------------'
 */
[_RAISE] = LAYOUT( \
  KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC, \
  _______, _______, _______, _______, WINFIND, _______, _______, KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_DEL, \
  _______, _______, WINCUT,  WINCOPY, WINPASTE, _______, _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______ \
),

/* Function
 * ,-----------------------------------------. ,-----------------------------------------.
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  | |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |
 * |------+------+------+------+------+------| |------+------+------+------+------+------|
 * |      |      |M C/P |M COPY|MPASTE| ROFI | |      |DMPLY1|DMREC1|DMSTOP|Vol + |Vol mt|
 * |------+------+------+------+------+------| |------+------+------+------+------+------|
 * |      |      |W C/P |W COPY|WPASTE|      | |      |DMPLY2|DMREC2|KEYMAP|Vol - |      |
 * |------+------+------+------+------+------| |------+------+------+------+------+------|
 * |      |XXXXXX|      |      |      |      | |      |      |      |      |XXXXXX|      |
 * `-----------------------------------------' `-----------------------------------------'
 */
[_FUNCT] = LAYOUT( \
  KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, \
  _______, _______, M(WIN_COPY_PASTE), WINCOPY, WINPASTE, ROFI, \
  _______, DYN_MACRO_PLAY1, DYN_REC_START1, DYN_REC_STOP, KC_VOLU, KC_MUTE, \
  _______, _______, M(MAC_COPY_PASTE), MACCOPY, MACPASTE, _______, \
  _______, DYN_MACRO_PLAY2, DYN_REC_START2, M(SEND_KEYMAP_URI), KC_VOLD, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______ \
),


/* Arrow
 * ,-----------------------------------------. ,-----------------------------------------.
 * |      |      |      |  Up  |      |      | |      |      |      |      |      |      |
 * |------+------+------+------+------+------| |------+------+------+------+------+------|
 * |      |      | Left | Down | Right|      | | Left | Down |  Up  |Right |XXXXXX|      |
 * |------+------+------+------+------+------| |------+------+------+------+------+------|
 * |      |      |      |      |      |      | |      |      |      |      |      |      |
 * |------+------+------+------+------+------| |------+------+------+------+------+------|
 * |ADMINI|      |      |      |      |      | |      |      |      |      |FROGLK|XXXXXX|
 * `-----------------------------------------' `-----------------------------------------'
 */
[_ARROW] =  LAYOUT( \
  _______, _______, _______, KC_UP, _______, _______, _______, _______, _______, _______, _______, _______, \
  _______, _______, KC_LEFT, KC_DOWN, KC_RGHT, _______, KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
  ADMINI, _______, _______, _______, _______, _______, _______, _______, _______, _______, FROGLK, _______ \
),


/* Adjust
 * ,-----------------------------------------. ,-----------------------------------------.
 * |      |      | WhDn | MsUp | WhUp |      | |      | WhDn | MsUp | WhUp |      |      |
 * |------+------+------+------+------+------| |------+------+------+------+------+------|
 * |      |      |MsLeft|MsDown|MsRght|      | |      |MsLeft|MsDown|MsRght|      |      |
 * |------+------+------+------+------+------| |------+------+------+------+------+------|
 * |      |      |      |      |      |      | |      |      |      |      |      |      |
 * |------+------+------+------+------+------| |------+------+------+------+------+------|
 * |XXXXXX|FROGLK|      |      | Lclk | Rclk | | Lclk | Rclk |      |      |      |ADMINI|
 * `-----------------------------------------' `-----------------------------------------'
 */
[_ADJUST] =  LAYOUT( \
  _______, _______, KC_WH_D, KC_MS_U, KC_WH_U, _______, _______, KC_WH_D, KC_MS_U, KC_WH_U, _______, _______, \
  _______, _______, KC_MS_L, KC_MS_D, KC_MS_R, _______, _______, KC_MS_L, KC_MS_D, KC_MS_R, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
  _______, FROGLK, _______, _______, KC_BTN1, KC_BTN2, KC_BTN1, KC_BTN2, _______, _______, _______, ADMINI \
),

/* administrator
 * ,-----------------------------------------. ,-----------------------------------------.
 * |RESET |      |      |      |      |      | |      |      |      |      |      |POWER |
 * |------+------+------+------+------+------| |------+------+------+------+------+------|
 * |RGB on|RGBmod|      |      |      |      | |      |      |      |      |RGB v-|RGB v+|
 * |------+------+------+------+------+------| |------+------+------+------+------+------|
 * |RGB h-|RGB h+|      |      |      |      | |      |      |      |      |RGB s-|RGB s+|
 * |------+------+------+------+------+------| |------+------+------+------+------+------|
 * |XXXXXX|      |      |      |      |      | |      |      |      |      |      |XXXXXX|
 * `-----------------------------------------' `-----------------------------------------'
 */
[_ADMINI] =  LAYOUT( \
  RESET, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_POWER, \
  RGB_TOG, RGB_MOD, _______, _______, _______, _______, _______, _______, _______, _______, RGB_VAD, RGB_VAI, \
  RGB_HUD, RGB_HUI, _______, _______, _______, _______, _______, _______, _______, _______, RGB_SAD, RGB_SAI, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______ \
),


/* Frogpad-like
 * ,-----------------------------------------. ,-----------------------------------------.
 * |      |      |      |      |      |      | |      |      |      |      |      |      |
 * |   P  |   W  |   R  |   A  |   F  |QWERTY| |QWERTY|   F  |   A  |   R  |   W  |   P  |
 * |------+------+------+------+------+------| |------+------+------+------+------+------|
 * |      |      |      |      |      |      | |      |      |      |      |      |      |
 * |   D  |   T  |   H  |   E  |   O  |  Esc | |  Esc |   O  |   E  |   H  |   T  |   D  |
 * |------+------+------+------+------+------| |------+------+------+------+------+------|
 * |      |      |      |      |      |      | |      |      |      |      |      |      |
 * |   Y  |   S  |   N  |   I  |   U  | Shift| | Shift|   U  |   I  |   N  |   S  |   Y  |
 * |------+------+------+------+------+------| |------+------+------+------+------+------|
 * |      |      |      |  SYM |  NUM |  OPT | |  OPT |  NUM |  SYM |      |      |      |
 * | Ctrl |  Alt | GUI  | Enter| Space|  BS  | |  BS  | Space| Enter|  GUI |  Alt | Ctrl |
 * `-----------------------------------------' `-----------------------------------------'
 */
[_FROGLK] = LAYOUT( \
  KC_P, KC_W, KC_R, KC_A, KC_F, QWERTY, QWERTY, KC_F, KC_A, KC_R, KC_W, KC_P, \
  KC_D, KC_T, KC_H, KC_E, KC_O, KC_ESC, KC_ESC, KC_O, KC_E, KC_H, KC_T, KC_D, \
  KC_Y, KC_S, KC_N, KC_I, KC_U, KC_LSFT, KC_LSFT, KC_U, KC_I, KC_N, KC_S, KC_Y, \
  KC_LCTL, KC_LALT, KC_LGUI, LT(_FROGSM, KC_ENT), LT(_FROGNM, KC_SPC), LT(_FROGOP, KC_BSPC), \
  LT(_FROGOP, KC_BSPC), LT(_FROGNM, KC_SPC), LT(_FROGSM, KC_ENT), KC_LGUI, KC_LALT, KC_LCTL \
),

/* Frogpad-opt
 * ,-----------------------------------------. ,-----------------------------------------.
 * |   J  |   M  |   B  |   '  |  Tab |   ,  | |   ,  |  Tab |   '  |   B  |   M  |   J  |
 * |------+------+------+------+------+------| |------+------+------+------+------+------|
 * |   V  |   C  |   L  |   Z  |   Q  |   .  | |   .  |   Q  |   Z  |   L  |   C  |   V  |
 * |------+------+------+------+------+------| |------+------+------+------+------+------|
 * |   X  |   G  |   K  |   -  |  Del |      | |      |  Del |   -  |   K  |   G  |   X  |
 * |------+------+------+------+------+------| |------+------+------+------+------+------|
 * |      |      |      |      |      |XXXXXX| |XXXXXX|      |      |      |      |      |
 * `-----------------------------------------' `-----------------------------------------'
 */
[_FROGOP] = LAYOUT( \
  KC_J, KC_M, KC_B, KC_QUOT, KC_TAB, KC_COMM, KC_COMM, KC_TAB, KC_QUOT, KC_B, KC_M, KC_J, \
  KC_V, KC_C, KC_L, KC_Z, KC_Q, KC_DOT, KC_DOT, KC_Q, KC_Z, KC_L, KC_C, KC_V, \
  KC_X, KC_G, KC_K, KC_MINS, KC_DEL, _______, _______, KC_DEL, KC_MINS, KC_K, KC_G, KC_X, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______ \
),

/* Frogpad-num
 * ,-----------------------------------------. ,-----------------------------------------.
 * |   +  |   7  |   8  |   9  |   [  |   ]  | |   [  |   ]  |   +  |   7  |   8  |   9  |
 * |------+------+------+------+------+------| |------+------+------+------+------+------|
 * |   =  |   4  |   5  |   6  |   (  |   )  | |   (  |   )  |   =  |   4  |   5  |   6  |
 * |------+------+------+------+------+------| |------+------+------+------+------+------|
 * |   0  |   1  |   2  |   3  |   <  |   >  | |   <  |   >  |   0  |   1  |   2  |   3  |
 * |------+------+------+------+------+------| |------+------+------+------+------+------|
 * |      |      |      |      |XXXXXX|      | |      |XXXXXX|      |      |      |      |
 * `-----------------------------------------' `-----------------------------------------'
 */
[_FROGNM] = LAYOUT( \
  KC_PLUS, KC_7, KC_8, KC_9, KC_LBRC, KC_RBRC, KC_LBRC, KC_RBRC, KC_PLUS, KC_7, KC_8, KC_9, \
  KC_EQL, KC_4, KC_5, KC_6, KC_LPRN, KC_RPRN, KC_LPRN, KC_RPRN, KC_EQL, KC_4, KC_5, KC_6, \
  KC_0, KC_1, KC_2, KC_3, KC_LT, KC_GT, KC_LT, KC_GT, KC_0, KC_1, KC_2, KC_3, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______ \
),

/* Frogpad-sym
 * ,-----------------------------------------. ,-----------------------------------------.
 * |   /  |   &  |   *  |   \  |   {  |   }  | |   {  |   }  |   /  |   &  |   *  |   \  |
 * |------+------+------+------+------+------| |------+------+------+------+------+------|
 * |   ?  |   $  |   %  |   ^  |   |  |   `  | |   |  |   `  |   ?  |   $  |   %  |   ^  |
 * |------+------+------+------+------+------| |------+------+------+------+------+------|
 * |   !  |  Up  |   @  |   #  |   _  |   ~  | |   _  |   ~  |   !  |   @  |  Up  |   #  |
 * |------+------+------+------+------+------| |------+------+------+------+------+------|
 * | Left | Down | Right|XXXXXX|      |      | |      |      |XXXXXX| Left | Down | Right|
 * `-----------------------------------------' `-----------------------------------------'
 */
[_FROGSM] = LAYOUT( \
  KC_SLSH, KC_AMPR, KC_ASTR, KC_BSLS, KC_LCBR, KC_RCBR, KC_LCBR, KC_RCBR, KC_SLSH, KC_AMPR, KC_ASTR, KC_BSLS, \
  KC_QUES, KC_DLR,  KC_PERC, KC_CIRC, KC_PIPE, KC_GRV,  KC_PIPE, KC_GRV,  KC_QUES, KC_DLR,  KC_PERC, KC_CIRC, \
  KC_EXLM, KC_UP,   KC_AT,   KC_HASH, KC_UNDS, KC_TILD, KC_UNDS, KC_TILD, KC_EXLM, KC_AT,   KC_UP,   KC_HASH, \
  KC_LEFT, KC_DOWN, KC_RGHT, _______, _______, _______, _______, _______, _______, KC_LEFT, KC_DOWN, KC_RGHT \
)

};

const uint16_t PROGMEM fn_actions[] = {
    [1] = ACTION_LAYER_TAP_TOGGLE(_FUNCT),
    [2] = ACTION_LAYER_TAP_TOGGLE(_ARROW),
    [3] = ACTION_LAYER_TAP_TOGGLE(_ADJUST),
};

static uint16_t start;
const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
    switch(id) {
        case SEND_KEYMAP_URI:
            if (record->event.pressed) {
                SEND_STRING("https://github.com/rinx/qmk_firmware_letssplit_rinx/blob/linux/keymap.c");
            }
            break;
        case MAC_COPY_PASTE:
            if (record->event.pressed) {
                start = timer_read();
            } else {
                if (timer_elapsed(start) >= TAPPING_TERM)
                    return MACRO(D(LGUI), T(C), U(LGUI), END);
                else
                    return MACRO(D(LGUI), T(V), U(LGUI), END);
            }
            break;
        case WIN_COPY_PASTE:
            if (record->event.pressed) {
                start = timer_read();
            } else {
                if (timer_elapsed(start) >= TAPPING_TERM)
                    return MACRO(D(LCTL), T(C), U(LCTL), END);
                else
                    return MACRO(D(LCTL), T(V), U(LCTL), END);
            }
            break;
    }
    return MACRO_NONE;
};

void matrix_init_user(void) {
    rgblight_mode(6);
};

// define variables for reactive RGB
bool TOG_STATUS = false;
int RGB_current_mode;

void matrix_scan_user(void) {

    uint8_t layer = biton32(layer_state);

    switch (layer) {
        case _LOWER:
            if (TOG_STATUS) {
            } else {
                RGB_current_mode = rgblight_config.mode;
                TOG_STATUS = true;
                rgblight_mode(31);
            }
            break;
        case _RAISE:
            if (TOG_STATUS) {
            } else {
                RGB_current_mode = rgblight_config.mode;
                TOG_STATUS = true;
                rgblight_mode(32);
            }
            break;
        case _FUNCT:
            if (TOG_STATUS) {
            } else {
                RGB_current_mode = rgblight_config.mode;
                TOG_STATUS = true;
                // rgblight_mode(0);
            }
            break;
        case _ARROW:
            if (TOG_STATUS) {
            } else {
                RGB_current_mode = rgblight_config.mode;
                TOG_STATUS = true;
                rgblight_mode(15);
            }
            break;
        case _ADJUST:
            if (TOG_STATUS) {
            } else {
                RGB_current_mode = rgblight_config.mode;
                TOG_STATUS = true;
                // rgblight_mode(15);
            }
            break;
        case _ADMINI:
            if (TOG_STATUS) {
            } else {
                RGB_current_mode = rgblight_config.mode;
                TOG_STATUS = true;
                rgblight_mode(20);
            }
            break;
        default:
            TOG_STATUS = false;
            rgblight_mode(RGB_current_mode);
            break;
    }

};

//Tap Dance Definitions
qk_tap_dance_action_t tap_dance_actions[] = {
  [TD_CTL_ROFI] = ACTION_TAP_DANCE_DOUBLE(KC_LCTL, ROFI)
};

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {

  if (!process_record_dynamic_macro(keycode, record)) {
    return false;
  }

  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        persistent_default_layer_set(1UL<<_QWERTY);
      }
      return false;
      break;
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
      } else {
        layer_off(_LOWER);
      }
      return false;
      break;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
      } else {
        layer_off(_RAISE);
      }
      return false;
      break;
    case FUNCT:
      if (record->event.pressed) {
        layer_on(_FUNCT);
      } else {
        layer_off(_FUNCT);
      }
      return false;
      break;
    case ARROW:
      if (record->event.pressed) {
        layer_on(_ARROW);
      } else {
        layer_off(_ARROW);
      }
      return false;
      break;
    case ADJUST:
      if (record->event.pressed) {
        layer_on(_ADJUST);
      } else {
        layer_off(_ADJUST);
      }
      return false;
      break;
    case ADMINI:
      if (record->event.pressed) {
        layer_on(_ADMINI);
      } else {
        layer_off(_ADMINI);
      }
      return false;
      break;
    case FROGLK:
      if (record->event.pressed) {
        persistent_default_layer_set(1UL<<_FROGLK);
      }
      return false;
      break;
    case RGB_MOD:
      #ifdef RGBLIGHT_ENABLE
        if (record->event.pressed) {
          rgblight_mode(RGB_current_mode);
          rgblight_step();
          RGB_current_mode = rgblight_config.mode;
        }
      #endif
      return false;
      break;
  }
  return true;
}
