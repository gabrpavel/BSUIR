# Operating Systems and System Programming

## **[Course project]("https://github.com/gabrpavel/BSUIR/tree/main/term4/ОСиСП/course work")**

## Labs:
1. **[lab 1](https://github.com/gabrpavel/BSUIR/tree/main/term4/ОСиСП/labs/lab1)**
2. **[lab 2](https://github.com/gabrpavel/BSUIR/tree/main/term4/ОСиСП/labs/lab2)**
3. **[lab 3](https://github.com/gabrpavel/BSUIR/tree/main/term4/ОСиСП/labs/lab3)**
4. **[lab 4](https://github.com/gabrpavel/BSUIR/tree/main/term4/ОСиСП/labs/lab4)**
5. **[lab 5](https://github.com/gabrpavel/BSUIR/tree/main/term4/ОСиСП/labs/lab5)**
6. **[lab 6](https://github.com/gabrpavel/BSUIR/tree/main/term4/ОСиСП/labs/lab6)**
7. **[lab 7](https://github.com/gabrpavel/BSUIR/tree/main/term4/ОСиСП/labs/lab7)**
8. **[lab 8](https://github.com/gabrpavel/BSUIR/tree/main/term4/ОСиСП/labs/lab8)**

---

## lab 1. Introduction to Linux/Unix and the programming environment. POSIX-compatible file system.
### Task: 
> Master efficient file manipulation in shell and ***mc***.<br>
> Develop a ***dirwalk*** program that scans the file system and outputs information to ***stdout*** information according to the program options.<br>
> The output format is similar to that of the ***find*** utility.<br>
> ```
> dirwalk [dir] [options]
> ```
> - `dir` -- initial directory. If omitted, current (./).<br>
> - `options`<br>
> - `-l` -- only symbolic links (***-type l***)<br>
> - `-d` -- directories only (***-type d***)<br>
> - `-f` -- files only (***-type f***)<br>
> - `-s` -- sort output according to ***LC_COLLATE***<br>
>
> Options can be specified either before a directory or after.<br>
> The options can be specified either separately or together (***-l -d, -ld***).<br>
> If the ***ldf*** options are omitted, directories, files, and links are output.<br>
>
> It is recommended to use `getopt(3)` or `gengetopt(1)` to handle options.<br>

**[CODE](https://github.com/gabrpavel/BSUIR/tree/main/term4/ОСиСП/labs/lab1)**

---

## lab 2. The concept of processes.
### Task:
> Develop two programs - ***parent*** and ***child***.<br><br>
> Before starting the ***parent*** program, the `CHILD_PATH` environment variable is created in the environment with the name of the directory where the child program is located with the name of the directory where the ***child*** program is located.<br><br>
> The ***parent*** process (parent program) after startup receives environment variables, sorts them in `LC_COLLATE=C` and outputs them to stdout. After that it enters the loop of keyboard presses processing.<br><br>
> The `+` symbol using `fork(2)` and `execve(2)` spawns a ***child*** process and starts another instance of the ***child*** program in it. Information about the directory where the ***child*** is located is obtained from the environment using the `getenv()` function. The program name (argv[0]) is set as child_XX, where XX is a sequence number from 00 to 99. The number is incremented by the ***parent***.<br><br>
> The `*` symbol spawns a ***child*** process similarly to the previous case, but the ***child*** obtains information about the program location by scanning the array of environment parameters passed in the third parameter of the `main()` function.<br><br>
> The `&` symbol spawns a ***child*** process similarly to the previous case, but the ***child*** obtains information about the program location by scanning the array of environment parameters, specified in the external variable
> ```
> extern char **environ
> ```
> which becomes the host environment at startup.<br><br>
> When a ***child*** process is started, it is passed an abbreviated environment that includes the set of variables specified in the file that is passed to the ***parent*** process as a ***command line parameter***. The minimum set of variables must include `SHELL, HOME, HOSTNAME, LOGNAME, LANG, TERM, USER, LC_COLLATE, and PATH`. The ***child*** process opens this file, reads the variable names, gets their value from the environment, and outputs them to stdout.<br><br>
> The ***child*** process (child program) outputs its name, pid, ppid, opens a file with a set of variables, reads their names, gets their value from the environment passed to it at startup in the way specified when handling keystrokes, outputs them to stdout, and terminates.<br><br>
> The "q" symbol terminates the execution of the ***parent*** process.

**[CODE](https://github.com/gabrpavel/BSUIR/tree/main/term4/ОСиСП/labs/lab2)**

---

## lab 3. Process interaction and synchronization.
### Task: 
> Control the ***child*** processes and order the output to stdout from them using the `SIGUSR1` and `SIGUSR2` signals.
> ### Parent process actions
> When the `+` key is pressed, the ***parent*** process (P) spawns a ***child*** process (C_k) and reports it.<br>
> When the `-` key is pressed, ***P*** deletes the last generated ***C_k***, reports it and the number of remaining ones.<br>
> If `l` is entered, a list of ***parent*** and ***child*** processes is displayed.<br>
> If `k` is entered, ***P*** deletes all ***C_k*** and reports it.<br>
> If `s` is entered, ***P*** forbids all ***C_k*** to output statistics (see below).<br>
> When a `g` character is entered, ***P*** allows all ***C_k*** to output statistics.<br>
> When `s<num>` is entered, ***P*** prohibits ***C_<num>*** from outputting statistics.<br>
> When `g<num>` is entered, ***P*** allows ***C_<num>*** to output statistics.<br>
> When the characters `p<num>` are entered, ***P*** forbids all ***C_k*** output and asks ***C_<num>*** to output its statistics. After a given time (5 s, for example), if no "g" character is entered, allows all ***C_k*** to output statistics again.<br>
> When the `q` key is pressed, ***P*** deletes all ***C_k***, reports it and terminates.
> ### Child process actions
> The ***child*** process starts the alarm clock `nanosleep(2)` in the outer loop and enters the perpetual loop in which it fills the structure containing a pair of variables of ***int*** type with values {0, 0} and {1, 1} in the alternation mode.<br>
> When it receives a signal from the alarm clock, it checks the contents of the structure, collects statistics and repeats the body of the outer loop.<br>
> After a specified number of repetitions of the outer loop (e.g. 101) the ***child*** process, if allowed, outputs its PPID, PID and 4 numbers - the number of different pairs registered at the moment of receiving a signal from the alarm clock.<br>
> The output is character-by-character `fputc(3)`.<br>
> ***C_k*** requests access to stdout from ***P*** and outputs after confirmation. When the output is complete, ***C_k*** informs ***P*** about it.<br>
> The waiting time interval and the number of repetitions of the outer loop must be chosen so that the statistics are meaningful.<br><br>
> Messages are output to `stdout`.<br>
> Process messages must contain identifying data so that the output can be filtered by the `grep` utility.<br>
**[CODE](https://github.com/gabrpavel/BSUIR/tree/main/term4/ОСиСП/labs/lab3)**

---

## lab 4 
### Task: 


**[CODE](https://github.com/gabrpavel/BSUIR/tree/main/term4/ОСиСП/labs/lab4)**

---

## lab 5 
### Task: 



**[CODE](https://github.com/gabrpavel/BSUIR/tree/main/term4/ОСиСП/labs/lab5)**

---

## lab 6 
### Task: 


**[CODE](https://github.com/gabrpavel/BSUIR/tree/main/term4/ОСиСП/labs/lab6)**

---

## lab 7 
### Task: 


**[CODE](https://github.com/gabrpavel/BSUIR/tree/main/term4/ОСиСП/labs/lab7)**

---

## lab 8 
### Task: 


**[CODE](https://github.com/gabrpavel/BSUIR/tree/main/term4/ОСиСП/labs/lab8)**
