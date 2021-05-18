# operating-systems-project
#PROJECT 1 – System Calls and the Shell 

Purpose: The purpose of this project is to familiarize you with the mechanics of process control through the implementation of a shell user interface. This includes the relationship between child and parent processes, the steps needed to create a new process, shell variables, and an introduction to user-input parsing and verification.

Task 1: Design and implement a basic shell interface that supports the execution of other programs and a series of built-in functions. The shell should be robust (e.g., it should not crash under any circumstance beyond machine failure). The shell (command line) is just a program that continually asks for user input, perhaps does something on the user’s behalf, resets itself, and again asks for user input. 


At this point, the prompt should indicate that the shell is ready to accept input from the user. Oftentimes, it also shows useful information, such as the name of the user running the shell and the current directory. For now, you just need to implement a simple prompt. 

The prompt should look like the following: 
o prompt$

Before the shell can begin executing commands, it needs to extract the command name and the arguments into “tokens”. It might be nice to store these tokens into an array so that you can then parse each one in order. 

Once the shell understands what commands to execute it is time to implement the execution of simple commands. Since the execution of another program involves creating another process, you will have to use the fork() system call to create another process. Once you have created the new child process, that process must use the execvp() system call to execute the program. Finally, the parent (shell) process must wait for the child process to complete before releasing the child’s resources using the waitpid() system call. However, the execvp() system call may return if there is an error. If it does, your shell should print an error, reset, and prompt for new input.

Task 1.1: Provide a concise and descriptive answer to the following questions. 

Q1: The following actions, do they require the OS to use kernel mode or user mode is sufficient? Explain. 


Starting a new process. 
Multiplying two floating numbers stored in an application’s memory. 
Writing the results of the multiplication to a temporary log file on disk. 

Q2: Explain the purpose of a system call. Describe how control passes to the kernel when executing a system call. 
