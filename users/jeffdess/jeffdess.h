#include QMK_KEYBOARD_H
#include "keymap_canadian_multilingual.h"
#include "config.h"
#include "keycodes.h"
#include "combos.h"
#include "macros.h"

enum userspace_layers {
    _COLEMAK = 0,
    _ACCENTS,
    _SYMBOLS,
    _NAV,
    _NUMBERS,
    _MOUSE,
    _GAME,
};
