# 「 Linux 」

> **💡 Linux 操作系统指导手册**

+ ***[目录导航](#-目录导航)***

+ ***[Linux 说明](#-linux-说明)***

> 话说你们的虚拟机出毛病可以 win+R -> msconfig -> 服务 -> 隐藏所有 Microsoft 服务 -> 全部禁用 -> 确定 -> 重启 -> 管理员模式打开 cmd -> netsh winsock reset -> win+R -> msconfig -> 服务 -> 隐藏所有 Microsoft 服务 -> 全部启用 -> 确定 -> 重启

<div align="center">
    <img src="https://github.com/fmw666/my-image-file/blob/master/images/cute/small-cute-8.jpg" width=100>
</div>

## 📚 目录导航

1. **[Shell 基础](docs/Shell%20基础.md)**

1. **[Linux 命令及常用命令](docs/Linux%20命令及常用命令.md)**

1. **[Vim 的基本操作](docs/Vim%20的基本操作.md)**

1. **[Shell 编程](docs/Shell%20编程)**

    + [Shell 操作](docs/Shell%20编程/Shell%20操作.md)

    + [元字符](docs/Shell%20编程/元字符.md)

    + [Shell 输入输出](docs/Shell%20编程/Shell%20输入输出.md)

    + [Shell 脚本](docs/Shell%20编程/Shell%20脚本.md)

    + [Shell 变量](docs/Shell%20编程/Shell%20变量.md)

    + [Shell 表达式](docs/Shell%20编程/Shell%20表达式.md)

    + [Shell if 结构](docs/Shell%20编程/Shell%20if%20结构.md)

    + [Shell for 结构](docs/Shell%20编程/Shell%20for%20结构.md)

    + [Shell while 结构](docs/Shell%20编程/Shell%20while%20结构.md)

    + [Shell until 结构](docs/Shell%20编程/Shell%20until%20结构.md)

    + [Shell case 结构](docs/Shell%20编程/Shell%20case%20结构.md)

    + [Shell 函数](docs/Shell%20编程/Shell%20函数.md)

1. **[Linux C 程序设计]()**

1. **[文件处理](docs/文件处理)**

    + [虚拟文件系统](docs/文件处理/虚拟文件系统.md)

    + [文件的访问之 系统调用](docs/文件处理/文件的访问.md)

        + [open]()

        + [close]()

        + [write]()

        + [read]()

        + [fcntl]()

        + [lseek]()

        + [*stat]()

        + [mmap/munmap]()

    + [文件的访问之 ANSI C库函数](docs/)

        + [fopen/fclose/fflush]()

        + [fgetc/getc/getchar]()

        + [fputc/putc/putchar]()

        + [fgets/gets]()

        + [fputs/puts]()

        + [fread/fwrite]()

        + [feof/ferror]()

        + [fseek/ftell]()

        + [printf/fprintf/sprintf]()

        + [scanf/fscanf/sscanf]()

    + [C 语言编程实例之 ls 命令的实现](docs/文件处理/C%20语言编程实例之%20ls%20命令的实现.md)

<div align="right">
    <a href="#-linux-">back to top ⤴</a>
</div>

## ⭐ Linux 说明

<div align="center"><h3> 「 简介 」 </h3></div>

+ **起源：[Linus Torvalds](#welcome)，芬兰赫尔辛基大学学生**

    <div align="center">
        <img src="pics/linus.jpg" width=150>
    </div>

+ **可在 GNU 公共许可权限下免费获得。**

+ **符合 POSIX 标准的操作系统。**

<div align="center"><h3> 「 Linux 版本 」 </h3></div>

+ **核心版本：序号由三部分数字构成**

    + major.minor.patchlevel

    + 例如：2.2.11 表示对核心 2.2 版本的第 11 次修订。

    + 约定：次版本号为奇数时，为测试版；次版本号为偶数时，为稳定版。

+ **发行版本**

    + RedHat&emsp;&emsp;http://www.redhat.com

    + TurboLinux&emsp;&emsp;http://www.turbolinux.com.cn

    + Slackware&emsp;&emsp;http://www.cdrom.com

    + OpenLinux&emsp;&emsp;http://www.caldera.com

    + Debian&emsp;&emsp;http://www.debian.org

    + SuSELinux&emsp;&emsp;http://www.suse.com

<div align="center"><h3> 「 Linux 特点 」 </h3></div>

+ **自由软件**

    + Linux 作为开放源码的自由软件的代表。

+ **完全兼容 POSIX 1.0 标准**

    + POSIX 可移植操作系统接口。

    + 用户可以在 Linux 下通过相应的模拟器运行常见的 DOS、Windows 程序。

+ **多用户、多任务操作系统**

    + 系统资源可以被不同用户各自拥有，互不影响。

    + 计算机同时执行多个程序，且运行相互独立。

+ **良好的用户界面**

    + 用户界面：命令行界面（shell）、图形界面。

    + 系统调用。

+ **支持多种文件系统**

    + 例如：EXT2 EXT3 NFS NTFS VFAT

+ **丰富的网络功能**

    + 例如：TFTP、BOOTP 等网络服务。

+ **可靠的系统安全**

+ **设备独立性**

+ **良好的可移植性**

    + 支持多种体系结构：X86、ARM、MIPS 等。

<div align="right">
    <a href="#-linux-">back to top ⤴</a>
</div>

<div align="center">
    <br>
    - End -
</div>