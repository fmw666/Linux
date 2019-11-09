## 「 文件的访问之 ANSI C库函数 」

<div align="right">
    <a href="https://github.com/fmw666/Linux#-目录导航">返回目录导航 ↩</a>
</div>

+ **[fopen](#-fopen-函数)** / **[fclose](#-fclose-函数)** / **[fflush](#-fflush-函数)**

+ **[fgetc](#-fgetc-函数)** / **[getc](#-getc-函数)** / **[getchar](#-getchar-函数)**

+ **[fputc](#-fputc-函数)** / **[putc](#-putc-函数)** / **[putchar](#-putchar-函数)**

+ **[fgets](#-fgets-函数)** / **[gets](#-gets-函数)**

+ **[fputs](#-fputs-函数)** / **[puts](#-puts-函数)**

+ **[fread](#-fread-函数)** / **[fwrite](#-fwrite-函数)**

+ **[feof](#-feof-函数)** / **[ferror](#-ferror-函数)**

+ **[fseek](#-fseek-函数)** / **[ftell](#-ftell-函数)**

+ **[printf](#-printf-函数)** / **[fprintf](#-fprintf-函数)** / **[sprintf](#-sprintf-函数)**

+ **[scanf](#-scanf-函数)** / **[fscanf](#-fscanf-函数)** / **[sscanf](#-sscanf-函数)**

### 💬 fopen 函数

+ 函数名：**[fopen](#welcome)**

+ 头文件：**[stdio.h](#welcome)**

+ 功能：*使用给定的模式 mode 打开 filename 所指向的文件*

+ 函数定义：

    + **FILE\* fopen(const char \*filename, const char \*mode)**

+ 其中：

    + **filename：** 要打开的文件名称

    + **mode：** 文件访问模式

        |mode|说明|
        |:-------|:---|
        |r|以只读方式打开文件，该文件必须存在|
        |r+|以读/写方式打开文件，该文件必须存在|
        |rb+|以读/写方式打开一个二进制文件，只允许读/写数据|
        |rt+|以读/写方式打开一个文本文件，允许读和写|
        |w|打开只写文件，若文件存在则文件长度清为零，即该文件内容会消失；若文件不存在则创建该文件|
        |w+|打开可读/写文件，若文件存在则文件长度清为零，即该文件内容会消失；若文件不存在则创建该文件|
        |a|以附加的方式打开只写文件。若文件不存在，则会创建该文件；如果文件存在，则写入的数据会被加到文件尾后，即文件原先的内容会被保留（EOF 符保留）|
        |a+|以附加方式打开可读/写的文件。若文件不存在，则会创建该文件，如果文件存在，则写入的数据会被加到文件尾后，即文件原先的内容会被保留（EOF 符不保留）|
        |wb|以只写方式打开或新建一个二进制文件，只允许写数据|
        |wb+|以读/写方式打开或新建一个二进制文件，允许读和写|
        |wt+|以读/写方式打开或新建一个文本文件，允许读和写|
        |at+|以读/写方式打开一个文本文件，允许读或在文本末追加数据|
        |ab+|以读/写方式打开一个二进制文件，允许读或在文件末追加数据|

    + **返回值：** 打开成功，返回该文件流指针；不成功，返回 NULL，并设置相应的 error　变量以指明出错的原因

### 💬 fclose 函数

+ 函数名：**[fclose](#welcome)**

+ 头文件：**[stdio.h](#welcome)**

+ 功能：*把缓冲区内最后剩余的数据输出到内核缓冲区，并释放文件指针和有关的缓冲区*

+ 函数定义：

    + **int fclose(FILE \*fp)**

+ 其中：

    + **fp：** 指向 FILE 对象的指针

    + **返回值：** 如果文件流成功关闭，返回 0；否则返回 EOF(-1)

### 💬 fflush 函数

+ 函数名：**[fflush](#welcome)**

+ 头文件：**[stdio.h](#welcome)**

+ 功能：*清除读写缓冲区，在需要立即把输出缓冲区的数据进行物理写入时*

+ 函数定义：

    + **int fflush(FILE \*fp)**

+ 其中：

    + **fp：** 指向 FILE 对象的指针，将要清洗的文件流

    + **返回值：** 如果成功刷新，返回 0；否则返回 EOF(-1)

<div align="right">
    <a href="#-文件的访问之-ansi-c库函数-">返回目录 ⬆</a>
</div>

### 💬 fgetc 函数

+ 函数名：**[fgetc]](#welcome)**

+ 头文件：**[stdio.h](#welcome)**

+ 功能：*从流中返回一个字符值*

+ 函数定义：

    + **int fgetc(FILE \*fp)**

+ 其中：

    + **fp：** 指向 FILE 对象的指针，将要读取的文件流

    + **返回值：** 得到的字符值

### 💬 getc 函数

+ 函数名：**[getc]](#welcome)**

+ 头文件：**[stdio.h](#welcome)**

+ 功能：*从流中返回一个字符值*

+ 函数定义：

    + **int getc(FILE \*fp)**

+ 其中：

    + **fp：** 指向 FILE 对象的指针，将要读取的文件流

    + **返回值：** 成功返回从文件流中得到的字符值；否则返回 EOF(-1)

### 💬 getchar 函数

+ 函数名：**[fgetc]](#welcome)**

+ 头文件：**[stdio.h](#welcome)**

+ 功能：*从流中返回一个字符值*

+ 函数定义：

    + **int getchar(void)**

+ 其中：

    + **返回值：** 以无符号 char 强制转换为 int 的形式返回读取的字符，如果到达文件末尾或发生读错误，则返回 EOF

<div align="right">
    <a href="#-文件的访问之-ansi-c库函数-">返回目录 ⬆</a>
</div>

### 💬 fputc 函数

+ 函数名：**[fputc]](#welcome)**

+ 头文件：**[stdio.h](#welcome)**

+ 功能：*向文件流 fp 中写入字符 c*

+ 函数定义：

    + **int fputc(int c, FILE \*fp)**

+ 其中：

    + **c：** 将要写入的字符量

    + **fp：**　指向 FILE 对象的指针，将要写入的文件流

    + **返回值：** 在正常调用情况下，函数返回写入文件的字符的 ASCII 码值，出错时，返回EOF(-1)

### 💬 putc 函数

+ 函数名：**[putc]](#welcome)**

+ 头文件：**[stdio.h](#welcome)**

+ 功能：*向文件流 fp 中写入字符 c，与 fputc 等价*

+ 函数定义：

    + **int putc(int c, FILE \*fp)**

+ 其中：

    + **c：** 将要写入的字符量

    + **fp：**　指向 FILE 对象的指针，将要写入的文件流

    + **返回值：** 在正常调用情况下，函数返回写入文件的字符的 ASCII 码值，出错时，返回EOF(-1)

### 💬 putchar 函数

+ 函数名：**[putchar]](#welcome)**

+ 头文件：**[stdio.h](#welcome)**

+ 功能：*把 参数 char 指定的（一个无字符）字符写入到标准输出 stdout 中*

+ 函数定义：

    + **int putchar(int char)**

+ 其中：

    + **char：** 将要被写入的字符，该字符以其对应的 int 值进行传递

    + **返回值：** 输出成功，则以无符号 char 强制转换为 int 的形式返回写入的字符；否则返回 EOF(End of file) 文件结束符

<div align="right">
    <a href="#-文件的访问之-ansi-c库函数-">返回目录 ⬆</a>
</div>

### 💬 fgets 函数

+ 函数名：**[fgets]](#welcome)**

+ 头文件：**[stdio.h](#welcome)**

+ 功能：*从指定的流 fp 读取一行，并把它存储在 str 所指向的字符串内。当读取(n-1)个字符时，或者读取到换行符时，或者到达文件末尾时，它会停止，具体视情况而定*

+ 函数定义：

    + **char\* fgets(char \*str, int n, FILE \*fp)**

+ 其中：

    + **str：** 指向一个字符数组的指针，该数组存储了要读取的字符串

    + **n：** 要读取的最大字符数（包括最后的空字符），通常是使用以 str 传递的数组长度

    + **fp：**　指向 FILE 对象的指针，该 FILE 对象标识了要从中读取字符的流

    + **返回值：** 在正常调用情况下，函数返回写入文件的字符的 ASCII 码值，出错时，返回EOF(-1)

### 💬 gets 函数

+ 函数名：**[gets]](#welcome)**

+ 头文件：**[stdio.h](#welcome)**

+ 功能：*从标准输入设备读字符串*

+ 函数定义：

    + **int xxx(int char)**

+ 其中：

    + **char：** 将

    + **返回值：** 读入成功，返回与参数 buffer 相同的指针；读入过程中遇到 EOF(End-of-File) 或发生错误，返回 NULL 指针

<div align="right">
    <a href="#-文件的访问之-ansi-c库函数-">返回目录 ⬆</a>
</div>

### 💬 fputs 函数

+ 函数名：**[fputs]](#welcome)**

+ 头文件：**[stdio.h](#welcome)**

+ 功能：*向文件流 fp 中写入字符 c，与 fputc 等价*

+ 函数定义：

    + **int putc(int c, FILE \*fp)**

+ 其中：

    + **c：** 将要写入的字符量

    + **fp：**　指向 FILE 对象的指针，将要写入的文件流

    + **返回值：** 在正常调用情况下，函数返回写入文件的字符的 ASCII 码值，出错时，返回EOF(-1)

### 💬 puts 函数

+ 函数名：**[puts]](#welcome)**

+ 头文件：**[stdio.h](#welcome)**

+ 功能：*把 参数 char 指定的（一个无字符）字符写入到标准输出 stdout 中*

+ 函数定义：

    + **int putchar(int char)**

+ 其中：

    + **char：** 将要被写入的字符，该字符以其对应的 int 值进行传递

    + **返回值：** 输出成功，则以无符号 char 强制转换为 int 的形式返回写入的字符；否则返回 EOF(End of file) 文件结束符

<div align="right">
    <a href="#-文件的访问之-ansi-c库函数-">返回目录 ⬆</a>
</div>

### 💬 fread 函数

+ 函数名：**[fread]](#welcome)**

+ 头文件：**[stdio.h](#welcome)**

+ 功能：*向文件流 fp 中写入字符 c，与 fputc 等价*

+ 函数定义：

    + **int putc(int c, FILE \*fp)**

+ 其中：

    + **c：** 将要写入的字符量

    + **fp：**　指向 FILE 对象的指针，将要写入的文件流

    + **返回值：** 在正常调用情况下，函数返回写入文件的字符的 ASCII 码值，出错时，返回EOF(-1)

### 💬 fwrite 函数

+ 函数名：**[fwrite]](#welcome)**

+ 头文件：**[stdio.h](#welcome)**

+ 功能：*把 参数 char 指定的（一个无字符）字符写入到标准输出 stdout 中*

+ 函数定义：

    + **int putchar(int char)**

+ 其中：

    + **char：** 将要被写入的字符，该字符以其对应的 int 值进行传递

    + **返回值：** 输出成功，则以无符号 char 强制转换为 int 的形式返回写入的字符；否则返回 EOF(End of file) 文件结束符

<div align="right">
    <a href="#-文件的访问之-ansi-c库函数-">返回目录 ⬆</a>
</div>

### 💬 feof 函数

+ 函数名：**[fputs]](#welcome)**

+ 头文件：**[stdio.h](#welcome)**

+ 功能：*向文件流 fp 中写入字符 c，与 fputc 等价*

+ 函数定义：

    + **int putc(int c, FILE \*fp)**

+ 其中：

    + **c：** 将要写入的字符量

    + **fp：**　指向 FILE 对象的指针，将要写入的文件流

    + **返回值：** 在正常调用情况下，函数返回写入文件的字符的 ASCII 码值，出错时，返回EOF(-1)

### 💬 ferror 函数

+ 函数名：**[puts]](#welcome)**

+ 头文件：**[stdio.h](#welcome)**

+ 功能：*把 参数 char 指定的（一个无字符）字符写入到标准输出 stdout 中*

+ 函数定义：

    + **int putchar(int char)**

+ 其中：

    + **char：** 将要被写入的字符，该字符以其对应的 int 值进行传递

    + **返回值：** 输出成功，则以无符号 char 强制转换为 int 的形式返回写入的字符；否则返回 EOF(End of file) 文件结束符

<div align="right">
    <a href="#-文件的访问之-ansi-c库函数-">返回目录 ⬆</a>
</div>

### 💬 fseek 函数

+ 函数名：**[fputs]](#welcome)**

+ 头文件：**[stdio.h](#welcome)**

+ 功能：*向文件流 fp 中写入字符 c，与 fputc 等价*

+ 函数定义：

    + **int putc(int c, FILE \*fp)**

+ 其中：

    + **c：** 将要写入的字符量

    + **fp：**　指向 FILE 对象的指针，将要写入的文件流

    + **返回值：** 在正常调用情况下，函数返回写入文件的字符的 ASCII 码值，出错时，返回EOF(-1)

### 💬 ftell 函数

+ 函数名：**[puts]](#welcome)**

+ 头文件：**[stdio.h](#welcome)**

+ 功能：*把 参数 char 指定的（一个无字符）字符写入到标准输出 stdout 中*

+ 函数定义：

    + **int putchar(int char)**

+ 其中：

    + **char：** 将要被写入的字符，该字符以其对应的 int 值进行传递

    + **返回值：** 输出成功，则以无符号 char 强制转换为 int 的形式返回写入的字符；否则返回 EOF(End of file) 文件结束符

<div align="right">
    <a href="#-文件的访问之-ansi-c库函数-">返回目录 ⬆</a>
</div>

### 💬 printf 函数

+ 函数名：**[fputs]](#welcome)**

+ 头文件：**[stdio.h](#welcome)**

+ 功能：*向文件流 fp 中写入字符 c，与 fputc 等价*

+ 函数定义：

    + **int putc(int c, FILE \*fp)**

+ 其中：

    + **c：** 将要写入的字符量

    + **fp：**　指向 FILE 对象的指针，将要写入的文件流

    + **返回值：** 在正常调用情况下，函数返回写入文件的字符的 ASCII 码值，出错时，返回EOF(-1)

### 💬 fprintf 函数

+ 函数名：**[puts]](#welcome)**

+ 头文件：**[stdio.h](#welcome)**

+ 功能：*把 参数 char 指定的（一个无字符）字符写入到标准输出 stdout 中*

+ 函数定义：

    + **int putchar(int char)**

+ 其中：

    + **char：** 将要被写入的字符，该字符以其对应的 int 值进行传递

    + **返回值：** 输出成功，则以无符号 char 强制转换为 int 的形式返回写入的字符；否则返回 EOF(End of file) 文件结束符

### 💬 sprintf 函数

+ 函数名：**[fputs]](#welcome)**

+ 头文件：**[stdio.h](#welcome)**

+ 功能：*向文件流 fp 中写入字符 c，与 fputc 等价*

+ 函数定义：

    + **int putc(int c, FILE \*fp)**

+ 其中：

    + **c：** 将要写入的字符量

    + **fp：**　指向 FILE 对象的指针，将要写入的文件流

    + **返回值：** 在正常调用情况下，函数返回写入文件的字符的 ASCII 码值，出错时，返回EOF(-1)

<div align="right">
    <a href="#-文件的访问之-ansi-c库函数-">返回目录 ⬆</a>
</div>

### 💬 scanf 函数

+ 函数名：**[fputs]](#welcome)**

+ 头文件：**[stdio.h](#welcome)**

+ 功能：*向文件流 fp 中写入字符 c，与 fputc 等价*

+ 函数定义：

    + **int putc(int c, FILE \*fp)**

+ 其中：

    + **c：** 将要写入的字符量

    + **fp：**　指向 FILE 对象的指针，将要写入的文件流

    + **返回值：** 在正常调用情况下，函数返回写入文件的字符的 ASCII 码值，出错时，返回EOF(-1)

### 💬 fscanf 函数

+ 函数名：**[fputs]](#welcome)**

+ 头文件：**[stdio.h](#welcome)**

+ 功能：*向文件流 fp 中写入字符 c，与 fputc 等价*

+ 函数定义：

    + **int putc(int c, FILE \*fp)**

+ 其中：

    + **c：** 将要写入的字符量

    + **fp：**　指向 FILE 对象的指针，将要写入的文件流

    + **返回值：** 在正常调用情况下，函数返回写入文件的字符的 ASCII 码值，出错时，返回EOF(-1)

### 💬 sscanf 函数

+ 函数名：**[puts]](#welcome)**

+ 头文件：**[stdio.h](#welcome)**

+ 功能：*把 参数 char 指定的（一个无字符）字符写入到标准输出 stdout 中*

+ 函数定义：

    + **int putchar(int char)**

+ 其中：

    + **char：** 将要被写入的字符，该字符以其对应的 int 值进行传递

    + **返回值：** 输出成功，则以无符号 char 强制转换为 int 的形式返回写入的字符；否则返回 EOF(End of file) 文件结束符

<div align="right">
    <a href="#-文件的访问之-ansi-c库函数-">返回目录 ⬆</a>
</div>

<div align="center">
    - End -
</div>