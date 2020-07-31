#ifndef SYSTEM_H
#define SYSTEM_H
#include <stdbool.h>
#include <string.h>
#include <unistd.h>
#define max  100
#define MAX  100	//最大教师数

//定义全局变量
int n;	//定义学生数量n
int N;	//定义教师数量N

//学生基本信息变量
typedef struct Student
{
	char name[20];
	char sex;
	int  id;
	int rank;
	char key[7];
	short sum;
	char Chinese;
	char Math;
	char English;
	char lock;
	char in_out;

}Student;

Student stu[100];
Student* stu1;

typedef struct Teacher
{
	char name[20];
	char sex;
	int id;
	char key[7];
	char lock;
	char in_out;
}Teacher;

Teacher tea[100];

typedef struct Principal
{
	char name[20];
	char id[9];
	char key[7];
}Principal;

Principal prin;

//函数
void init_system(void);

void run_system(void);

void exit_system(void);

#endif//SYSTEM_H
