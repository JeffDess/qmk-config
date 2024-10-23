#include <stdint.h>
#include "sendstring_canadian_multilingual.h"

uint8_t mod_state;
enum custom_keycodes {
    A_CI = SAFE_RANGE,
    E_CI,
    E_TR,
    I_CI,
    I_TR,
    O_CI,
    O_TR,
    U_CI,
    U_TR,
    GRAVE,
    TILDE,
    CIRC,
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
    layer_invert(current_layer);
}

void send_accent(const char *lower, const char *upper, uint8_t mod_state) {
    if (mod_state & MOD_MASK_SHIFT) {
        del_mods(MOD_MASK_SHIFT);
        SEND_STRING(upper);
    } else {
        SEND_STRING(lower);
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
                send_accent("â", "Â", mod_state);
                break;
            case E_CI:
                send_accent("ê", "Ê", mod_state);
                break;
            case E_TR:
                send_accent("ë", "Ë", mod_state);
                break;
            case I_CI:
                send_accent("î", "Î", mod_state);
                break;
            case I_TR:
                send_accent("ï", "Ï", mod_state);
                break;
            case O_CI:
                send_accent("ô", "Ô", mod_state);
                break;
            case O_TR:
                send_accent("ö", "Ö", mod_state);
                break;
            case U_CI:
                send_accent("û", "Û", mod_state);
                break;
            case U_TR:
                send_accent("ü", "Ü", mod_state);
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
