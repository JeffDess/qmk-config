#!/bin/bash

ROOT=$(dirname "$(readlink -f "$0")" | sed 's/\/[^/]*$//')

declare -A KBD_MANUFACTURER=(
    ['ximi']='fingerpunch'
    ['charybdis']='bastardkb'
)

declare -A KBD_VERSION=(
    ['ximi']='v2'
    ['charybdis']='3x5'
)

declare -A KBD_QMK=(
    ['ximi']='fingerpunch/ximi/v2'
    ['charybdis']='bastardkb/charybdis/3x5/v2/splinky_3'
)

KM=jeffdess
KBD=${2:-${1:-ximi}}
MANUFACTURER="${KBD_MANUFACTURER[$KBD]}"
VERSION="${KBD_VERSION[$KBD]}"

if [[ -z "$MANUFACTURER" ]]; then
    echo "Unknown keyboard: $KBD"
    echo "Supported keyboards: ${!KBD_MANUFACTURER[*]}"
    exit 1
fi

IMG="$ROOT/keyboards/$MANUFACTURER/$KBD/$VERSION/keymaps/$KM"
KMD="$ROOT/keymap-drawer"

parse() {
    KBD_NAME=$1

    qmk c2json -kb "${KBD_QMK[$KBD_NAME]}" -km $KM --no-cpp |
        keymap -c "$KMD"/config.yaml parse -b "$KMD/$KBD"/base.yaml \
            -c 10 \
            -q - \
            -o "$KMD/$KBD"/keymap.yaml \
            -l \
            "Colemak" \
            "Accents" \
            "Symbols" \
            "Navigation" \
            "Numbers" \
            "Mouse" \
            "Game" \
        ;
    echo "Keymap Parsed"
}

draw() {
    KBD_NAME=$1
    OPT=$2

    CONFIG="$KMD/config.yaml"
    if [ "$KBD_NAME" == "ximi" ]; then
        ENCODERS=$(cat "$KMD"/encoders.css)
        CONFIG=$(mktemp)
        yq --arg encoders "$ENCODERS" \
            '.draw_config.svg_style = $encoders + "\n" + .draw_config.svg_style' \
            "$KMD/config.yaml" >"$CONFIG"
    fi

    if keymap -c "$CONFIG" \
        draw "$KMD/$KBD_NAME"/keymap.yaml \
        "$KMD/$KBD_NAME"/combos.yaml -j \
        "$KMD/$KBD_NAME"/layout.json \
        -o "$IMG/keymap.svg" \
        ; then
        echo "Keymap Drawned"
        [ "$KBD_NAME" == "ximi" ] && rm -f "$CONFIG" || true
    else
        echo "Error drawing keymap"
        [ "$KBD_NAME" == "ximi" ] && rm -f "$CONFIG" || true
        exit 1
    fi
}

preview() {
    echo "Launching preview in feh..."
    find "$IMG/keymap.svg" | entr -r feh "$IMG/keymap.svg" || true
}

init() {
    parse "$KBD"
    draw "$KBD" --keys-only
}

watch() {
    echo "Watching files..."
    find ./keymap-drawer/ \
        ./users/ \
        "./keyboards/$MANUFACTURER/$KBD/$VERSION/keymaps/" |
        entr -ps "sh $0 $KBD"
}

case "$1" in
'-p' | '--preview')
    init
    preview
    ;;
'-w' | '--watch')
    init
    preview
    watch
    ;;
'-h' | '--help')
    echo 'SUMMARY'
    echo 'Draw keymap from configuration and export as SVG'
    echo
    echo 'USAGE'
    echo "  $0 [KEYBOARD] [FLAGS]"
    echo
    echo 'ARGUMENTS'
    echo "  KEYBOARD      Keyboard name (default: ximi)"
    echo "                Supported: ${!KBD_MANUFACTURER[*]}"
    echo
    echo 'FLAGS'
    echo '  -p --preview  Launch preview in feh'
    echo '  -w --watch    Launch preview and update when files are modified'
    echo '  -h --help     Show this help message'
    ;;
*)
    init
    ;;
esac
