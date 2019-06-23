
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
DEFAULT_PACKAGES += kmod-switch gpioctl

BCM_KF:=y
BRCMDRIVERS_DIR:=$(TOPDIR)/extern/broadcom-bsp/broadcom_modules/bcmdrivers
BCM_USERSPACE_DIR:=$(TOPDIR)/extern/broadcom-bsp/bcm_userspace
SHARED_DIR:=$(TOPDIR)/extern/broadcom-bsp/bcm_userspace/broadcom_apps/shared
INSTALL_MOD_DIR:=extra
BRCM_BOARD:=bcm963xx
#BRCM_CHIP:=63138
PROFILE:=963138BGWV
RDPA_PLATFORM=dsl
VOXXXLOAD=1

INC_BROADCOM_APPS_SHARED:=$(BCM_USERSPACE_DIR)/broadcom_apps/shared
INC_BRCMDRIVER_PUB_PATH:=$(BRCMDRIVERS_DIR)/opensource/include
INC_BRCMDRIVER_PRIV_PATH:=$(BRCMDRIVERS_DIR)/broadcom/include
INC_ADSLDRV_PATH:=$(BRCMDRIVERS_DIR)/broadcom/char/adsl/impl1
INC_ATMAPI_DRV_PATH:=$(BRCMDRIVERS_DIR)/broadcom/char/atmapi/impl1
INC_MOCACFGDRV_PATH:=$(BRCMDRIVERS_DIR)/opensource/char/moca/impl2
INC_BRCMSHARED_PUB_PATH:=$(SHARED_DIR)/opensource/include
INC_BRCMSHARED_PRIV_PATH:=$(SHARED_DIR)/broadcom/include
INC_BRCMBOARDPARMS_PATH:=$(SHARED_DIR)/opensource/boardparms
INC_FLASH_PATH:=$(SHARED_DIR)/opensource/flash
INC_SPI_PATH:=$(SHARED_DIR)/opensource/spi
INC_SPUDRV_PATH:=$(BRCMDRIVERS_DIR)/broadcom/char/spudd/impl1
INC_PWRMNGTDRV_PATH:=$(BRCMDRIVERS_DIR)/broadcom/char/pwrmngt/impl1
INC_ENETDRV_PATH:=$(BRCMDRIVERS_DIR)/opensource/net/enet/impl5
INC_EPONDRV_PATH:=$(BRCMDRIVERS_DIR)/broadcom/char/epon/impl1
INC_RDPA_PATH:=$(BRCMDRIVERS_DIR)/opensource/char/rdpa_gpl/impl1/include
INC_RDPA_MW_PATH:=$(BRCMDRIVERS_DIR)/opensource/char/rdpa_mw/impl1
INC_RDPA_DRV_PATH:=$(BRCMDRIVERS_DIR)/opensource/char/rdpa_drv/impl1
INC_RDPA_PATH_PLATFORM:=$(INC_RDPA_PATH)/$(RDPA_PLATFORM)
INC_BDMF_PATH:=$(BRCMDRIVERS_DIR)/opensource/char/bdmf/impl1
INC_UTILS_PATH:=$(SHARED_DIR)/opensource/utils
RDP_PATH:=$(SHARED_DIR)/broadcom/rdp

ADD_LINUX_INCLUDE:=-I$(BRCMDRIVERS_DIR)/broadcom/net/wl/impl22/main/src/include

export BCM_KF BRCMDRIVERS_DIR BCM_USERSPACE_DIR SHARED_DIR INSTALL_MOD_DIR BRCM_BOARD BRCM_CHIP PROFILE RDPA_PLATFORM VOXXXLOAD ADD_LINUX_INCLUDE
export INC_BROADCOM_APPS_SHARED INC_BRCMDRIVER_PUB_PATH INC_BRCMDRIVER_PRIV_PATH INC_ADSLDRV_PATH INC_ATMAPI_DRV_PATH INC_MOCACFGDRV_PATH INC_BRCMSHARED_PUB_PATH INC_BRCMSHARED_PRIV_PATH INC_BRCMBOARDPARMS_PATH INC_FLASH_PATH INC_UTILS_PATH INC_SPI_PATH INC_SPUDRV_PATH INC_PWRMNGTDRV_PATH INC_ENETDRV_PATH INC_EPONDRV_PATH INC_RDPA_PATH INC_RDPA_MW_PATH INC_RDPA_DRV_PATH INC_RDPA_PATH_PLATFORM INC_BDMF_PATH RDP_PATH

define Target/Description
	Build firmware images for Technicolor Broadcom based xDSL/routers
endef

include $(INCLUDE_DIR)/target.mk

KERNEL_DIR:=$(BUILD_DIR)/linux-$(BOARD)_$(SUBTARGET)/linux-3.4.11
export KERNEL_DIR

ifeq ($(BRCM_CHIP),63138)
  CFLAGS:=-Os -pipe -march=armv7-a -mtune=cortex-a9 -fno-caller-saves -mfpu=neon
endif

ifeq ($(BRCM_CHIP),63148)
  CFLAGS:=-Os -pipe -march=armv7-a -mtune=cortex-a15 -fno-caller-saves
endif


$(eval $(call BuildTarget))
