#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "tools.h"
#include "teacher.h"
#include "system.h"
#include "principal.h"


int i_tea = 0;
//显示界面
void show_principal(void)
{
	char pass_id[9] = {};
	char password[7] = {};

	for(;;)
	{
		printf("请输入工号和密码");
		scanf("%s",pass_id);
		if(0== strcmp(prin.id,pass_id))
		{
			break;
		}
		else
		{
			puts("工号错误，请重试!");
			sleep(1);
		}
	}
	for(;;)
	{
			get_password(password,7,true);
			if(cmp_password(password,prin.key))
			{
				printf("密码正确，等待进入。。。\n");
				sleep(2);
				break;
			}
			else
			{
				printf("密码错误请重试！\n");
				sleep(1);
			}
	}
	
	if(0 == strcmp("123456",prin.key))
	{
		char tmp[7] = {};
		puts("首次登录系统，请修改密码");
		get_password(tmp,7,true);
		rep_password(prin.key,tmp);

	}
	for(;;)
	{
		system("clear");
		/*
		____________________________________
		|									|
		|									|
		|		   欢迎进入校长系统			|
		|									|
		|___________________________________|
		*/
		puts("$~~~~~~~~~~~~~欢迎校长~~~~~~~~~~~~~~$");
		puts("$~~~~~~~~~1、重置密码~~~~~~~~~~~~~~~$");
		puts("$~~~~~~~~~2、添加教师~~~~~~~~~~~~~~~$");
		puts("$~~~~~~~~~3、删除教师~~~~~~~~~~~~~~~$");
		puts("$~~~~~~~~~4、显示在职教师~~~~~~~~~~~$");
		puts("$~~~~~~~~~5、显示离职教师~~~~~~~~~~~$");
		puts("$~~~~~~~~~q、退出到系统界面~~~~~~~~~$");
		//swhich,获取键值(查成绩，改密码，查个人信息，退出)
		switch(getch())
		{
			case '1': ;break;
			case '2': add_teacher();break;
			case '3': del_teacher();break;
			case '4': show_all_in_teacher();break;
			case '5': show_all_out_teacher();break;
			case 'q': exit_teacher();return;	
		//swhich,获取键值(重置自己密码，重置教师密码，添加教师,删除教师,显示所有在职教师，显示所有离职教师，退出)
		}
	}
}

//添加教师
void add_teacher(void)
{
	while(tea[i_tea++].sex);
	printf("请输入教师姓名:\n");
	gets(tea[i_tea].name);
	puts("请输入教师性别");
	tea[i_tea].sex = getch();
	printf("%c\n",tea[i_tea].sex);
	puts("添加联系人成功！");
	sleep(1);
	tea[i_tea].id = id_teacher();
	tea[i_tea].in_out=0;
	N++;
}

//删除教师
void del_teacher(void)
{
	int id_del = 0;
	puts("请输入要删除的教师的工号");
	scanf("%d",&id_del);
	for(int i=0; i<max; i++)
	{
		if((tea[i].in_out==0) && (id_del == tea[i].id))
		{
			tea[i].in_out = 1;
			puts("删除教师成功，可惜了！");
			sleep(1);
			return;
		}
	}
	puts("输入工号有误!");
	N--;
}

//显示所有在职教师
void show_all_in_teacher(void)
{
	for(int i = 0; i< max ; i++)
	{
		if(tea[i].in_out == 0 && 0!=tea[i].sex)
		{
			printf("姓名:%s 性别:%c 工号:%d\n",tea[i].name,tea[i].sex,tea[i].id);
			
		}
	}
	sleep(2);
}

//显示所有离职教师
void show_all_out_teacher(void)
{
	for(int i=0; i<max; i++)
	{
		if(tea[i].in_out == 1 && 0!=tea[i].sex)
		{
			printf("姓名:%s 性别:%c 工号:%d\n",tea[i].name,tea[i].sex,tea[i].id);
		}
	}
}

//退出并保存（退出到系统界面）
void exit_principal(void)
{
	FILE* fwp_prin = fopen("principal.bin","w");
	if(NULL == fwp_prin)
	{
		puts("保存失败！");
		return ;
	}

	fwrite(&prin,sizeof(prin),1,fwp_prin);

	fclose(fwp_prin);

	FILE* fwp_tea=fopen("tea.bin","w");
	if(NULL == fwp_tea)
	{
		puts("保存失败!");
		return;
	}

	fwrite(&tea,sizeof(tea[0]),100,fwp_tea);

	fclose(fwp_tea);

	run_system();
	return;

}
