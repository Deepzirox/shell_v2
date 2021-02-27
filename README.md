# 0x02. C - Shell v2

`Shell v2` is the continous `Shell v1` project for the System Programming & Algorithms specialization for Holberton School.

The shell is an interactive interface that allows users to execute commands and utilities in Linux and other UNIX based operatin systems. The shell lets the user interact internally with the system by using built-in functions. When a user types in a command this is interpreted as an input that will execute a program. Once the program is finishes it will display an output.

## Installation and Compilation

In order to use the `Shell v2` you should use a GNU/Linux based operating system which allows you to execute commands using the command line interface (CLI) or terminal.

#### Instructions

- Open your terminal. Go to the directory where you would like to install te repository.
- Git clone the repository in your machine.
```
$ git clone https://github.com/Deepzirox/shell_v2.git
```
- Locate yourself in `/shell_v2` folder:
```
$ cd shell_v2
```
- Make hsh file:
```
$ make
```
- To run the `Shell v2` you should execute the `hsh` file in your terminal. This will open the shell in interactive mode and will prompt you to type a command:
```
$ ./hsh
```

### Example

The shell can execute the commands that are stored in `/bin` folder, e.g. `ls`, `cat`, `echo`, `mkdir`, `touch`, `date`, etc. 

```
$ ./hsh
(14:4:2)~(/home/your_pc/shell_v2)
>>>  ls
README.md   LICENSE    README.md   argv.c   env2.c	     hsh       main.c	   process.c   shell.h	   virtual.c
 AUTHORS.md     Makefile   alias.c     env.c    handlers.c   input.c   man_1_hsh   shell.c     strings.c
(14:4:56)~(/home/your_pc/shell_v2)
>>>  /bin/ls
README.md   LICENSE    README.md   argv.c   env2.c	     hsh       main.c	   process.c   shell.h	   virtual.c
 AUTHORS.md     Makefile   alias.c     env.c    handlers.c   input.c   man_1_hsh   shell.c     strings.c
(14:5:18)~(/home/your_pc/shell_v2)
>>>  exit
exit
$
```


### LICENSE

[GNU General Public License v3.0](https://github.com/Deepzirox/shell_v2/blob/master/LICENSE)