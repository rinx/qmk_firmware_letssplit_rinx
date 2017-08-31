#include "lets_split.h"
#include "action_layer.h"
#include "eeconfig.h"

extern keymap_config_t keymap_config;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _QWERTY 0
#define _LOWER 1
#define _RAISE 2
#define _FUNCT 3
#define _NUMPAD 4
#define _ADJUST 5

#define _______ KC_TRNS
#define XXXXXXX KC_NO

#define NEXTWKS ACTION_MODS_KEY(MOD_LCTL, KC_RGHT)
#define PREVWKS ACTION_MODS_KEY(MOD_LCTL, KC_LEFT)
#define NEXTTAB ACTION_MODS_KEY(MOD_LGUI, KC_RCBR)
#define PREVTAB ACTION_MODS_KEY(MOD_LGUI, KC_LCBR)
#define WINCOPY ACTION_MODS_KEY(MOD_LCTL, KC_C)
#define WINPASTE ACTION_MODS_KEY(MOD_LCTL, KC_V)
#define MACCOPY ACTION_MODS_KEY(MOD_LGUI, KC_C)
#define MACPASTE ACTION_MODS_KEY(MOD_LGUI, KC_V)

#define SPTLGHT (KC_SPC | QK_LGUI)
#define MISSIONCTL (KC_UP | QK_LCTL)
#define NEXTAPP (KC_TAB | QK_LGUI)
#define PREVAPP (KC_TAB | QK_LGUI | QK_LSFT)

// macros
#define MAC_COPY_PASTE 0
#define WIN_COPY_PASTE 1

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  FUNCT,
  NUMPAD,
  ADJUST,
  DYNAMIC_MACRO_RANGE
};

#include "dynamic_macro.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------. ,-----------------------------------------.
 * | Tab  |   Q  |   W  |   E  |   R  |   T  | |   Y  |   U  |   I  |   O  |   P  |  \   |
 * |------+------+------+------+------+------| |------+------+------+------+------+------|
 * | Ctrl |   A  |   S  |   D  |   F  |   G  | |   H  |   J  |   K  |   L  |   ;  |  "   |
 * |------+------+------+------+------+------| |------+------+------+------+------+------|
 * |Shft/[|Rais/Z|   X  |   C  |   V  |   B  | |   N  |   M  |   ,  |   .  |Lowr//|Shft/]|
 * |------+------+------+------+------+------| |------+------+------+------+------+------|
 * |SPTLGT|PREVWK|      |      |      | BS   | | Esc  |      |      |      |NEXTWK|MSNCTL| // TODO
 * |Adjust| Func | Alt  | GUI  |Space | Lower| | Raise| Enter|   (  |   )  | Func |Numpad|
 * `-----------------------------------------' `-----------------------------------------'
 */
[_QWERTY] = KEYMAP( \
  KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSLS, \
  KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, \
  SFT_T(KC_LBRC), LT(_RAISE, KC_Z), KC_X, KC_C, KC_V, KC_B, \
  KC_N, KC_M, KC_COMM, KC_DOT, LT(_LOWER, KC_SLSH), SFT_T(KC_RBRC), \
  ADJUST, FUNCT, KC_LALT, KC_LGUI, KC_SPC, LT(_LOWER, KC_BSPC), \
  LT(_RAISE, KC_ESC), KC_ENT, KC_LPRN, KC_RPRN, FUNCT, NUMPAD \
),

/* Lower
 * ,-----------------------------------------. ,-----------------------------------------.
 * |   ~  |   !  |   @  |   #  |   $  |   %  | |   ^  |   &  |   *  |   (  |   )  | Bksp |
 * |------+------+------+------+------+------| |------+------+------+------+------+------|
 * |      |      |      |      |      |      | |      |   _  |   +  |   {  |   }  | Del  |
 * |------+------+------+------+------+------| |------+------+------+------+------+------|
 * |      |      |      |      |      |      | |      |      |      |      |      |      |
 * |------+------+------+------+------+------| |------+------+------+------+------+------|
 * |      |      |      |      |      |      | |      |      |      |      |      |      |
 * `-----------------------------------------' `-----------------------------------------'
 */
[_LOWER] = KEYMAP( \
  KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_BSPC, \
  _______, _______, _______, _______, _______, _______, _______, KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_DEL, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______ \
),

/* Raise
 * ,-----------------------------------------. ,-----------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  | |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+------| |------+------+------+------+------+------|
 * |      |      |      |      |      |      | |      |   -  |   =  |   [  |   ]  | Del  |
 * |------+------+------+------+------+------| |------+------+------+------+------+------|
 * |      |      |      |      |      |      | |      |      |      |      |      |      |
 * |------+------+------+------+------+------| |------+------+------+------+------+------|
 * |      |      |      |      |      |      | |      |      |      |      |      |      |
 * `-----------------------------------------' `-----------------------------------------'
 */
[_RAISE] = KEYMAP( \
  KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC, \
  _______, _______, _______, _______, _______, _______, _______, KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_DEL, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______ \
),

/* Function
 * ,-----------------------------------------. ,-----------------------------------------.
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  | |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |
 * |------+------+------+------+------+------| |------+------+------+------+------+------|
 * |      |      |M C/P |M COPY|MPASTE|      | |      |      |DMPLY1|DMREC1|DMSTOP|      |
 * |------+------+------+------+------+------| |------+------+------+------+------+------|
 * |      |      |W C/P |W COPY|WPASTE|      | |      |      |DMPLY2|DMREC2|      |      |
 * |------+------+------+------+------+------| |------+------+------+------+------+------|
 * |      |      |      |      |      |      | |      |      |      |      |      |      |
 * `-----------------------------------------' `-----------------------------------------'
 */
[_FUNCT] = KEYMAP( \
  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12, \
  _______, _______, M(MAC_COPY_PASTE), MACCOPY, MACPASTE, _______, \
  _______, _______, DYN_MACRO_PLAY1, DYN_REC_START1, DYN_REC_STOP, _______, \
  _______, _______, M(WIN_COPY_PASTE), WINCOPY, WINPASTE, _______, \
  _______, _______, DYN_MACRO_PLAY2, DYN_REC_START2, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______ \
),


/* Numpad
 * ,-----------------------------------------. ,-----------------------------------------.
 * |      |      |   7  |   8  |   9  |      | |      |      |  Up  |      |      |      |
 * |------+------+------+------+------+------| |------+------+------+------+------+------|
 * |      |      |   4  |   5  |   6  |      | |      | Left | Down |Right |      |      |
 * |------+------+------+------+------+------| |------+------+------+------+------+------|
 * |      |      |   1  |   2  |   3  |PREVTB| |NEXTTB|      |      |      |      |      |
 * |------+------+------+------+------+------| |------+------+------+------+------+------|
 * |RESET |      |   0  |   ,  |   .  |      | |      |      |      |      |      |      |
 * `-----------------------------------------' `-----------------------------------------'
 */
[_NUMPAD] =  KEYMAP( \
  _______, _______, KC_7,    KC_8,    KC_9,    _______, _______, _______, KC_UP,   _______, _______, _______, \
  _______, _______, KC_4,    KC_5,    KC_6,    _______, _______, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______, \
  _______, _______, KC_1,    KC_2,    KC_3,    PREVTAB, NEXTTAB, _______, _______, _______, _______, _______, \
  RESET,   _______, KC_0,    KC_COMM, KC_DOT,  _______, _______, _______, _______, _______, _______, _______ \
),


/* Adjust
 * ,-----------------------------------------. ,-----------------------------------------.
 * |RGB on|RGBmod|      | MsUp |      | WhDn | | WhDn |      | MsUp |      |RGB v-|RGB v+|
 * |------+------+------+------+------+------| |------+------+------+------+------+------|
 * |RGB h-|RGB h+|MsLeft|MsDown|MsRght| WhUp | | WhUp |MsLeft|MsDown|MsRght|RGB s-|RGB s+|
 * |------+------+------+------+------+------| |------+------+------+------+------+------|
 * |      |      |      |      |      |PREVWK| |NEXTWK|      |      |      |      |      |
 * |------+------+------+------+------+------| |------+------+------+------+------+------|
 * |      |      |      |      | Lclk | Rclk | | Lclk | Rclk |      |      |      |RESET |
 * `-----------------------------------------' `-----------------------------------------'
 */
[_ADJUST] =  KEYMAP( \
  RGB_TOG, RGB_MOD, _______, KC_MS_U, _______, KC_WH_D, KC_WH_D, _______, KC_MS_U, _______, RGB_VAD, RGB_VAI, \
  RGB_HUD, RGB_HUI, KC_MS_L, KC_MS_D, KC_MS_R, KC_WH_U, KC_WH_U, KC_MS_L, KC_MS_D, KC_MS_R, RGB_SAD, RGB_SAI, \
  _______, _______, _______, _______, _______, PREVWKS, NEXTWKS, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, KC_BTN1, KC_BTN2, KC_BTN1, KC_BTN2, _______, _______, _______, RESET \
)


};

const uint16_t PROGMEM fn_actions[] = {
    [1] = ACTION_LAYER_TAP_TOGGLE(_FUNCT),
    [2] = ACTION_LAYER_TAP_TOGGLE(_NUMPAD),
    [3] = ACTION_LAYER_TAP_TOGGLE(_ADJUST),
};

static uint16_t start;
const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
    switch(id) {
        case MAC_COPY_PASTE:
            if (record->event.pressed) {
                start = timer_read();
            } else {
                if (timer_elapsed(start) >= 150)
                    return MACRO(D(LGUI), T(C), U(LGUI), END);
                else
                    return MACRO(D(LGUI), T(V), U(LGUI), END);
            }
            break;
        case WIN_COPY_PASTE:
            if (record->event.pressed) {
                start = timer_read();
            } else {
                if (timer_elapsed(start) >= 150)
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

void matrix_scan_user(void) {

    uint8_t layer = biton32(layer_state);

    switch (layer) {
        case _LOWER:
            rgblight_mode(31);
            break;
        case _RAISE:
            rgblight_mode(32);
            break;
        case _FUNCT:
            rgblight_mode(0);
            rgblight_setrgb(0xff,0x00,0xff);
            break;
        case _NUMPAD:
            rgblight_mode(0);
            rgblight_setrgb(0x00,0xff,0xff);
            break;
        case _ADJUST:
            rgblight_mode(0);
            rgblight_setrgb(0xff,0xff,0x00);
            break;
        default:
            rgblight_mode(6);
            break;
    }

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
    case NUMPAD:
      if (record->event.pressed) {
        layer_on(_NUMPAD);
      } else {
        layer_off(_NUMPAD);
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
  }
  return true;
}
