# operating-systems-project

# PROJECT 1 – System Calls and the Shell

# Group members
- Mahmut Beširević
- Asim Veledarević
- Mirza Kurtović
- Ajdin Bajramović
- Nedim Bajraktarević

# Folder structure


<pre>

📦operating-systems-project
 ┣ 📦task1.1
	┣ 📜question1.txt
 	┗ 📜question2.txt
 ┣ 📜.makefile.swp
 ┣ 📜.shell.swp
 ┣ 📜README.md
 ┣ 📜makefile
 ┣ 📜shell
 ┗ 📜shell.c

</pre>

# Outline of the project

The goal of this project is to get a better understanding of the mechanics of process control by creating a shell user interface. The link between child and parent processes, the steps to establish a new process, shell variables, and an introduction to user-input parsing and verification are all covered. This is a type of a simple shell interface written in the C language.  

Purpose: The purpose of this project is to familiarize with the mechanics of process control through the implementation of a shell user interface. This includes the relationship between child and parent processes, the steps needed to create a new process, shell variables, and an introduction to user-input parsing and verification.

| Shell requirements       |
| ------------------------ |
| The GNU Readline Library |
| C compiler               |
| Linux                    |
| Readline GNU library     |

<code>
sudo apt-get install libreadline6 libreadline6-dev
</code>

<h3>Makefile is included for compiling with it</h3>

---

Command to compile the shell

<code>
gcc shell.c -L/usr/local/lib -I/user/local/include -lreadline -o shell
</code>

Or

<code>
	make
</code>

Command to run the shell

<code>
./shell
</code>

---

<img src="https://upload.wikimedia.org/wikipedia/commons/8/83/The_GNU_logo.png" alt="GNU" width="200" height="200"/>

| Project requirements            |     |
| ------------------------------- | --- |
| Basic shell interface           | ✔️  |
| Execution of programms          | ✔️  |
| Execution of built in functions | ✔️  |
| Current dir display             | ✔️  |
| Command parsing                 | ✔️  |
| Command history                 | ✔️  |
| Error handling                  | ✔️  |
| Forking and child processes     | ✔️  |

Task 1.1: Provide a concise and descriptive answer to the following questions.

<h2>Q1: The following actions, do they require the OS to use kernel mode or user mode is sufficient? Explain.
-Starting a new process.
-Multiplying two floating numbers stored in an application’s memory.
-Writing the results of the multiplication to a temporary log file on disk.</h2>

A1: For this type of shell and its actions, the user mode is sufficient in order to run them. In the user mode the the code being executed has no direct access to the hardware or the reference memory.
The code ran on the computer is mostly in user mode hence the user mode being enough.

- Starting a new process:
  Anwser: While user mode is sufficient to simply start a new process, it has limited access to system resources.
  
- Multiplying two floating numbers stored in an application’s memory:
  Anwser: For this operation, user mode is sufficient. The compiler is an application which, in this case, does not reuqire access to special functions or direct hardware         access.

- Writing the results of the multiplication to a temporary log file on disk:
  Anwser: Kernel mode must be invoked, because writing temporary log files is restricted for regular users.

<h2>Q2: Explain the purpose of a system call. Describe how control passes to the kernel when executing a system call.</h2>

A2: A system call is a method for the program to request a service from the kernel in the operating system. Its purpose is interacting with the operating system. In other words, a system call provides an API (Application User Interface) with its services from the operating system to the program which uses them.
System calls are considered to be the only way to interact with the kernel, as they allow the user-level processes to request services of the operating system in use.

An interrupt is used to transfer control to the kernel. The program uses the system call along with the ID of the system call, then executes the system interrupt.

<h3>Tutorials and useful links</h3>

GeeksForGeeks C, linux shell tutorials
YouTube - Linux shell in C tutorial
