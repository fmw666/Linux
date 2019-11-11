## 「 GNU CC 编程 」

<div align="right">
    <a href="https://github.com/fmw666/Linux#-目录导航">返回目录导航 ↩</a>
</div>

<br>

&emsp;&emsp;**GCC（GNU Compiler Collection，GNU 编译器套件）** 是由 GNU 开发的编程语言编译器。

+ **[简介](#-简介)**

+ **[GCC 所支持的扩展名表](#-gcc-所支持的扩展名表)**

+ **[GCC 编译过程](#-gcc-编译过程)**

+ **[函数库之 静态库](#-函数库之-静态库)**

+ **[函数库之 动态库](#-函数库之-动态库)**

+ **[GCC 编译选项汇总](#-gcc-编译选项汇总)**

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

基本语法格式：

    ```bash
    gcc [选项] 源文件 [选项] [目标文件]
    ```

***编译过程分为四个阶段***

+ 预处理（Pre-Processing）

    ```bash
    $ gcc -E hello.c -o hello.i
    ```

    + "[-E](#welcome)"：指定只进行预处理

    + "[hello.c](#welcome)"：源程序文件

    + "[-o](#welcome)"：指定生成目标文件

    + "[hello.i](#welcome)"：预处理过程生成的目标文件

+ 编译（Compiling）

    ```bash
    $ gcc -S hello.i -o hello.S
    ```

    + "[-S](#welcome)"：指定只进行到编译阶段

    + "[hello.i](#welcome)"：进行编译的源文件

    + "[-o](#welcome)"：指定生成目标文件

    + "[hello.S](#welcome)"：编译生成的目标文件名

+ 汇编（Assembling）

    ```bash
    $ gcc -c hello.S -o hello.o
    ```
    
    + "[-c](#welcome)"：指定只进行到汇编阶段结束为止

    + "[hello.S](#welcome)"：进行汇编的源文件

    + "[-o](#welcome)"：指定生成目标文件

    + "[hello.o](#welcome)"：二进制目标代码文件，编译生成的目标文件名

+ 链接（Linking）

    + "[hello.i](#welcome)"：预处理过程生成的目标文件

    + "[hello.i](#welcome)"：预处理过程生成的目标文件

<div align="center">
    - End -
</div>