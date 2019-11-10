## 「 基于 POSIX 的目录管理 」

<div align="right">
    <a href="https://github.com/fmw666/Linux#-目录导航">返回目录导航 ↩</a>
</div>

+ **[opendir](#-opendir-函数)** / **[closedir](#-closedir-函数)**

+ **[readdir](#-readdir-函数)** / **[telldir](#-telldir-函数)** / **[seekdir](#-seekdir-函数)**

+ **[mkdir](#-mkdir-函数)** / **[rmdir](#-rmdir-函数)**

+ **[chdir 函数](#-chdir-函数)**

+ **[getcwd 函数](#-getcwd-函数)**

### 💬 opendir 函数

+ 函数名：**[opendir](#welcome)**

+ 头文件：
    
    + **[sys/types.h](#welcome)**

    + **[dirent.h](#welcome)**

+ 功能：*打开一个子目录并建立一个子目录流。如果成功，它将返回一个指向 DIR 结构体的指针，以后对目录数据项的读操作将通过这个指针来完成*

+ 函数定义：

    + **DIR\* opendir(const char \*name)**

+ 其中：

    + **name：** 子目录名

    + **返回值：** 调用成功返回打开的子目录流指针；不成功返回 NULL

### 💬 closedir 函数

+ 函数名：**[closedir](#welcome)**

+ 头文件：
    
    + **[sys/types.h](#welcome)**

    + **[dirent.h](#welcome)**

+ 功能：*关闭一个子目录流，并释放与之关联的资源*

+ 函数定义：

    + **int closedir(DIR \*dirp)**

+ 其中：

    + **dirp：** 子目录流指针

    + **返回值：** 调用成功返回 0；不成功返回 -1

<div align="right">
    <a href="#-基于-posix-的目录管理-">返回目录 ⬆</a>
</div>

### 💬 readdir 函数

+ 函数名：**[readdir](#welcome)**

+ 头文件：
    
    + **[sys/types.h](#welcome)**

    + **[dirent.h](#welcome)**

+ 功能：*返回一个指针，该指针指向的结构保存着子目录流 dirp 中下一个目录数据项的有关资料。后续的 readdir 返回的是后续的目录数据项。如果发生错误或达到子目录尾，readdir 将返回 NULL。POSIX 兼容的系统在到达子目录尾时，只返回 NULL，但不改变 errno 的值；当发生错误的时候才修改 errno 的值*

+ 函数定义：

    + **struct dirent\* readdir(DIR \*dirp)**

+ 其中：

    + **dirp：** 子目录流指针

    + **返回值：** 成功则返回下个目录进入点. 有错误发生或读取到目录文件尾则返回NULL。其中 dirent 的结构指针定义如下

        ```c
        struct dirent
        {
            ino_t d_ino;                /* d_ino 此目录进入点的 inode 值 */
            off_t d_off;                /* d_off 目录文件开头至此目录进入点的位移 */
            unsigned short d_reclen;    /* 用以存储文件名的空间大小，根据文件名长度有差异 */
            unsigned char d_type;       /* 文件类型 */
            char d_name[256];           /* 文件名，以 `\0` 结束，最长 255 个字符 */
        }
        ```

### 💬 telldir 函数

+ 函数名：**[telldir](#welcome)**

+ 头文件：
    
    + **[sys/types.h](#welcome)**

    + **[dirent.h](#welcome)**

+ 功能：*获取当前子目录流中的当前位置*

+ 函数定义：

    + **long int telldir(DIR \*dirp)**

+ 其中：

    + **dirp：** 子目录流指针

    + **返回值：** 返回当前子目录流中的当前位置

### 💬 seekdir 函数

+ 函数名：**[seekdir](#welcome)**

+ 头文件：
    
    + **[sys/types.h](#welcome)**

    + **[dirent.h](#welcome)**

+ 功能：*改变子目录流中的目录数据项指针的指向，通过 loc 来指定目录数据项指针所指向的位置。这个位置可通过 telldir 函数来获取*

+ 函数定义：

    + **void seekdir(DIR \*dirp, long int loc)**

+ 其中：

    + **dirp：** 子目录流指针

    + **loc：** 设置目录数据项指针的位置

    + **返回值：** 无

<div align="right">
    <a href="#-基于-posix-的目录管理-">返回目录 ⬆</a>
</div>

### 💬 mkdir 函数

+ 函数名：**[mkdir](#welcome)**

+ 头文件：**[sys/stat.h](#welcome)**

+ 功能：*创建一个子目录，子目录名字将由 path 指出*

+ 函数定义：

    + **int mkdir(const char \*path, mode_t mode)**

+ 其中：

    + **path：** 需要创建的子目录名

    + **mode：** 与 open 系统调用中使用 O_CREAT 时的设置一样

    + **返回值：** 创建成功返回 0；不成功则返回 -1

### 💬 rmdir 函数

+ 函数名：**[rmdir](#welcome)**

+ 头文件：**[sys/stat.h](#welcome)**

+ 功能：*删除子目录，但要求子目录为空*

+ 函数定义：

    + **int rmdir(const char \*path)**

+ 其中：

    + **path：** 需要删除的子目录名

    + **返回值：** 删除成功返回 0；不成功则返回 -1

<div align="right">
    <a href="#-基于-posix-的目录管理-">返回目录 ⬆</a>
</div>

### 💬 chdir 函数

+ 函数名：**[chdir](#welcome)**

+ 头文件：**[unistd.h](#welcome)**

+ 功能：*改变当前工作目录*

+ 函数定义：

    + **int chdir(const char \*path)**

+ 其中：

    + **path：** 需要切换的工作目录

    + **返回值：** 切换成功返回 0；不成功则返回 -1

<div align="right">
    <a href="#-基于-posix-的目录管理-">返回目录 ⬆</a>
</div>

### 💬 getcwd 函数

+ 函数名：**[getcwd](#welcome)**

+ 头文件：**[unistd.h](#welcome)**

+ 功能：*把当前子目录名写入到指定的缓冲区 buff 中*

+ 函数定义：

    + **char* getcwd(char \*buff, size_t size)**

+ 其中：

    + **buff：** 保存绝对路径的缓冲区

    + **size：** buff 的大小。至少要保证比返回值大 1

    + **返回值：** 成功返回指针 buff；不成功则返回 NULL

<div align="right">
    <a href="#-基于-posix-的目录管理-">返回目录 ⬆</a>
</div>

<div align="center">
    - End -
</div>