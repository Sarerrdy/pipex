*This project has been created as part of the 42 curriculum by eina.*

# Pipex

## Description

Pipex is a 42 project that recreates the behavior of a simple shell pipeline:

`< infile cmd1 | cmd2 > outfile`

The goal is to understand UNIX process control, file descriptors, pipes, and command execution.  
The program takes an input file, executes a first command with that file as standard input, pipes its output into a second command, and writes the final result into an output file.

This project reinforces:
- process creation (`fork`)
- inter‑process communication (`pipe`)
- file redirection (`dup2`)
- command execution (`execve`)
- environment variable handling (`PATH` resolution)

---

## Instructions

### **Compilation**

Run:

`make`


This builds the `pipex` executable and compiles `libft` automatically.

### **Execution**


`./pipex infile "cmd1 args" "cmd2 args" outfile`


Example:

`./pipex input.txt  "grep hello" "wc -l" output.txt`


This behaves like:

`< input.txt  grep hello | wc -l > output.txt`


### **Project Structure**

```
pipex/
│
├── libft/              # Custom libft library
│
├── mandatory/
│   ├── main.c
│   ├── pipex.c
│   ├── fd_utils.c
│   ├── path_utils.c
│   ├── error.c
│   ├── clean_up.c
│
├── pipex.h
├── Makefile
└── README.md
```


---

## Resources

### **Classic references**

- UNIX manual pages: `man 2 pipe`, `man 2 fork`, `man 2 execve`, `man 2 dup2`, `man 2 access`
- GNU Bash manual – pipelines and redirections  
- Advanced Programming in the UNIX Environment (W. Richard Stevens)
- Linux Programmer’s Manual

### **How AI was used**

AI assistance (Microsoft Copilot) was used for:
- reviewing code structure for leaks and Norm compliance
- generating this README according to the official 42 requirements

All code was written, validated, and debugged manually.

---

## Additional Notes

- This repository contains **only the mandatory part** of Pipex.
- Command parsing is intentionally simple, as required by the subject.
- The program is fully leak‑free and Norm‑compliant.



