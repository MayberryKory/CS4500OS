NAME OF PROJECT: Makefile
================
MEMBERS: Kacy Horning, Ashley Judson, Kory Mayberry
========
STATEMENT: We have neither given nor received unauthorized assistance on this work.
==========
VIRTUAL MACHINE (VM) INFORMATION:
=================================
NAME OF VIRTUAL MACHINE (VM): group10Ubuntu
USERNAME: group10
PASSWORD: encode december presume <Include the spaces!>

Describe where the files can be found.
Describe each file and the purpose it serves.

LinkedList.c : The primary implementation of the linked list data structure as defined by the skeleton in the pdf document for the project
LinkedList.h : The header file for LinkedList.c, which allows for LinkedList.c to be called in other files
ListTest.c : The primary test file for the linked list implementation. Uses the code in LinkedList.c to execute
Makefile : The file that contains the instructions for code compliation and creates the binary executable file
ListTest : The binary executable.
ListTest.o : The object file created by the Makefile for the ListTest.c
LinkedList.o : The object file created by the Makefile for LinkedList.c

Provide any special instructions to access or run your program.

==============
PROBLEM DESCRIPTION AND REMEDIATION:
====================================
PART 0: SET UP
When setting up our virtual machine, we followed the instructions provided in the Ubuntu-guide.docx and  ssh-guide-1.docx. 
Once our environment was set up, we ran the sudo apt update && sudo apt upgrade to run the updates and then installed
gcc. We also set up openssh-server to more easily access the virtual machine. We also added to our .ssh config files
to make it easier to SSH into the VM in the future. 
==============
PART 1: LINKED LIST
===================
PART 2: WRITING A MAKEFILE