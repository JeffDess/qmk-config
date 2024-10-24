#include <stdint.h>
#include "sendstring_canadian_multilingual.h"

#define SS_CIRC SS_TAP(X_LBRC)
#define SS_TREM SS_ALGR(SS_TAP(X_LBRC))

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
                break;
            case CIRC:
                SEND_STRING("^");
                break;
            case TILDE:
                SEND_STRING("~");
                break;
            case A_CI:
                if (mod_state & MOD_MASK_SHIFT) {
                    del_mods(MOD_MASK_SHIFT);
                    SEND_STRING(SS_CIRC SS_LSFT(SS_TAP(X_A)));
                } else {
                    SEND_STRING(SS_CIRC SS_TAP(X_A));
                }
                deactivate_current_layer();
                break;
            case A_GR:
                tap_code(CA_AGRV);
                deactivate_current_layer();
                break;
            case CEDIL:
                tap_code(CA_CCED);
                deactivate_current_layer();
                break;
            case E_CU:
                tap_code(CA_EACU);
                deactivate_current_layer();
                break;
            case E_CI:
                if (mod_state & MOD_MASK_SHIFT) {
                    del_mods(MOD_MASK_SHIFT);
                    SEND_STRING(SS_CIRC SS_LSFT(SS_TAP(X_E)));
                } else {
                    SEND_STRING(SS_CIRC SS_TAP(X_E));
                }
                deactivate_current_layer();
                break;
            case E_GR:
                tap_code(CA_EGRV);
                deactivate_current_layer();
                break;
            case E_TR:
                if (mod_state & MOD_MASK_SHIFT) {
                    del_mods(MOD_MASK_SHIFT);
                    SEND_STRING(SS_TREM SS_LSFT(SS_TAP(X_E)));
                } else {
                    SEND_STRING(SS_TREM SS_TAP(X_E));
                }
                deactivate_current_layer();
                break;
            case I_CI:
                if (mod_state & MOD_MASK_SHIFT) {
                    del_mods(MOD_MASK_SHIFT);
                    SEND_STRING(SS_CIRC SS_LSFT(SS_TAP(X_I)));
                } else {
                    SEND_STRING(SS_CIRC SS_TAP(X_I));
                }
                deactivate_current_layer();
                break;
            case I_TR:
                if (mod_state & MOD_MASK_SHIFT) {
                    del_mods(MOD_MASK_SHIFT);
                    SEND_STRING(SS_TREM SS_LSFT(SS_TAP(X_I)));
                } else {
                    SEND_STRING(SS_TREM SS_TAP(X_I));
                }
                deactivate_current_layer();
                break;
            case O_CI:
                if (mod_state & MOD_MASK_SHIFT) {
                    del_mods(MOD_MASK_SHIFT);
                    SEND_STRING(SS_CIRC SS_LSFT(SS_TAP(X_O)));
                } else {
                    SEND_STRING(SS_CIRC SS_TAP(X_O));
                }
                deactivate_current_layer();
                break;
            case O_TR:
                if (mod_state & MOD_MASK_SHIFT) {
                    del_mods(MOD_MASK_SHIFT);
                    SEND_STRING(SS_TREM SS_LSFT(SS_TAP(X_O)));
                } else {
                    SEND_STRING(SS_TREM SS_TAP(X_O));
                }
                deactivate_current_layer();
                break;
            case U_CI:
                if (mod_state & MOD_MASK_SHIFT) {
                    del_mods(MOD_MASK_SHIFT);
                    SEND_STRING(SS_CIRC SS_LSFT(SS_TAP(X_U)));
                } else {
                    SEND_STRING(SS_CIRC SS_TAP(X_U));
                }
                deactivate_current_layer();
                break;
            case U_GR:
                tap_code(CA_UGRV);
                deactivate_current_layer();
                break;
            case U_TR:
                if (mod_state & MOD_MASK_SHIFT) {
                    del_mods(MOD_MASK_SHIFT);
                    SEND_STRING(SS_TREM SS_LSFT(SS_TAP(X_U)));
                } else {
                    SEND_STRING(SS_TREM SS_TAP(X_U));
                }
                deactivate_current_layer();
                break;
            case FAT_ARROW:
                SEND_STRING(" => ");
                break;
            case ARROW:
                SEND_STRING(" -> ");
                break;
            case GTE:
                SEND_STRING(" >= ");
                break;
            case LTE:
                SEND_STRING(" <= ");
                break;
            case TMUX_CMD:
                SEND_STRING(SS_TMUX SS_TAP(X_SEMICOLON));
                break;
            case TMUX_SESSION:
                SEND_STRING(SS_TMUX SS_TAP(X_SEMICOLON) SS_DELAY(10) "new -s ");
                break;
        }
    }
    return true;
};
