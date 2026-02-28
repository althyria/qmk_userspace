/* Copyright 2022 @ sajenim (https://github.com/sajenim)
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

enum layers {
    CANARY,
    NAV,
    NUM,
    SYM,
    FUN,
};

/* Thumb Keys:
 * dual role keys for accessing layers and prefixes */

#define NAV_XM LT(NAV, G(KC_A))
#define NUM_WZ LT(NUM, A(KC_A))

/* Home Row Mods:
 * https://precondition.github.io/home-row-mods */

#define HRM_R LALT_T(KC_R)
#define HRM_S LSFT_T(KC_S)
#define HRM_T LGUI_T(KC_T)
#define HRM_D LCTL_T(KC_D)
#define HRM_J LT(SYM, KC_J)
#define HRM_N RGUI_T(KC_N)
#define HRM_E RSFT_T(KC_E)
#define HRM_I RALT_T(KC_I)
#define HRM_H RCTL_T(KC_H)
#define HRM_COM LT(SYM, KC_COMM)

/* One Shot Keys:
 * https://github.com/qmk/qmk_firmware/blob/master/docs/one_shot_keys.md */

#define OS_LCTL OSM(MOD_LCTL)
#define OS_LSFT OSM(MOD_LSFT)
#define OS_LALT OSM(MOD_LALT)
#define OS_LGUI OSM(MOD_LGUI)
#define OS_RCTL OSM(MOD_RCTL)
#define OS_RSFT OSM(MOD_RSFT)
#define OS_RALT OSM(MOD_RALT)
#define OS_RGUI OSM(MOD_RGUI)
#define OS_SYM  OSL(SYM)

#include "g/keymap_combo.h" // layer names must be defined before engine include

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  // clang-format off
  [CANARY] = LAYOUT_split_3x5_2(
  //,--------------------------------------------.                    ,--------------------------------------------.
         KC_W,    KC_L,    KC_Y,    KC_P,    KC_B,                         KC_Z,    KC_F,    KC_O,    KC_U, KC_QUOT,
  //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
         KC_C,   HRM_R,   HRM_S,   HRM_T,    KC_G,                         KC_M,   HRM_N,   HRM_E,   HRM_I,    KC_A,
  //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
         KC_Q,   HRM_J,    KC_V,   HRM_D,    KC_K,                         KC_X,   HRM_H, KC_SLSH, HRM_COM,  KC_DOT,
  //|--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------|
                                           NAV_XM,  KC_SPC,    KC_BSPC,  NUM_WZ
                                      //`-----------------'  `-----------------'
  ),

  [NAV] = LAYOUT_split_3x5_2(
  //,--------------------------------------------.                    ,--------------------------------------------.
      XXXXXXX, KC_MPRV, KC_MPLY, KC_MNXT, KC_VOLU,                      KC_PGUP, KC_HOME,   KC_UP,  KC_END, XXXXXXX,
  //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
      XXXXXXX, OS_LALT, OS_LSFT, OS_LGUI, KC_VOLD,                      KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT,  KC_DEL,
  //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
      XXXXXXX,  OS_SYM, XXXXXXX, OS_LCTL, XXXXXXX,                      XXXXXXX,  KC_TAB, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------|
                                          _______, _______,    _______, _______
                                      //`-----------------'  `-----------------'
  ),

  [NUM] = LAYOUT_split_3x5_2(
  //,--------------------------------------------.                    ,--------------------------------------------.
      KC_LPRN,    KC_7,    KC_8,    KC_9, KC_RPRN,                      XXXXXXX, KC_PLUS, KC_MINS, KC_ASTR, KC_SLSH,
  //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
         KC_0,    KC_4,    KC_5,    KC_6,  KC_EQL,                      XXXXXXX, OS_RGUI, OS_RSFT, OS_RALT, XXXXXXX,
  //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
      KC_COMM,    KC_1,    KC_2,    KC_3,  KC_DOT,                      XXXXXXX, OS_RCTL, XXXXXXX,  OS_SYM, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------|
                                          _______, _______,    _______, _______
                                      //`-----------------'  `-----------------'
  ),

  [SYM] = LAYOUT_split_3x5_2(
  //,--------------------------------------------.                    ,--------------------------------------------.
       KC_GRV, KC_LABK, KC_MINS, KC_RABK, XXXXXXX,                      XXXXXXX, KC_LBRC, KC_UNDS, KC_RBRC, KC_PLUS,
  //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
      KC_PIPE, KC_LPRN,  KC_EQL, KC_RPRN, KC_HASH,                      KC_PERC, KC_LCBR,  KC_DLR, KC_RCBR, KC_SCLN,
  //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
      KC_EXLM, KC_AMPR, KC_CIRC,   KC_AT, XXXXXXX,                      XXXXXXX, KC_ASTR, _______, _______, _______,
  //|--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------|
                                          _______, _______,    _______, _______
                                      //`-----------------'  `-----------------'
  ),

  [FUN] = LAYOUT_split_3x5_2(
  //,--------------------------------------------.                    ,--------------------------------------------.
       KC_F12,   KC_F7,   KC_F8,   KC_F9, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, QK_BOOT,
  //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
       KC_F11,   KC_F4,   KC_F5,   KC_F6, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_SLEP,
  //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
       KC_F10,   KC_F1,   KC_F2,   KC_F3, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  QK_RBT,
  //|--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------|
                                          _______, _______,    _______, _______
                                      //`-----------------'  `-----------------'
  ),
  // clang-format on
};


/* Tri-state Layers:
 * setup FUN layer to activate when NAV & NUM is held */

layer_state_t layer_state_set_user(layer_state_t state) {
    // Activate function layer
    state = update_tri_layer_state(state, NAV, NUM, FUN);
    return state;
}

/* Custom keycodes:
 * program the behaviour of any keycode */

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case NAV_XM:
            if (record->tap.count) {
                if (record->event.pressed) register_code16(G(KC_A));
                else unregister_code16(G(KC_A));
                return false;
            }
            return true;
        case NUM_WZ:
            if (record->tap.count) {
                if (record->event.pressed) register_code16(A(KC_A));
                else unregister_code16(A(KC_A));
                return false;
            }
            return true;
    }
    return true;
}
