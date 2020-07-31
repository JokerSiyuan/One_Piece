#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "system.h"
#include "teacher.h"
#include "student.h"
#include "principal.h"
#include "tools.h"

#define max 100

//定义全局变量
int n=0;	//定义学生数量n
int N=0;	//定义教师数量N


void init_system(void)
{
	//初始化数据
    strcpy(prin.id,"00000001");
    strcpy(prin.name,"孙令令");
    strcpy(prin.key,"111111");
	for(int i=0; i<max;i++)
	{
		stu[i].lock =0;
		tea[i].lock =0;
		stu[i].in_out=0;
		tea[i].in_out=0;
		strcpy(tea[i].key,"123456");
		strcpy(stu[i].key,"123456");

	}
	//从文件读取数据到内存
	FILE* frp_stu = fopen("stu.bin","r");
	if(NULL == frp_stu)
	{
		puts("文件打开失败!\n");
		return ;
	}
	fread(stu,sizeof(stu),max,frp_stu);
	fclose(frp_stu);

	FILE* frp_tea = fopen("tea.bin","r");
	if(NULL == frp_tea)
	{
		puts("文件打开失败!\n");
		return ;
	}
	fread(tea,sizeof(tea),max,frp_tea);
	fclose(frp_tea);

	FILE* frp_prin = fopen("principal.bin","r");
	if(NULL == frp_prin)
	{
		puts("文件打开失败!\n");
		return;
	}
	fread(&prin,sizeof(prin),1,frp_prin);
	fclose(frp_prin);

}

//运行程序
void run_system(void)
{
	//显示界面（“欢迎来到指针带学教务系统！”）
	for(;;)
	{
		system("clear");
		puts("$~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~$");
		puts("$~~~~~欢迎进入指针带学教务系统!~~~~~~~~$");
		puts("$~~~~~~~~~~~1、我是校长~~~~~~~~~~~~~~~~$");
		puts("$~~~~~~~~~~~2、我是老师~~~~~~~~~~~~~~~~$");
		puts("$~~~~~~~~~~~3、我是学生~~~~~~~~~~~~~~~~$");
		puts("$~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~$");
		puts("$~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~$");
		puts("$~~~~~~~~~~~q、退出系统~~~~~~~~~~~~~~~~$");		
		printf("校长备忘录:  工号：%s 密码：%s\n",prin.id,prin.key);
	//获取键值（'s':进入学生系统，'t':进入教师系统，‘p’：进入校长系统）
		switch(getch())
		{
			case '1':show_principal();break; 
			case '2':show_teacher();break;
			case '3':show_student();break;
			case 'q':exit_system();return;
		}
	}
}

void exit_system(void)
{
	system("clear");
	//显示界面（感谢使用指针带学教务系统！）
		puts("$~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~$");
		puts("$~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~$");
		puts("$~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~$");
		puts("$~~~~~~~~感谢使用指针教务系统！~~~~~~~~$");
		puts("$~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~$");
		puts("$~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~$");
		puts("$~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~$");
		puts("$~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~$");	
	//保存数据并退出
	FILE* fwp_stu = fopen("stu.bin","w");
	if(NULL == fwp_stu)
	{
		puts("数据保存失败！");
		return ;
	}
	fwrite(stu,sizeof(stu[0]),100,fwp_stu);
	fclose(fwp_stu);

	FILE* fwp_tea = fopen("tea.bin","w");
	if(NULL == fwp_tea)
	{
		puts("数据保存失败！");
		return ;
	}
	fwrite(&tea,sizeof(tea[0]),100,fwp_tea);
	fclose(fwp_tea);

	FILE* fwp_prin = fopen("prin.bin","w");
	if(NULL == fwp_prin)
	{
		puts("数据保存失败！");
		return ;
	}
	fwrite(&prin,sizeof(prin),100,fwp_prin);
	fclose(fwp_prin);
	return ;
}
