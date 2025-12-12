.SILENT:
.PHONY: drawing preview watch

MAKEFLAGS += --no-print-directory

QMK_USERSPACE := $(patsubst %/,%,$(dir $(shell realpath "$(lastword $(MAKEFILE_LIST))")))
ifeq ($(QMK_USERSPACE),)
    QMK_USERSPACE := $(shell pwd)
endif

QMK_FIRMWARE_ROOT = $(shell qmk config -ro user.qmk_home | cut -d= -f2 | sed -e 's@^None$$@@g')
ifeq ($(QMK_FIRMWARE_ROOT),)
    $(error Cannot determine qmk_firmware location. `qmk config -ro user.qmk_home` is not set)
endif

%:
	+$(MAKE) -C $(QMK_FIRMWARE_ROOT) $(MAKECMDGOALS) QMK_USERSPACE=$(QMK_USERSPACE)

KM := jeffdess
KB_MAP = \
  ximi:fingerpunch/ximi/v2 \
  cnano:bastardkb/charybdis/3x5/v2/splinky_3 \
  ergolite:keyclicks/w_ergolite \
  ploopy:ploopyco/trackball_nano/rev1_001

compiledb:
ifdef KB
	$(eval KB_PATH := $(or $(patsubst $(KB):%,%,$(filter $(KB):%,$(KB_MAP))),$(KB)))
	@echo "Generating compile_commands.json for $(KB) → $(KB_PATH):$(KM)"
	@qmk generate-compilation-database -kb $(KB_PATH) -km $(KM)
else
	@./scripts/compiledb.sh
endif

drawing:
	@./scripts/generate-keymap-images.sh $(KB)

preview:
	@./scripts/generate-keymap-images.sh -p $(KB)

watch:
	@./scripts/generate-keymap-images.sh --watch $(KB)
