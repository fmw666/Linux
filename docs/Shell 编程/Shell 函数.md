## 「 Shell 函数 」

<div align="right">
    <a href="https://github.com/fmw666/Linux#-目录导航">返回目录导航 ↩</a>
</div>

+ **[函数定义](#-函数定义)**

+ **[函数调用](#-函数调用)**

+ **[函数返回](#-函数返回)**

+ **[全局函数](#-全局函数)**

+ **[函数共享](#-函数共享)**

+ **[变量限制](#-变量限制)**

### 💬 函数定义

+ 格式：

    ```bash
    functionName()
    {
        命令序列;
    }
    ```

+ 举例：

    ```shell
    $ cat func
    ```

    ```bash
    #!/bin/bash
    f()
    {
        echo 'parameter $1='$1
        echo 'parameter list='$*
    }
    #main program.
    f 1
    f cat my file1 file2
    ```

### 💬 函数调用

+ 格式：

    ```shell
    $ functionName
    ```

    ```shell
    $ functionName 位置参数
    ```

+ 举例：

    ```shell
    $ ./func
    ```
    
    ```shell
    parameter $1=1
    parameter list=1
    parameter $1=cat
    parameter list=cat my file1 file2
    ```

### 💬 函数返回

+ [return](#welcome)：用函数中执行的上一个命令的返回值返回

+ [return [value]](#welcome)：用给定的 value 值（0-255之间的整数）返回

### 💬 全局函数

&emsp;&emsp;[export](#welcome) 命令可以将函数说明为全局函数，使其可以被子 Shell 继承。

### 💬 函数共享

&emsp;&emsp;把要共享的函数单独放在一个文件中，然后在要使用该函数的脚本中，在开始位置用以下格式的命令读取该文件。

> [. fileName](#welcome) 或 [source fileName](#welcome)

### 💬 变量限制

[local 变量名](#welcome)

> 限制变量只能限制本地 Shell 的当前函数。

<div align="center">
    - End -
</div>