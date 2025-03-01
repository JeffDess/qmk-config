#include QMK_KEYBOARD_H
// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _QWERTY 0
#define _SYMB 1
#define _NAVI 2
#define _ADJUST 3

#define _BASE 0
#define _FN 1

// Shortcut to make keymap more readable
// #define SYM_L   MO(_SYMB)

// #define KC_ALAS LALT_T(KC_PAST)
// #define KC_CTPL LCTL_T(KC_BSLS)

// #define KC_NAGR LT(_NAV, KC_GRV)
// #define KC_NAMI LT(_NAV, KC_MINS)

// #define KC_ADEN LT(_ADJUST, KC_END)
// #define KC_ADPU LT(_ADJUST, KC_PGUP)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
     *    ┌───┐  ┌───┬───┬───┬───┬───┬───┬───┐         ┌───┬───┬───┬───┬───┬───┬───┐
     *    │Esc│  │ ` │ 1 │ 2 │ 3 │ 4 │ 5 │ 6 │         │ 7 │ 8 │ 9 │ 0 │ - │ = │Bsp│
     *   ┌┴──┬┘ ┌┴───┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┘       ┌─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴────┐
     *   │PUp│  │ Tab │ Q │ W │ E │ R │ T │          │ Y │ U │ I │ O │ P │ [ │ ] │   \  │
     *  ┌┴──┬┘ ┌┴─────┼───┼───┼───┼───┼───┤          └┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴──────┴┐
     *  │PDn│  │ Caps │ A │ S │ D │ F │ G │           │ H │ J │ K │ L │ ; │ ' │   Enter  │
     * ┌┴──┬┘ ┌┴──────┴┬──┴┬──┴┬──┴┬──┴┬──┴┐        ┌─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴──┬┴──────────┴┐
     * │Del│  │ Shift  │ Z │ X │ C │ V │ B │        │ N │ M │ , │ . │ / │ Up │    Shift   │
     * └───┘  ├─────┬──┴──┬┴───┴┬──┴───┴┬──┴──┐     ├───┴───┴──┬┴───┴┬──┴────┴─────┬──┴──┬┘
     *        │ Ctl │     │ Alt │       │ GUI │     │          │ Alt │             │ Ctl │
     *        └─────┘     └─────┴───────┴─────┘     └──────────┴─────┘             └─────┘
     */
    [_BASE] =
        LAYOUT(KC_ESC, KC_1, KC_2, KC_3, KC_4, KC_5, KC_LBRC, KC_BSPC, KC_0, KC_9, KC_8, KC_7, KC_6,
               KC_RBRC, KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_UNDS, KC_BSLS, KC_P, KC_O, KC_I,
               KC_U, KC_Y, KC_PLUS, KC_CAPS, KC_A, KC_S, KC_D, KC_F, KC_G, KC_LABK, KC_ENT, KC_SCLN,
               KC_L, KC_K, KC_J, KC_H, KC_RABK, KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_VOLU,
               KC_RSFT, KC_SLSH, KC_RABK, KC_LABK, KC_M, KC_N, KC_VOLD, KC_LGUI, KC_LALT, KC_SPC,
               KC_LCTL, KC_PGUP, KC_LGUI, KC_LALT, KC_SPC, KC_LCTL, KC_PGDN),
    [_FN] = LAYOUT(KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                   KC_TRNS, KC_TRNS, KC_TRNS)};

led_config_t g_led_config = {{{0, 1, 2, 3}},
                             {// LED 对应到物理位置，可以参考下面这个公式
                              // x = 224 / (NUMBER_OF_COLS - 1) * COL_POSITION
                              // y = 64 / (NUMBER_OF_ROWS - 1) * ROW_POSITION
                              {0, 0},
                              {75, 0},
                              {149, 0},
                              {224, 0}

                             },
                             {// 分组，如果没有自己做灯光的需求用处其实不大
                              1, 1, 1, 1}};
