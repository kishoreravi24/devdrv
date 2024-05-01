#include<linux/module.h>
#include<linux/init.h>

/* info */
MODULE_LICENSE("GPL");
MODULE_AUTHOR("KISHORE JR");
MODULE_DESCRIPTION("Basic hello module");

static int __init ModuleInit(void){
  printk("Hello kernel\n");
  return 0;
}

static void __exit ModuleExit(void){
  printk("Goodbye, kernel\n");
}

module_init(ModuleInit);
module_exit(ModuleExit);

