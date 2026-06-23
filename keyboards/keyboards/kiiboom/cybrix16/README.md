# Kiiboom Cybrix 16 — QMK + VIA Firmware

## File structure

```
cybrix16_via/
├── config.h                  ← hardware config + VIA layer count
├── info.json                 ← keyboard definition (matrix, RGB, encoders, layout)
├── rules.mk                  ← enables VIA + encoder map
├── cybrix16_via.json         ← VIA sideload file (upload once to use.keeb.io)
└── keymaps/
    └── via/
        ├── keymap.c          ← 6-layer keymap with encoder map
        └── rules.mk
```

## How to build

### 1 – Place files in QMK
Copy the `cybrix16_via/` folder into your QMK tree:
```
qmk_firmware/keyboards/kiiboom/cybrix16/
```
The folder acts as the keyboard definition. The `keymaps/via/` subfolder is your keymap.

### 2 – Build
```bash
qmk compile -kb kiiboom/cybrix16 -km via
```
Or with the legacy make command:
```bash
make kiiboom/cybrix16:via
```

### 3 – Flash
Enter the bootloader first (one of three ways):
- **Bootmagic**: hold `ESC` (top-left key) while plugging in USB
- **Physical button**: press the reset button on the back of the PCB
- **Keycode**: press the key mapped to `QK_BOOT`

Then flash:
```bash
qmk flash -kb kiiboom/cybrix16 -km via
```
Or:
```bash
make kiiboom/cybrix16:via:flash
```
QMK Toolbox can also be used — select the `.bin` file and hit Flash.

## Using VIA

1. Go to **[use.keeb.io](https://use.keeb.io)** (or the VIA desktop app).
2. Click **Load** → **Load Draft Definition** and upload `cybrix16_via.json`.
3. Plug in the Cybrix 16 — VIA will detect it automatically.
4. Remap all 16 keys, the 4 encoder-push-button positions, and all 3 rotary
   encoders (CCW / CW) across all 6 layers in real time.

## Default Layer 0 layout

```
┌──────────────────┬──────┬──────┬──────┐
│  My Computer     │  7   │  8   │  9   │
├──────────────────┼──────┼──────┼──────┤
│  Browser Home    │  4   │  5   │  6   │
├──────────────────┼──────┼──────┼──────┤
│  Ctrl+X (cut)    │  1   │  2   │  3   │
├──────────────────┼──────┼──────┼──────┤
│  Ctrl+C (copy)   │Ctrl+V│  0   │  .   │
├──────────────────┼──────┼──────┼──────┤
│  (encoder push)  │RGB   │ Play │ ►L1  │
└──────────────────┴──────┴──────┴──────┘

Encoders (layer 0):
  Knob 1 (left)   – Page Up / Page Down
  Knob 2 (middle) – Prev Track / Next Track
  Knob 3 (right)  – Volume Down / Volume Up
```

## Layer cycling

The bottom-right key on each layer advances to the next layer:
- Layer 0 → TO(1) → TO(2) → TO(3) → TO(4) → TO(5) → TO(0)

Layer 5 is the RGB control layer. All layers 1-4 are blank (`KC_TRNS`) by
default so you can fill them in VIA without reflashing.

## Notes

- `DYNAMIC_KEYMAP_LAYER_COUNT 6` is set in `config.h` — VIA will show all 6 layers.
- Encoder CW/CCW are also fully remappable in VIA (use.keeb.io supports this).
- The RGB LED count is set to **16** (one per key). Adjust `RGB_MATRIX_LED_COUNT`
  in `config.h` if your PCB revision differs.
- Processor: STM32F103 (stm32duino bootloader).
