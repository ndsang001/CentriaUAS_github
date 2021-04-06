#include <linux/module.h>	/* Needed by all modules */
#include <linux/kernel.h>	/* Needed for KERN_INFO */

int init_module(void)
{
	printk(KERN_INFO "Hello world 1.\n");
	return 0; //A non 0 return means init_module failed; module can't be loaded. 
}

void cleanup_module(void)
{
	printk(KERN_INFO "Goodbye world 1.\n");
}
