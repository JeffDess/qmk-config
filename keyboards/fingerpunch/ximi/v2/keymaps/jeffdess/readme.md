# Ximi v2

This is my [Ximi](https://fingerpunch.xyz/products/ximi-v2), a 36 keys with a bunch of features:

* Dual trackballs
* Rotary Encoders
* 3-way toggle switches
* Haptic Feedback
* Hotswap Gateron low-profile switches (KS33)

## Keymap

The keymap is optimized for software development and French/English typing.

* [Colemak-DH](https://colemakmods.github.io/mod-dh/) layout
* French and Spanish characters support with dead key and accent layer
* Home row mods
* Mouse keys support
* Gaming Layer (shifted WASD position, free of homerow mods)
* Mnemonic key overrides

<p><small>
  NOTE: The keymap is programmed over the Canadian Multilingual Standard (CSA)
  base layout.
</small></p>

Also check out my other [ZMK keyboards](https://github.com/JeffDess/zmk-config)
based on the same keymap. I haven't set up a keymap drawer for this keymap yet,
but here's the keymap of my Urchin (I use 34 keys instead of 36 on the Ximi).
Only difference is the QWERTY and Ergo-L layers that I didn't include on this
keymap.

![Urchin Keymap drawing](https://github.com/JeffDess/zmk-config/raw/main/images/keymaps/urchin_keymap.svg)

## Building the board

### Guide

I have followed [Ximi v1 build guide](https://github.com/sadekbaroudi/fingerpunch/blob/master/keyboards/ximi/v1/BUILDGUIDE.md)
for assembly and soldering the Ximi.

### BOM

| Item                   | Qty | Description/Link                         |
|------------------------|----:|:-----------------------------------------|
| Ximi PCB               | 2   | [Fingerpunch Store](https://fingerpunch.xyz/product/ximi-v2/) |
| Case (Top Left)        | 1   | JLCPCB 9600 resin painted matte silver ([STL](https://github.com/sadekbaroudi/fingerpunch/blob/master/keyboards/ximi/v1/cases/stl/xi-5-choc-tr-ec-3wt-left.stl))              |
| Case (Top Right)       | 1   | JLCPCB 9600 resin painted matte silver ([STL](https://github.com/sadekbaroudi/fingerpunch/blob/master/keyboards/ximi/v1/cases/stl/xi-5-choc-tr-ec-3wt-right.stl))              |
| Case (Bottom Left)     | 1   | JLCPCB MJF Black ([STL](https://github.com/sadekbaroudi/fingerpunch/blob/master/keyboards/ximi/v1/cases/stl/xi-5-bot-2.8mm-trackball-left.stl)). I tried regular black resin and came out way too warped! |
| Case (Bottom Right)    | 1   | JLCPCB MJF Black ([STL](https://github.com/sadekbaroudi/fingerpunch/blob/master/keyboards/ximi/v1/cases/stl/xi-5-bot-2.8mm-trackball-right.stl)). |
| Case (Trackball Cover) | 2   | JLCPCB Imagine Black resin ([STL](https://github.com/sadekbaroudi/fingerpunch/blob/master/keyboards/ximi/v1/cases/stl/xi-trackball-cover-slimmer-bottom-edge.stl)) |
| Hotswap sockets        | 36  | Gateron KS33 |
| Keyboard switches      | 36  | [Gateron KS33 Aloe](https://nuphy.com/collections/switches/products/nuphy-aloe-l37-low-profile-switches) (Linear 37gpf) |
| Keycaps                | 36  | [KLP Lamé MX](https://github.com/braindefender/KLP-Lame-Keycaps) printed with Imagine Black resin |
| TRRS jacks             | 2   | Included with Ximi PCB |
| TRRS cable             | 1   | Angled, 60cm. |
| Rotary encoders        | 2   | EC11 |
| Rotary encoder caps    | 2   | 14,5mm aluminium found on Ali |
| Haptic Modules         | 2   | [Pimoroni DRV2605L](https://shop.pimoroni.com/products/drv2605l-linear-actuator-haptic-breakout) |
| Trackball Sensors      | 2   | PMW3360DM-T2QU + lens |
| Trackball PCB          | 2   | [Fingerpunch Store](https://fingerpunch.xyz/product/vik-pmw3360-trackball-module/) |
| Trackballs             | 2   | 34mm, Perixx Like |
| FPC Cables             | 2   | 10cm ribbon cables for linking PCBs. Incleded with trackball PCB |
| Stainless bearings     | 6   | For static trackball sockets. Included with Ximi PCB |
| Heatset inserts        | 14  | M2 6mm (OD 3.5mm). Compression fit, just push them without any heat. Might need some teflon tape for a snug fit in the trackball ones. |
| Screws                 | 14  | M2 5mm |
| Tenting legs           | 4   | Laptop legs were slippery, now with 3 positions phone kickstand |
| Anti-slip feets        | 4   | Silicone |
| Electrical tape        |     | Put between haptic modules and encoders |
