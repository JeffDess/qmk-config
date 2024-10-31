#include <stdint.h>

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case NAV_RET:
            return THUMB_TAP_TERM;
        case NUM_ESC:
            return THUMB_TAP_TERM;
        case KC_BSPC:
            return THUMB_TAP_TERM;
        case SYM_SP:
            return THUMB_TAP_TERM;
        case KC_SPACE:
            return THUMB_TAP_TERM;
        default:
            return TAPPING_TERM;
    }
}
