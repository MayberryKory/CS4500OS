# NAME OF PROJECT: Kernel Module and Processes
*** 
# MEMBERS:
Kacy Horning, Ashley Judson, Kory Mayberry
***
# STATEMENT:
We have neither given nor received unauthorized assistance on this work.
*** 
# VIRTUAL MACHINE (VM) INFORMATION:
NAME OF VM: group10Ubuntu
USENAME: group10
PASSWORD: mayberry7
PATH IN VM: ~/Documents/CS4500OS/Project2

## Describe where the files can be found.
## Describe each file and the purpose it serves.
## Provide instructions to access/run your program.

### PART 1
Located: ~/Documents/CS4500OS/Project2/part1
- `hello.c` // program is a complete helloworld module. This program will print 'hello world' when a module is loaded in & 'goodbye world' when the module is removed using kernel macros to do this. 

1. locate to proper directory
2. build this project via `make`
3. load your module in via `sudo insmod hello.ko`
4. view output `sudo dmesg -T | tail`
5. verify module has been loaded `sudo lsmod`
6. remove module f/ kernel `sudo rmmod hello`
7. view output again `sudo dmesg -T | tail`

Make Error: We did get an error when running the 'make' command. We fixed this error by commenting out the
module_init and module_exit function calls in hello.c. We encountered some other errors that were solved
by including the printk library and explicitly specifying the compiler in the Makefile.

### PART 2
Located: CS4500OS/Project2/part2
- `print_self.c` // program will identify the current processes occuring @ the user-level & print the
processes name, pid, & state & will print the parent processes info
 
Steps to Run program, Load, Remove, & View Modules
1. locate to directory
2. `make`
3. `sudo insmod print_self.ko`
4. `sudo dmesg -T | tail`
5. `sudo lsmod`
6. `sudo rmmod print_self`
7. `sudo dmesg -T | tail`

Answer the following questions:
1. When you load your module, which process is recognized as current? Modify the header to use 
the correct header file.
> When we first ran our module, the process recognized as 'current' was kworker. We found that 
for our program to work, the only modification we needed was to add the library
linux/sched.signal.h. This gave us access to the integer values that represented the process states.
2. In newer kernels, what is 'init' called and what do you see from your module's output?
> 'Init' is called systemd in newer kernels and has a PID of 1.
3. When printing your code, please map the numeric state to string state. From your module's output,
which state(s) are observed?
> We mapped the integer state value to its string using a switch statement. In our output, there are the
states 'TASK_INTERRUPTABLE', 'TASK_RUNNING', and 'UNKNOWN'.

### PART 3
Located: CS4500OS/Project2/part3
- `print_other.c` // prints info for arbirary an process.  
1. locate to directory
2. `make`
3. get a valid PID for a process by running `pgrep bash`
4. using a PID f/ step 3 run this & replace your_pid w/ the value above; load in your module via `sudo insmod print_other.ko pid=<your_pid>`
5. view output via `sudo dmesg -T | tail`
6. `sudo lsmod`
7. remove this module via `sudo rmmod print_other`

### PART 4
1. What is the difference between a kernel module & a system call?
> A kernel modules is a code that can be dynamically loaded & unloaded into the kernel for to extend functionality. This is important because it allows the kernel to be updated w/out a system reboot.
> A system call allows user-level processes to request from the kernel. This is an entry point into the kernel. This is important because it provides users the ability to access files, process control & memory management. 
> The key difference between these is kernel modules extend the kernels funcitonality, where as system calls allow users to interact with the kernel.  

2. When you try to the code in part4 (1) does it work? (2) explain why you think this may be a good (or bad) thing.
> This program was throwing issues because of the <sys/syscall.h> library. The primary reason this code is unfit & wouldn't work on modern days is due to newer security measures that are now implemented. For example, the sys_call_table[] is no longer assessible to kernel modules. You cannot modify & write to this table. In the cleanup_module() function, this is no longer a way to end the module, instead you would need to implement the standard cleanup function using module_exit() in todays kernels.   


ROOT PASSWORD: mayberry7
==============
# DESCRIPTION AND REMEDIATION:
============================
### Part 1:
For Part 1, we used the provided code and Makefile to start our program. We ran into one error message
that was saying the compiler used to build the kernel was different from the one we used to compile our
program.
This was solved by explicitly stating the compiler to use in our Makefile to be the same as the one used
to build the kernel. We also found we needed to include the 'printk' header library as the code was not 
printing correctly without it. Finally, we found that in order to get our program to run, we had to remove 
the kernel macro definitions module_init and module_exit.
### Part 2:
During this part, our team made progress in creating a functional c file. However opon creating changes to the file & running the command `sudo insmod print_self.ko` this led to our entire envirnment freezing multiple times. We found that we were overcomplicating the conversion of the state to a string and in simplifying that by just using the integer values that represent the state, we were able to make a switch statement to print the state string values. 
### Part 3: 
During this part, our team created a functional print_other.c. We experienced no issues during this problem. We were able to follow the guidelines on how how to find the processes running. We modifed the previous commands to intake a PID # & print the proper information. 
### Part 4:
We were able to fill out the questions for this portion. This is located on this readme above this section. For this section we copied in the given code and ran it. We were met with a few errors that we had not seen prior to this. After some research, we learned that the given code was outdated & not used now-a-days for security vulnerbaility purposes & processes. To read more on this question, visit our answer response. 


