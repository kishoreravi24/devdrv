# Simple hello device driver

### hellomodule.c 
* importing the linux/module.h and linux/init.h
* __init and __exit to act as entry and exit of the module
* don't forgot to add the module information like author,description and license.

### Makefile
* obj -m += hellomodule.o which is used for building linux kernel modules. It tells the build system to compile the source file hellomodule.c into a kernel module named hellomodule.o
* now, all & clean: This command compiles kernel modules located in the current directory using the kernel build environment found at `/lib/modules/<kernel_version>/build`.

### commands
```
sudo insmod hellomodule.ko
lsmod | grep hellomodule
dmesg | tail
sudo rmmod hellomodule
dmesg | tail
```

