const key_override_t backspace_delete_override =
    ko_make_basic(MOD_MASK_SHIFT, KC_BACKSPACE, KC_DEL);

const key_override_t space_nbsp_override =
    ko_make_with_layers(MOD_MASK_SHIFT, SYM_SP, RALT(KC_SPACE), 1 << _COLEMAK);

const key_override_t plus_minus_override =
    ko_make_with_layers(MOD_MASK_SHIFT, CA_PLUS, CA_MINS, 1 << _NUMBERS);

const key_override_t multi_div_override =
    ko_make_with_layers(MOD_MASK_SHIFT, CA_ASTR, CA_SLSH, 1 << _NUMBERS);

const key_override_t comma_dot_override =
    ko_make_with_layers(MOD_MASK_SHIFT, KC_COMM, KC_DOT, 1 << _NUMBERS);

const key_override_t slash_backslash_override =
    ko_make_with_layers(MOD_MASK_SHIFT, CA_SLSH, CA_BSLS, 1 << _SYMBOLS);

const key_override_t question_mark_inverted_override =
    ko_make_basic(MOD_MASK_SHIFT, CA_QUES, CA_IQUE);

const key_override_t exclamation_inverted_override =
    ko_make_basic(MOD_MASK_SHIFT, CA_EXLM, CA_IEXL);

const key_override_t escape_shift_click_override =
    ko_make_basic(MOD_MASK_SHIFT, NUM_ESC, S(KC_MS_BTN1));

const key_override_t escape_ctrl_click_override =
    ko_make_basic(MOD_MASK_CTRL, NUM_ESC, C(KC_MS_BTN1));

// clang-format off
const key_override_t **key_overrides = (const key_override_t *[]){
    &backspace_delete_override,
    &space_nbsp_override,
    &plus_minus_override,
    &multi_div_override,
    &comma_dot_override,
    &slash_backslash_override,
    &escape_shift_click_override,
    &escape_ctrl_click_override,
    &exclamation_inverted_override,
    &question_mark_inverted_override
};
