```text
                         ________________________________________________
                        /                                                \
                       |    _________________________________________     |
                       |   |                                         |    |
                       |   | miniteam:~$ Minishell as beautiful      |    |
                       |   | as a shell                              |    |
                       |   |                                         |    |
                       |   |                                         |    |
                       |   |                                         |    |
                       |   |                                         |    |
                       |   |                                         |    |
                       |   |                                         |    |
                       |   |_________________________________________|    |
                       |                                                  |
                       \_________________________________________________/
                              \___________________________________/
                           ___________________________________________
                        _-'    .-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.  --- `-_
                     _-'.-.-. .---.-.-.-.-.-.-.-.-.-.-.-.-.-.-.--.  .-.-.`-_
                  _-'.-.-.-. .---.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-`__`. .-.-.-.`-_
               _-'.-.-.-.-. .-----.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-----. .-.-.-.-.`-_
            _-'.-.-.-.-.-. .---.-. .-------------------------. .-.---. .---.-.-.-.`-_
           :-------------------------------------------------------------------------:
           `---._.-------------------------------------------------------------._.---'
```

# Minishell (42 - lvl 3)

## 1. Overview

Minishell is a project of the common core in school 42. This project was made in collaboration with [Ines](https://github.com/inesalves44).

It's objective is to create a simple Unix shell!
A Unix shell is a command-line interface that allows users to interact with the operating system by executing commands. It serves as a bridge between the user and the kernel of the operating system. Minishell aims to replicate some of the basic functionalities of a Unix shell, providing a simplified version of the command-line interface.

## 2. Rules
These are the features needed to implement in the minishell process:

1. Command Line Interface: Implement a prompt that accepts user input and displays the shell's output.

2. Built-in Commands: Implement essential built-in commands such as `cd`, `echo`, `pwd`, `export`, `unset`, and `env`. These commands should be executed directly within the shell.

3. External Commands: execute shell commands directly in the program.

4. Handle `<`, `>`, `>>`,`<<`.

5. Pipes: Implement the ability to chain commands together using pipes (`|`).

6. Environment Variables: Implement functionalities to manage environment variables, including setting, unsetting, and displaying them.

7. Signal Handling: Handle signals like `Ctrl-C` (SIGINT) and `Ctrl-D` (EOF)  and `Ctrl-\` to provide a proper termination of processes and enable an interactive experience.

8. Error Handling: Implement error handling to display appropriate error messages for invalid commands or other errors that may occur during execution.

## 3. The Project
To implement this project well we needed to create a few key elements: a lexer, a parser, an expander, a treatement for redirection and for commands/pipes.

### 3.1 The Lexer
The lexer plays a crucial role in parsing the received string by separating it into tokens for future use. In our implementation, we utilize a doubly linked list as our lexer, effectively dividing the string into tokens.

It's important to note that before the separation process, we clean the string by handling quotes. Our approach involves identifying the first quote encountered and searching for its closing counterpart from the end of the string to the beginning. This ensures proper handling of quoted sections within the input.

Token  | Lexer
-------|--------
STRING | ls
PIPE   | |
STRING | grep
STRING | mini

### 3.2 The Parser
With the lexer in place, we can now proceed to build the parser, which is a crucial component for executing commands in a shell.

Our parser constructs an Abstract Syntax Tree (AST) to represent the structure of the commands. Here's the general process we follow:

1. Parsing Pipes and Redirections: Initially, we focus on parsing pipes (|) and redirections (<, >, >>). These elements define how command output flows or is redirected to files. By identifying and capturing these constructs, we establish the connections between commands in the AST.

2. Node Interpretation: Once we have parsed the pipes and redirections, we proceed to interpret the content of each node in the AST. This step involves understanding the specific details of the command within each node. Notably, in the case of redirections, we recognize that the files are always specified on the right side of the redirection indicators.

Example of a parsing tree for the command: cat file | wc -l > out

              PIPE
            /     \
     cat; file     REDIRECT
                   /     \
                 out    wc; -l

### 3.3 The Expander
Before processing the commands, it is important to handle the expansion of the "$" character. In bash, the "$" symbol is used to expand environment variables. In our implementation, we manage environment variables using a linked list, which is derived from the bash environment variables.

To accomplish this, our expander searches for variables and updates their values accordingly. If a variable's value does not exist, the expander returns NULL. By performing this expansion step, we ensure that when the execution of commands and redirections takes place, all relevant components have been replaced with their corresponding environment variable values.

### 3.4 Redirections, Commands and Pipes
In this stage, we begin the actual execution of the command string. For each command or segment of the pipe, we start by examining the redirections to determine the appropriate input and output for the command.

Next, we distinguish between builtin commands, which are handled internally, and external commands that require the use of the `execve` system call for execution.

Throughout the execution process, we meticulously check for errors at various stages. This includes verifying the correctness of the command structure, detecting any issues with input/output redirection, and ensuring the proper handling of errors in both builtin and external commands.

## 4. Execution
To run our minishell you just need to run make!
Then ./minishell. And there we go!!

![Untitled design(1)](https://github.com/inesalves44/minishell/assets/105734074/efcbdfe6-75df-42ed-ba07-39acb4f42105)

## Make Commands
```
make all - creates executable minishell
make clean - cleans the objects
make fclean - clean executable and any library, also runs clean
make re - runs clean and fclean and then runs all to create the executable
 ```

 ## Links
 [42 Docs](https://harm-smits.github.io/42docs/projects/minishell)

 [Parsing tree](https://www.geeksforgeeks.org/parse-tree-and-syntax-tree/)

 [Shell Language](https://pubs.opengroup.org/onlinepubs/009695399/utilities/xcu_chap02.html)

 [Writing a shell example](https://www.cs.purdue.edu/homes/grr/SystemsProgrammingBook/Book/Chapter5-WritingYourOwnShell.pdf)
