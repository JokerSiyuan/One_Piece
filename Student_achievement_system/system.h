#ifndef SYSTEM_H
#define SYSTEM_H

#define max  100
#define MAX  100	//最大教师数

//定义全局变量
int n;	//定义学生数量n
int N;	//定义教师数量N
extern Score sco[100];
extern Student stu[100];
extern Teacher tea[100];

//函数
void init_system(void);

void run_system(void);

void exit_system(void);

#endif//SYSTEM_H
