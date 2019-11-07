## 「 Linux 命令及常用命令 」

<div align="right">
    <a href="https://github.com/fmw666/Linux#-目录导航">返回目录导航 ↩</a>
</div>

+ **[切换目录命令——cd](#-切换目录命令cd)**

+ **[列表命令——ls](#-列表命令ls)**

+ **[文件处理命令](#-文件处理命令)**

+ **[查看文件内容](#-查看文件内容)**


### 💬 切换目录命令——cd

+ **格式：**

    ```bash
    $ cd dir_path
    ```

+ **切换到上个目录下：**

    *不加参数：*

    ```bash
    $ cd
    ```

    *或者加上参数 `..`：*

    ```bash
    $ cd ..
    ```

    > 其中一个 `.` 表示当前路径

+ **绝对文件路径：**

    ```bash
    $ cd /usr/bin/
    $ pwd
    /usr/bin
    ```

    > 其中 pwd 命令用于查看终端下当前路径

    ```bash
    /usr/lib$ cd ../bin/
    /usr/bin$ pwd
    /usr/bin
    ```

+ **相对文件路径：**

    ```bash
    /usr$ cd bin/
    /usr/bin$ pwd
    /usr/bin
    ```

### 💬 列表命令——ls

+ **格式：**

    ```bash
    $ ls [选项]... [文件]...
    ```

+ **运行：**

    ```bash
    $ ls .
    css  index.html
    ```

    ```bash
    $ ls ..
    bootstrap-4.3.1-dist  bootstrap4-demo-web
    ```

+ **选项 -l——显示长列表**

    ```bash
    $ ls -l /home/ .
    .:
    总用量 8
    drwxr-xr-x 2 fmw fmw 4096 10月 25 17:05 css
    -rw-r--r-- 1 fmw fmw  790 10月 25 17:29 index.html

    /home/:
    总用量 24
    drwxr-xr-x 32 fmw  fmw   4096 11月  7 15:38 fmw
    drwx------  2 root root 16384 10月 23 08:34 lost+found
    drwxr-xr-x 21 tyj  tyj   4096 11月  4 15:28 tyj
    ```

### 💬 文件处理命令

+ **创建文件命令——touch**

    ```bash
    $ touch file
    $ ls file -l    
    -rw-r--r-- 1 fmw fmw 0 11月  7 21:04 file
    ```

    + touch 命令对于同一文件使用不会修改文件内容，但会更新

        ```bash
        $ touch file
        $ ls -l file
        -rw-r--r-- 1 fmw fmw 0 11月  7 21:04 file
        $ touch file
        $ ls -l file
        -rw-r--r-- 1 fmw fmw 0 11月  7 21:06 file
        ```

    + 如果只想改变访问时间，可用参数 a

        ``` bash
        $ ls -l file
        -rw-r--r-- 1 fmw fmw 0 11月  7 21:06 file
        $ touch -a file
        $ ls -l file
        -rw-r--r-- 1 fmw fmw 0 11月  7 21:06 file
        ```

    + 查看文件访问时间，添加参数 --time=atime

        ```bash
        $ ls -l --time=atime file
        -rw-r--r-- 1 fmw fmw 0 11月  7 21:40 file
        ```

+ **复制文件命令——cp**

    ```bash
    # 基本语法
    $ cp source destination
    ```

    + 如果 source 和 destination 都是文件的话就是文件的重命名

        ```bash
        $ ls
        old.file
        $ cp old.file new.file
        $ ls
        new.file  old.file
        ```

    + 添加 -i 来询问是否覆盖已有文件（如果有）

        ```bash
        $ ls
        new.file  old.file
        $ cp -i old.file new.file
        cp：是否覆盖'new.file'？ n
        $ ls
        new.file  old.file
        ```
    
+ **重命名文件命令——mv**

    ```bash
    $ mv old_name new_name
    ```

    ***mv 也可以用于移动文件***

    ```bash
    $ mv old_name test/
    ```

+ **删除文件命令——rm**

    ```bash
    $ ls
    new.file  old.file
    $ rm old.file
    $ ls
    new.file
    ```

    > 其中常用参数 `-i` 表示删除时提醒，`-f` 表示强制删除，`-r` 表示递归删除（用于删除目录）

+ **创建目录命令——mkdir**

    ```bash
    $ mkdir test
    $ ls
    new.file test
    ```

+ **删除目录命令——rmdir**

    ```bash
    $ rmdir test
    ```

    > 要值得注意，`rmdir` 只能删除空目录。所以对于非空目录更多使用：`rm -r test`

### 💬 查看文件内容

<div align="center">
    - End -
</div>