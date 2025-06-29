#include QMK_KEYBOARD_H
#include "layout.h"
#include "jeffdess.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    // clang-format off

[_COLEMAK] = LAYOUT_5col(
// ╭──────────────┬──────────────┬──────────────┬──────────────┬──────────────╮ ╭─────────────┬──────────────┬──────────────┬──────────────┬──────────────╮
         KC_Q     ,     KC_W     ,     KC_F     ,     KC_P     ,     KC_B     ,      KC_J     ,     KC_L     ,     KC_U     ,     KC_Y     ,    KC_SCLN   ,
// ├──────────────┼──────────────┼──────────────┼──────────────┼──────────────┤ ├─────────────┼──────────────┼──────────────┼──────────────┼──────────────┤
     LGUI_T(KC_A) , LALT_T(KC_R) , LCTL_T(KC_S) , LSFT_T(KC_T) ,     KC_G     ,      KC_M     , RSFT_T(KC_N) , LCTL_T(KC_E) , RALT_T(KC_I) , RGUI_T(KC_O) ,
// ├──────────────┼──────────────┼──────────────┼──────────────┼──────────────┤ ├─────────────┼──────────────┼──────────────┼──────────────┼──────────────┤
         KC_Z     ,     KC_X     ,     KC_C     ,     KC_D     ,     KC_V     ,      KC_K     ,     KC_H     ,    KC_COMM   ,    KC_DOT    , OSL(_ACCENTS),
// ╰──────────────┼──────────────┼──────────────┼──────────────┼──────────────┤ ├─────────────┼──────────────┼──────────────┼──────────────┼──────────────╯
                      DPI_RESET  ,    XXXXXXX   ,    NAV_RET   ,    NUM_ESC   ,     KC_BSPC   ,    SYM_SP    ,    XXXXXXX   ,    KC_MUTE   ,
//                ╰──────────────┴──────────────┴──────────────┴──────────────╯ ╰─────────────┴──────────────┴──────────────┴──────────────╯
//                  ↑ ENCODER ↑                                     ↓ 3-WAY THUMB SWITCHES ↓                                  ↑ ENCODER ↑
//                                              ╭─────────┬─────────┬─────────╮ ╭─────────┬─────────┬─────────╮
                                                   UNDO   ,  REDO2  ,  REDO   ,   KC_VOLD , KC_MUTE , KC_VOLU
//                                              ╰─────────┴─────────┴─────────╯ ╰─────────┴─────────┴─────────╯
),

[_ACCENTS] = LAYOUT_5col(
// ╭──────────────┬──────────────┬──────────────┬──────────────┬──────────────╮ ╭─────────────┬──────────────┬──────────────┬──────────────┬──────────────╮
        CA_TILD   ,    CA_ACUT   ,     E_TR     ,   XXXXXXX    ,    XXXXXXX   ,     XXXXXXX   ,     I_TR     ,     O_TR     ,     U_TR     ,    CA_DIAE   ,
// ├──────────────┼──────────────┼──────────────┼──────────────┼──────────────┤ ├─────────────┼──────────────┼──────────────┼──────────────┼──────────────┤
         A_GR     ,      E_CI    ,     E_CU     , LSFT_T(E_GR) ,    XXXXXXX   ,     XXXXXXX   , RSFT_T(I_CI) ,     O_CI     ,     U_CI     ,    CA_GRV    ,
// ├──────────────┼──────────────┼──────────────┼──────────────┼──────────────┤ ├─────────────┼──────────────┼──────────────┼──────────────┼──────────────┤
         A_CI     ,    XXXXXXX   ,     CEDIL    ,   XXXXXXX    ,    XXXXXXX   ,     XXXXXXX   ,  XXXXXXX     ,   XXXXXXX    ,     U_GR     ,    CA_CIRC   ,
// ╰──────────────┼──────────────┼──────────────┼──────────────┼──────────────┤ ├─────────────┼──────────────┼──────────────┼──────────────┼──────────────╯
                      HF_TOGG    ,    _______   ,   _______    , TO(_COLEMAK) ,     _______   ,   _______    ,   _______    ,   RGB_TOG    ,
//                ╰──────────────┴──────────────┴──────────────┴──────────────╯ ╰─────────────┴──────────────┴──────────────┴──────────────╯
//                  ↑ ENCODER ↑                                     ↓ 3-WAY THUMB SWITCHES ↓                                  ↑ ENCODER ↑
//                                              ╭─────────┬─────────┬─────────╮ ╭─────────┬─────────┬─────────╮
                                                  _______ , _______ , _______ ,   _______ , _______ , _______
//                                              ╰─────────┴─────────┴─────────╯ ╰─────────┴─────────┴─────────╯
),

[_SYMBOLS] = LAYOUT_5col(
// ╭──────────────┬──────────────┬──────────────┬──────────────┬──────────────╮ ╭─────────────┬──────────────┬──────────────┬──────────────┬──────────────╮
       CA_HASH    ,     CA_AT    ,   CA_LCBR    ,   CA_RCBR    ,    CA_PLUS   ,     XXXXXXX   ,     TILDE    ,     GRAVE    ,    CA_DLR    ,    XXXXXXX   ,
// ├──────────────┼──────────────┼──────────────┼──────────────┼──────────────┤ ├─────────────┼──────────────┼──────────────┼──────────────┼──────────────┤
       CA_SLSH    ,    CA_MINS   ,   CA_LPRN    ,   CA_RPRN    ,    CA_EQL    ,      CIRC     ,    CA_QUES   ,    CA_EXLM   ,    CA_AMPR   ,    CA_PIPE   ,
// ├──────────────┼──────────────┼──────────────┼──────────────┼──────────────┤ ├─────────────┼──────────────┼──────────────┼──────────────┼──────────────┤
       CA_ASTR    ,    CA_PERC   ,   CA_LBRC    ,   CA_RBRC    ,    CA_UNDS   ,     XXXXXXX   ,    CA_LABK   ,    CA_RABK   ,    CA_LDAQ   ,    CA_RDAQ   ,
// ╰──────────────┼──────────────┼──────────────┼──────────────┼──────────────┤ ├─────────────┼──────────────┼──────────────┼──────────────┼──────────────╯
                     ZOOM_RESET  ,    _______   ,   _______    ,   _______    ,     _______   ,   _______    ,   _______    ,   _______    ,
//                ╰──────────────┴──────────────┴──────────────┴──────────────╯ ╰─────────────┴──────────────┴──────────────┴──────────────╯
//                  ↑ ENCODER ↑                                     ↓ 3-WAY THUMB SWITCHES ↓                                  ↑ ENCODER ↑
//                                              ╭─────────┬─────────┬─────────╮ ╭─────────┬─────────┬─────────╮
                                                  _______ , _______ , _______ ,   _______ , _______ , _______
//                                              ╰─────────┴─────────┴─────────╯ ╰─────────┴─────────┴─────────╯
),

[_NAV] = LAYOUT_5col(
// ╭──────────────┬──────────────┬──────────────┬──────────────┬──────────────╮ ╭─────────────┬──────────────┬──────────────┬──────────────┬──────────────╮
       XXXXXXX    ,   XXXXXXX    ,   XXXXXXX    ,   XXXXXXX    ,    XXXXXXX   ,     XXXXXXX   ,   XXXXXXX    ,   XXXXXXX    ,   XXXXXXX    ,    XXXXXXX   ,
// ├──────────────┼──────────────┼──────────────┼──────────────┼──────────────┤ ├─────────────┼──────────────┼──────────────┼──────────────┼──────────────┤
    OSM(MOD_LGUI) ,   KC_MPRV    ,    KC_MPLY   ,   KC_MNXT    ,    XXXXXXX   ,      KC_LEFT  ,   KC_DOWN    ,     KC_UP    ,   KC_RIGHT   ,   KC_INSERT  ,
// ├──────────────┼──────────────┼──────────────┼──────────────┼──────────────┤ ├─────────────┼──────────────┼──────────────┼──────────────┼──────────────┤
       XXXXXXX    ,   XXXXXXX    ,   KC_VOLD    ,   KC_VOLU    ,    XXXXXXX   ,      KC_HOME  , KC_PAGE_DOWN ,  KC_PAGE_UP  ,    KC_END    ,KC_SCROLL_LOCK,
// ╰──────────────┼──────────────┼──────────────┼──────────────┼──────────────┤ ├─────────────┼──────────────┼──────────────┼──────────────┼──────────────╯
                      KC_MUTE    ,    _______   ,   _______    ,   _______    ,     _______   ,   _______    ,   _______    ,   KC_MUTE    ,
//                ╰──────────────┴──────────────┴──────────────┴──────────────╯ ╰─────────────┴──────────────┴──────────────┴──────────────╯
//                  ↑ ENCODER ↑                                     ↓ 3-WAY THUMB SWITCHES ↓                                  ↑ ENCODER ↑
//                                              ╭─────────┬─────────┬─────────╮ ╭─────────┬─────────┬─────────╮
                                                  _______ , _______ , _______ ,   _______ , _______ , _______
//                                              ╰─────────┴─────────┴─────────╯ ╰─────────┴─────────┴─────────╯
),

[_NUMBERS] = LAYOUT_5col(
// ╭──────────────┬──────────────┬──────────────┬──────────────┬──────────────╮ ╭─────────────┬──────────────┬──────────────┬──────────────┬──────────────╮
         KC_F1    ,     KC_F2    ,     KC_F3    ,     KC_F4    ,    CA_PLMN   ,     CA_QRTR   ,     KC_7     ,     KC_8     ,     KC_9     ,    CA_ASTR   ,
// ├──────────────┼──────────────┼──────────────┼──────────────┼──────────────┤ ├─────────────┼──────────────┼──────────────┼──────────────┼──────────────┤
         KC_F5    ,     KC_F6    ,     KC_F7    , LSFT_T(KC_F8),    CA_DEG    ,     CA_HALF   ,     KC_4     ,     KC_5     ,     KC_6     ,    CA_PLUS   ,
// ├──────────────┼──────────────┼──────────────┼──────────────┼──────────────┤ ├─────────────┼──────────────┼──────────────┼──────────────┼──────────────┤
         KC_F9    ,     KC_F10   ,     KC_F11   ,    KC_F12    ,    CA_MICR   ,     CA_TQTR   ,     KC_1     ,     KC_2     ,     KC_3     ,    KC_COMM   ,
// ╰──────────────┼──────────────┼──────────────┼──────────────┼──────────────┤ ├─────────────┼──────────────┼──────────────┼──────────────┼──────────────╯
                      _______    ,    _______   ,   _______    ,   _______    ,     _______   ,     KC_0     ,   _______    ,   _______    ,
//                ╰──────────────┴──────────────┴──────────────┴──────────────╯ ╰─────────────┴──────────────┴──────────────┴──────────────╯
//                  ↑ ENCODER ↑                                     ↓ 3-WAY THUMB SWITCHES ↓                                  ↑ ENCODER ↑
//                                              ╭─────────┬─────────┬─────────╮ ╭─────────┬─────────┬─────────╮
                                                  _______ , _______ , _______ ,   _______ , _______ , _______
//                                              ╰─────────┴─────────┴─────────╯ ╰─────────┴─────────┴─────────╯
),

[_MOUSE] = LAYOUT_5col(
// ╭──────────────┬──────────────┬──────────────┬──────────────┬──────────────╮ ╭─────────────┬──────────────┬──────────────┬──────────────┬──────────────╮
       XXXXXXX    ,   XXXXXXX    ,    XXXXXXX   ,    XXXXXXX   ,   XXXXXXX    ,     XXXXXXX   ,   XXXXXXX    ,    XXXXXXX   ,   XXXXXXX    ,    XXXXXXX   ,
// ├──────────────┼──────────────┼──────────────┼──────────────┼──────────────┤ ├─────────────┼──────────────┼──────────────┼──────────────┼──────────────┤
       XXXXXXX    , KC_MS_WH_LEFT, KC_MS_WH_UP  , KC_MS_WH_DOWN,KC_MS_WH_RIGHT,   KC_MS_LEFT  ,  KC_MS_DOWN  ,   KC_MS_UP   ,  KC_MS_RIGHT ,    XXXXXXX   ,
// ├──────────────┼──────────────┼──────────────┼──────────────┼──────────────┤ ├─────────────┼──────────────┼──────────────┼──────────────┼──────────────┤
       XXXXXXX    ,    KC_LALT   ,    KC_LCTL   ,    KC_LSFT   ,   XXXXXXX    ,     XXXXXXX   ,   KC_LSFT    ,    KC_LCTL   ,    KC_LALT   ,    XXXXXXX   ,
// ╰──────────────┼──────────────┼──────────────┼──────────────┼──────────────┤ ├─────────────┼──────────────┼──────────────┼──────────────┼──────────────╯
                      DPI_RESET  ,    _______   ,  KC_MS_BTN1  ,  KC_MS_BTN2  ,     XXXXXXX   ,   XXXXXXX    ,   _______    , FP_ACCEL_TOG ,
//                ╰──────────────┴──────────────┴──────────────┴──────────────╯ ╰─────────────┴──────────────┴──────────────┴──────────────╯
//                  ↑ ENCODER ↑                                     ↓ 3-WAY THUMB SWITCHES ↓                                  ↑ ENCODER ↑
//                                              ╭─────────┬─────────┬─────────╮ ╭─────────┬─────────┬─────────╮
                                                  _______ , _______ , _______ ,   _______ , _______ , _______
//                                              ╰─────────┴─────────┴─────────╯ ╰─────────┴─────────┴─────────╯
),

[_GAME] = LAYOUT_5col(
// ╭──────────────┬──────────────┬──────────────┬──────────────┬──────────────╮ ╭─────────────┬──────────────┬──────────────┬──────────────┬──────────────╮
        KC_TAB    ,     KC_Q     ,     KC_W     ,     KC_E     ,     KC_R     ,    KC_MS_BTN1 ,  KC_MS_BTN2  ,  KC_MS_BTN3  ,   XXXXXXX    ,    KC_LALT   ,
// ├──────────────┼──────────────┼──────────────┼──────────────┼──────────────┤ ├─────────────┼──────────────┼──────────────┼──────────────┼──────────────┤
        KC_LSFT   ,     KC_A     ,     KC_S     ,     KC_D     ,     KC_F     ,      KC_1     ,     KC_2     ,     KC_3     ,     KC_4     ,     KC_5     ,
// ├──────────────┼──────────────┼──────────────┼──────────────┼──────────────┤ ├─────────────┼──────────────┼──────────────┼──────────────┼──────────────┤
        KC_LCTL   ,     KC_Z     ,     KC_X     ,     KC_C     ,     KC_V     ,      KC_6     ,     KC_7     ,     KC_8     ,     KC_9     ,     KC_0     ,
// ╰──────────────┼──────────────┼──────────────┼──────────────┼──────────────┤ ├─────────────┼──────────────┼──────────────┼──────────────┼──────────────╯
                      _______    ,    KC_BSPC   ,   KC_SPACE   ,   KC_RETURN  ,     KC_ESC    ,     KC_M     ,     KC_I     ,   _______    ,
//                ╰──────────────┴──────────────┴──────────────┴──────────────╯ ╰─────────────┴──────────────┴──────────────┴──────────────╯
//                  ↑ ENCODER ↑                                     ↓ 3-WAY THUMB SWITCHES ↓                                  ↑ ENCODER ↑
//                                              ╭─────────┬─────────┬─────────╮ ╭─────────┬─────────┬─────────╮
                                                  _______ , _______ , _______ ,   _______ , _______ , _______
//                                              ╰─────────┴─────────┴─────────╯ ╰─────────┴─────────┴─────────╯
)
};
