## 「 Vim 的基本操作 」

<div align="right">
    <a href="https://github.com/fmw666/Linux#-目录导航">返回目录导航 ↩</a>
</div>

+ **[VI 简介](#-vi-简介)**

+ **[VI 的模式](#-vi-的模式)**

+ **[VI 的常用命令](#-vi-的常用命令)**

### 💬 VI 简介

1. VI 全称 [visual editor](#welcome) 的简称，最初为 BSD UNIX 编写

1. Vim vi [improvement](#welcome)，GNU 项目中开发的与 vi 兼容的全屏编辑器

1. Linux 中 shell 启动脚本一般都定义一个别名 vi 指向 vim

### 💬 VI 的模式

&emsp;&emsp;三种模式：命令模式、插入模式、未行模式。

+ 命令模式：直接与 Linux 内核相交互

+ 插入模式：在命令模式下按下 `i` 进入，按下 `ESC` 退出

+ 未行模式：在命令模式下按下 `:` 进入，按下 `Enter` 退出

### 💬 VI 的常用命令

|命令|描述|
|:--:|:-:|
|i|进入插入模式|
|v|选定范围|
|y|复制|
|d|删除|
|p|粘贴|
|w|保存当前文件|
|dd|删除光标所在行|
|:|进入未行模式|
|ESC|退出插入模式|
|q|退出 vi|
|wq|保存文件并退出|
|q!|强行退出|
|x|退出 vi|

<div align="center">
    - End -
</div>