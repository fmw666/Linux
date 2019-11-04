// 调用 printf、perror 函数
#include <stdio.h>
// ---

// 调用 exit 函数
#include <stdlib.h>
// ---

// 调用 *stat、chdir 函数
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
// ---

// 调用 strcmp 函数，char *字符串数组
#include <string.h>
// ---

// 调用 DIR、opendir 函数
#include <dirent.h>
// ---

// 调用 getpwuid 函数
#include <pwd.h>
// ---

// 调用 getgrgid 函数
#include <grp.h>
// ---

// 调用 ctime 函数
#include <time.h>
// ---

// 宏定义布尔类型
#define BOOL int
#define TRUE 1
#define FALSE 0


/*
 * ls 的参数库
 * 如：ls -xx
 * 参数个数变量：ARGS_COUNT
 * 参数功能开启变量：ARG_FUNC_OPEN[ARGS_COUNT]
 */
// 参数个数
#define ARGS_COUNT 1
// 参数列表数组
static char ARG_LIST[ARGS_COUNT] = {'l'};
// 宏定义参数位置
#define arg_l 0
// 显示的 额外功能参数描述 是否开启数组保存信息
BOOL ARG_FUNC_OPEN[ARGS_COUNT];
// 相当于执行 ls --help 出现的帮助文档
void args_help(char prog_name[])
{
    printf("NAME\n\t%s - list directory contents\n\n", prog_name);
    printf("SYNOPSIS\n\t%s [OPTION]... [FILE]...\n\n", prog_name);
    printf("DESCRIPTION\n");
    printf("\t-l\tuse a long listing format\n");
}
// 开启相关参数功能，成功返回1，失败返回-1
int set_arg_func(char arg)
{
    for (int i = 0; i < ARGS_COUNT; i++)
    {
        if (arg == ARG_LIST[i])
        {
            ARG_FUNC_OPEN[i] = TRUE;
            return 1;
        }
    }
    return -1;
}

// 返回文件类型
char get_file_type(mode_t st_mode)
{
	if ((st_mode & __S_IFMT) == __S_IFSOCK)
		return 's';
	else if ((st_mode & __S_IFMT) == __S_IFLNK)
		return 'l';
	else if ((st_mode & __S_IFMT) == __S_IFREG)
		return '-';
	else if ((st_mode & __S_IFMT) == __S_IFBLK)
		return 'b';
	else if ((st_mode & __S_IFMT) == __S_IFCHR)
		return 'c';
	else if ((st_mode & __S_IFMT) == __S_IFIFO)
		return 'p';
	else if ((st_mode & __S_IFMT) == __S_IFDIR)
		return 'd';
}

// 给文件权限变量赋值
void set_file_permissions(mode_t st_mode, char *file_permissions)
{
    strcpy(file_permissions, "");
    unsigned int mask = 0700;
	static char *perm[] = {"---", "--x", "-w-", "-wx", "r--", "r-x", "rw-", "rwx"};
	for (int i = 3; i; --i)
	{
        file_permissions = strcat(file_permissions, perm[(st_mode & mask) >> (i - 1) * 3]);
        // printf("%3s", perm[(st_mode & mask) >> (i - 1) * 3]);
		mask >>= 3;
	}
}

/*
 * ls 展示文件信息
 */
void list_dir(char prog_name[], char *dir_name)
{
    // 如果不能访问该文件，执行报错信息
    if (access(dir_name, F_OK) != 0)
    {
        printf("%s: 无法访问'%s': 没有那个文件或目录\n", prog_name, dir_name);
    }
    // 如果能访问该文件，执行如下逻辑层
    else
    {
        // 文件打开指针
        DIR *pDir = opendir(dir_name);
        // 文件项指针
        struct dirent *pDirent;
        /*
         * 函数名：stat
         * 作用：读取文件属性
         * 系统调用名：fstat/stat/lstat
         * 头文件：unistd.h、sys/stat.h、sys/types.h
         */
        struct stat buff;

        // 如果开启功能 -l，直接输出文件名
        if (ARG_FUNC_OPEN[arg_l] == TRUE)
        {
            // 总用量，单位B，之后除以1024输出单位KB
            int total_size = 0;
            // 文件类型
            char file_type;
            // 文件权限
            char file_permissions[9];
            //
            struct passwd *p_passwd;
            // 
            struct group *p_group;
            char *p_time;

            // 改变当前工作目录，相当于cd。需要得到文件目录下所有属性
            // *需要注意一个bug：
            //  即 ’ls . /home/ .‘ 时
            //  切换到‘/home/’ 目录后，下一个‘.’是当前‘/home/’目录
            //  所以在每次执行chdir后要跳回原来目录
            char *current_dir_path;
            current_dir_path = getcwd(NULL, 0);
            chdir(dir_name);

            // 打开文件项
            while ((pDirent = readdir(pDir)) != NULL)
            {
                // 略去 ’.‘ 开头隐藏文件
                if (pDirent->d_name[0] == '.')
                {
                    continue;
                }
                // 如果能获取文件相关属性到buff里面
                if (lstat(pDirent->d_name, &buff) == -1)
                {
                    perror(dir_name);
                }
                // 总用量增加相应size大小
                total_size += (int)buff.st_size;
            }
            
            // 输出 总用量
            printf("总用量 %d\n", total_size/1024);
    

            // 重新打开文件项用于输出
            pDir = opendir(dir_name);
            while ((pDirent = readdir(pDir)) != NULL)
            {
                // 略去 ’.‘ 开头隐藏文件
                if (pDirent->d_name[0] == '.')
                {
                    continue;
                }
                // 如果能获取文件相关属性到buff里面
                if (lstat(pDirent->d_name, &buff) == -1)
                {
                    perror(dir_name);
                }

                // 输出 ‘drwxr-xr-x 2 fmw fmw  4096 11月  2 00:38 dir’
                // 文件类型
                file_type = get_file_type(buff.st_mode);
                printf("%c", file_type);
                // 文件权限
                set_file_permissions(buff.st_mode, file_permissions);
                printf("%s", file_permissions);
                //
                p_time = ctime(&buff.st_mtime);
                p_passwd = getpwuid(buff.st_uid);	
                p_group = getgrgid(buff.st_gid);
                printf(" %2d %4s %4s %6d", buff.st_nlink, p_passwd->pw_name, p_group->gr_name, (int)buff.st_size);
                for (int i = 3; p_time[i+8] != 0 && p_time[i+8] != '\n'; i++)
                {
                    putchar(p_time[i]);
                }
                printf(" %s\n", pDirent->d_name);
            }


            // 切换回当前路径下
            chdir(current_dir_path);
            free(current_dir_path);
            // 关闭文件指针
            closedir(pDir);
        }

        // 如果没有开启功能 -l，直接输出文件名
        else if (ARG_FUNC_OPEN[arg_l] == FALSE)
        {
            // 打开文件项
            while ((pDirent = readdir(pDir)) != NULL)
            {
                // 略去 ’.‘ 开头隐藏文件
                if (pDirent->d_name[0] == '.')
                {
                    continue;
                }
                // 输出 文件名
                printf("%s  ", pDirent->d_name);
            }
            printf("\n");
            closedir(pDir);
        }
    }
}


int main(int argc, char *argv[])
{
    /*
     * 表示只有程序名输入，未加路径参数或路径
     * 相当于执行 'ls' 或 'ls .'
     */
    if (argc == 1)
    {
        list_dir(argv[0], ".");
        return 0;
    }

    else if (argc == 2 && strcmp(argv[1], "--help") == 0)
    {
        args_help(argv[0]);
    }
    
    /*
     * 当参数除了程序名外还有其他参数时
     * 1. 先判断有没有‘-’符号
     * 2. 若‘-’符号后不接参数，则当做目录名来处理
     * 3. 若‘-’符号后接参数，入
     */
    else if (argc >= 2)
    {
        // 字符串数组用于存放 路径。最多 argc-1 个数
        char *dirs[argc-1];
        // 变量保存 路径 数目
        int dir_count = 0;
        // 遍历所有参数去找 -xx 命令和 路径
        for (int i = 1; i < argc; i++)
        {
            // 如果是‘-’命令型。注意，单个‘-’算是文件，另作处理
            if (argv[i][0] == '-' && argv[i][1])
            {
                // 遍历所有 命令参数
                for (int j = 1; argv[i][j]; j++)
                {
                    // 如果 命令参数 中出现 ‘-’ 则报错
                    if (argv[i][j] == '-')
                    {
                        printf("%s: 不适用的选项 -- -\nTry '%s --help' for more information.\n", argv[0], argv[0]);
                        return -1;
                    }
                    // 调用相关函数，设置相应功能开启
                    if (set_arg_func(argv[i][j]) == -1)
                    {
                        printf("%s: 不适用的选项 -- %c\nTry '%s --help' for more information.\n", argv[0], argv[i][j], argv[0]);
                        return -1;
                    }
                }
            }
            // 保存文件进字符串数组
            else
            {
                // 存入数组
                dirs[dir_count] = argv[i];
                // 文件数量增1
                dir_count++;
            }
        }

        // 如果没有文件，如 ls -l -l ...
        if (dir_count == 0)
        {
            list_dir(argv[0], ".");
        }
        // 如果只有一个文件，如 ls /home/ -l -l ...
        else if (dir_count == 1)
        {
            list_dir(argv[0], dirs[0]);
        }    
        // 如果有超过两个文件，如 ls /home/ /usr/ -l ...
        // 先记录不能访问的文件，因为在输出时要先输出
        else if (dir_count >= 2)
        {
            // 能访问的文件数组及其数量
            char *acc_dirs[dir_count];
            int acc_dir_count = 0;
            // 不能访问的文件数组及其数量
            char *err_dirs[dir_count];
            int err_dir_count = 0;
            // 遍历文件数组把所有的给预先分类
            for (int i = 0; i < dir_count; i++)
            {
                // 能正常访问
                if(access(dirs[i], F_OK) == 0)
                {
                    acc_dirs[acc_dir_count] = dirs[i];
                    acc_dir_count++;
                }
                // 不能正常访问
                else
                {
                    err_dirs[err_dir_count] = dirs[i];
                    err_dir_count++;
                }
            }
            // 预先展示不能访问的文件输出信息
            for (int i = 0; i < err_dir_count; i++)
            {
                list_dir(argv[0], err_dirs[i]);
            }
            // 后展示能访问的文件输出信息
            for (int i = 0; i < acc_dir_count; i++)
            {
                // 如：/home/:\n
                printf("%s:\n", acc_dirs[i]);
                list_dir(argv[0], acc_dirs[i]);
                // 如果没到最后一个文件展示则执行换行
                if (i != acc_dir_count - 1)
                {
                    printf("\n");
                }
            }
        }
        
        
    }

}