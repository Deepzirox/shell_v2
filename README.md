# 0x02. C - Shell v2

`Shell v2` is the continous `Shell v1` project for the System Programming & Algorithms specialization for Holberton School.

The shell is an interactive interface that allows users to execute commands and utilities in Linux and other UNIX based operatin systems. The shell lets the user interact internally with the system by using built-in functions. When a user types in a command this is interpreted as an input that will execute a program. Once the program is finishes it will display an output.

### The Shell v2 will:

- Display a prompt and wait for the user to type a command. A command line always ends with a new line.
- The prompt is displayed again each time a command has been executed.
- If an executable cannot be found, print an error message and display the prompt again.
- Handle errors.
- You have to handle the “end of file” condition (Ctrl+D)
- Handle command lines with arguments
- Handle and parse the PATH environment variable

### Builtins

- Implement the built-in command `exit`:
  - Your `exit` built-in must behave exactly like `sh`‘s
  - You have to handle arguments

- Implement the built-in command cd:
  - Changes the current directory of the process.
  - Command syntax: `cd [path]`
  - If no argument is given to `cd` the command must be interpreted like `cd $HOME`
  - You have to handle the command `cd -`
  - You have to update the environment variable `PWD` when you change directory

- Implement the built-in command `env`:
  - Prints the current environment

### How to use?

In order to use the `Shell v2` you should use a GNU/Linux based operating system, which allows you to execute commands using the command line interface (CLI) or terminal.

#### Instructions

- Open your terminal.
- Git clone the repository in your machine.

`$ git clone https://github.com/Deepzirox/shell_v2.git`
- To run the `Shell v2` you should execute the `hsh` file in your terminal. This will open the shell in interactive mode and will prompt you to type a command:

`$ ./hsh`

The shell can execute the commands that are stored in `/bin` folder, e.g. `ls`, `cat`, `echo`, `mkdir`, `touch`, `date`, etc. 

### LICENSE

[GNU General Public License v3.0](https://github.com/Deepzirox/shell_v2/blob/master/LICENSE)