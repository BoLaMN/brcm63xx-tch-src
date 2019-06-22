
# Copyright (C) 2006-2009 OpenWrt.org
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#
include $(TOPDIR)/rules.mk

BOARD:=brcm63xx-tch
BOARDNAME:=Broadcom BCM63xx based Technicolor platform
DEFAULT_SUBTARGET:=VBNTO

LINUX_VERSION:=3.4.11-rt19
KERNEL_PATCHVER:=3.4

FEATURES:=squashfs jffs2 usb atm pci pcmcia
#DEFAULT_PACKAGES += kmod-switch gpioctl

define Target/Description
	Build firmware images for Technicolor Broadcom based xDSL/routers
endef

include $(INCLUDE_DIR)/target.mk

ifeq ($(BRCM_CHIP),63138)
  CFLAGS:=-Os -pipe -march=armv7-a -mtune=cortex-a9 -fno-caller-saves -mfpu=neon
endif

ifeq ($(BRCM_CHIP),63148)
  CFLAGS:=-Os -pipe -march=armv7-a -mtune=cortex-a15 -fno-caller-saves
endif


$(eval $(call BuildTarget))
