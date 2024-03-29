KERNEL_SRC ?= /lib/modules/$(shell uname -r)/build

KBUILD_OPTIONS := WLAN_ROOT=$(CURDIR)
KBUILD_OPTIONS += MODNAME?=wlan

# Determine if the driver license is Open source or proprietary
# This is determined under the assumption that LICENSE doesn't change.
# Please change here if driver license text changes.
LICENSE_FILE ?= $(CURDIR)/$(WLAN_ROOT)/CORE/HDD/src/wlan_hdd_main.c
WLAN_OPEN_SOURCE = $(shell if grep -q "MODULE_LICENSE(\"Dual BSD/GPL\")" \
		$(LICENSE_FILE); then echo 1; else echo 0; fi)
GIT_COMMIT_ID = g$(shell git rev-parse --short HEAD)

#By default build for CLD
WLAN_SELECT := CONFIG_QCA_CLD_WLAN=m
KBUILD_OPTIONS += CONFIG_QCA_WIFI_ISOC=0
KBUILD_OPTIONS += CONFIG_QCA_WIFI_2_0=1
KBUILD_OPTIONS += $(WLAN_SELECT)
KBUILD_OPTIONS += WLAN_OPEN_SOURCE=$(WLAN_OPEN_SOURCE)
KBUILD_OPTIONS += BUILD_STRING=$(GIT_COMMIT_ID)
KBUILD_OPTIONS += $(KBUILD_EXTRA) # Extra config if any

all:
	$(MAKE) -C $(KERNEL_SRC) M=$(CURDIR) modules $(KBUILD_OPTIONS)

modules_install:
	$(MAKE) INSTALL_MOD_STRIP=1 -C $(KERNEL_SRC) M=$(CURDIR) modules_install

clean:
	$(MAKE) -C $(KERNEL_SRC) M=$(CURDIR) clean
