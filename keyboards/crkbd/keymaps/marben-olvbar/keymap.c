/*
  Copyright 2019 @foostan
  Copyright 2020 Drashna Jaelre <@drashna>

  This program is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 2 of the License, or
  (at your option) any later version.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H
#include <stdio.h>
#include "keycodes.h"

// Tap Dance definitions
qk_tap_dance_action_t tap_dance_actions[] = {
    // Tap once for Escape, twice for Caps Lock
    [TD_SUPER_SHIFT] = ACTION_TAP_DANCE_DOUBLE(KC_LGUI, KC_LSFT),
    [TD_SYM_ALT] = ACTION_TAP_DANCE_DOUBLE(MO(_SYMBOLS), KC_LALT),
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    // qwertz base layer
    [_BASE_QWERTZ] = LAYOUT_split_3x6_3(
        //,-----------------------------------------------------.                    ,-----------------------------------------------------.
        KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Z,    KC_U,    KC_I,    KC_O,   KC_P,  KC_BSPC,
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        KC_LCTL,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                        KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, KC_QUOT,
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        TD(TD_SYM_ALT),    KC_Y,    KC_X,    KC_C,    KC_V,    KC_B,                   KC_N,    KC_M,   KC_COMM,  KC_DOT, KC_SLSH,  KC_ESC,
        //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                           TD(TD_SUPER_SHIFT), MO(_MOVEMENT),  KC_SPC,     KC_ENT,   KC_LSFT,  KC_LALT
                                            //`--------------------------'  `--------------------------'
        ),

    // colemak dh base layer
    [_BASE_COLEMAK_DH] = LAYOUT_split_3x6_3(
        //,-----------------------------------------------------.                    ,-----------------------------------------------------.
        KC_TAB,   KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,                         KC_J,    KC_L,    KC_U,    KC_Y,   KC_SCLN, KC_BSPC,
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        KC_LCTL,  KC_A,    KC_R,    KC_S,    KC_T,    KC_G,                         KC_M,    KC_N,    KC_E,    KC_I,   KC_O,    KC_QUOT,
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        TD(TD_SUPER_SHIFT),KC_Z, KC_X,    KC_C,    KC_D,    KC_V,                         KC_K,    KC_H,    KC_COMM, KC_DOT, KC_SLSH, KC_ESC,
        //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                            TD(TD_SUPER_SHIFT), MO(_MOVEMENT),  KC_SPC,     KC_ENT,   KC_LSFT,  KC_LALT
                                            //`--------------------------'  `--------------------------'
        ),
    // gaming base layer, TODO
    [_BASE_GAMING] = LAYOUT_split_3x6_3(
        //,-----------------------------------------------------.                    ,-----------------------------------------------------.
        KC_T,  KC_TAB,   KC_Q,    KC_W,   KC_E,   KC_R,                            KC_I,    KC_M,    KC_UP,    KC_9,    KC_0,   KC_BSPC,
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        KC_G,  KC_LSFT,  KC_A,    KC_S,   KC_D,   KC_F,                            KC_L,   KC_LEFT, KC_DOWN,  KC_RIGHT, KC_NO,  KC_NO,
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        KC_B,  KC_LCTL,  KC_Y,    KC_X,   KC_C,   KC_V,                            KC_N,   KC_Z,    KC_NO,  KC_NO, DF(_BASE_QWERTZ),DF(_BASE_COLEMAK_DH),
        //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                               KC_LALT, KC_SPC,  KC_ENT,     KC_ENT,   KC_LSFT,  KC_LALT
                                            //`--------------------------'  `--------------------------'
        ),

    // symbol layer
    [_SYMBOLS] = LAYOUT_split_3x6_3(
        //,-----------------------------------------------------.                    ,-----------------------------------------------------.
        A(KC_TAB), KC_1,   KC_2,   KC_3,    KC_4,    KC_5,                         KC_6,     KC_7,   KC_8,    KC_9,    KC_0,     KC_BSPC,
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        KC_LCTL, KC_PLUS, KC_LBRC, KC_RBRC, KC_LPRN, KC_RPRN,                      KC_GRV,  KC_EQL, KC_MINS, KC_BSLS,  KC_ASTR,  KC_TILD,
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        _______, KC_NO,   KC_NO,   KC_PIPE, KC_LCBR, KC_RCBR,          A(ALGR(KC_5)), A(ALGR(KC_SCLN)), KC_NO, KC_DOT,  KC_NO,    KC_NO,
        //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                           _______, MO(_SPECIAL),_______,    _______, _______, _______
                                            //`--------------------------'  `--------------------------'
        ),
    // movement layer
    [_MOVEMENT] = LAYOUT_split_3x6_3(
        //,-----------------------------------------------------.                    ,-----------------------------------------------------.
        KC_ESC,  KC_NO,   KC_NO,   KC_LSFT,  KC_F11, KC_F9,                        KC_HOME, KC_PGUP, KC_UP, KC_PGDN, A(ALGR(KC_Y)), KC_DEL,
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        KC_LCTL, KC_NO,   KC_NO,   KC_NO,    KC_NO,  KC_NO,                        KC_END,  KC_LEFT, KC_DOWN, KC_RGHT, A(ALGR(KC_P)), A(ALGR(KC_Q)),
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        MO(_SPECIAL), KC_NO,   KC_NO, C(S(KC_C)), C(S(KC_V)), KC_NO,               KC_APP, KC_WWW_BACK, KC_WWW_FORWARD, KC_NO, A(ALGR(KC_S)), KC_PSCR,
        //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                               _______, _______, _______,    _______, _______, _______
                                            //`--------------------------'  `--------------------------'
        ),
    // special function layer
    [_SPECIAL] = LAYOUT_split_3x6_3(
        //,-----------------------------------------------------.                    ,-----------------------------------------------------.
        KC_NO,   KC_MPRV, KC_MPLY, KC_MNXT, KC_CALC, KC_FIND,                       KC_NO,   KC_P7,   KC_P8,   KC_P9,   KC_F1,    KC_F2,
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        KC_LCTL, KC_NO,   KC_VOLD, KC_VOLU, KC_MUTE, KC_NO,                         KC_NO,   KC_P4,   KC_P5,   KC_P6,   KC_F3,    KC_F4,
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        _______,KC_NO,DF(_BASE_QWERTZ),DF(_BASE_COLEMAK_DH),DF(_BASE_GAMING),KC_NO, KC_P0,   KC_P1,   KC_P2,   KC_P3,   KC_F5,    KC_F6,
        //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                               _______, _______, _______,    _______, _______, _______
                                            //`--------------------------'  `--------------------------'
        )
};

#ifdef OLED_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    if (!is_keyboard_master()) {
        return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
    }
    return rotation;
}

void oled_render_layer_state(void) {
    oled_write_P(PSTR("Layer: "), false);
    switch (get_highest_layer(layer_state | default_layer_state)) {
    case _BASE_QWERTZ:
        oled_write_ln_P(PSTR("QWERTZ"), false);
        break;
    case _BASE_COLEMAK_DH:
        oled_write_ln_P(PSTR("Colemak DH"), false);
        break;
    case _BASE_GAMING:
        oled_write_ln_P(PSTR("Gaming"), false);
        break;
    case _SYMBOLS:
        oled_write_ln_P(PSTR("Symbols"), false);
        break;
    case _MOVEMENT:
        oled_write_ln_P(PSTR("Movement"), false);
        break;
    case _SPECIAL:
        oled_write_ln_P(PSTR("Special"), false);
        break;
    default:
        oled_write_ln_P(PSTR("Undefined"), false);
    }
}

void render_bootmagic_status(bool status) {
    /* Show Ctrl-Gui Swap options */
    static const char PROGMEM logo[][2][3] = {
        {{0x97, 0x98, 0}, {0xb7, 0xb8, 0}},
        {{0x95, 0x96, 0}, {0xb5, 0xb6, 0}},
    };
    if (status) {
        oled_write_ln_P(logo[0][0], false);
        oled_write_ln_P(logo[0][1], false);
    } else {
        oled_write_ln_P(logo[1][0], false);
        oled_write_ln_P(logo[1][1], false);
    }
}

void oled_render_logo(void) {
    static const char PROGMEM crkbd_logo[] = {
        0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8a, 0x8b, 0x8c, 0x8d, 0x8e, 0x8f, 0x90, 0x91, 0x92, 0x93, 0x94,
        0xa0, 0xa1, 0xa2, 0xa3, 0xa4, 0xa5, 0xa6, 0xa7, 0xa8, 0xa9, 0xaa, 0xab, 0xac, 0xad, 0xae, 0xaf, 0xb0, 0xb1, 0xb2, 0xb3, 0xb4,
        0xc0, 0xc1, 0xc2, 0xc3, 0xc4, 0xc5, 0xc6, 0xc7, 0xc8, 0xc9, 0xca, 0xcb, 0xcc, 0xcd, 0xce, 0xcf, 0xd0, 0xd1, 0xd2, 0xd3, 0xd4,
        0};
    oled_write_P(crkbd_logo, false);
}

bool oled_task_user(void) {
    if (is_keyboard_master()) {
        oled_render_logo();
    } else {
        oled_render_layer_state();
    }
    return false;
}
#endif // OLED_ENABLE
