#include <stdint.h>
#include "sendstring_canadian_multilingual.h"

#define SS_CIRC SS_TAP(X_LBRC)
#define SS_TREM SS_LSFT(SS_TAP(X_LBRC))

uint8_t mod_state;
enum custom_keycodes {
    A_CI = SAFE_RANGE,
    A_GR,
    E_CI,
    E_CU,
    E_GR,
    E_TR,
    I_CI,
    I_TR,
    O_CI,
    O_TR,
    U_CI,
    U_GR,
    U_TR,
    GRAVE,
    TILDE,
    CIRC,
    CEDIL,
    SLSH_BSLSH,
    DASH_TILDE,
    COMMA_DOT,
    FAT_ARROW,
    ARROW,
    GTE,
    LTE,
    TMUX_SESSION,
    TMUX_CMD,
};

void deactivate_current_layer(void) {
    uint8_t current_layer = get_highest_layer(layer_state);
    clear_keyboard_but_mods();
    layer_invert(current_layer);
}

void send_circ_accent(const uint16_t letter, uint8_t mod_state) {
    if (mod_state & MOD_MASK_SHIFT) {
        del_mods(MOD_MASK_SHIFT);
        SEND_STRING(SS_TAP(X_LBRC) SS_LSFT(SS_TAP(X_A)));
    } else {
        SEND_STRING(SS_TAP(X_LBRC) SS_TAP(X_A));
    }
    deactivate_current_layer();
}

void send_diae_accent(const uint16_t letter, uint8_t mod_state) {
    if (mod_state & MOD_MASK_SHIFT) {
        del_mods(MOD_MASK_SHIFT);
        SEND_STRING(SS_ALGR(SS_TAP(X_LBRC)) SS_LSFT(SS_TAP(X_A)));
    } else {
        SEND_STRING(SS_ALGR(SS_TAP(X_LBRC)) SS_TAP(X_A));
    }
    deactivate_current_layer();
}

void send_dead_accent(const char *accent) {
    SEND_STRING(accent);
    deactivate_current_layer();
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    mod_state = get_mods();
    if (record->event.pressed) {
        switch (keycode) {
            case GRAVE:
                SEND_STRING("`");
                return false;
            case CIRC:
                SEND_STRING("^");
                return false;
            case TILDE:
                SEND_STRING("~");
                return false;
            case FAT_ARROW:
                SEND_STRING(" => ");
                return false;
            case ARROW:
                SEND_STRING(" -> ");
                return false;
            case GTE:
                SEND_STRING(" >= ");
                return false;
            case LTE:
                SEND_STRING(" <= ");
                return false;
            case TMUX_CMD:
                SEND_STRING(SS_TMUX ":");
                return false;
            case TMUX_SESSION:
                SEND_STRING(SS_TMUX ":" SS_DELAY(10) "new -s ");
                return false;
            case CA_MINS:
                if (mod_state & MOD_MASK_SHIFT) {
                    del_mods(MOD_MASK_SHIFT);
                    SEND_STRING("~");
                } else {
                    SEND_STRING("-");
                }
                return false;
            case A_CI:
                if (mod_state & MOD_MASK_SHIFT) {
                    del_mods(MOD_MASK_SHIFT);
                    SEND_STRING(SS_CIRC SS_LSFT(SS_TAP(X_A)));
                } else {
                    SEND_STRING(SS_CIRC SS_TAP(X_A));
                }
                return false;
            case A_GR:
                tap_code(CA_AGRV);
                return false;
            case CEDIL:
                tap_code(CA_CCED);
                return false;
            case E_CU:
                tap_code(CA_EACU);
                return false;
            case E_CI:
                if (mod_state & MOD_MASK_SHIFT) {
                    del_mods(MOD_MASK_SHIFT);
                    SEND_STRING(SS_CIRC SS_LSFT(SS_TAP(X_E)));
                } else {
                    SEND_STRING(SS_CIRC SS_TAP(X_E));
                }
                return false;
            case LSFT_T(E_GR):
                if (record->tap.count) {
                    tap_code(CA_EGRV);
                    return false;
                }
                break;
            case E_TR:
                if (mod_state & MOD_MASK_SHIFT) {
                    del_mods(MOD_MASK_SHIFT);
                    SEND_STRING(SS_TREM SS_LSFT(SS_TAP(X_E)));
                } else {
                    SEND_STRING(SS_TREM SS_TAP(X_E));
                }
                return false;
            case RSFT_T(I_CI):
                if (record->tap.count) {
                    if (mod_state & MOD_MASK_SHIFT) {
                        del_mods(MOD_MASK_SHIFT);
                        SEND_STRING(SS_CIRC SS_LSFT(SS_TAP(X_I)));
                    } else {
                        SEND_STRING(SS_CIRC SS_TAP(X_I));
                    }
                    return false;
                }
                break;
            case I_TR:
                if (mod_state & MOD_MASK_SHIFT) {
                    del_mods(MOD_MASK_SHIFT);
                    SEND_STRING(SS_TREM SS_LSFT(SS_TAP(X_I)));
                } else {
                    SEND_STRING(SS_TREM SS_TAP(X_I));
                }
                return false;
            case O_CI:
                if (mod_state & MOD_MASK_SHIFT) {
                    del_mods(MOD_MASK_SHIFT);
                    SEND_STRING(SS_CIRC SS_LSFT(SS_TAP(X_O)));
                } else {
                    SEND_STRING(SS_CIRC SS_TAP(X_O));
                }
                return false;
            case O_TR:
                if (mod_state & MOD_MASK_SHIFT) {
                    del_mods(MOD_MASK_SHIFT);
                    SEND_STRING(SS_TREM SS_LSFT(SS_TAP(X_O)));
                } else {
                    SEND_STRING(SS_TREM SS_TAP(X_O));
                }
                return false;
            case U_CI:
                if (mod_state & MOD_MASK_SHIFT) {
                    del_mods(MOD_MASK_SHIFT);
                    SEND_STRING(SS_CIRC SS_LSFT(SS_TAP(X_U)));
                } else {
                    SEND_STRING(SS_CIRC SS_TAP(X_U));
                }
                return false;
            case U_GR:
                tap_code(CA_UGRV);
                return false;
            case U_TR:
                if (mod_state & MOD_MASK_SHIFT) {
                    del_mods(MOD_MASK_SHIFT);
                    SEND_STRING(SS_TREM SS_LSFT(SS_TAP(X_U)));
                } else {
                    SEND_STRING(SS_TREM SS_TAP(X_U));
                }
                return false;
        };
    }
    return true;
};
