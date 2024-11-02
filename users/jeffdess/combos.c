#include <stdint.h>
#include "drivers/haptic/drv2605l.h"
#include "combos.h"
#include "haptic_feedback.h"

const uint16_t PROGMEM cut[]          = {KC_Z, KC_X, COMBO_END};
const uint16_t PROGMEM copy[]         = {KC_X, KC_C, COMBO_END};
const uint16_t PROGMEM paste[]        = {KC_C, KC_D, COMBO_END};
const uint16_t PROGMEM printscreen[]  = {KC_Y, KC_SCLN, COMBO_END};
const uint16_t PROGMEM capsword[]     = {LSFT_T(KC_T), RSFT_T(KC_N), COMBO_END};
const uint16_t PROGMEM capslock[]     = {LCTL_T(KC_S), LCTL_T(KC_E), COMBO_END};
const uint16_t PROGMEM tmux[]         = {LALT_T(KC_R), LCTL_T(KC_S), COMBO_END};
const uint16_t PROGMEM tmux_command[] = {LALT_T(KC_R), LCTL_T(KC_S), RGUI_T(KC_O), COMBO_END};
const uint16_t PROGMEM tmux_session[] = {LGUI_T(KC_A), LALT_T(KC_R), LCTL_T(KC_S), COMBO_END};
const uint16_t PROGMEM mouse_layer[]  = {KC_Q, KC_P, COMBO_END};
const uint16_t PROGMEM game_layer[]   = {KC_L, KC_SCLN, COMBO_END};
const uint16_t PROGMEM fat_arrow[]    = {CA_LPRN, CA_RPRN, COMBO_END};
const uint16_t PROGMEM arrow[]        = {CA_LBRC, CA_RBRC, COMBO_END};
const uint16_t PROGMEM lte[]          = {CA_LABK, CA_RABK, COMBO_END};
const uint16_t PROGMEM gte[]          = {CA_LDAQ, CA_RDAQ, COMBO_END};
const uint16_t PROGMEM tab[]          = {KC_BSPC, SYM_SP, COMBO_END};
const uint16_t PROGMEM nav_toggle[]   = {NAV_RET, NUM_ESC, COMBO_END};
const uint16_t PROGMEM mouse_lclick[] = {KC_F, KC_P, COMBO_END};
const uint16_t PROGMEM mouse_rclick[] = {KC_Q, KC_W, COMBO_END};

combo_t key_combos[] = {[CB_CUT]          = COMBO_ACTION(cut),
                        [CB_COPY]         = COMBO_ACTION(copy),
                        [CB_PASTE]        = COMBO_ACTION(paste),
                        [CB_PRINTSCREEN]  = COMBO(printscreen, KC_PSCR),
                        [CB_CAPS_WORD]    = COMBO(capsword, QK_CAPS_WORD_TOGGLE),
                        [CB_CAPS_LOCK]    = COMBO(capslock, KC_CAPS),
                        [CB_TMUX_COMMAND] = COMBO(tmux_command, TMUX_CMD),
                        [CB_TMUX_SESS]    = COMBO(tmux_session, TMUX_SESSION),
                        [CB_TMUX]         = COMBO(tmux, LCTL(LALT(KC_J))),
                        [CB_MOUSE_LAYER]  = COMBO(mouse_layer, TG(_MOUSE)),
                        [CB_GAME_LAYER]   = COMBO(game_layer, TG(_GAME)),
                        [CB_FAT_ARROW]    = COMBO(fat_arrow, FAT_ARROW),
                        [CB_ARROW]        = COMBO(arrow, ARROW),
                        [CB_LTE]          = COMBO(lte, LTE),
                        [CB_GTE]          = COMBO(gte, GTE),
                        [CB_TAB]          = COMBO(tab, KC_TAB),
                        [CB_NAV_TOGGLE]   = COMBO(nav_toggle, TG(_NAV)),
                        [CB_MS_LCLICK]    = COMBO(mouse_lclick, KC_MS_BTN1),
                        [CB_MS_RCLICK]    = COMBO(mouse_rclick, KC_MS_BTN2)};

void process_combo_event(uint16_t combo_index, bool pressed) {
    switch (combo_index) {
        case CB_COPY:
            if (pressed) {
                register_code16(KC_LCTL);
                tap_code16(KC_C);
                unregister_code16(KC_LCTL);
#ifdef HAPTIC_ENABLE
                pulse_both(DRV2605L_EFFECT_LONG_DOUBLE_SHARP_CLICK_STRONG_1_100);
#endif
            }
            break;
        case CB_CUT:
            if (pressed) {
                register_code16(KC_LCTL);
                tap_code16(KC_X);
                unregister_code16(KC_LCTL);
#ifdef HAPTIC_ENABLE
                pulse_both(DRV2605L_EFFECT_LONG_DOUBLE_SHARP_CLICK_STRONG_1_100);
#endif
            }
            break;
        case CB_PASTE:
            if (pressed) {
                register_code16(KC_LCTL);
                tap_code16(KC_V);
                unregister_code16(KC_LCTL);
#ifdef HAPTIC_ENABLE
                pulse_both(DRV2605L_EFFECT_SOFT_BUMP_100);
#endif
            }
            break;
    }
}

uint8_t combo_ref_from_layer(uint8_t layer) {
    switch (get_highest_layer(layer_state)) {
        case _SYMBOLS:
            return _SYMBOLS;
        case _NAV:
            return _NAV;
        default:
            return _COLEMAK;
    }

    return layer; // important if default is not in case.
}
