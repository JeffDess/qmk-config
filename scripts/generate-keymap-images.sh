#!/bin/bash

ROOT=$(dirname "$(readlink -f "$0")" | sed 's/\/[^/]*$//')
IMG="$ROOT/keyboards/fingerpunch/ximi/v2/keymaps/jeffdess"
KMD="$ROOT/keymap-drawer"

parse () {
    KBD_NAME=$1

    qmk c2json -kb fingerpunch/ximi/v2 -km jeffdess --no-cpp | \
        keymap -c "$KMD/config.yaml" parse -b "$KMD/base.yaml" -c 10 -q - -o "$KMD/$KBD_NAME"_keymap.yaml \
        -l \
        "Colemak"\
        "Accents"\
        "Symbols"\
        "Navigation"\
        "Numbers"\
        "Mouse"\
        "Game"\
        ;
        echo "Keymap Parsed"
}

draw () {
    KBD_NAME=$1
    OPT=$2
    if keymap -c "$KMD/config.yaml" \
        draw "$KMD/$KBD_NAME"_keymap.yaml "$KMD"/combos.yaml -j "$KMD"/ximi.json \
            -o "$IMG/keymap.svg" \
        ; then
        echo "Keymap Drawned"
    else
        echo "Error drawing keymap"
        exit 1
    fi
}

launch_preview () {
   echo "Launching preview in Firefox"
   firefox "$IMG"/keymap.svg &
}

init() {
    KBD=ximi
    parse "$KBD"
    draw "$KBD" --keys-only
}

case "$1" in
    '-p'|'--preview')
        init
        launch_preview
        ;;
    '-h'|'--help')
        echo 'Draw keymap from configuration and export as SVG'
        echo 'Add -p or --preview to launch preview in Firefox'
        ;;
    *)
        init
        ;;
esac
