#!/usr/bin/env bash

if [[ ! -f qmk.json ]]; then
    echo "No qmk.json found in $(pwd)"
    return 1
fi

tmp=$(mktemp -d)
trap 'rm -rf "$tmp"' EXIT

echo "Generating compile_commands.json for all keyboards…"

targets=$(jq -r '.build_targets[] | .[0] + " " + .[1]' qmk.json)

count=0
all_dbs=()
original_db="compile_commands.json"
has_original=false

[[ -f "$original_db" ]] && has_original=true && mv "$original_db" "$tmp/original.json"

while read -r kb km; do
    [[ -z "$kb" || -z "$km" ]] && continue
    echo "→ Generating for $kb:$km..."

    if qmk generate-compilation-database -kb "$kb" -km "$km"; then
        safe_name="${kb//\//_}_${km}.json"
        mv compile_commands.json "$tmp/$safe_name"
        all_dbs+=("$tmp/$safe_name")
        ((count++))
        echo "  ✓ Saved as $safe_name"
    else
        echo "  Failed for $kb:$km — skipping"

        [[ -f compile_commands.json ]] && rm -f compile_commands.json
    fi
done <<<"$targets"

if ((count == 0)); then
    echo "No successful generations — check your targets in qmk.json"

    [[ $has_original == true ]] && mv "$tmp/original.json" "$original_db"

    exit 1
fi

jq -s 'add' "${all_dbs[@]}" >compile_commands.json

echo "✅ Done! compile_commands.json now contains all $count keyboards."

[[ $count -eq 0 && $has_original == true ]] && mv "$tmp/original.json" "$original_db"
