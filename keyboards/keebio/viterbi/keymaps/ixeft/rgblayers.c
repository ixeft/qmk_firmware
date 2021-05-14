#ifdef RGBLIGHT_ENABLE
const rgblight_segment_t PROGMEM capslock_layer[] = RGBLIGHT_LAYER_SEGMENTS(
        {0, 12, HSV_RED}       // Light 3 LEDs, starting with LED 0
        //        {0, 3, HSV_RED},       // Light 3 LEDs, starting with LED 0
        //        {6, 3, HSV_RED}       // Light 3 LEDs, starting with LED 6
        );

const rgblight_segment_t PROGMEM function_layer[] = RGBLIGHT_LAYER_SEGMENTS(
        {0, 12, HSV_GREEN}       // Light 3 LEDs, starting with LED 0
        //        {0, 3, HSV_GREEN},       // Light 3 LEDs, starting with LED 0
        //        {6, 3, HSV_GREEN}       // Light 3 LEDs, starting with LED 6
        );

// Now define the array of layers. Later layers take precedence
const rgblight_segment_t* const PROGMEM rgb_layers[] = RGBLIGHT_LAYERS_LIST(
        capslock_layer,
        function_layer
        );

void keyboard_post_init_user(void) {

    rgblight_layers = rgb_layers;

}
bool led_update_user(led_t led_state) {
    rgblight_set_layer_state(0, led_state.caps_lock);
    return true;
}

//layer_state_t default_layer_state_set_user(layer_state_t state) {
//    rgblight_set_layer_state(1, layer_state_cmp(state, _DVORAK));
//    return state;
//}

layer_state_t layer_state_set_user(layer_state_t state) {
    rgblight_set_layer_state(1, layer_state_cmp(state, 1));
    return state;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_LSFT:
        case KC_RSFT:
            if (record->event.pressed) {
                rgblight_set_layer_state(0, true);
            } else {
                rgblight_set_layer_state(0, host_keyboard_led_state().caps_lock);
            }
            return true; // Skip all further processing of this key
        default:
            return true; // Process all other keycodes normally
    }
}
#endif
