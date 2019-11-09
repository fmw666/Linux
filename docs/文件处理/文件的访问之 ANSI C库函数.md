## 「 文件的访问之 ANSI C库函数 」

<div align="right">
    <a href="https://github.com/fmw666/Linux#-目录导航">返回目录导航 ↩</a>
</div>

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

### 💬 fopen 函数

+ 函数名：**[fopen](#welcome)**

+ 头文件：**[stdio.h](#welcome)**

+ 功能：*使用给定的模式 mode 打开 filename 所指向的文件*

+ 函数定义：

    + **FILE* fopen(const char \*filename, const char \*mode)**

+ 其中：

    + **filename：** 要打开的文件名称

    + **mode：** 文件访问模式

        |mode 模式|说明|
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

<div align="center">
    - End -
</div>