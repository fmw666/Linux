## 「 GNU CC 编程 」

<div align="right">
    <a href="https://github.com/fmw666/Linux#-目录导航">返回目录导航 ↩</a>
</div>

<br>

&emsp;&emsp;**GCC（GNU Compiler Collection，GNU 编译器套件）** 是由 GNU 开发的编程语言编译器。

<br>

+ **[简介](#-简介)**

+ **[GCC 所支持的扩展名表](#-gcc-所支持的扩展名表)**

+ **[GCC 编译过程](#-gcc-编译过程)**

+ **[函数库之 静态库](#-函数库之-静态库)**

+ **[函数库之 动态库](#-函数库之-动态库)**

+ **[多个源文件的编译](#-多个源文件的编译)**

+ **[GCC 编译选项汇总](#-gcc-编译选项汇总)**

+ **[出错检查与警告提示选项](#-出错检查与警告提示选项)**

### 💬 简介

+ GCC 的初衷是为 GNU 操作系统专门编写一款编译器，现已被大多数类 Unix 操作系统（如 Linux、BSD、Mac OS X 等）采纳为标准的编译器，甚至在微软的 Windows 上也可以使用 GCC

+ GCC 原名为 GNU C 语言编译器（GNU C Compiler），只能处理 C 语言。但其很快扩展，变得可处理 C++，后来又扩展为能够支持更多编程语言，如 Fortran、Pascal、Objective -C、Java、Ada、Go 以及各类处理器架构上的汇编语言等，所以改名 GNU 编译器套件（GNU Compiler Collection）

+ GCC 编译器能将 C、C++ 语言源程序、汇编程序和目标程序编译、连接成可执行文件，如果没有给出可执行文件的名字，GCC 将生成一个名为 a.out 的文件

+ 在 Linux 系统中，编译器通过程序的扩展名可分辨出编写原始程序代码所用的语言，由于不同程序所需要执行编译的步骤是不同的。因此 GCC 可根据不同的扩展名对它们进行分别处理

### 💬 GCC 所支持的扩展名表

|扩展名|文件类型|后续编译流程|
|:----|:------|:---------|
|.c|C 语言源代码文件|预处理、编译、汇编、链接|
|.C/.cc/.cxx|C++ 源代码文件|预处理、编译、汇编、链接|
|.i|以及预处理过的 C 源代码文件|编译、汇编、链接|
|.ii|已经预处理过的 C++ 源代码文件|编译、汇编、链接|
|.s|汇编语言源代码文件|汇编、链接|
|.S|经过预编译的汇编语言源代码文件|汇编、链接|
|.a|由目标文件构成的档案库文件|链接|
|.o|编译后的目标文件|链接|
|.h|程序所包含的头文件|

### 💬 GCC 编译过程

> 基本语法格式：

```bash
gcc [选项] 源文件 [选项] [目标文件]
```

<div align="right">
    <b><i>编译过程分为四个阶段 ⬇</i></b>
</div>

+ **预处理（Pre-Processing）**

    ```bash
    $ gcc -E hello.c -o hello.i
    ```

    + "[-E](#welcome)"：指定只进行预处理

    + "[hello.c](#welcome)"：源程序文件

    + "[-o](#welcome)"：指定生成目标文件

    + "[hello.i](#welcome)"：预处理过程生成的目标文件

+ **编译（Compiling）**

    ```bash
    $ gcc -S hello.i -o hello.S
    ```

    + "[-S](#welcome)"：指定只进行到编译阶段

    + "[hello.i](#welcome)"：进行编译的源文件

    + "[-o](#welcome)"：指定生成目标文件

    + "[hello.S](#welcome)"：编译生成的目标文件名

+ **汇编（Assembling）**

    ```bash
    $ gcc -c hello.S -o hello.o
    ```
    
    + "[-c](#welcome)"：指定只进行到汇编阶段结束为止

    + "[hello.S](#welcome)"：进行汇编的源文件

    + "[-o](#welcome)"：指定生成目标文件

    + "[hello.o](#welcome)"：二进制目标代码文件，编译生成的目标文件名

+ **链接（Linking）**

&emsp;&emsp;在目标文件 hello.o 中没有定义 “printf” 的函数实现，且在预编译中包含进的 “stdio.h” 中也只有该函数的声明，而没有定义函数的实现，系统把这些函数实现都被做到名为 libc.so.6 的库文件中去了，在没有特别指定时，gcc 会到系统默认的搜索路径 “/usr/lib” 下进行查找，也就是链接到 libc.so.6 库函数中去，这样就能实现函数 “printf” 了，而这也就是链接的作用

### 💬 函数库之 静态库

&emsp;&emsp;编译链接时，把库文件的代码全部加入到可执行文件中，因此生成的文件比较大，但在运行时也就不再需要库文件了。其后缀名一般为：`.a`

<div align="right">
    <b><i>静态库的创建 ⬇</i></b>
</div>

+ **创建源文件**

    ```c
    /*
     * libhello.h
     */
    #ifndef _libhello_H_
    #define _libhello_H_
    void print_hello(void);
    #endif
    ```

    > libhello.h

    ```c
    /*
     * libhello.c
     */
    #include <stdio.h>
    void print_hello(void)
    {
        printf("hello library\n");
    }
    ```

    > libhello.c

+ **生成目标文件 libhello.o**

    ```bash
    $ gcc -c libhello.c -o libhello.o
    ```

+ **使用 `ar` 命令创建静态库 libhello.a**

    ```bash
    $ ar -rc libhello.a libhello.o
    ```

<div align="right">
    <b><i>静态库的使用 ⬇</i></b>
</div>

+ **编辑测试文件**

    ```c
    /*
     * usehello.c
     */
    #include "libhello.h"
    
    int main(void)
    {
        print_hello();
        return 0;
    }
    ```

+ **生成可执行文件**

    ```bash
    $ gcc -o usehello usehello.c libhello.a
    ```

+ **运行测试文件**

    ```bash
    $ ./usehello
    ```

### 💬 函数库之 动态库

&emsp;&emsp;编译链接时，没有把库文件的代码加入到可执行文件中，而是在程序执行时运行链接文件加载库，这样可以节省系统的开销。其后缀名一般为：`.so`，如前面 libc.so.6 就是动态库，GCC 在编译时默认使用动态库

<div align="right">
    <b><i>动态库的创建 ⬇</i></b>
</div>

+ **创建源文件**

    ```c
    /*
     * libhello.h
     */
    #ifndef _libhello_H_
    #define _libhello_H_
    void print_hello(void);
    #endif
    ```

    > libhello.h

    ```c
    /*
     * libhello.c
     */
    #include <stdio.h>
    void print_hello(void)
    {
        printf("hello library\n");
    }
    ```

    > libhello.c

+ **生成共享库目标文件 libhello.o**

    ```bash
    $ gcc -fPIC -Wall -g -c libhello.c -o libhello.o
    ```

    + 编译共享库 libhello.so.1.0

        ```bash
        $ gcc -g -shared -W1,-soname,libhello.so -o libhello.so.1.0 libhello.o
        ```

    + 创建共享库的符号连接

        ```bash
        $ ln -s libhello.so.1.0 libhello.so
        ```

<div align="right">
    <b><i>动态库的使用 ⬇</i></b>
</div>

+ **编辑测试文件**

    ```c
    /*
     * usehello.c
     */
    #include "libhello.h"
    
    int main(void)
    {
        print_hello();
        return 0;
    }
    ```

+ **生成可执行文件**

    ```bash
    $ gcc -o usehello usehello.c -lhello -L ./
    ```

+ **运行测试文件**

    ```bash
    $ LD_LIBRARY_PATH=$(pwd) ./usehello
    ```

### 💬 多个源文件的编译

    ```
    $ gcc foo1.c foo2.c -o foo
    ```

&emsp;&emsp;对于源文件不止一个情况，GCC 编译过程仍然按照预处理、编译、汇编和链接的过程依次进行。因此，上面这条命令相当于依次执行如下三条命令：

    ```bash
    $ gcc -c foo1.c -o foo1.o
    $ gcc -c foo2.c -o foo2.o
    $ gcc foo1.o foo2.o -o foo
    ```

### 💬 GCC 编译选项汇总

|选项|作用|
|:--|:---|
|-E|只进行编译，不做其他处理|
|-o|指定编译的输出文件|
|-S|只编译到汇编阶段，生成汇编代码|
|-c|只编译到链接阶段，生成目标文件“.o”|
|-g|在可执行程序中包含标准调试信息|
|-v|打印出编译器内部编译各过程的命令行信息和编译器的版本|
|-I dir|在头文件的搜索路径列表中添加 dir 目录|
|-L dir|在库文件的搜索路径列表中添加 dir 目录|
|-static|链接静态库|
|-l lib|链接名为 lib 的库文件|

+ **-l dir 实例**

    ```c
    /*
     * hello.c
     */
    #include "my.h"

    int main()
    {
        printf("hello world!\n");
        return 0;
    }
    ```

    > ./hello.c

    ```c
    /*
     * my.h
     */
    #include <stdio.h>
    ```

    > /root/work/gcc/my.h

    + 编译命令：

        ```bash
        $ gcc hello.c -l /root/work/gcc/ -o hello
        ```

+ **-L dir 实例**

    + ./hello.c

    + /root/work/gcc/lib/libxch.so

    + 编译命令：

        ```bash
        $ gcc hello.c -L /root/work/gcc/lib hello
        ```

### 💬 出错检查与警告提示选项

|选项|作用|
|:--|:---|
|-ansi|支持符合 ANSI 标准的 C 程序|
|-pedantic|允许发出 ANSI C 标准所列的全部警告信息|
|-pedantic-error|允许发出 ANSI C 标准所列的全部错误信息|
|-w|关闭所有告警|
|-Wall|允许发出 GCC 提供的所有有用的告警信息|
|-werror|把所有的告警信息转化为错误信息，并终止编译过程|

<div align="center">
    - End -
</div>