#obj-m = wqueue.o
#KVERSION = 3.1.0-1282-omap4
#INCLUDEDIR = /usr/src/linux=headers-$(VERSION)/arch/arm/plat-omap/include

#all:
#	make -I $(INCLUDEDIR) -C /lib/modules/$(KVERSION)/build M=$(PWD) modules
#clean:
#	make -C /lib/modules/$(KVERSION)/build M=$(PWD) clean

obj-m += wqueue.o
KVERSION = $(shell uname -r)
KDIR := /lib/modules/$(shell uname -r)/build
ARM_KDIR := /home/likhit/linux-ti-omap4_3.2.0-1412.16
ARCH := arm
CROSS := arm-linux-gnueabi-
PWD := $(shell pwd)

all:
	make -C $(KDIR) M=$(PWD) modules
arm:
	make -C $(ARM_KDIR) ARCH=$(ARCH) CROSS_COMPILE=$(CROSS) M=$(PWD) modules
clean:
	make -C $(KDIR) M=$(PWD) clean
install:
	insmod kernelpc