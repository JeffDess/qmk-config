#!/bin/bash

ROOT=$(dirname "$(readlink -f "$0")" | sed 's/\/[^/]*$//')
IMG="$ROOT/doc/img/keymaps"
KMD="$ROOT/keymap-drawer"

parse () {
    KBD_NAME=$1

    qmk c2json -kb fingerpunch/ximi/v2 -km jeffdess --no-cpp | \
        keymap parse -c 10 -q - -o keymap-drawer/"$KBD_NAME"_keymap.yaml \
        -l \
        "Colemak"\
        "Colemak Accents"\
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
            -o "$IMG/${KBD_NAME}_keymap.svg" \
        ; then
        echo "Keymap Drawned"
    else
        echo "Error drawing keymap"
        exit 1
    fi
}

launch_preview () {
   echo "Launching preview in Firefox"
   firefox doc/img/keymaps/ximi_keymap.svg &
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
