{
  description = "QMK Config Shell";

  inputs = {
    nixpkgs.url = "github:nixos/nixpkgs?ref=nixos-unstable";
    flake-utils.url = "github:numtide/flake-utils";
  };

  outputs = { nixpkgs, flake-utils, ... }:
    flake-utils.lib.eachDefaultSystem (system:
      let
        pkgs = nixpkgs.legacyPackages.${system};
        keymap-drawer_version = "0.22.0";
      in {
        devShells.default = pkgs.mkShell {
          buildInputs = with pkgs; [
            qmk
            dfu-programmer
            dfu-util
            avrdude
            gcc
            python313
            uv
            entr
            resvg
            yq
          ];
          shellHook = ''
            echo
            printf "⌨️ \e[38;5;195mQMK Config\033[0m\n"
            echo

            uv tool install keymap-drawer==${keymap-drawer_version}

            if [ ! -f compile_commands.json ] || [ ! -s compile_commands.json ]; then
              echo 'Generating compile_commands.json via `make compiledb...`'
            make compiledb && 'compile_commands.json generated' \
              || echo "Warning: make compiledb failed"
            else
              printf '`\033[34mcompile_commands.json\033[0m` is already generated\n'
              printf '  ↳ Recompile with `\033[32mmake compiledb\033[0m`\n'
            fi

          '';
        };

      });
}
