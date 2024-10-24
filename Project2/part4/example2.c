#include <linux/kernel.h>
#include <linux/module.h>
#include <sys/syscall.h>

extern void *sys_call_table[];

asmlinkage int (*original_sys_exit)(int);

asmlinkage int our_fake_exit_function(int error_code) {
	/* print message on console everytime we are called */
	printk("HEY! sys_exit called w/ error_code=%d\n", error_code);

	/* call the original sys_exit */
	return original_sys_exit(error_code);
}

/* This function is called when the module is loaded (initalization) */
int init_module() {
	/* store reference to the original sys_exit */
	origiinal_sys_exit=sys_call_table[__NR_exit];

	/* manipulate sys_call_table to call our fake exit function instead of sys_exit */
	sys_call_table[__NR_exit]=our_fake_exit_function;
}

/* this function is called when the module is unloaded */
void cleanup_module() {
	/* make __NR_exit point to the original sys_exit when our module is unloaded */
	sys_call_table[__NR_exit]=original_sys_exit;
}
