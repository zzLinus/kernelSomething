#include <linux/init.h>
#include <linux/module.h>

MODULE_LICENSE("GPL");

static int hello_init(void) {
  printk(KERN_ALERT "My kernel module!!!\n");
  return 0;
}

static void hello_exit(void) { printk(KERN_ALERT "Bye my kernel module\n"); }

module_init(hello_init);
module_exit(hello_exit);
