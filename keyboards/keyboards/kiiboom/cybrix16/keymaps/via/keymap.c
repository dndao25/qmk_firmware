// Copyright 2024 KiiBOOM
// SPDX-License-Identifier: GPL-2.0-or-later
//
// Kiiboom Cybrix 16 — VIA keymap
// Layout: 4×4 keys (16) + 1 encoder row (4 positions) = 20 matrix positions
// Encoders: 3 rotary knobs, all remappable via VIA
//
// Layer cycling: bottom-right key on each layer steps to the next layer.
// Layer 5 (RGB) returns to layer 0.

#include QMK_KEYBOARD_H

// ─── Encoder map ────────────────────────────────────────────────────────────
// All 6 layers × 3 encoders × 2 directions.
// Layer 0 defaults: knob1=Page Up/Down, knob2=Prev/Next Track, knob3=Vol-/Vol+
// Layers 1-5 are set to KC_TRNS so VIA can override them freely.
#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [0] = {
        ENCODER_CCW_CW(KC_PAGE_UP,            KC_PAGE_DOWN),
        ENCODER_CCW_CW(KC_MEDIA_PREV_TRACK,   KC_MEDIA_NEXT_TRACK),
        ENCODER_CCW_CW(KC_VOLD,               KC_VOLU)
    },
    [1] = {
        ENCODER_CCW_CW(KC_TRNS, KC_TRNS),
        ENCODER_CCW_CW(KC_TRNS, KC_TRNS),
        ENCODER_CCW_CW(KC_TRNS, KC_TRNS)
    },
    [2] = {
        ENCODER_CCW_CW(KC_TRNS, KC_TRNS),
        ENCODER_CCW_CW(KC_TRNS, KC_TRNS),
        ENCODER_CCW_CW(KC_TRNS, KC_TRNS)
    },
    [3] = {
        ENCODER_CCW_CW(KC_TRNS, KC_TRNS),
        ENCODER_CCW_CW(KC_TRNS, KC_TRNS),
        ENCODER_CCW_CW(KC_TRNS, KC_TRNS)
    },
    [4] = {
        ENCODER_CCW_CW(KC_TRNS, KC_TRNS),
        ENCODER_CCW_CW(KC_TRNS, KC_TRNS),
        ENCODER_CCW_CW(KC_TRNS, KC_TRNS)
    },
    [5] = {
        ENCODER_CCW_CW(KC_TRNS, KC_TRNS),
        ENCODER_CCW_CW(KC_TRNS, KC_TRNS),
        ENCODER_CCW_CW(KC_TRNS, KC_TRNS)
    },
};
#endif // ENCODER_MAP_ENABLE

// ─── Keymaps ─────────────────────────────────────────────────────────────────
// LAYOUT order (20 keys):
//   Row 0: K00  K01  K02  K03
//   Row 1: K10  K11  K12  K13
//   Row 2: K20  K21  K22  K23
//   Row 3: K30  K31  K32  K33
//   Row 4: K40  K42  K41  K43   ← encoder push buttons (matrix col order differs)
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    // ── Layer 0 : Numpad / General ──────────────────────────────────────────
    [0] = LAYOUT(
        KC_MY_COMPUTER, KC_7,        KC_8,    KC_9,
        KC_WWW_HOME,    KC_4,        KC_5,    KC_6,
        LCTL(KC_X),     KC_1,        KC_2,    KC_3,
        LCTL(KC_C),     LCTL(KC_V),  KC_0,    KC_DOT,
        KC_TRNS,        RGB_TOG,     KC_MPLY, TO(1)
    ),

    // ── Layer 1 : User layer (blank → customise in VIA) ─────────────────────
    [1] = LAYOUT(
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, TO(2)
    ),

    // ── Layer 2 : User layer ────────────────────────────────────────────────
    [2] = LAYOUT(
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, TO(3)
    ),

    // ── Layer 3 : User layer ────────────────────────────────────────────────
    [3] = LAYOUT(
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, TO(4)
    ),

    // ── Layer 4 : User layer ────────────────────────────────────────────────
    [4] = LAYOUT(
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, TO(5)
    ),

    // ── Layer 5 : RGB controls ───────────────────────────────────────────────
    [5] = LAYOUT(
        RGB_TOG,          RGB_MOD,          RGB_RMOD,        RGB_HUD,
        RGB_HUI,          RGB_SAD,          RGB_SAI,         RGB_VAD,
        RGB_VAI,          RGB_SPD,          RGB_SPI,         RGB_MODE_PLAIN,
        RGB_MODE_BREATHE, RGB_MODE_RAINBOW, KC_NO,           KC_NO,
        KC_NO,            KC_NO,            KC_NO,           TO(0)
    ),
};
