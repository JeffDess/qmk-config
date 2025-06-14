#pragma once

#ifdef TAPPING_TERM
#    undef TAPPING_TERM
#endif

// Timings
#define TAPPING_TERM 200
#define TAPPING_TERM_PER_KEY
#define THUMB_TAP_TERM 180
#define HRM_TAP_TERM 220
#define QUICK_TAP_TERM 160
#define PERMISSIVE_HOLD
#define CHORDAL_HOLD

#ifdef ENCODER_ENABLE
#    include "encoders.h"
#endif
