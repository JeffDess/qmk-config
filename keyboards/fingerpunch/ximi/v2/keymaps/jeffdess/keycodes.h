#define DPI_RESET FP_POINT_DPI_RESET
#define ZOOM_RESET LCTL(KC_0)

#define NAV_RET LT(_NAV, KC_ENTER)
#define NUM_ESC LT(_NUMBERS, KC_ESC)
#define SYM_SP LT(_SYMBOLS, KC_SPACE)

#define REDO C(S(KC_Z))
#define REDO2 C(KC_Y)
#define UNDO C(KC_Z)

// Tmux -> Ctrl + Alt + J
#define SS_TMUX SS_LCTL(SS_LALT("j"))
#define TMUX LCTL(LALT(KC_J))
