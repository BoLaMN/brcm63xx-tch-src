#
# Copyright (C) 2006-2015 OpenWrt.org
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#
include $(TOPDIR)/rules.mk

PKG_NAME:=mtd-utils
PKG_VERSION:=1.5.1

PKG_SOURCE_VERSION:=92686f212c9a4e16891c6a3c57629cbf4f0f8360
PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION)-$(PKG_SOURCE_VERSION).tar.gz
PKG_SOURCE_URL:=git://git.infradead.org/mtd-utils.git
PKG_SOURCE_PROTO:=git
PKG_SOURCE_SUBDIR:=$(PKG_NAME)-$(PKG_VERSION)
PKG_MIRROR_MD5SUM:=9fe0518213feddacd1842935dddeb6c8
PKG_CAT:=zcat

PKG_BUILD_DIR:=$(BUILD_DIR)/$(PKG_NAME)-$(PKG_VERSION)

include $(INCLUDE_DIR)/package.mk

PKG_CFLAGS += -I$(STAGING_DIR_HOST)/include/e2fsprogs
CFLAGS := $(PKG_CFLAGS) -I$(PKG_BUILD_DIR)/include -L$(PKG_BUILD_DIR) -L$(STAGING_DIR_HOST)/lib -DNO_NATIVE_SUPPORT
ifneq ($(PKG_OS),Linux)
CFLAGS += -Dloff_t=off_t -D__BYTE_ORDER=BYTE_ORDER -include getline.h -include endian.h -I$(CURDIR)/include -include fls.h
endif

define Package/mtd-utils/Default
  SECTION:=utils
  CATEGORY:=Utilities
  TITLE:=mtd-utils
endef

MTD_MAKEOPTS = \
	CFLAGS="$(CFLAGS)" \
	LDFLAGS="$(PKG_LDFLAGS)" \
	WITHOUT_LZO=1 WITHOUT_XATTR=1 \
	SUBDIRS="" \
	BUILDDIR="$(PKG_BUILD_DIR)"

define Build/Compile
	$(MAKE) -C $(PKG_BUILD_DIR) \
		$(MTD_MAKEOPTS) \
		TARGETS="mkfs.jffs2 ubi-utils/ubinize mkfs.ubifs/mkfs.ubifs"
endef

define Build/Install
	$(CP) \
		$(PKG_BUILD_DIR)/mkfs.jffs2 \
		$(PKG_BUILD_DIR)/mkfs.ubifs/mkfs.ubifs \
		$(PKG_BUILD_DIR)/ubi-utils/ubinize \
		$(STAGING_DIR_HOST)/bin/
endef

define Host/Clean
	rm -f $(STAGING_DIR_HOST)/bin/{mkfs.jffs2,mkfs.ubifs,ubinize}
endef

$(eval $(call HostBuild))
