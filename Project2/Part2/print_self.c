#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/sched.h>
#include <linux/sched/signal.h>
#include <linux/printk.h>


char *state_int_to_string(int stateInt);

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


int init_module(void){
	struct task_struct *task = current;

	int task_state;

	printk(KERN_ALERT "LOADED MODULE: PRINT SELF\n");

	while(task->pid != 1){

		task_state = task->__state;

		printk(KERN_ALERT "Process ->-> PID (%d)\t NAME (%s) \t STATE (%s)\n", task->pid, task->comm, state_int_to_string(task_state));
		
		task = task->real_parent;
	}

	
	
	return 0;
}
void cleanup_module(void) {
	printk(KERN_INFO "Cleaning up module\n");
}



MODULE_LICENSE("GPL");
