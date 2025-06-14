{
  description = "QMK Config Shell";

  inputs = {
    nixpkgs.url = "github:nixos/nixpkgs?ref=nixos-unstable";
    flake-utils.url = "github:numtide/flake-utils";
  };

  outputs = { nixpkgs, flake-utils, ... }:
    flake-utils.lib.eachDefaultSystem (system:
      let pkgs = nixpkgs.legacyPackages.${system};
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
          ];
          shellHook = ''
            uv venv
            source .venv/bin/activate
            uv pip install -r requirements.txt
          '';
        };

      });
}
