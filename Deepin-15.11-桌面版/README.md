> <h3><a href="#welcome">《Deepin，优雅且喜欢》</a></h3>

.<br>.<br>.<br>.<br>.<br>

#### 目录

+ [Linux 装机必备]()

+ [Deepin 爬坑]()

### Linux 装机必备

+ how to show dir tree structure?

    ```bash
    $ tree
    bash: tree: 未找到命令
    $ sudo apt-get install tree
    ...
    $ tree
    .
    ├── imgs
    │   ├── README.md
    │   ├── ubuntu经典桌面.jpg
    │   ├── ubuntu主题桌面.png
    ├── order_list.md
    └── README.md

    1 directory, 5 files
    ```

+ how to push files to Github?

    ```bash
    $ git clone https://github.com/username/repo.git
    bash: git: 未找到命令
    $ apt-get install git
    E: 无法打开锁文件 /var/lib/dpkg/lock - open (13: 权限不够)
    E: 无法对状态列表目录加锁(/var/lib/dpkg/)，请查看您是否正以 root 用户运行？
    $ sudo apt-get install git
    ```

    ```bash
    $ git add .
    $ git commit -m "commit info"

    *** 请告诉我你是谁。

    运行

    git config --global user.email "you@example.com"
    git config --global user.name "Your Name"

    来设置您账号的缺省身份标识。
    如果仅在本仓库设置身份标识，则省略 --global 参数。
    fatal: empty ident name (for <(null)>) not allowed
    $ git config --global user.email "fmw19990718@qq.com"
    $ git config --global user.name "fmw666"
    $ git commit -m "commit info"
    [master e7b2c36] commit info
     1 file changed, 12 insertions(+)
    create mode 100644 "xxx"
    $ git push origin master
    Username for 'https://github.com': fmw666
    Password for 'https://fmw666@github.com': 
    ```

+ how to play with VS Code?

### Deepin 爬坑

+ 首先列一个官方社区（深度科技论坛）地址：[https://bbs.deepin.org/](https://bbs.deepin.org/)

    + [深度操作系统新手引导（FAQ）-深度科技论坛](https://bbs.deepin.org/forum.php?mod=viewthread&tid=146921&extra=page%3D1)

    + [Deepin使用心得和一些引用推荐-深度科技论坛](https://bbs.deepin.org/forum.php?mod=viewthread&tid=142227&extra=page%3D1)

    + [15.8问题集中反馈贴-深度科技论坛](https://bbs.deepin.org/forum.php?mod=viewthread&tid=170998)

+ 开机遇见：[[Firmware Bug]： TSC_DEADLINE disabled due to Errata; please update microcode to version: 0x25 (or later)](#welcome) 解决方法

    + 首先输入 `exit`，然后再输入 `fsck -y /dev/sd*`(如：`fsck -y /dev/sda`)

    + 再输入 `exit` 进入系统，执行更新命令：`sudo apt-get install intel-microcode` 或者：`sudo apt-get install amd64-ucode`

+ 关机时屏幕卡住无法顺利完成关机

    + 修改 [grub](#welcome) 文件

        ```bash
        $ sudo vi /etc//default/grub
        ```

    + 添加一行内容：`GRUB_CMDLINE_LINUX="acpi_osi=! acpi_osi='Windows 2009'"`