#include "drivers/haptic/drv2605l.h"
#include "sendstring_canadian_multilingual.h"
#include "haptic_feedback.h"

uint8_t mod_state;

void send_accent(uint16_t keycode, const char *accent, uint8_t mod_state) {
    if (mod_state & MOD_MASK_SHIFT) {
        del_mods(MOD_MASK_SHIFT);
        send_string(accent);
        tap_code16(S(keycode));
    } else {
        send_string(accent);
        tap_code16(keycode);
    }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
#ifdef CONSOLE_ENABLE
    uprintf("KL: kc: 0x%04X, col: %2u, row: %2u, pressed: %u, time: %5u, int: %u, count: %u\n",
            keycode, record->event.key.col, record->event.key.row, record->event.pressed,
            record->event.time, record->tap.interrupted, record->tap.count);
#endif

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
            case SYM_SP:
                if ((get_mods() & MOD_MASK_SHIFT) || (get_oneshot_mods() & MOD_MASK_SHIFT)) {
                    if (!record->tap.count && record->event.pressed) {
                        layer_move(_SYMBOLS);
                        return false;
                    }
                }
            case LCTL_T(KC_S):
                if (record->event.pressed) {
                    if ((get_mods() & MOD_MASK_CTRL) || (get_oneshot_mods() & MOD_MASK_CTRL)) {
#ifdef HAPTIC_ENABLE
                        pulse_right(DRV2605L_EFFECT_TRANSITION_CLICK_1_100);
#endif
                    }
                }
                break;
            case KC_D:
                if (record->event.pressed) {
                    if ((get_mods() & MOD_MASK_CTRL) || (get_oneshot_mods() & MOD_MASK_CTRL)) {
#ifdef HAPTIC_ENABLE
                        pulse_right(DRV2605L_EFFECT_STRONG_CLICK_100);
#endif
                    }
                }
                break;
        };
    }
    return true;
};
