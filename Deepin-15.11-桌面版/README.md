> <h3><a href="#welcome">《Deepin，优雅且危险》</a></h3>

.<br>.<br>

<div align="right">
	<img src="pics/deepin-logo.jpg">
</div>

.<br>.<br>.<br>

#### 目录

+ [Linux 装机必备](#)

+ [Deepin 爬坑](#)

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

    + 这儿出现一个问题，就是每次 push 都需要一次身份验证，那么如何一次性解决呢？

        + 需要添加本机密钥到 Github，下面是测试以及步骤

        + 运行 `ssh -T git@github.com` 指令会出现如下提示：

            ```bash
            $ ssh -T git@github.com
            The authenticity of host 'github.com (52.74.223.119)' can't be established.
            RSA key fingerprint is SHA256:nThbg6kXUpJWGl7E1IGOCspRomTxdCARLviKw6E5SY8.
            Are you sure you want to continue connecting (yes/no)? yes
            Warning: Permanently added 'github.com,52.74.223.119' (RSA) to the list of known hosts.
            Permission denied (publickey).
            ```
        
        + 没关系，我们使用 `ssh-keygen -t rsa -C "youremail@example.com"` 来生成我们的密钥，注意期间是四次回车

        + 我们可以看下 `.ssh/` 下目录文件：

            ```bash
            $ ls ~/.ssh/
            id_rsa  id_rsa.pub  know_hosts
            ```
        
        + 添加密钥 id_rsa：

            ```bash
            ssh-add id_rsa
            ```

        + 添加公钥 id_rsa.pub：我们只需复制里面的内容到 Github 中添加即可

            ```bash
            $ cat .ssh/id_rsa.pub
            ```

        + Github 添加密钥网址：[https://github.com/settings/ssh/new](https://github.com/settings/ssh/new)

        + 最后推荐使用 SSH 进行 clone，如果你当前 repo 已进行 HTTPS 的 clone 方式：

            ```bash
            git remote set-url origin git+ssh://git@github.com/fmw666/Linux.git
            ```
            
            > 其中 [fmw666](#welcome) 为笔者我的 github 用户名，[Linux](#welcome) 为笔者我的当前克隆仓库。


+ how to play with VS Code?

    + 下载我就不用说了吧，下载都下不好，就真太丢了

    + 在终端中使用 `$ code` 打开 VS code

    + 汉化步骤

        1. 选择左侧扩展（Extensions），快捷键 Ctrl+Shift+X

        1. 搜索 Chinese，并选择第一个进行下载，下载完成后软件右下角会提醒你重启此软件

        1. 重启回来后，好像就变成中文的了？好吧，就这样！

        1. 如果不放心，那就快捷键 Ctrl+Shift+P 打开并搜索 `Configure DIsplay Language`，选择我们的 `zh-cn` 就是我们的中文设置。

    + （如果系统自带Python）删除 Python 及其依赖

        1. `sudo apt-get remove --auto-remove python2.*`

        1. `sudo apt-get remove --auto-remove python3.*`

        1. `sudo apt-get purge python2.*`

        1. `sudo apt-get purge python3.*` 

    + 安装 Python3.7

        + 安装/更新依赖

            ```bash
            $ sudo apt update
            $ sudo apt install -y make build-essentiallibssl-dev zliblg-dev
            $ sudo apt install -y libbz2-dev libreadline-dev libsqlite3-dev wget curl llvm
            $ sudo apt install -y libncurses5-dev libncursesw5-dev xz-utils tk-dev
            ```

        + 安装 Python 包

            ```bash
            /Download$ wget https://www.python.org/ftp/python/3.7.4/Python-3.7.4.tgz
            ```

        + 解包

            ```bash
            $ tar xvf Python-3.7.4.tgz 
            ```
        
        + 执行安装

            ```bash
            $ cd Python-3.7.4/
            $ ./configure --enable-optimizations
            $ sudo make altinstall
            ```

        + 建立软连接

            ```bash
            $ sudo ln -s /usr/local/bin/python3 /usr/bin/python3
            $ sudo ln -s /usr/local/bin/python3 /usr/bin/python
            $ sudo ln -s /usr/local/bin/pip3 /usr/bin/pip3
            $ sudo ln -s /usr/local/bin/pip3 /usr/bin/pip
            ```

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

        > 新一点的电脑电脑可以把2009替换为2012或2015，分别代表Win8和Win10 
