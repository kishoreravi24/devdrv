#include <linux/module.h>
#include <linux/init.h>
#include <linux/usb.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("KISHORE JR");
MODULE_DESCRIPTION("USB DEVICE ENTRY AND EXIT ACTION");

#define VENDOR_ID 0x0781
#define PRODUCT_ID 0x5567

static struct usb_device_id usb_table[] = {
    {USB_DEVICE(VENDOR_ID, PRODUCT_ID)},
    {},
};
MODULE_DEVICE_TABLE(usb, usb_table);

static int usb_probe(struct usb_interface *intf, const struct usb_device_id *id) {
    printk(KERN_INFO "Sandisk Cruzer connected successfully && சாண்டிஸ்க் க்ரூசர் வெற்றிகரமாக இணைக்கப்பட்டது\n");
    return 0;
}

static void usb_disconnect(struct usb_interface *intf) {
    printk(KERN_INFO "Sandisk Cruzer disconnected && சாண்டிஸ்க் க்ரூசர் துண்டிக்கப்பட்டது\n");
}

static struct usb_driver sandisk_driver = {
    .name = "sandisk_cruzer_driver",
    .id_table = usb_table,
    .probe = usb_probe,
    .disconnect = usb_disconnect,
};

static int __init ModuleInit(void) {
    printk(KERN_INFO "Sandisk module init\n");
    int result = usb_register(&sandisk_driver);
    if (result) {
        printk(KERN_ERR "Error during register: %d\n", result);
        return result;
    }
    return 0;
}

static void __exit ModuleExit(void) {
    printk(KERN_INFO "Sandisk module exit\n");
    usb_deregister(&sandisk_driver);
}

module_init(ModuleInit);
module_exit(ModuleExit);

