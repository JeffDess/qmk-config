#pragma once
#define MASTER_RIGHT
#define ___ KC_NO
#define UNDO C(KC_Z)
#define REDO C(S(KC_Z))
#define REDO2 C(KC_Y)

// clang-format off
#define LAYOUT_ximi_5col( \
  K00, K01, K02, K03, K04, K34, K33, K32, K31, K30, \
  K10, K11, K12, K13, K14, K44, K43, K42, K41, K40, \
  K20, K21, K22, K23, K24, K54, K53, K52, K51, K50, \
       K98, K06, K16, K26, K56, K46, K36, K99, \
            K07, K17, K27, K57, K47, K37 \
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

