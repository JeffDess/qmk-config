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
            uv tool install keymap-drawer==${keymap-drawer_version}
          '';
        };

      });
}
