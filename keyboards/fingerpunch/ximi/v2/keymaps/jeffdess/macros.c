#include <stdint.h>
#include "drivers/haptic/drv2605l.h"
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

void send_accent(uint16_t keycode, const char *accent, uint8_t mod_state) {
    if (mod_state & MOD_MASK_SHIFT) {
        del_mods(MOD_MASK_SHIFT);
        SEND_STRING(accent);
        tap_code16(S(keycode));
    } else {
        SEND_STRING(accent);
        tap_code16(keycode);
    }
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
                send_accent(KC_A, SS_CIRC, mod_state);
                return false;
            case A_GR:
                tap_code(CA_AGRV);
                return false;
            case CEDIL:
                tap_code(CA_CCED);
                return false;
            case E_CI:
                send_accent(KC_E, SS_CIRC, mod_state);
                return false;
            case E_CU:
                tap_code(CA_EACU);
                return false;
            case LSFT_T(E_GR):
                if (record->tap.count) {
                    tap_code(CA_EGRV);
                    return false;
                }
                break;
            case E_TR:
                send_accent(KC_E, SS_TREM, mod_state);
                return false;
            case RSFT_T(I_CI):
                if (record->tap.count) {
                    send_accent(KC_I, SS_CIRC, mod_state);
                    return false;
                }
                break;
            case I_TR:
                send_accent(KC_I, SS_TREM, mod_state);
                return false;
            case O_CI:
                send_accent(KC_O, SS_CIRC, mod_state);
                return false;
            case O_TR:
                send_accent(KC_O, SS_TREM, mod_state);
                return false;
            case U_CI:
                send_accent(KC_U, SS_CIRC, mod_state);
                return false;
            case U_GR:
                tap_code(CA_UGRV);
                return false;
            case U_TR:
                send_accent(KC_U, SS_TREM, mod_state);
                return false;
            case LCTL_T(KC_S):
                if (record->event.pressed) {
                    if ((get_mods() & MOD_MASK_CTRL) || (get_oneshot_mods() & MOD_MASK_CTRL)) {
                        pulse_right(DRV2605L_EFFECT_TRANSITION_CLICK_1_100);
                    }
                }
                break;
            case KC_D:
                if (record->event.pressed) {
                    if ((get_mods() & MOD_MASK_CTRL) || (get_oneshot_mods() & MOD_MASK_CTRL)) {
                        pulse_left(DRV2605L_EFFECT_STRONG_CLICK_100);
                    }
                }
                break;
        };
    }
    return true;
};
