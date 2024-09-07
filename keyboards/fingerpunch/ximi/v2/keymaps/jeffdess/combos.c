enum combos {
    CB_COPY,
    CB_CUT,
    CB_PASTE,
    CB_PRINTSCREEN,
    CB_CAPS_WORD,
    CB_CAPS_LOCK,
    CB_TMUX_COMMAND,
    CB_TMUX_SESS,
    CB_MOUSE_LAYER,
    CB_GAME_LAYER,
    CB_FAT_ARROW,
    CB_ARROW,
    CB_LTE,
    CB_GTE,
    CB_TAB,
    CB_NAV_TOGGLE
};

const uint16_t PROGMEM cut[]          = {KC_Z, KC_X, COMBO_END};
const uint16_t PROGMEM copy[]         = {KC_X, KC_C, COMBO_END};
const uint16_t PROGMEM paste[]        = {KC_C, KC_D, COMBO_END};
const uint16_t PROGMEM printscreen[]  = {KC_Y, KC_SCLN, COMBO_END};
const uint16_t PROGMEM capsword[]     = {KC_T, KC_N, COMBO_END};
const uint16_t PROGMEM capslock[]     = {KC_S, KC_E, COMBO_END};
const uint16_t PROGMEM tmux_command[] = {KC_R, KC_S, KC_SCLN, COMBO_END};
const uint16_t PROGMEM tmux_session[] = {KC_A, KC_R, KC_S, COMBO_END};
const uint16_t PROGMEM mouse_layer[]  = {KC_Q, KC_P, COMBO_END};
const uint16_t PROGMEM game_layer[]   = {KC_L, KC_SCLN, COMBO_END};
const uint16_t PROGMEM fat_arrow[]    = {CA_RPRN, CA_EQL, COMBO_END};
const uint16_t PROGMEM arrow[]        = {CA_RBRC, CA_UNDS, COMBO_END};
const uint16_t PROGMEM lte[]          = {CA_LABK, CA_RABK, COMBO_END};
const uint16_t PROGMEM gte[]          = {CA_LDAQ, CA_RDAQ, COMBO_END};
const uint16_t PROGMEM tab[]          = {KC_BSPC, SYM_SP, COMBO_END};
const uint16_t PROGMEM nav_toggle[]   = {NAV_RET, NUM_ESC, COMBO_END};

combo_t key_combos[] = {
    [CB_CUT]          = COMBO(cut, LCTL(KC_X)),
    [CB_COPY]         = COMBO(copy, LCTL(KC_C)),
    [CB_PASTE]        = COMBO(paste, LCTL(KC_V)),
    [CB_PRINTSCREEN]  = COMBO(printscreen, KC_PSCR),
    [CB_CAPS_WORD]    = COMBO(capsword, QK_CAPS_WORD_TOGGLE),
    [CB_CAPS_LOCK]    = COMBO(capslock, KC_CAPS),
    [CB_TMUX_COMMAND] = COMBO(tmux_command, TMUX_CMD),
    [CB_TMUX_SESS]    = COMBO(tmux_command, TMUX_SESSION),
    [CB_MOUSE_LAYER]  = COMBO(mouse_layer, TG(_MOUSE)),
    [CB_GAME_LAYER]   = COMBO(game_layer, TG(_GAME)),
    [CB_FAT_ARROW]    = COMBO(fat_arrow, FAT_ARROW),
    [CB_ARROW]        = COMBO(arrow, ARROW),
    [CB_LTE]          = COMBO(lte, LTE),
    [CB_GTE]          = COMBO(gte, GTE),
    [CB_TAB]          = COMBO(tab, KC_TAB),
    [CB_NAV_TOGGLE]   = COMBO(nav_toggle, TG(_NAV)),
};
