## 「 Shell 基础 」

<div align="right">
    <a href="https://github.com/fmw666/Linux#-目录导航">返回目录导航 ↩</a>
</div>

<br>

&emsp;&emsp;大多数 Linux 发行版的默认 shell 都是 [GNU bash shell](#welcome)。本套文档也只基于 [GNU bash shell](#welcome) 的一些基本特性来作介绍。

### 💬 启动 shell

+ `/etc/passwd` 文件包含了所有系统用户账户列表以及每个用户的基本配置信息。

+ `fmw:x:1000:1000:fmw,,,,:/home/fmw:/bin/bash`

+ 这是从该文件中取出的一行内容，其中最后一个字段 `/bin/bash` 指定了用户使用的 shell 程序。

### 💬 shell 提示符

+ 对于普通用户，Base shell 默认的提示符是美元符号 [$](#welcome)

+ 对于超级用户（root 用户），Bash Shell 默认的提示符是井号 [#](#welcome)

+ 提示符表示 Shell 等待输入命令。

+ 按下回车键才能让 Shell 执行输入的命令

### 💬 bash 手册

+ [man](#welcome) 命令用来访问存储在 Linux 系统上的手册页面。

+ 如使用：`$ man xterm` 来查找 [xterm](#welcome) 命令的手册页面。

+ bash 手册甚至包含了一份有关其自身的参考信息，输入：`$ man man` 以查看。

+ 当使用 man 命令查看命令手册页的时候，这些手册页是由分页程序（pager）来显示的。

+ 分页程序能逐页显示文本，可以通过点击 [空格键](#welcome) 进行翻页，或是点击 [回车键](#welcome) 逐行查看。

+ （如果终端仿真软件包支持箭头键功能）还可以使用 [箭头键](#welcome) 向前向后滚动手册页的内容。

+ 要退出手册页，可以点击 [q键](#welcome) 退出。

<div align="center">
    - End -
</div>