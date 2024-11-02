#include "features/achordion.h"

#define SS_CIRC SS_TAP(X_LBRC)
#define SS_TREM SS_LSFT(SS_TAP(X_LBRC))

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
