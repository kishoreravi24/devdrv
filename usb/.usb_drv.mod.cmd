savedcmd_/home/kishore/codes/devdrv/usb/usb_drv.mod := printf '%s\n'   usb_drv.o | awk '!x[$$0]++ { print("/home/kishore/codes/devdrv/usb/"$$0) }' > /home/kishore/codes/devdrv/usb/usb_drv.mod
