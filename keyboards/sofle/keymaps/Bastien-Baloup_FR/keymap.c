 /* Copyright 2022 Bastien Baloup
  * based on the work of Josef Adamcik, Jens Bonk-Wiltfang and Michal S. (@ihatethefrench)
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

enum custom_keycodes {
    PLACEHOLDER = SAFE_RANGE,  // can always be here (4 bytes)
    // CL_ keycodes are here for charaters that need capslock on to be inputed.
    CL_AGRV,                   // À
    CL_EACU,                   // É
    CL_EGRV,                   // È
    // UC_ keycodes uses (ctrl+shift+u)+code+enter to input unicode. Should be replaced by alt+code for windows.
    UC_PI  ,                   // π
    UC_ELIP                    // …
};

// Following keymaps are made for the french ISO keyboard layout

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*
 * LOWERcase
 * ,-----------------------------------------.                     ,-----------------------------------------.
 * |   ²  |   &  |   é  |   "  |   '  |  _^  |                     |  _¨  |   è  |   %  |   ç  |   à  |TGUtil|
 * |------+------+------+------+------+------|                     |------+------+------+------+------+------|
 * | ESC  |   a  |   z  |   e  |   r  |   t  |                     |   y  |   u  |   i  |   o  |   p  | Bspc |
 * |------+------+------+------+------+------|                     |------+------+------+------+------+------|
 * | Tab  |   q  |   s  |   d  |   f  |   g  |-------.     ,-------|   h  |   j  |   k  |   l  |   m  |  ù   |
 * |------+------+------+------+------+------|       |     | Mute  |------+------+------+------+------+------|
 * |UPPER |   w  |   x  |   c  |   v  |   b  |-------|     |-------|   n  |   ,  |   ;  |   :  |   !  | UPPER|
 * `-----------------------------------------/       /      \      \-----------------------------------------'
 *            | LGUI | LAlt | LCTR |SYMBOL| /Enter  /        \Space \  |UTILS | RCTR | RAlt | HYPER|
 *            |      |      |      |      |/       /          \      \ |      |      |      |      |
 *            `-----------------------------------'            '------''---------------------------'
 */

[0] = LAYOUT(
   KC_GRV    , KC_1   , KC_2   , KC_3   , KC_4   , KC_LBRC,                         S(KC_LBRC), KC_7   , S(KC_QUOT), KC_9   , KC_0   , TG(3)  ,
   KC_ESC    , KC_Q   , KC_W   , KC_E   , KC_R   , KC_T   ,                         KC_Y      , KC_U   , KC_I      , KC_O   , KC_P   , KC_BSPC,
   KC_TAB    , KC_A   , KC_S   , KC_D   , KC_F   , KC_G   ,                         KC_H      , KC_J   , KC_K      , KC_L   , KC_SCLN, KC_QUOT,
   MO(1)     , KC_Z   , KC_X   , KC_C   , KC_V   , KC_B   , XXXXXXX,       KC_MUTE, KC_N      , KC_M   , KC_COMM   , KC_DOT , KC_SLSH, MO(1)  ,
                      KC_LGUI, KC_LALT, KC_LCTRL, MO(2)  , KC_ENT,           KC_SPC, MO(3)  , KC_RCTRL, KC_RALT, KC_HYPR
),

/*
 * UPPERcase
 * ,-----------------------------------------.                     ,-----------------------------------------.
 * |      |   1  |   2  |   3  |   4  |   5  |                     |   6  |   7  |   8  |   9  |   0  |TGUtil|
 * |------+------+------+------+------+------|                     |------+------+------+------+------+------|
 * | ESC  |   A  |   Z  |   E  |   R  |   T  |                     |   Y  |   U  |   I  |   O  |   P  | Bspc |
 * |------+------+------+------+------+------|                     |------+------+------+------+------+------|
 * | TAB  |   Q  |   S  |   D  |   F  |   G  |-------.     ,-------|   H  |   J  |   K  |   L  |   M  |  µ   |
 * |------+------+------+------+------+------|       |     | Mute  |------+------+------+------+------+------|
 * |UPPER |   W  |   X  |   C  |   V  |   B  |-------|     |-------|   N  |   ?  |   .  |   /  |   §  | UPPER|
 * `-----------------------------------------/       /      \      \-----------------------------------------'
 *            | LGUI | LAlt | LCTR |SYMBOL| /Enter  /        \Space \  |UTILS | RCTR | RAlt | HYPER|
 *            |      |      |      |      |/       /          \      \ |      |      |      |      |
 *            `-----------------------------------'            '------''---------------------------'
 */
[1] = LAYOUT(
   _______, S(KC_1), S(KC_2), S(KC_3), S(KC_4), S(KC_5),                         S(KC_6) , S(KC_7), S(KC_8)   , S(KC_9)  , S(KC_0)   , _______   ,
   _______, S(KC_Q), S(KC_W), S(KC_E), S(KC_R), S(KC_T),                         S(KC_Y) , S(KC_U), S(KC_I)   , S(KC_O)  , S(KC_P)   , _______   ,
   _______, S(KC_A), S(KC_S), S(KC_D), S(KC_F), S(KC_G),                         S(KC_H) , S(KC_J), S(KC_K)   , S(KC_L)  , S(KC_SCLN), S(KC_NUHS),
   _______, S(KC_Z), S(KC_X), S(KC_C), S(KC_V), S(KC_B), _______,       _______, S(KC_N) , S(KC_M), S(KC_COMM), S(KC_DOT), S(KC_SLSH), _______   ,
                   _______, _______, _______, _______, _______,           _______, _______, _______, _______, _______
),

/* SYMBOLS
 * ,-----------------------------------------.                     ,-----------------------------------------.
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |                     |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |
 * |------+------+------+------+------+------|                     |------+------+------+------+------+------|
 * | ESC  |   À  |   È  |   É  |   (  |   )  |                     |   =  |   |  |   \  |   ·  |   @  | Bspc |
 * |------+------+------+------+------+------|                     |------+------+------+------+------+------|
 * | Tab  |   `  |   ~  |   #  |   <  |   >  |-------.     ,-------|   +  |   -  |   /  |   *  |   °  |  …   |
 * |------+------+------+------+------+------|       |     | Play  |------+------+------+------+------+------|
 * | Shift|   ¤  |   [  |   ]  |   {  |   }  |-------|     |-------|   π  |   _  |   €  |   $  |   £  | Shift|
 * `-----------------------------------------/       /      \      \-----------------------------------------'
 *            | LGUI | LAlt | LCTR |SYMBOL| /Enter  /        \Space \  |UTILS | RCTR | RAlt | HYPER|
 *            |      |      |      |      |/       /          \      \ |      |      |      |      |
 *            `-----------------------------------'            '------''---------------------------'
 */
[2] = LAYOUT(
  KC_F1  , KC_F2        , KC_F3     , KC_F4        , KC_F5     , KC_F6       ,                         KC_F7    , KC_F8     , KC_F9     , KC_F10       , KC_F11    , KC_F12 ,
  _______, CL_AGRV      , CL_EGRV   , CL_EACU      , KC_5      , KC_MINS     ,                         KC_EQL   , ALGR(KC_6), ALGR(KC_8), ALGR(KC_COMM), ALGR(KC_0), _______,
  _______, ALGR(KC_7)   , ALGR(KC_2), ALGR(KC_3)   , KC_NUBS   , S(KC_NUBS)  ,                         S(KC_EQL), KC_6      , S(KC_DOT) , KC_NUHS      , S(KC_MINS), UC_ELIP,
  KC_LSFT, ALGR(KC_RBRC), ALGR(KC_5), ALGR(KC_MINS), ALGR(KC_4), ALGR(KC_EQL), _______,       KC_MPLY, UC_PI    , KC_8      , ALGR(KC_E), KC_RBRC      , S(KC_RBRC), KC_RSFT,
                                         _______, _______, _______, _______, _______,           _______, _______, _______, _______, _______
),
/* UTILS
 * ,----------------------------------------.                      ,-----------------------------------------.
 * |      |   &  |   é  |   "  |   (  |  _^  |                     | CLock|PScr  |ScLock| Pause|  Ins |TGUtil|
 * |------+------+------+------+------+------|                     |------+------+------+------+------+------|
 * | Esc  |   a  |   z  |   e  |   r  |  t   |                     | PgUp | Home |  Up  | End  |  Del | Bspc |
 * |------+------+------+------+------+------|                     |------+------+------+------+------+------|
 * | Tab  |   q  |   s  |   d  |   f  |  g   |-------.     ,-------| PgDo | Left | Down | Rigth|CALeft|CARigt|
 * |------+------+------+------+------+------|       |     | Play  |------+------+------+------+------+------|
 * |Shift |   w  |   x  |   c  |   v  |  b   |-------|     |-------|      | PWrd |      | NWrd | Menu | Shift|
 * `-----------------------------------------/      /       \      \-----------------------------------------'
 *            | LGUI | LAlt | LCTR |SYMBOL| /Enter  /        \Space \  |UTILS | RCTR | RAlt | HYPER|
 *            |      |      |      |      |/      /           \      \ |      |      |      |      |
 *            `----------------------------------'             '------''---------------------------'
 */
[3] = LAYOUT(
  _______, _______, _______, _______, _______, _______,                         KC_CAPS, KC_PSCR   , KC_SCRL, KC_PAUS   , KC_INS       , _______      ,
  _______, _______, _______, _______, _______, _______,                         KC_PGUP, KC_HOME   , KC_UP  , KC_END    , KC_DEL       , _______      ,
  _______, _______, _______, _______, _______, _______,                         KC_PGDN, KC_LEFT   , KC_DOWN, KC_RGHT   , C(A(KC_LEFT)), C(A(KC_RGHT)),
  KC_LSFT, _______, _______, _______, _______, _______, _______,       KC_MPLY, XXXXXXX, C(KC_LEFT), XXXXXXX, C(KC_RGHT), KC_MENU      , KC_RSFT      ,
                  _______, _______, _______, _______, _______,           _______, _______, _______, _______, _______
)
};

// Custom keycode handling.
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    // handling this once instead of in each keycode uses less program memory.
    if ((keycode >= SAFE_RANGE) && !(record->event.pressed)) {
        return false;
    }

    switch (keycode) {
        case CL_AGRV:
            SEND_STRING(SS_TAP(X_CAPS)"0"SS_TAP(X_CAPS));
            break;
        case CL_EACU:
            SEND_STRING(SS_TAP(X_CAPS)"2"SS_TAP(X_CAPS));
            break;
        case CL_EGRV:
            SEND_STRING(SS_TAP(X_CAPS)"7"SS_TAP(X_CAPS));
            break;
        case UC_PI:
            tap_code16(LCTL(LSFT(KC_U)));
            tap_code16(S(KC_3));
            tap_code16(KC_C);
            tap_code16(S(KC_0));
            tap_code16(KC_ENT);
            break;
        case UC_ELIP:
            tap_code16(LCTL(LSFT(KC_U)));
            tap_code16(S(KC_2));
            tap_code16(S(KC_0));
            tap_code16(S(KC_2));
            tap_code16(S(KC_6));
            tap_code16(KC_ENT);
            break;
    }

    // this uses less memory than returning in each case.
    return keycode < SAFE_RANGE;
};

#ifdef ENCODER_ENABLE

// This section is like the keymap matrix, but for rotary encoders
// My left encoder is currently not working, so I'm using Layers to cope :')
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
    [0] = { ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(KC_VOLU, KC_VOLD)},
    [1] = { ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(KC_VOLU, KC_VOLD)},
    [2] = { ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(KC_MNXT, KC_MPRV)},
    [3] = { ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(KC_MNXT, KC_MPRV)},
};

#endif

#ifdef RGBLIGHT_ENABLE

const rgblight_segment_t PROGMEM rgb_layer_1[] = RGBLIGHT_LAYER_SEGMENTS(
    {30, 6, HSV_TURQUOISE},
    {38, 6, HSV_TURQUOISE}
);
const rgblight_segment_t PROGMEM rgb_layer_2[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 73, HSV_TEAL}
);
const rgblight_segment_t PROGMEM rgb_layer_3[] = RGBLIGHT_LAYER_SEGMENTS(
    {37, 36, HSV_PURPLE}
);

const rgblight_segment_t* const PROGMEM rgb_layers[] = RGBLIGHT_LAYERS_LIST(
    rgb_layer_1,     // Overrides for layer 1
    rgb_layer_2,     // Overrides for layer 2
    rgb_layer_3     // Overrides for layer 3
);

void keyboard_post_init_user(void) {
    // Enable the LED layers
    rgblight_layers = rgb_layers;
}

layer_state_t layer_state_set_user(layer_state_t state) {
    rgblight_set_layer_state(0, layer_state_cmp(state, 1));
    rgblight_set_layer_state(1, layer_state_cmp(state, 2));
    rgblight_set_layer_state(2, layer_state_cmp(state, 3));
    return state;
}

#endif
