#
# Copyright (C) 2013-2020 iopsys
#

include $(TOPDIR)/rules.mk
include $(INCLUDE_DIR)/kernel.mk

PKG_NAME:=questd
PKG_VERSION:=5.1.11

PKG_SOURCE_VERSION:=6b64dafae52d0cd28a31d364aeed80380875293b
PKG_SOURCE_PROTO:=git

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION)-$(PKG_SOURCE_VERSION).tar.gz
PKG_SOURCE_SUBDIR:=$(PKG_NAME)-$(PKG_VERSION)
PKG_BUILD_DIR:=$(BUILD_DIR)/$(PKG_NAME)-$(PKG_VERSION)

PKG_LICENSE:=GPL-2.0-only
PKG_LICENSE_FILES:=LICENSE

include $(INCLUDE_DIR)/package.mk
include $(INCLUDE_DIR)/cmake.mk

PKG_INSTALL:=

define Build/Prepare
	mkdir -p $(PKG_BUILD_DIR)
	$(CP) ./src/$(PKG_NAME)-$(PKG_VERSION)/* $(PKG_BUILD_DIR)/
endef

define Package/questd
	CATEGORY:=Utilities
	DEPENDS:=+libuci +libubox +ubus +libpthread
	TITLE:=Router information daemon
endef

define Package/questd/description
	questd collects system and network information and presents
	this information via ubus
endef

define Package/questd/install
	$(CP) ./files/* $(1)/
	$(INSTALL_DIR) $(1)/sbin
	$(INSTALL_BIN) $(PKG_BUILD_DIR)/questd $(1)/sbin/
endef

$(eval $(call BuildPackage,questd))
