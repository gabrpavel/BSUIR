# Operating Systems and System Programming

## **[Course project](https://github.com/gabrpavel/BSUIR/tree/c875cec851be8d9038b12b4e3021f9fdfb976884/term4/%D0%9E%D0%A1%D0%B8%D0%A1%D0%9F/course%20work)**

## Labs:
1. **[lab 1](https://github.com/gabrpavel/BSUIR/tree/main/term4/%D0%9E%D0%A1%D0%B8%D0%A1%D0%9F/labs/lab1)**
2. **[lab 2](https://github.com/gabrpavel/BSUIR/tree/main/term4/%D0%9E%D0%A1%D0%B8%D0%A1%D0%9F/labs/lab2)**
3. **[lab 3](https://github.com/gabrpavel/BSUIR/tree/main/term4/%D0%9E%D0%A1%D0%B8%D0%A1%D0%9F/labs/lab3)**
4. **[lab 4](https://github.com/gabrpavel/BSUIR/tree/main/term4/%D0%9E%D0%A1%D0%B8%D0%A1%D0%9F/labs/lab4)**
5. **[lab 5](https://github.com/gabrpavel/BSUIR/tree/main/term4/%D0%9E%D0%A1%D0%B8%D0%A1%D0%9F/labs/lab5)**
6. **[lab 6](https://github.com/gabrpavel/BSUIR/tree/main/term4/%D0%9E%D0%A1%D0%B8%D0%A1%D0%9F/labs/lab6)**
7. **[lab 7](https://github.com/gabrpavel/BSUIR/tree/main/term4/%D0%9E%D0%A1%D0%B8%D0%A1%D0%9F/labs/lab7)**
8. **[lab 8](https://github.com/gabrpavel/BSUIR/tree/main/term4/%D0%9E%D0%A1%D0%B8%D0%A1%D0%9F/labs/lab8)**

---

## lab 1. Introduction to Linux/Unix and the programming environment. POSIX-compatible file system
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

**[CODE](https://github.com/gabrpavel/BSUIR/tree/9f3129f04189a5d92798a86c7ade416e78da5872/term4/%D0%9E%D0%A1%D0%B8%D0%A1%D0%9F/labs/lab1)**

## lab 2. The concept of processes.
### Task:
> Develop two programs - ***parent*** and ***child***.<br><br>
> Before starting the ***parent*** program, the `CHILD_PATH` environment variable is created in the environment with the name of the directory where the child program is located with the name of the directory where the ***child*** program is located.<br><br>
> The ***parent*** process (parent program) after startup receives environment variables, sorts them in `LC_COLLATE=C` and outputs them to stdout. After that it enters the loop of keyboard presses processing.<br><br>
> The "+" symbol using `fork(2)` and `execve(2)` spawns a ***child*** process and starts another instance of the ***child*** program in it. Information about the directory where the ***child*** is located is obtained from the environment using the `getenv()` function. The program name (argv[0]) is set as child_XX, where XX is a sequence number from 00 to 99. The number is incremented by the ***parent***.<br><br>
> The "*" symbol spawns a ***child*** process similarly to the previous case, but the ***child*** obtains information about the program location by scanning the array of environment parameters passed in the third parameter of the `main()` function.<br><br>
> The "&" symbol spawns a ***child*** process similarly to the previous case, but the ***child*** obtains information about the program location by scanning the array of environment parameters, specified in the external variable
> ```
> extern char **environ
> ```
> which becomes the host environment at startup.<br><br>
> When a ***child*** process is started, it is passed an abbreviated environment that includes the set of variables specified in the file that is passed to the ***parent*** process as a ***command line parameter***. The minimum set of variables must include `SHELL, HOME, HOSTNAME, LOGNAME, LANG, TERM, USER, LC_COLLATE, and PATH`. The ***child*** process opens this file, reads the variable names, gets their value from the environment, and outputs them to stdout.<br><br>
> The ***child*** process (child program) outputs its name, pid, ppid, opens a file with a set of variables, reads their names, gets their value from the environment passed to it at startup in the way specified when handling keystrokes, outputs them to stdout, and terminates.<br><br>
> The "q" symbol terminates the execution of the ***parent*** process.

**[CODE](https://github.com/gabrpavel/BSUIR/tree/5b85104fb9b4c6dd0b85fc7e2d692863a9cca166/term4/%D0%9E%D0%A1%D0%B8%D0%A1%D0%9F/labs/lab2)**

## lab 3 
### Task: 


**[CODE](https://github.com/gabrpavel/BSUIR/tree/5b85104fb9b4c6dd0b85fc7e2d692863a9cca166/term4/%D0%9E%D0%A1%D0%B8%D0%A1%D0%9F/labs/lab3)**

## lab 4 
### Task: 


**[CODE](https://github.com/gabrpavel/BSUIR/tree/5b85104fb9b4c6dd0b85fc7e2d692863a9cca166/term4/%D0%9E%D0%A1%D0%B8%D0%A1%D0%9F/labs/lab4)**

## lab 5 
### Task: 


**[CODE](https://github.com/gabrpavel/BSUIR/tree/5b85104fb9b4c6dd0b85fc7e2d692863a9cca166/term4/%D0%9E%D0%A1%D0%B8%D0%A1%D0%9F/labs/lab5)**

## lab 6 
### Task: 


**[CODE](https://github.com/gabrpavel/BSUIR/tree/5b85104fb9b4c6dd0b85fc7e2d692863a9cca166/term4/%D0%9E%D0%A1%D0%B8%D0%A1%D0%9F/labs/lab6)**

## lab 7 
### Task: 


**[CODE](https://github.com/gabrpavel/BSUIR/tree/5b85104fb9b4c6dd0b85fc7e2d692863a9cca166/term4/%D0%9E%D0%A1%D0%B8%D0%A1%D0%9F/labs/lab7)**

## lab 8 
### Task: 


**[CODE](https://github.com/gabrpavel/BSUIR/tree/5b85104fb9b4c6dd0b85fc7e2d692863a9cca166/term4/%D0%9E%D0%A1%D0%B8%D0%A1%D0%9F/labs/lab8)**
