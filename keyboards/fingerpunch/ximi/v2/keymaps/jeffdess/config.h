#pragma once

// Boot mode if pressing down outer thumb key while connecting the keyboard
#define BOOTMAGIC_ROW_RIGHT 4
#define BOOTMAGIC_COLUMN_RIGHT 6
#define BOOTMAGIC_ROW_LEFT 0
#define BOOTMAGIC_COLUMN_LEFT 6

#define MASTER_RIGHT
#define POINTING_DEVICE_ROTATION_180_RIGHT
#define FP_POINTING_SCROLLING_X_REVERSED
#define FP_POINTING_SCROLLING_Y_REVERSED
#define FP_POINTING_DEFAULT_DPI 8
#define FP_POINTING_MIN_DPI 2
#define FP_POINTING_MAX_DPI 60
#define FP_HAPTIC_MOUSE_BUTTONS
#define FP_HAPTIC_CUT_COPY_PASTE
#define FP_HAPTIC_SAVE
#define FP_HAPTIC_ENABLE
#define HAPTIC_FEEDBACK

#undef TAPPING_TERM
#define TAPPING_TERM 280
#define QUICK_TAP_TERM 175
#undef COMBO_TERM
#define COMBO_TERM 60

#define ___ KC_NO

// clang-format off
#define LAYOUT_ximi_5col( \
  K00, K01, K02, K03, K04, K34, K33, K32, K31, K30, \
  K10, K11, K12, K13, K14, K44, K43, K42, K41, K40, \
  K20, K21, K22, K23, K24, K54, K53, K52, K51, K50, \
       K98, K06, K16, K26, K56, K46, K36, K99, \
            K07, K17, K27, K37, K47, K57 \
  ) \
  { \
    { ___, K00, K01, K02, K03, K04, K06, K07 }, \
    { ___, K10, K11, K12, K13, K14, K16, K17 }, \
    { ___, K20, K21, K22, K23, K24, K26, K27 }, \
    { ___, ___, K98, ___, ___, ___, ___, ___ }, \
    { ___, K30, K31, K32, K33, K34, K36, K37 }, \
    { ___, K40, K41, K42, K43, K44, K46, K47 }, \
    { ___, K50, K51, K52, K53, K54, K56, K57 }, \
    { ___, ___, K99, ___, ___, ___, ___, ___ } \
  }

