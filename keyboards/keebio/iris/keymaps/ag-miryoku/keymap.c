#include QMK_KEYBOARD_H

#define _BASE 0
#define _NAV 1
#define _MOUSE 2
#define _MEDIA 3
#define _NUM 4
#define _SYM 5
#define _FUN 6

enum custom_keycodes {
    MS_JGL = SAFE_RANGE,
};

bool mouse_jiggle_mode = false;

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_BASE] = LAYOUT(
        _______, _______, _______, _______, _______, _______,                     _______, _______, _______, _______, _______, _______,
        _______, KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                       KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    _______,
        _______, GUI_T(KC_A), ALT_T(KC_S), CTL_T(KC_D), SFT_T(KC_F), KC_G,  KC_H,    SFT_T(KC_J), CTL_T(KC_K), ALT_T(KC_L), GUI_T(KC_SCLN), _______,
        _______, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    _______, _______,  KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, _______,
        LT(_MEDIA,KC_ESC), LT(_NAV,KC_SPC), LT(_MOUSE,KC_TAB),                    LT(_SYM,KC_ENT), LT(_NUM,KC_BSPC), LT(_FUN,KC_DEL)
    ),

    [_NAV] = LAYOUT(
        _______, _______, _______, _______, _______, _______,                     _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,                     KC_CAPS, _______, _______, _______, QK_BOOT,  _______,
        _______, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, _______,                    CW_TOGG, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______,
        _______, _______, _______, _______, _______, _______, _______, _______,  KC_INS,  KC_HOME, KC_PGDN, KC_PGUP, KC_END, _______,
        _______, _______, _______,                                               _______, _______, _______
    ),

    [_MOUSE] = LAYOUT(
        _______, _______, _______, _______, _______, _______,                     _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,                     _______, MS_JGL,  _______, _______, _______, _______,
        _______, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, _______,                     KC_BTN4, KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, _______,
        _______, _______, _______, _______, _______, _______, _______, _______,   KC_BTN5, KC_WH_L, KC_WH_D, KC_WH_U, KC_WH_R, _______,
        _______, _______, _______,                                               KC_BTN2, KC_BTN1, KC_BTN3
    ),

    [_MEDIA] = LAYOUT(
        _______, _______, _______, _______, _______, _______,                     _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,                     RGB_MOD, RGB_HUD, RGB_HUI, RGB_SAD, RGB_SAI, _______,
        _______, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, _______,                    RGB_RMOD, KC_MPRV, KC_VOLD, KC_VOLU, KC_MNXT, _______,
        _______, _______, _______, _______, _______, _______, _______, _______,   RGB_TOG, RGB_VAD, RGB_VAI, _______, _______, _______,
        _______, _______, _______,                                               KC_MSTP, KC_MPLY, KC_MUTE
    ),

    [_NUM] = LAYOUT(
        _______, _______, _______, _______, _______, _______,                     _______, _______, _______, _______, _______, _______,
        _______, KC_LBRC, KC_7,    KC_8,    KC_9,    KC_RBRC,                     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  _______,
        _______, KC_QUOT, KC_4,    KC_5,    KC_6,    KC_EQL,                      XXXXXXX, KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI, _______,
        _______, KC_GRV,  KC_1,    KC_2,    KC_3,    KC_BSLS, _______, _______,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
        KC_DOT,  KC_0,    KC_MINS,                                               _______, _______, _______
    ),

    [_SYM] = LAYOUT(
        _______, _______, _______, _______, _______, _______,                     _______, _______, _______, _______, _______, _______,
        _______, KC_LCBR, KC_AMPR, KC_ASTR, KC_LPRN, KC_RCBR,                     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  _______,
        _______, KC_DQUO, KC_DLR,  KC_PERC, KC_CIRC, KC_PLUS,                     XXXXXXX, KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI, _______,
        _______, KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_PIPE, _______, _______,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
        KC_LPRN, KC_RPRN, KC_UNDS,                                               _______, _______, _______
    ),

    [_FUN] = LAYOUT(
        _______, _______, _______, _______, _______, _______,                     _______, _______, _______, _______, _______, _______,
        _______, KC_F12,  KC_F7,   KC_F8,   KC_F9,   KC_PSCR,                     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  _______,
        _______, KC_F11,  KC_F4,   KC_F5,   KC_F6,   KC_SCRL,                     XXXXXXX, KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI, _______,
        _______, KC_F10,  KC_F1,   KC_F2,   KC_F3,   KC_PAUS, _______, _______,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
        KC_APP,  KC_SPC,  KC_TAB,                                                _______, _______, _______
    )
};

void matrix_scan_user(void) {
    if (mouse_jiggle_mode) {
        tap_code(KC_MS_LEFT);
        tap_code(KC_MS_RIGHT);
    }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case MS_JGL:
        if (record->event.pressed) {
            mouse_jiggle_mode = !mouse_jiggle_mode;
        }
        return false;

    default:
        break;
  }
  return true;
}
