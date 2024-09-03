#include <stdint.h>
#include "sendstring_canadian_multilingual.h"

#define TMUX SS_LCTL(SS_LALT("j")) // Tmux -> Ctrl + Alt + J

uint8_t mod_state;
enum custom_keycodes {
    ACC_CI = SAFE_RANGE,
    ACC_GR,
    ACC_TR,
    A_CI,
    A_GR,
    CEDIL,
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
            case ACC_CI:
                send_dead_accent("^");
                break;
            case ACC_GR:
                send_dead_accent("`");
                break;
            case ACC_TR:
                send_dead_accent("¨");
                break;
            case A_CI:
                send_accent("â", "Â", mod_state);
                break;
            case A_GR:
                send_accent("à", "À", mod_state);
                break;
            case CEDIL:
                send_accent("ç", "Ç", mod_state);
                break;
            case E_CI:
                send_accent("ê", "Ê", mod_state);
                break;
            case E_CU:
                send_accent("é", "É", mod_state);
                break;
            case E_GR:
                send_accent("è", "È", mod_state);
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
            case U_GR:
                send_accent("ù", "Ù", mod_state);
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
                SEND_STRING(TMUX ";");
                break;
            case TMUX_SESSION:
                SEND_STRING(TMUX "; new -s ");
                break;
        }
    }
    return true;
};
