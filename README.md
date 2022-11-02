# [0x16. C - Simple Shell](https://github.com/leulyk/simple_shell) - (Not fully implemented)

A simple unix command interpreter built as a project for the ALX software engineering program.

## Learning Objectives

At the end of this project, you are expected to be able to explain to anyone:


	Who designed and implemented the original Unix operating system
	Who wrote the first version of the UNIX shell
	Who invented the B programming language (the direct predecessor to the C programming language)
	Who is Ken Thompson
	How does a shell work
	What is a pid and a ppid
	How to manipulate the environment of the current process
	What is the difference between a function and a system call
	How to create processes
	What are the three prototypes of main
	How does the shell use the PATH to find the programs
	How to execute another program with the execve system call
	How to suspend the execution of a process until one of its children terminates
	What is EOF / “end-of-file”?

### Code will be compiled this way:

	$ gcc -Wall -Werror -Wextra -pedantic -std=gnu89

### Allowed system calls and functions

> **Functions:** closedir, exit, fflush, free, getcwd, getline, isatty, malloc, 
		opendir, readdir

> **System calls:** access, chdir, close, execve, _exit, fork, getpid, kill, open
		read, signal, stat (__xstat), lstat (__lxstat), fstat (__fxstat),
		wait, waitpid, wait3, wait4, write

### Output

	Unless specified otherwise, your program must have the exact same output as sh (/bin/sh) as well as the exact same error output.
	The only difference is when you print an error, the name of the program must be equivalent to your argv[0]

### Testing

	> Your shell should work like this in interactive mode:

		$ ./hsh
		($) /bin/ls
		hsh main.c shell.c
		($)
		($) exit
		$

	> But also in non-interactive mode:

		$ echo "/bin/ls" | ./hsh
		hsh main.c shell.c test_ls_2
		$
		$ cat test_ls_2
		/bin/ls
		/bin/ls
		$
		$ cat test_ls_2 | ./hsh
		hsh main.c shell.c test_ls_2
		hsh main.c shell.c test_ls_2
		$
	
-------------------------------------------------------------------------------------------------------------------------------------------

### Mandatory Tasks

- [ ] **0. README, man, AUTHORS**

	- Write a README.
	- Write a man for your shell.
	- You should have an AUTHORS file at the root of your repository, listing all individuals having contributed content to the repository.

- [ ] 1. **Betty would be proud**

	- Write a beautiful code that passes the Betty checks

- [ ] 2. **Simple shell 0.1**

	- Write a UNIX command interpreter

		Usage: simple_shell

	- Your shell should:

		- Display a prompt and wait for the user to type a command. A command line always ends with a new line.
		- The prompt is displayed again each time a command has been executed.
		- The command lines are simple, no semicolons, no pipes, no redirections or any other advanced features.
		- The command lines are made only of one word. No arguments will be passed to programs.
		- If an executable cannot be found, print an error message and display the prompt again.
		- Handle errors.
		- You have to handle the “end of file” condition (Ctrl+D)

- [ ] 3. **Simple shell 0.2**

	Simple shell 0.1 +
		
		- Handle command lines with arguments

- [ ] 4. **Simple shell 0.3**

	Simple shell 0.2 +

		- Handle the PATH
		- fork must not be called if the command doesn't exist

- [ ] 5. **Simple shell 0.4**

	Simple shell 0.3 +

		- Implement the 'exit' built-in, that exits the shell
		- Usage: exit
		- You don't have to hanlde arguments
	
- [ ] 6. **Simple shell 1.0**

	Simple shell 0.4 +

		- Implement the env built-in, that prints the current environment

- [ ] 7. **What happens when you type `ls -l *.c` in the shell**

	Write a blog post describing step by step what happens when you type ls -l *.c and hit Enter in a shell.
	Try to explain every step you know of, going in as much details as you can, give examples and draw diagrams when needed.
	You should merge your previous knowledge of the shell with the specifics of how it works under the hoods (including syscalls).

		- Have at least one picture, at the top of the blog post
		- Publish your blog post on Medium or LinkedIn
		- Share your blog post at least on LinkedIn
		- Only one blog post by team
		- The blog post must be done and published before the first deadline (it will be part of the manual review)
		- Please, remember that these blogs must be written in English to further your technical ability in a variety of settings

------------------------------------------------------------------------------------------------------------------------------------------

### Advanced Tasks

- [ ]  8. **Test suite**

	Contribute a test suite for the shell (a task shared everyone in the class) which adheres to the guidelines:

		- The test suite should cover every tasks from 0 to 20
		- The test suite should cover every regular cases (many different examples) and possible edge cases
		- The entire class should work on the same test suite. Use only one repository (don’t forget the README.md file)
		- Start adding tests ASAP and not just before the deadline in order to help everyone from day 0
		- You can take (or fork) inspiration from this example, but it is not mandatory to follow this format/way
		- Adopt a style and be consistent. If you choose a style that already exists, add it to the README.md in a style section. 
		- If you write your own, create a Wiki page attached to the project and refer to it in the README.md style section.
		- You should have an AUTHORS file, listing all individuals having contributed content to the repository.

- [ ] 9. **Simple shell 0.1.1**

	Simple shell 0.1 +

		- Write your own getline function
		- Use a buffer to read as many characters at once and call the least possible using the read system call
		- You will need to use static variables
		- You don't have to be able to move the cursor

- [ ] 10. **Simple shell 0.2.1**

	Simple shell 0.2 +

		- You are not allowed to use strtok

- [ ] 11. **Simple shell 0.4.1**

	Simple shell 0.4 +

		- Handle arguments for the built-in 'exit'
		- Usage: exit status, where status is an integer used to the exit the shell

- [ ] 12. **Simple shell 0.4.2**

	Simple shell 0.4 +

		- Handle Ctrl+C: your shell should not quit when the user enter ^c

- [ ] 13. **setenv, unsetenv**

	Simple shell 1.0 +

	Implement the setenv and unsetenv built-in commands
		
		- setenv

			- Initialize a new environment variable, or modify an existing one
			- Command syntax: setenv VARIABLE VALUE
			- Should print something on stderr on failure

		- unsetenv

			- Remove an environment variable
			- Command syntax: unsetenv VARIABLE
			- Should print something on stderr on failure

- [ ] 14. **cd**

	Simple shell 1.0 +

	Implement the built-in command 'cd':
	
		- Changes the current directory of the process.
		- Command syntax: cd [DIRECTORY]
		- If no argument is given to cd the command must be interpreted like cd $HOME
		- You have to handle the command cd -
		- You have to update the environment variable PWD when you change directory

- [ ] 15. **;**

	Simple shell 1.0 +

		- Handle the commands separator ;

- [ ] 16. **&& and ||**

	Simple shell 1.0 +

		- Hanlde the && and || shell logical operators

- [ ] 17. **alias**

	Simple shell 1.0 +

		- Implement the 'alias' built-in command
		- Usage: alias [name[='value'] ...]
			- alias: Prints a list of all aliases, one per line, in the form name='value'
			- alias name [name2 ...]: Prints the aliases name, name2, etc 1 per line, in the form name='value'
			- alias name='value' [...]: Defines an alias for each name whose value is given.
				-If name is already an alias, replaces its value with value

- [ ] 18. **Variables**

	Simple shell 1.0 +

		- Handle variables replacement
		- Handle the $? variable
		- Handle the ?? variable

- [ ] 19. **Comments**

	Simple shell 1.0 +

		- Handle comments (#)

- [ ] 20. **help**

	Simple shell 1.0 +

		- Implement the 'help' built-in
		- Usage: help [BUILTIN]

- [ ] 21. **history**

	Simple shell 1.0 +

		- Implement the history built-in, without any argument
		- The history built-in displays the history list, one command by line, preceded with line numbers (starting at 0)
		- On exit, write the entire history, without line numbers, to a file named .simple_shell_history in the directory $HOME
		- When the shell starts, read the file .simple_shell_history in the directory $HOME if it exists, and set the first line number to the total number of lines in the file modulo 4096

- [ ] 22. **File as input**

	Simple shell 1.0 +

		- Usage: simple_shell [filename]
		- Your shell can take a file as a command line argument
		- The file contains all the commands that your shell should run before exiting
		- The file should contain one command per line
		- In this mode, the shell should not print a prompt and should not read from stdin

## Author

<a href="https://linkedin.com/in/leul-yiheyis-a165a394" target="blank">Leul Yiheyis</a>

<a href="https://github.com/PeterSimiyu" target="blank">Peter Simiyu</a>
