#include <stdio.h>
#include <stdlib.h>

// 学生信息管理文件名
#define file_name "stu_info.txt"

// 菜单选择按键宏定义
#define SHOW 1
#define SEARCH 2
#define ADD 3
#define CHANGE 4
#define DELETE 5
#define CLEAR 6
#define EXIT 7


// 学生信息结构体
typedef struct stu_info {
	char stu_num[12];
	char name[10];
	short int sex;/*0为女生，1为男生*/
	char mobile_phone[12];
} Student;

// 函数声明
void err_exit(char *err_s);
void menu();
int input_check(int choose);
int open_file(FILE *fp);
void menu_call(int choose);
void show_all();
void search();
void add();
void change();
void delete();
void clear();


void err_exit(char *err_s)
{
	perror(err_s);
	exit(1);
}


void menu()
{
	printf("\033[1;34m== Student Manage System ==\n\033[0m");
	printf("---\n");
	printf("\033[1;37m1. Show all students' info\n\033[0m");
	printf("\033[1;37m2. Search for student's info\n\033[0m");
	printf("\033[1;37m3. Add a new student\n\033[0m");
	printf("\033[1;37m4. Change student's info\n\033[0m");
	printf("\033[1;37m5. Delete a student\n\033[0m");
	printf("\033[1;31m6. Clear all students' info\n\033[0m");
	printf("---\n");
	printf("\033[1;33m7. Exit\n\033[0m");
	printf("\nPlease input your choose: ");
}

int input_check(int choose)
{
	int t;
	do
	{
		t = scanf("%d", &choose);
		// 用循环把缓冲区的不匹配字符读完
		while(getchar()!='\n'){}
		if (t == 0)
		{
			printf("Input error, please reinput: ");
		}
		
	} while (t == 0);
	
	
	while (choose < SHOW || choose > EXIT)
	{
		printf("Input error, please reinput: ");
		do
		{
			t = scanf("%d", &choose);
			// 用循环把缓冲区的不匹配字符读完
			while(getchar()!='\n'){}
			if (t == 0)
			{
				printf("Input error, please reinput: ");
			}
			
		} while (t == 0);
	}
	return choose;
}

int open_file(FILE *fp)
{
	if ((fp = fopen(file_name, "r")) == NULL)
	{
		// 如果没有这个文件则自动创建
		if ((fp = fopen(file_name, "w")) == NULL)
		{
			// 自动创建失败
			// err_exit("Error: failed create!");
			return -2;
		}
		// 创建成功后写入初始信息
		char str[] = "====Student-Info Management====\nid\tname\tsex\tphone\n";
		if(fprintf(fp, str) < 0)
		{
			// 写入信息失败
			return -1;
		}
		// 不存在文件自动创建成功返回值
		return 0;
	}
	// 存在文件返回值
	return 1;
}

void menu_call(int choose)
{
	if (choose == SHOW)
	{
		show_all();
	}
	else if (choose == SEARCH)
	{
		search();
	}
	else if (choose == ADD)
	{
		add();
	}
	else if (choose == CHANGE)
	{
		change();
	}
	else if (choose == DELETE)
	{
		delete();
	}
	else if (choose == CLEAR)
	{
		clear();
	}
	else if (choose == EXIT)
	{
		//
	}
}

void show_all()
{
	system("reset");

	printf("\033[1;34m== Show all student's info ==\n\033[0m");
	FILE *fp;
	// 文件打开，若不存在自动新建一个
	int ret = open_file(fp);
	if (ret == 0)
		printf("\033[1;31mno-data\033[0m");
	else if (ret != 1)
		err_exit("Error in file open!");
	
	fclose(fp);
	printf("\n\nplease press a key for continue...");
	getchar();
}

void search()
{

}

void add()
{}

void change()
{}

void delete()
{}

void clear()
{}


int main()
{
	// FILE *fp;
	// // 文件打开，若不存在自动新建一个
	// if (open_file(fp) != 1)
	// 	err_exit("Error in file open!");
	// fclose(fp);

	int choose = 0;
	while (choose != EXIT)
	{
		// 清屏
		system("reset");
		// 菜单调用
		menu();
		
		// 输入检查
		choose = input_check(choose);
		
		// 菜单功能实现
		menu_call(choose);
		
	}

    return 0;
}