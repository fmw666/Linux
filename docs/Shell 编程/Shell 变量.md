## 「 Shell 变量 」

<div align="right">
    <a href="https://github.com/fmw666/Linux#-目录导航">返回目录导航 ↩</a>
</div>

### 💬 Shell 变量的特点

1. Shell 变量使用之前不需要事先对它进行声明，在第一次使用它的时候创建它

1. Shell 变量默认情况下，是字符串类型

1. Shell 变量名区分大小写

1. 弱类型

### 💬 Shell 环境变量

+ 每个 Shell 都有一组预定义的环境变量，用户也可以自己指定环境变量

    |环境变量|说明|
    |:------|:---|
    |HOME|主目录的完整路径|
    |PATH|Shell 搜索命令的路径|
    |MAIL|邮箱的完整路径|
    |USER|用户名|
    |SHELL|登陆 Shell 的完整路径名|

+ 引用环境变量：`$变量名`

+ 查看环境变量：`env;set`

+ 指定局部变量为环境变量：`export`
    + 例：export name

### 💬 系统预定于变量

&emsp;&emsp;预定义变量和环境变量相类似，所不同的是，用户只能根据Shell的定义来使用这些变量，而不能重定义它。 

|符号|说明|
|:--|:---|
|$$|当前 Shell 的进程号|
|$#|位置参数的数量|
|$@, $*|所有位置参数的列表|
|$?|命令执行后返回的状态|
|$!|后台运行的最后一个进程号|
|$0|当前的 Shell 脚本文件名|
|$RANDOM|一个随机整数|
|$PPID|父 Shell 的进程 ID|
|$1...$9|$n 指向第 n 个命令行参数|

### 💬 位置参数

1. 由 Shell 在程序运行时设置

1. 共 10 个位置参数变量，从程序名开始依次为第 0~9 个

1. [$@](#welcome) 或 [$*](#welcome) 代表所有位置参数

1. [Shift](#welcome) 命令递归访问参数

+ 例：

    ```bash
    $ cat myscript
    ```
    ```bash
    #!/bin/bash
    echo $0
    echo $@
    shift
    echo $*
    echo $1
    ```

    ```bash
    $ ./myscript a b c d e
    ```
    ```bash
    ./myscript
    a b c d e
    b c d e
    b
    ```

### 💬 局部变量

&emsp;&emsp;局部变量（简单变量）——用户自定义变量

1. 局部变量的创建/赋值：[变量名=变量值;](#welcome)

1. 引用局部变量的值：[$变量名;](#welcome)

1. 清除局部变量：[unset 变量名;](#welcome)

1. 查看局部变量：[set;](#welcome)

+ 举例：

    ```shell
    $ a=5
    $ gamelist=12
    $ name="Mr Fan"
    ```

+ 局部变量的引用：

    |格式|说明|
    |:--|:---|
    |${变量}|变量值|
    |${#变量}|变量值的长度|
    |${#变量}|数组第 1 个元素的长度|
    |${#变量[*]}|数组元素的总个数|
    |${变量:-word}|如果变量存在且非 null，返回它的值；否则返回 word|
    |${变量:=word}|如果变量存在且非 null，返回它的值；否则将 word 赋值给变量，并返回变量的值|
    |${变量:+word}|如果变量存在且非 null，返回 word；否则返回 null|
    |${变量:?word}|如果变量存在且非 null，返回它的值；否则显示：“变量:word”|
    |${变量#pattern}|匹配前缀（最小匹配），并返回余下内容|
    |${变量##pattern}|匹配前缀（最大匹配），并返回余下内容|
    |${变量%pattern}|匹配结尾（最小匹配），并返回余下内容|
    |${变量%%pattern}|匹配结尾（最大匹配），并返回余下内容|

### 💬 从标准输入读取变量值

+ 格式：[read 变量表](#welcome)

+ 例：

    ```bash
    #script.sh
    echo "enter your name:\c"
    read name
    echo "your name is $name"
    ```

### 💬 只读变量

&emsp;&emsp;[readonly](#welcome) 命令能保护变量，使其不被修改。

+ 例：

    ```shell
    $ password=123456
    ```
    ```shell
    $ readonly password
    ```
    ```shell
    $ password=991228
    ```
    ```bash
    bash: password: readonly variable
    ```
    ```bash
    $ readonly  #列出所有只读变量
    ```

<div align="center">
    - End -
</div>