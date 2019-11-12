## 「 GDB 调试 」

<div align="right">
    <a href="https://github.com/fmw666/Linux#-目录导航">返回目录导航 ↩</a>
</div>

<br>

&emsp;&emsp;**GDB（GNU Debugger）** 通过与 GCC 的配合使用，为基于 Linux 的软件开发提供了一个完善的调试环境

<br>

+ **[GDB 的运行](#-gdb-的运行)**

+ **[条件表达式](#-条件表达式)**

### 💬 GDB 的运行

+ 首先使用 GCC 对 test.c 进行编译：

    ```bash
    $ gcc -g test.c -o test
    ```

    > 注意：GDB 进行调试的是可执行文件，而不是如 “.c” 的源代码，因此，需要先通过 GCC 编译生成可执行文件才能用 GDB 进行调试。编译时一定要加上选项 “-g”，这样编译出的可执行代码中才包含调试信息，否则 GDB 无法载入该可执行文件

### 💬 进入 GDB 调试环境

```bash
$ gdb test
GNU gdb (Debian 7.12-6) 7.12.0.20161007-git
Copyright (C) 2016 Free Software Foundation, Inc.
License GPLv3+: GNU GPL version 3 or later <http://gnu.org/licenses/gpl.html>
This is free software: you are free to change and redistribute it.
There is NO WARRANTY, to the extent permitted by law.  Type "show copying"
and "show warranty" for details.
This GDB was configured as "x86_64-linux-gnu".
Type "show configuration" for configuration details.
For bug reporting instructions, please see:
<http://www.gnu.org/software/gdb/bugs/>.
Find the GDB manual and other documentation resources online at:
<http://www.gnu.org/software/gdb/documentation/>.
For help, type "help".
Type "apropos word" to search for commands related to "word"...
Reading symbols from test...done.
(gdb) 
```

### 💬 GDB 使用流程

+ 查看程序源文件

    ```bash
    -(gdb) list
    ```

+ 设置断点

    ```bash
    -(gdb) break 6
    ```

+ 查看断点设置情况

    ```bash
    -(gdb) info b
    ```

+ 运行程序

    ```bash
    -(gdb) run
    ```

+ 查看变量值

    ```bash
    -(gdb) print n
    $1 = 0
    -(gdb) print i
    $2 = 123
    ```

+ 单步运行

    ```bash
    -(gdb) next
    -(gdb) step
    ```

+ 恢复程序运行

    ```bash
    -(gdb) c
    Continuing.
    The sum of 1-50 is :1275
    Program exited normally.
    ```

+ 

<div align="center">
    - End -
</div>