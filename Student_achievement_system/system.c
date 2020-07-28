#include "system.h"
#include "tools.h"
#include "teacher.h"
#include "student.h"
#include "principal.h"
#include <getch.h>

#define max  100	//最大学生数
#define MAX  100	//最大教师数

//定义全局变量
int n=0;	//定义学生数量n
int N=0;	//定义教师数量N

//学生基本信息变量
typedef struct Student
{
	char name[20];
	char sex;
	char id[20];
	char key[6];
	char lock;
}Student;

Student stu[100];

typedef struct Teacher
{
	char name[20];
	char sex;
	char id[20];
	char key[6];
	char lock;
}Teacher;

Teacher tea[100];

typedef struct Score
{
	char Chinese;
	char Math;
	char English;
}Score;

Score sco[100];

void init_system(void)
{
	debug("%s\n",__func__);
	//初始化数据
	//从文件读取数据到内存
}

void run_system(void)
{
	debug("%s\n",__func__);
	//显示界面（“欢迎来到指针带学教务系统！”）
	//获取键值（'s':进入学生系统，'t':进入教师系统，‘p’：进入校长系统）
}

void exit_system(void)
{
	debug("%s\n",__func__);
	//显示界面（感谢使用指针带学教务系统！）
	//保存数据并退出
}
