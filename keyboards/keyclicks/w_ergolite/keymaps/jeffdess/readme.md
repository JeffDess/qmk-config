# Keyclicks W-Ergolite

Here's the my keymap for this 66 keys, wireless split keyboard.

> [!warning] **Disclaimer**
> The keymap compiles, but I have not flashed it yet. The ergolite has a dongle
> that comes preflashed with Vial firmware, but QMK cannot use this bootloader
> directly.
>
> I am currently exploring the option of reflashing [STM32duino-bootloader](https://github.com/rogerclarkmelbourne/STM32duino-bootloader)
> with [df-utils](https://dfu-util.sourceforge.net/), as suggested in [QMK docs](https://docs.qmk.fm/flashing#stm32duino).

Official documentation: <https://docs.keyclicks.ca/w-keyboards/w-ergolite>

## Features

### Hardware

* Wireless Dongle (STM32F103 micro-controller)
* Gateron low profile or MX hotswap switches

### Keymap

* Colemak DH (based on CSA system layout)
* Keymap optimized for English/French and programming
* Mouse and gaming layers
* Even if 66 physical keys, the keymap is focused on 34 key typing
  (except for the gaming layer)

## Compiling

Default keymap (QWERTY with raise/lower pattern)

```sh
qmk compile -kb keyclicks/w_ergolite -km default
```

My keymap keymap

```sh
qmk compile -kb keyclicks/w_ergolite -km jeffdess
```
