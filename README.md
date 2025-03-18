
```markdown
# Pico Shell - System Programming Assignment

This project implements a simple shell program (Pico Shell) in C. It supports basic shell functionalities such as built-in commands (`echo`, `pwd`, `cd`, `exit`), command execution via `fork()` and `execvp()`, and dynamic argument handling (with a maximum of 5 arguments per command). The shell can execute commands either by their full paths or just by their names (if available in the system's `PATH`).

## Features

- **Built-in Commands:**
  - `echo`: Prints the provided arguments to the console.
  - `pwd`: Prints the current working directory.
  - `cd`: Changes the current working directory.
  - `exit`: Exits the Pico shell.

- **Command Execution:**
  - External commands can be executed by specifying their name (no need for the full path).
  - The program uses `fork()` to create child processes and `execvp()` to replace the child process with the specified command.

- **Command Line Parsing:**
  - Supports parsing the command line and handling up to 5 arguments separated by spaces.
  - Dynamically allocates memory for argument parsing and ensures there are no memory leaks.
  
- **Argument Handling:**
  - The shell supports up to 5 arguments for each command. If more than 5 arguments are provided, they will be ignored.
  
- **Dynamic Memory Allocation:**
  - Memory is dynamically allocated for the input buffer and arguments to handle varying input sizes and avoid memory leaks.

## Requirements

- A C compiler (e.g., GCC) that supports C99.
- Linux-based operating system (tested on Ubuntu 20.04).
- The `man` pages for `execvp` and `chdir` (for reference).

## Compilation

To compile the Pico Shell, run the following command:

```bash
gcc -o myPicoShell myPicoShell.c
```

This will generate the executable `myPicoShell` from the source file `myPicoShell.c`.

## Running the Shell

After compiling, you can run the shell with the following command:

```bash
./myPicoShell
```

The shell will prompt you with the following:

```
ismail's_Pico_Shell$
```

You can then enter commands like `echo`, `pwd`, `cd <directory>`, or `exit`.

## Example Usage

### 1. **Echo command:**
   ```bash
   ismail's_Pico_Shell$ echo Hello, World!
   Hello, World!
   ```

### 2. **Print working directory:**
   ```bash
   ismail's_Pico_Shell$ pwd
   /home/ismail-malash/Desktop/SysProgInLinux
   ```

### 3. **Change directory:**
   ```bash
   ismail's_Pico_Shell$ cd ../../Documents
   ismail's_Pico_Shell$ pwd
   /home/ismail-malash/Desktop/Documents
   ```

### 4. **External command execution:**
   ```bash
   ismail's_Pico_Shell$ ls -l -a
   total 140
   drwxrwxr-x 3 ismail-malash ismail-malash  4096 Mar 18 08:15 .
   drwxr-xr-x 7 ismail-malash ismail-malash  4096 Mar 15 00:50 ..
   drwxrwxr-x 8 ismail-malash ismail-malash  4096 Mar  9 06:44 .git
   -rwxrwxr-x 1 ismail-malash ismail-malash 16720 Mar 18 08:15 myPicoShell
   -rw-rw-r-- 1 ismail-malash ismail-malash  1822 Mar 18 08:15 myPicoShell.c
   ```

### 5. **Exit the shell:**
   ```bash
   ismail's_Pico_Shell$ exit
   ```

## Code Structure

The Pico Shell program is structured as follows:

- **myPicoShell.c**: The main program file implementing the shell functionality.
  - The main loop where user input is taken, parsed, and executed.
  - The program handles built-in commands (`echo`, `pwd`, `cd`, `exit`) directly in the main function.
  - For other commands, the program forks a child process and uses `execvp()` to execute external commands.
  
- **Dynamic Memory Allocation:**
  - Memory is dynamically allocated for the input buffer using `calloc` to handle varying input sizes.
  - The shell ensures no memory leaks by freeing allocated memory after each command execution.

- **Argument Handling:**
  - The shell supports a maximum of 5 arguments per command. The arguments are parsed and stored in an array, and the array is passed to `execvp()` to execute the command.
  - Any additional arguments beyond the maximum number are ignored.



