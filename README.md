# operating-systems-project
# PROJECT 1 – System Calls and the Shell 

Purpose: The purpose of this project is to familiarize you with the mechanics of process control through the implementation of a shell user interface. This includes the relationship between child and parent processes, the steps needed to create a new process, shell variables, and an introduction to user-input parsing and verification.



| Shell requirements       |
|--------------------------|
| The GNU Readline Library |
| C compiler               |
| Linux                    |



<h3>Makefile is included for compiling with it</h3>


---

Command to compile the shell


<code>
gcc shell.c -L/usr/local/lib -I/user/local/include -lreadline -o shell
</code>


Command to run the shell 


<code>
./shell
</code>

---

<img src="https://upload.wikimedia.org/wikipedia/commons/8/83/The_GNU_logo.png" alt="GNU" width="200" height="200"/>


| Project requirements            |   | 
|---------------------------------|---|
| Basic shell interface           |✔️ |  
| Execution of programms          |✔️ |
| Execution of built in functions |✔️ |
| Current dir display             |✔️ |
| Command parsing                 |✔️ |
| Command history                 |✔️ |
| Error handling                  |✔️ |
| Forking and child processes     |✔️ | 
 



Task 1.1: Provide a concise and descriptive answer to the following questions. 

Q1: The following actions, do they require the OS to use kernel mode or user mode is sufficient? Explain. 


Starting a new process. 
Multiplying two floating numbers stored in an application’s memory. 
Writing the results of the multiplication to a temporary log file on disk. 

Q2: Explain the purpose of a system call. Describe how control passes to the kernel when executing a system call. 