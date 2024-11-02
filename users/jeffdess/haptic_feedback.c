#include "haptic_feedback.h"

#ifdef HAPTIC_ENABLE
#    undef DRV2605L_GREETING
#    define DRV2605L_GREETING DRV2605L_EFFECT_TRANSITION_RAMP_UP_LONG_SMOOTH_2_50
#    undef DRV2605L_DEFAULT_MODE
#    define DRV2605L_DEFAULT_MODE DRV2605L_EFFECT_SHARP_TICK_1_100

extern uint8_t split_haptic_play;

void pulse_right(drv2605l_effect_t waveform) {
    drv2605l_pulse(waveform);
}

void pulse_left(drv2605l_effect_t waveform) {
    split_haptic_play = waveform;
}

void pulse_both(drv2605l_effect_t waveform) {
    pulse_left(waveform);
    pulse_right(waveform);
}
#endif
