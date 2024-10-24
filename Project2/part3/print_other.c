#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/printk.h>
#include <linux/sched.h>
#include <linux/sched/signal.h>
#include <linux/pid.h>
#include <linux/moduleparam.h>

// function prototype
char *state_int_to_string(int stateInt);
void print_process_info(struct task_struct *task);

char *state_int_to_string(int stateInt){
	switch(stateInt){

        	case 0:
			return "TASK_RUNNING";
        	case 1:
			return "TASK_INTERRUPTABLE";
        	case 2:
			return "TASK_NOT_INTERRUPTABLE";
		case 4:
			return "TASK_STOPPED";
		case 8:
			return "TASK_TRACED";
		case 16: 
			return "EXIT_ZOMBIE_TASK";
		case 32:
			return "EXIT_DEAD_TASK";
		case 64:
			return "TASK_NOT_INTERACTIVE";
		default:
			return "UNKNOWN";
	}
	return "THIS_SHOULD_NOT_RETURN";
}

// module parameters for accepting PID
static int pid = 1; 
module_param(pid, int, 0);
MODULE_PARM_DESC(pid, "The PID of the process to print info about");


/* Function will print info about a process */
void print_process_info(struct task_struct *task) {
	printk(KERN_INFO "Process: %s, PID: %d, state: %s\n", task->comm, task->pid, state_int_to_string(task->__state));
}

/* Initial Functions when module is loaded */
static int __init print_other(void) {
	struct task_struct *task;
	struct pid *pid_struct;

	// get the task_struct for given PID
	pid_struct = find_get_pid(pid);
	task = pid_task(pid_struct, PIDTYPE_PID);

	if (!task) {
		printk(KERN_INFO "Invalid PID %d.\n", pid);
		return -1;
	}

	// traverse through processes till the initital process (1)
	printk(KERN_INFO "Printing Process info for PID %d & its parents:\n", pid);
	while (task->pid != 1) {
		print_process_info(task);
		task = task->real_parent;	// this will move to the parent process
	}

	print_process_info(task);
	return 0;
}


/* cleanup function called when the module is removed */
void cleanup_module(void) {
    printk(KERN_INFO "Module removed.\n");
}

MODULE_LICENSE("GPL");

module_init(print_other);
