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
#define _NUMPAD 3
#define _ADJUST 16

#define _______ KC_TRNS
#define XXXXXXX KC_NO

#define NEXTWKS ACTION_MODS_KEY(MOD_LCTL, KC_RGHT)
#define PREVWKS ACTION_MODS_KEY(MOD_LCTL, KC_LEFT)
#define NEXTTAB ACTION_MODS_KEY(MOD_LGUI, KC_RCBR)
#define PREVTAB ACTION_MODS_KEY(MOD_LGUI, KC_LCBR)

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  NUMPAD,
  ADJUST
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------. ,-----------------------------------------.
 * | Tab  |   Q  |   W  |   E  |   R  |   T  | |   Y  |   U  |   I  |   O  |   P  |  \   |
 * |------+------+------+------+------+------| |------+------+------+------+------+------|
 * | Ctrl |   A  |   S  |   D  |   F  |   G  | |   H  |   J  |   K  |   L  |   ;  |  "   |
 * |------+------+------+------+------+------| |------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  | |   N  |   M  |   ,  |   .  |   /  |Shift |
 * |------+------+------+------+------+------| |------+------+------+------+------+------|
 * |Adjust|Lower | Alt  | GUI  | Bksp |Space | |  Esc | Enter|   [  |   ]  |Raise |Numpad|
 * `-----------------------------------------' `-----------------------------------------'
 */
[_QWERTY] = KEYMAP( \
  KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSLS, \
  KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, \
  KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, \
  ADJUST,  LOWER,   KC_LALT, KC_LGUI, KC_BSPC, KC_SPC,  KC_ESC,  KC_ENT,  KC_LBRC, KC_RBRC, RAISE,   NUMPAD \
),

/* Lower
 * ,-----------------------------------------. ,-----------------------------------------.
 * |   ~  |   !  |   @  |   #  |   $  |   %  | |   ^  |   &  |   *  |   (  |   )  | Bksp |
 * |------+------+------+------+------+------| |------+------+------+------+------+------|
 * |      |  F1  |  F2  |  F3  |  F4  |  F5  | |  F6  |   _  |   +  |   {  |   }  | Del  |
 * |------+------+------+------+------+------| |------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 | |  F12 |ISO ~ |ISO | |      |      |      |
 * |------+------+------+------+------+------| |------+------+------+------+------+------|
 * |      |      |      |      |      |      | |      |      |      |      |      |      |
 * `-----------------------------------------' `-----------------------------------------'
 */
[_LOWER] = KEYMAP( \
  KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_BSPC, \
  _______,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_DEL, \
  _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,S(KC_NUHS),S(KC_NUBS),_______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______ \
),

/* Raise
 * ,-----------------------------------------. ,-----------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  | |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+------| |------+------+------+------+------+------|
 * |      |  F1  |  F2  |  F3  |  F4  |  F5  | |  F6  |   -  |   =  |   [  |   ]  | Del  |
 * |------+------+------+------+------+------| |------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 | |  F12 |ISO # |ISO / |      |      |      |
 * |------+------+------+------+------+------| |------+------+------+------+------+------|
 * |      |      |      |      |      |      | |      |      |      |      |      |      |
 * `-----------------------------------------' `-----------------------------------------'
 */
[_RAISE] = KEYMAP( \
  KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC, \
  _______,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_DEL, \
  _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_NUHS, KC_NUBS, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______ \
),

/* Numpad
 * ,-----------------------------------------. ,-----------------------------------------.
 * |      |      |   7  |   8  |   9  |PREVTB| |NEXTTB|      |  Up  |      |      |      |
 * |------+------+------+------+------+------| |------+------+------+------+------+------|
 * |      |      |   4  |   5  |   6  |      | |      | Left | Down |Right |      |      |
 * |------+------+------+------+------+------| |------+------+------+------+------+------|
 * |      |      |   1  |   2  |   3  |      | |      |      |      |      |      |      |
 * |------+------+------+------+------+------| |------+------+------+------+------+------|
 * |      |      |   0  |   ,  |   .  |      | |      |      |      |      |      |      |
 * `-----------------------------------------' `-----------------------------------------'
 */
[_NUMPAD] =  KEYMAP( \
  _______, _______, KC_7,    KC_8,    KC_9,    PREVTAB, NEXTTAB, _______, KC_UP,   _______, _______, _______, \
  _______, _______, KC_4,    KC_5,    KC_6,    _______, _______, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______, \
  _______, _______, KC_1,    KC_2,    KC_3,    _______, _______, _______, _______, _______, _______, _______, \
  _______, _______, KC_0,    KC_COMM, KC_DOT,  _______, _______, _______, _______, _______, _______, _______ \
),


/* Adjust
 * ,-----------------------------------------. ,-----------------------------------------.
 * |RGB on|RGBmod|      | MsUp |      |PREVWK| |NEXTWK|      | MsUp |      |RGB v-|RGB v+|
 * |------+------+------+------+------+------| |------+------+------+------+------+------|
 * |RGB h-|RGB h+|MsLeft|MsDown|MsRght|      | |      |MsLeft|MsDown|MsRght|RGB s-|RGB s+|
 * |------+------+------+------+------+------| |------+------+------+------+------+------|
 * |      |      |      |      |      |      | |      |      |      |      |      |      |
 * |------+------+------+------+------+------| |------+------+------+------+------+------|
 * |      |      |      |      | Lclk | Rclk | | Lclk | Rclk |      |      |      |      |
 * `-----------------------------------------' `-----------------------------------------'
 */
[_ADJUST] =  KEYMAP( \
  RGB_TOG, RGB_MOD, _______, KC_MS_U, _______, PREVWKS, NEXTWKS, _______, KC_MS_U, _______, RGB_VAD, RGB_VAI, \
  RGB_HUD, RGB_HUI, KC_MS_L, KC_MS_D, KC_MS_R, _______, _______, KC_MS_L, KC_MS_D, KC_MS_R, RGB_SAD, RGB_SAI, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, KC_BTN1, KC_BTN2, KC_BTN1, KC_BTN2, _______, _______, _______, _______ \
)


};

const uint16_t PROGMEM fn_actions[] = {
    [1] = ACTION_LAYER_TAP_TOGGLE(_LOWER),  // FN1 - Momentary Layer 1
    [2] = ACTION_LAYER_TAP_TOGGLE(_RAISE),  // FN2 - Momentary Layer 2
    [3] = ACTION_LAYER_TAP_TOGGLE(_NUMPAD), // FN3 - Momentary Layer 3
    [4] = ACTION_LAYER_TAP_TOGGLE(_ADJUST)  // FN3 - Momentary Layer 4
};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
    switch(id) {
        case 0:
            if (record->event.pressed) {
                SEND_STRING ("git pull");
                return MACRO( T(ENT), END );
            }
            break;
        case 1:
            if (record->event.pressed) {
                SEND_STRING ("git push");
                return MACRO( T(ENT), END );
            }
            break;
    }
    return MACRO_NONE;
};

void matrix_init_user(void) {
    rgblight_mode(6);
};

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        persistent_default_layer_set(1UL<<_QWERTY);
        rgblight_mode(6);
      }
      return false;
      break;
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
        rgblight_mode(31);
      } else {
        layer_off(_LOWER);
        rgblight_mode(6);
      }
      return false;
      break;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
        rgblight_mode(32);
      } else {
        layer_off(_RAISE);
        rgblight_mode(6);
      }
      return false;
      break;
    case NUMPAD:
      if (record->event.pressed) {
        layer_on(_NUMPAD);
        rgblight_mode(0);
        rgblight_setrgb(0x00,0xff,0xff);
      } else {
        layer_off(_NUMPAD);
        rgblight_mode(6);
      }
      return false;
      break;
    case ADJUST:
      if (record->event.pressed) {
        layer_on(_ADJUST);
        rgblight_mode(0);
        rgblight_setrgb(0xff,0xff,0x00);
      } else {
        layer_off(_ADJUST);
        rgblight_mode(6);
      }
      return false;
      break;
  }
  return true;
}
