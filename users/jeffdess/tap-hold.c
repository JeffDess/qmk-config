uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    /*printf(" COL: %d ", record->event.key.col);*/
    /*printf(" ROW: %d ", record->event.key.row);*/

    uint8_t thumb_col     = 6;
    uint8_t hrm_left_col  = 1;
    uint8_t hrm_right_col = 5;

    if (record->event.key.col == thumb_col) {
        return THUMB_TAP_TERM;
    }

    if (record->event.key.col == hrm_left_col || record->event.key.col == hrm_right_col) {
        return HRM_TAP_TERM;
    }
    return TAPPING_TERM;
}
