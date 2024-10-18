#pragma once
#define MASTER_RIGHT
#define ___ KC_NO
#define UNDO C(KC_Z)
#define REDO C(S(KC_Z))
#define REDO2 C(KC_Y)

// clang-format off
#define LAYOUT_ximi_5col( \
  K01, K02, K03, K04, K05, K35, K34, K33, K32, K31, \
  K11, K12, K13, K14, K15, K45, K44, K43, K42, K41, \
  K21, K22, K23, K24, K25, K55, K54, K53, K52, K51, \
       K98, K06, K16, K26, K56, K46, K36, K99,      \
            K07, K17, K27, K57, K47, K37 \
  ) \
  { \
    { K01, K02, K03, K04, K05, K06, K07 }, \
    { K11, K12, K13, K14, K15, K16, K17 }, \
    { K21, K22, K23, K24, K25, K26, K27 }, \
    { ___, K98, ___, ___, ___, ___, ___ }, \
    { K31, K32, K33, K34, K35, K36, K37 }, \
    { K41, K42, K43, K44, K45, K46, K47 }, \
    { K51, K52, K53, K54, K55, K56, K57 }, \
    { ___, K99, ___, ___, ___, ___, ___ } \
  }


