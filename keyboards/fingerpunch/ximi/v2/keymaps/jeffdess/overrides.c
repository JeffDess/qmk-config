const key_override_t backspace_delete_override =
    ko_make_basic(MOD_MASK_SHIFT, KC_BACKSPACE, KC_DEL);

const key_override_t plus_minus_override =
    ko_make_with_layers(MOD_MASK_SHIFT, CA_PLUS, CA_MINS, ~_NUMBERS);

const key_override_t multi_div_override =
    ko_make_with_layers(MOD_MASK_SHIFT, CA_ASTR, CA_SLSH, ~_NUMBERS);

const key_override_t comma_dot_override =
    ko_make_with_layers(MOD_MASK_SHIFT, KC_COMM, KC_DOT, ~_NUMBERS);

const key_override_t slash_backslash_override =
const key_override_t dash_tilde_override =
    ko_make_with_layers(MOD_MASK_SHIFT, CA_MINS, CA_TILD, _SYMBOLS);

const key_override_t escape_shift_click_override =
    ko_make_basic(MOD_MASK_SHIFT, KC_ESC, S(KC_MS_BTN1));

const key_override_t escape_ctrl_click_override =
    ko_make_basic(MOD_MASK_CTRL, KC_ESC, C(KC_MS_BTN1));

// clang-format off
const key_override_t **key_overrides = (const key_override_t *[]){
    &backspace_delete_override,
    &plus_minus_override,
    &multi_div_override,
    &comma_dot_override,
    &slash_backslash_override,
    &dash_tilde_override,
    &escape_shift_click_override,
};
