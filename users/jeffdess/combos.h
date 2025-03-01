#pragma once
#include QMK_KEYBOARD_H

#undef COMBO_TERM
#define COMBO_TERM 60
#define COMBO_COUNT 19
#define COMBO_REF_DEFAULT _COLEMAK

enum combos {
    CB_COPY,
    CB_CUT,
    CB_PASTE,
    CB_PRINTSCREEN,
    CB_CAPS_WORD,
    CB_CAPS_LOCK,
    CB_TMUX,
    CB_TMUX_COMMAND,
    CB_TMUX_SESS,
    CB_MOUSE_LAYER,
    CB_GAME_LAYER,
    CB_FAT_ARROW,
    CB_ARROW,
    CB_LTE,
    CB_GTE,
    CB_TAB,
    CB_NAV_TOGGLE,
    CB_MS_LCLICK,
    CB_MS_RCLICK
};
