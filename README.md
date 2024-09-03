# QMK Config

This repository includes my personal QMK keymaps to build firmware for
keyboards and trackballs:

* [Fingerpunch Ximi v2 Keyboard](keyboards/fingerpunch/ximi/v2/keymaps/jeffdess)
(build in process, keymap has not been tested correctly yet)
* [Ploopy Nano Trackball](keyboards/ploopyco/trackball_nano/rev1_001/keymaps/jeffdess)

## Build

1. Run the normal `qmk setup` procedure if you haven't already done so
  -- see [QMK Docs](https://docs.qmk.fm/#/newbs) for details.
1. Clone this repository
1. `cd` into this repository's clone directory
1. Set global userspace path: `qmk config user.overlay_dir="$(realpath .)"`
   -- you MUST be located in the cloned userspace location for this to
   work correctly
     * This will be automatically detected if you've `cd`ed into your userspace
       repository, but the above makes your userspace available regardless of
       your shell location.
1. Compile:
   * `qmk compile -kb fingerpunch/ximi/v2 -km jeffdess`
   * `qmk compile -kb ploopyco/trackball_nano/rev1_001 -km jeffdess`

Alternatively, `qmk userspace-compile` to build all of your userspace targets
at once.
