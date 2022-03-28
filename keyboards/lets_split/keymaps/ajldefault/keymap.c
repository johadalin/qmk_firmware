#include QMK_KEYBOARD_H

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _QWERTY 0
#define _LOWER 1
#define _RAISE 2
#define _ADJUST 16
//#define _LAYER1 1
//#define _LAYER2 2
//#define _LAYER3 3
#define _LAYER4 4


/*
 * #define _LOWER 1
 * #define _RAISE 2
 * #define _ADJUST 16
*/

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  ADJUST,
  LAYER4,
//  LAYER1,
//  LAYER2,
//  LAYER3,
//  LAYER4,
};
#define NUMPAD MO(_LOWER)
#define CMD    MO(_RAISE)
#define F_PAD  MO(_ADJUST)
#define KEEB   MO(_LAYER4)

//#define NUMPAD MO(_LAYER1)
//#define CMD    MO(_LAYER2)
//#define F_PAD  MO(_LAYER3)
//#define KEEB   MO(_LAYER4)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_QWERTY] = LAYOUT_ortho_4x12(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐        ┌────────┬────────┬────────┬────────┬────────┬────────┐
      KC_ESC,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,             KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
  //├────────┼────────┼────────┼────────┼────────┼────────┤        ├────────┼────────┼────────┼────────┼────────┼────────┤
      KC_LSFT, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,             KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
  //├────────┼────────┼────────┼────────┼────────┼────────┤        ├────────┼────────┼────────┼────────┼────────┼────────┤
      KC_LCTL, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,             KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
  //├────────┼────────┼────────┼────────┼────────┼────────┤        ├────────┼────────┼────────┼────────┼────────┼────────┤
      F_PAD,   KC_TAB,  KC_LALT, KC_LGUI, MO(1),   KC_SPC,           KC_ENT,  MO(2),   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
  //└────────┴────────┴────────┴────────┴────────┴────────┘        └────────┴────────┴────────┴────────┴────────┴────────┘
),

[_LOWER] = LAYOUT_ortho_4x12(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐        ┌────────┬────────┬────────┬────────┬────────┬────────┐
      KC_ESC,  KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,            KC_NLCK, KC_P7,   KC_P8,   KC_P9,   KC_MINS, KC_BSPC,
  //├────────┼────────┼────────┼────────┼────────┼────────┤        ├────────┼────────┼────────┼────────┼────────┼────────┤
      KC_LSFT, KC_NO,   KC_NO,   KC_NO,   KC_PGUP, KC_NO,            KC_PSLS, KC_P4,   KC_P5,   KC_P6,   KC_PPLS, KC_DEL,
  //├────────┼────────┼────────┼────────┼────────┼────────┤        ├────────┼────────┼────────┼────────┼────────┼────────┤
      KC_LCTL, KC_NO,   KC_NO,   KC_NO,   KC_PGDN, KC_NO,            KC_PAST, KC_P1,   KC_P2,   KC_P3,   KC_EQL,  KC_NO,
  //├────────┼────────┼────────┼────────┼────────┼────────┤        ├────────┼────────┼────────┼────────┼────────┼────────┤
      KEEB,    KC_NO,   KC_NO,   KC_NO,   KC_TRNS, KC_NO,             KC_ENT, KEEB,    KC_P0,   KC_PDOT, KC_PENT, KC_NO
  //└────────┴────────┴────────┴────────┴────────┴────────┘        └────────┴────────┴────────┴────────┴────────┴────────┘
),

[_RAISE] = LAYOUT_ortho_4x12(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐        ┌────────┬────────┬────────┬────────┬────────┬────────┐
      KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,            KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
  //├────────┼────────┼────────┼────────┼────────┼────────┤        ├────────┼────────┼────────┼────────┼────────┼────────┤
 LSFT(KC_TAB), KC_TAB, KC_MPLY, KC_VOLU, KC_PGUP,  KC_NO,            KC_NO,   KC_BTN1, KC_BTN2, KC_BTN3, KC_NO,   KC_NO,
  //├────────┼────────┼────────┼────────┼────────┼────────┤        ├────────┼────────┼────────┼────────┼────────┼────────┤
      KC_NO,   KC_NO,   KC_MUTE, KC_VOLD, KC_PGDN, KC_NO,            KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
  //├────────┼────────┼────────┼────────┼────────┼────────┤        ├────────┼────────┼────────┼────────┼────────┼────────┤
      KC_TRNS, KC_NO,   KC_NO,   KC_LCTL, KEEB,    KC_LALT,          KC_NO,   KC_TRNS, KC_NO,   KC_NO,   KC_NO,   KC_NO
  //└────────┴────────┴────────┴────────┴────────┴────────┘        └────────┴────────┴────────┴────────┴────────┴────────┘
),

[_LAYER4] = LAYOUT_ortho_4x12(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐        ┌────────┬────────┬────────┬────────┬────────┬────────┐
      KC_NO,   KC_NO,   KC_NO,   KC_UP,   KC_NO,   KC_NO,            KC_INS,  KC_F7,   KC_F8,   KC_F9,   KC_HOME, KC_NO,
  //├────────┼────────┼────────┼────────┼────────┼────────┤        ├────────┼────────┼────────┼────────┼────────┼────────┤
      KC_NO,   KC_NO,   KC_LEFT, KC_DOWN, KC_RGHT, KC_PGUP,     LSFT(KC_INS), KC_F4,   KC_F5,   KC_F6,   KC_END, KC_NO,
  //├────────┼────────┼────────┼────────┼────────┼────────┤        ├────────┼────────┼────────┼────────┼────────┼────────┤
      KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_PGDN,          KC_NO,   KC_F1,   KC_F2,   KC_F3,   KC_NO,   KC_NO,
  //├────────┼────────┼────────┼────────┼────────┼────────┤        ├────────┼────────┼────────┼────────┼────────┼────────┤
      KC_TRNS, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,            KC_PSCR, KC_F10,  KC_F11,  KC_F12,  KC_NO,   KC_NO
  //└────────┴────────┴────────┴────────┴────────┴────────┘        └────────┴────────┴────────┴────────┴────────┴────────┘
),

[_ADJUST] = LAYOUT_ortho_4x12(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐        ┌────────┬────────┬────────┬────────┬────────┬────────┐
      RESET,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,            KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
  //├────────┼────────┼────────┼────────┼────────┼────────┤        ├────────┼────────┼────────┼────────┼────────┼────────┤
      KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,            KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
  //├────────┼────────┼────────┼────────┼────────┼────────┤        ├────────┼────────┼────────┼────────┼────────┼────────┤
      KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,            KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
  //├────────┼────────┼────────┼────────┼────────┼────────┤        ├────────┼────────┼────────┼────────┼────────┼────────┤
      KC_TRNS, KC_NO,   KC_NO,   KC_NO,   KC_TRNS, KC_NO,            KC_NO,   KC_TRNS, KC_NO,   KC_NO,   KC_NO,   KC_NO
  //└────────┴────────┴────────┴────────┴────────┴────────┘        └────────┴────────┴────────┴────────┴────────┴────────┘
)


/* Qwerty
 * ,------------------------------------------  ------------------------------------------.
 * | Esc  |   Q  |   W  |   E  |   R  |   T  |  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+-------  -------+------+------+------+------+------|
 * | Tab  |   A  |   S  |   D  |   F  |   G  |  |   H  |   J  |   K  |   L  |   ;  |  "   |
 * |------+------+------+------+------+------|  |------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |  |   N  |   M  |   ,  |   .  |   /  |Enter |
 * |------+------+------+------+------+------+  +------+------+------+------+------+------|
 * |Adjust| Ctrl | Alt  | GUI  |Lower |Space |  |Enter |Raise | Left | Down |  Up  |Right |
 * `------------------------------------------  ------------------------------------------'
 *
[_QWERTY] = LAYOUT_ortho_4x12(
   KC_ESC,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
   KC_TAB,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
   KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT ,
   ADJUST,  KC_LCTL, KC_LALT, KC_LGUI, LOWER,   KC_ENT,  KC_SPC,  RAISE,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
),

* Lower
 * ,------------------------------------------  ------------------------------------------.
 * |   ~  |   !  |   @  |   #  |   $  |   %  |  |   ^  |   &  |   *  |   (  |   )  | Del  |
 * |------+------+------+------+------+-------  -------+------+------+------+------+------|
 * | Del  |  F1  |  F2  |  F3  |  F4  |  F5  |  |  F6  |   _  |   +  |   {  |   }  |  |   |
 * |------+------+------+------+------+------|  |------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  |  F12 |ISO ~ |ISO | |      |      |      |
 * |------+------+------+------+------+------+  +------+------+------+------+------+------|
 * |      |      |      |      |      |         |      |      | Next | Vol- | Vol+ | Play |
 * `------------------------------------------  ------------------------------------------'
 *
[_LOWER] = LAYOUT_ortho_4x12(
  KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_DEL,
  KC_DEL,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE,
  _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,S(KC_NUHS),S(KC_NUBS),_______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY
),

* Raise
 * ,------------------------------------------  ------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |  |   6  |   7  |   8  |   9  |   0  | Del  |
 * |------+------+------+------+------+-------  -------+------+------+------+------+------|
 * | Del  |  F1  |  F2  |  F3  |  F4  |  F5  |  |  F6  |   -  |   =  |   [  |   ]  |  \   |
 * |------+------+------+------+------+------|  |------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  |  F12 |ISO # |ISO / |      |      |      |
 * |------+------+------+------+------+------+  +------+------+------+------+------+------|
 * |      |      |      |      |      |         |      |      | Next | Vol- | Vol+ | Play |
 * `------------------------------------------  ------------------------------------------'
 *
[_RAISE] = LAYOUT_ortho_4x12(
  KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_DEL,
  KC_DEL,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS,
  _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_NUHS, KC_NUBS, _______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY
),

* Adjust (Lower + Raise)
 * ,------------------------------------------  ------------------------------------------.
 * |      | Reset|      |      |      |      |  |      |      |      |      |      |  Del |
 * |------+------+------+------+------+-------  -------+------+------+------+------+------|
 * |      |      |      |Aud on|Audoff|AGnorm|  |AGswap|Qwerty|      |      |      |      |
 * |------+------+------+------+------+------|  |------+------+------+------+------+------|
 * |      |      |      |      |      |      |  |      |      |      |      |      |      |
 * |------+------+------+------+------+------+  +------+------+------+------+------+------|
 * |      |      |      |      |      |         |      |      |      |      |      |      |
 * `------------------------------------------  ------------------------------------------'
 *
[_ADJUST] =  LAYOUT_ortho_4x12(
  _______, RESET,   _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_DEL,
  _______, _______, _______, AU_ON,   AU_OFF,  AG_NORM, AG_SWAP, QWERTY,  _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
)
*/

};

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_QWERTY);
      }
      return false;
  }
  return true;
}
