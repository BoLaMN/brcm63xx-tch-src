##################################################
##################################################
#
#  BUILDING THIS CODE FOR LINUX KERNEL MODULE
#
$(warning Compiling for kernel module)
##################################################
##################################################


obj-${CONFIG_RIPDRV} += ripdrv.o

ripdrv-y := main.o rip2lib.o rip2_cert_privkey.o target/linux/platform.o flashrip_drv.o rip_proc.o efu_privileged.o efu_common.o rip_efu_proc.o target/linux/crypto_api.o
ccflags-y += -I$(src)/include -I$(src)/target/linux/include/ -I$(src)/target/linux/${TARGET}/include/

ifneq ($(CONFIG_RIP_ON_UBI),)
ripdrv-y += target/linux/ubi.o
else
ripdrv-y += target/linux/mtd.o
endif

ifneq ($(CONFIG_RIPDRV_CRYPTO_SUPPORT),)
ccflags-y += -DCONFIG_RIPDRV_CRYPTO_SUPPORT
ripdrv-y += crypto.o target/linux/crypto_lx.o
endif

ifneq ($(CONFIG_RIPDRV_EXPOSE_PRIVATES),)
ccflags-y += -DCONFIG_RIPDRV_EXPOSE_PRIVATES
endif

ifneq ($(CONFIG_RIPDRV_INTEGRITY_ONLY),)
ccflags-y += -DCONFIG_RIPDRV_INTEGRITY_ONLY
endif

ifneq ($(CONFIG_RIPDRV_ANVIL),)
ccflags-y += -DCONFIG_RIPDRV_ANVIL
endif

ifneq ($(CONFIG_ARM),)
ccflags-y += -DCONFIG_ARM
endif

ccflags-y += -Wall -Werror -Wno-pointer-to-int-cast -Wno-strict-prototypes

clean:
	rm -f core *.o *.a *.s *~

