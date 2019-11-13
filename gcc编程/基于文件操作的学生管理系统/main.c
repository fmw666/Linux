#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

// 学生信息管理文件名
#define file_name "stu.info"
// 临时文件
#define temp_file_name ".stu.info.temp"

// 初始化文本字符串信息
const char INIT_STR[] = "====Student-Info Management====\nid\tname\tsex\tphone\n";

// 宏定义布尔类型
#define BOOL int
#define TRUE 1
#define FALSE 0

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
	short int sex[1];/*0为女生，1为男生*/
	char mobile_phone[12];
} Student;

// 函数声明
void menu();
int input_check(int choose);
int yes_or_no_check(int choose);
int file_check();
BOOL id_check(char *id);
void menu_call(int choose);
void show_all();
void search();
void add();
void change();
void delete();
void clear();


// 菜单
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

// 菜单选择
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

// 0-1选择
int yes_or_no_check(int choose)
{
	int t;
	do
	{
		t = scanf("%d", &choose);
		// 用循环把缓冲区的不匹配字符读完
		while(getchar()!='\n'){}
		if (t == 0)
		{
			printf("\033[1;31m(Input error, please reinput): \033[0m");
		}
		
	} while (t == 0);
	
	
	while (choose != 0 && choose != 1)
	{
		printf("\033[1;31m(Input error, please reinput): \033[0m");
		do
		{
			t = scanf("%d", &choose);
			// 用循环把缓冲区的不匹配字符读完
			while(getchar()!='\n'){}
			if (t == 0)
			{
				printf("\033[1;31m(Input error, please reinput): \033[0m");
			}
			
		} while (t == 0);
	}
	return choose;
}

int file_check()
{
	FILE *fp;

	if ((fp = fopen(file_name, "r")) == NULL)
	{
		// 如果没有这个文件则自动创建
		if ((fp = fopen(file_name, "w")) == NULL)
		{
			// 自动创建失败
			return -2;
		}
		// 创建成功后写入初始信息
		if (fprintf(fp, INIT_STR) < 0)
		{
			// 写入信息失败
			return -1;
		}
		fclose(fp);
		// 不存在文件自动创建成功返回值
		return 0;
	}
	fclose(fp);
	// 存在文件返回值
	return 1;
}

// id 重复检测
BOOL id_check(char *id)
{
	char str_line[1024]; 
	FILE *fp = fopen(file_name, "r");
	fseek(fp, sizeof(INIT_STR)-1, SEEK_SET);
	while (1)
	{
		fgets(str_line, 1024, fp);
		char *stu_num = strtok(str_line, "\t");
		if(strcmp(stu_num, id) == 0)
		{
			stu_num = strtok(NULL, "");
			fclose(fp);
			fp = NULL;
			return FALSE;
		}
		if (feof(fp))
		{
			break;
		}
	}
	close(fp);
	fp = NULL;
	return TRUE;
}

// 菜单按键响应
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

	printf("\033[1;34m== Show all student's info ==\n\n\033[0m");

	// 文件检查，若不存在自动新建一个
	if (file_check() == 0)
	{
		printf("\033[1;33m 学号\t姓名\t性别\t电话\n\033[0m");
		printf("\033[1;31m\n no-data\033[0m");	
	}
	// 如果文件存在则开始展示
	else if (file_check() == 1)
	{
		char str_line[1024];             //每行最大读取的字符数

		FILE *fp = fopen(file_name, "r");
		
		printf("\033[1;33m 学号\t姓名\t性别\t电话\n\033[0m");
		fseek(fp, sizeof(INIT_STR)-1, SEEK_SET);
		int index = 1;
		while (1)
		{
			fgets(str_line, 1024, fp);
			if (feof(fp))
			{
				break;
			}
			char *line = strtok(str_line, "\n");
			printf("\033[1;37m %s\t(%d)\n\033[0m", line, index++);
		}
		if (index == 1)
		{
			printf("\033[1;31m\n no-data\033[0m");
		}
		
				
		fclose(fp);
	}

	printf("\n\nplease press a key for continue...");
	getchar();
}

void search()
{
	system("reset");

	printf("\033[1;34m== Search for students' info ==\n\n\033[0m");
	printf("\033[1;37mPlease input the student's id for searching: \033[0m");
	char id[12];
	scanf("%s", id);

	FILE *fp = fopen(file_name, "r");
	fseek(fp, sizeof(INIT_STR)-1, SEEK_SET);
	char str_line[1024];
	BOOL find = FALSE;
	while (1)
	{
		if (fgets(str_line, 1024, fp) == NULL)
		{
			getchar();
			break;
		}
		char temp[1024];
		strcpy(temp, str_line);
		char *stu_num = strtok(temp, "\t");
		// 查到对应 id 学生
		if(strcmp(stu_num, id) == 0)
		{
			stu_num = strtok(NULL, "");
			find = TRUE;
			printf("\033[1;33m\n学号\t姓名\t性别\t电话\n\033[0m");
			printf("\033[1;37m%s\033[0m", str_line);

			getchar();
			break;
		}
		if (feof(fp))
		{
			getchar();
			break;
		}
	}
	if (find == FALSE)
	{
		printf("\033[1;33mFind no student!\033[0m");
	}
	fclose(fp);

	printf("\n\nplease press a key for continue...");
	getchar();
}

void add()
{
	system("reset");
	fflush(stdin);
	fflush(stdout);

	printf("\033[1;34m== Add a new student ==\n\033[0m");

	Student student;
	printf("\033[1;33m\nPlease input the student's id: \033[0m");
	scanf("%s", student.stu_num);
	if (id_check(student.stu_num))
	{
		printf("\033[1;33mPlease input the student's name: \033[0m");
		scanf("%s", student.name);
		printf("\033[1;33mPlease input the student's sex(0-man,1-woman): \033[0m");
		scanf("%d", &student.sex[0]);
		printf("\033[1;33mPlease input the student's phone: \033[0m");
		scanf("%s", student.mobile_phone);

		FILE *fp = fopen(file_name, "a");
		fprintf(fp, "%s\t%s\t%d\t%s\n", student.stu_num, student.name, student.sex[0], student.mobile_phone);
		fclose(fp);
		printf("\033[1;37m\nAdd succeed !\033[0m");
	}
	else
	{
		printf("\033[1;31mID repeat, please show first, then add the new !\033[0m");
	}

	getchar();

	printf("\n\nplease press a key for continue...");
	getchar();
}

void change()
{
	system("reset");

	printf("\033[1;34m== Change students' info ==\n\n\033[0m");
	printf("\033[1;37mPlease input the student's id for changing: \033[0m");
	char id[12];
	scanf("%s", id);

	FILE *fp = fopen(file_name, "r+");
	fseek(fp, sizeof(INIT_STR)-1, SEEK_SET);
	FILE *tp = fopen(temp_file_name, "w");
	fprintf(tp, INIT_STR);
	fseek(tp, sizeof(INIT_STR)-1, SEEK_SET);

	char str_line[1024];
	long len = 0;
	long line_len = 0;
	BOOL find = FALSE;

	while (fgets(str_line, 512, fp))
	{
		line_len = strlen(str_line);
		len += line_len;

		char temp[1024];
		strcpy(temp, str_line);
		char *stu_num = strtok(temp, "\t");
		// 查到对应 id 学生
		if(strcmp(stu_num, id) == 0)
		{
			stu_num = strtok(NULL, "");
			find = TRUE;
			printf("\033[1;33m\n学号\t姓名\t性别\t电话\n\033[0m");
			printf("\033[1;37m%s\033[0m", str_line);

			getchar();

			Student student;
			printf("\033[1;37m\nPlease input the changed info\n\033[0m");

			printf("\033[1;33mPlease input the student's name: \033[0m");
			scanf("%s", student.name);
			printf("\033[1;33mPlease input the student's sex(0-man,1-woman): \033[0m");
			scanf("%d", &student.sex[0]);
			printf("\033[1;33mPlease input the student's phone: \033[0m");
			scanf("%s", student.mobile_phone);

			fprintf(tp, "%s\t%s\t%d\t%s\n", id, student.name, student.sex[0], student.mobile_phone);
		}
		else
		{
			fputs(str_line, tp);
		}
	}
	if (find == FALSE)
	{
		printf("\033[1;33mFind no student!\033[0m");
		getchar();
	}
	fclose(fp);
	fclose(tp);
	remove(file_name);
	rename(temp_file_name, file_name);

	printf("\n\nplease press a key for continue...");
	getchar();
}

void delete()
{
	system("reset");

	printf("\033[1;34m== Delete a student ==\n\n\033[0m");
	printf("\033[1;37mPlease input the student's id for deleting: \033[0m");
	char id[12];
	scanf("%s", id);

	FILE *fp = fopen(file_name, "r+");
	fseek(fp, sizeof(INIT_STR)-1, SEEK_SET);
	FILE *tp = fopen(temp_file_name, "w");
	fprintf(tp, INIT_STR);
	fseek(tp, sizeof(INIT_STR)-1, SEEK_SET);

	char str_line[512] = {0};
	int line_len = 0;
	int len = 0;

	BOOL find = FALSE;
	while (fgets(str_line, 512, fp))
	{
		line_len = strlen(str_line);
		len += line_len;

		char temp[512];

		strcpy(temp, str_line);
		char *stu_num = strtok(temp, "\t");
		// 查到对应 id 学生
		if(strcmp(stu_num, id) == 0)
		{
			find = TRUE;
			printf("\033[1;33m\n学号\t姓名\t性别\t电话\n\033[0m");
			printf("\033[1;37m%s\033[0m", str_line);
			printf("\033[1;31m\nThis info has been deleted !\033[0m");
		}
		else 
		{
			fputs(str_line, tp);
		}
		
	}
	fclose(fp);
	fclose(tp);
	remove(file_name);
	rename(temp_file_name, file_name);
	getchar();

	if (find == FALSE)
	{
		printf("\033[1;33mFind no student!\033[0m");
		getchar();
	}

	printf("\n\nplease press a key for continue...");
	getchar();
}

void clear()
{
	system("reset");

	printf("\033[1;34m== Clear all students' info ==\n\n\033[0m");
	printf("\033[1;31mWarning!!! Are you sure to clear all the dates?\n\033[0m");
	printf("\033[1;31m(0--for no, 1--for yes): \033[0m");
	int choose = -1;
	// 输入检查
	choose = yes_or_no_check(choose);
	if (choose == 1)
	{
		FILE *fp = fopen(file_name, "w");
		fprintf(fp, INIT_STR);
		fclose(fp);
		printf("\033[1;37m\nClear succeed !\033[0m");		
	}
	
	printf("\n\nplease press a key for continue...");
	getchar();
}


int main()
{
	// 文件检查，若不存在自动新建一个
	file_check();

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