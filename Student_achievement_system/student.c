#include "tools.h"
#include "system.h"
#include "student.h"

//显示界面("欢迎进入学生系统！")
void show_student(void)
{
	char pass_id[9] = {};
	char password[7] = {};
	printf("请输入学号和密码");
	scanf("%s", pass_id);
	int cnt = 0;
	int index=0;
	int* p =&index;

	for(index=0;index<max;index++)
	{
		if(stu[index].lock == 1)
		{
			puts("账户已锁定！");
			sleep(1);
			return;
		}
		if(stu[index].in_out == 1)
		{
			puts("用户名错误!");
			sleep(1);
			return;
		}
		if(0 == strcmp(stu[index].id,pass_id))
		{
			for(int j=0; j<3;j++)
			{
				get_password(password,6,true);
				if(cmp_password(password,stu[index].key))
				{
					break;
				}
				else
				{
					cnt++;
				}
			}
			if(cnt <3)
			{
				printf("密码正确!\n");
				sleep(1);
				break;
			}
			else
			{
				stu[index].in_out = 1;
				printf("密码错误!\n");
				sleep(1);

				return;
			}
		}
	}
	
	if(strcmp("123456",stu[index].key))
	{
		char tmp[7] = {};
		puts("首次登录系统，请修改密码");
		get_password(tmp,7,true);
		rep_password(stu[index].key,tmp);

	}
	for(;;)
	{	
		/*
		____________________________________
		|									|
		|									|
		|		   欢迎进入学生系统			|
		|									|
		|___________________________________|
		*/
		printf("$~~~~~~~~~~~欢迎%s同学~~~~~~~~~~~~~~$\n",stu[index].name);
		puts("$~~~~~~~~~1、查询成绩~~~~~~~~~~~~~~~$");
		puts("$~~~~~~~~~2、查询信息~~~~~~~~~~~~~~~$");
		puts("$~~~~~~~~~3、修改密码~~~~~~~~~~~~~~~$");
		//swhich,获取键值(查成绩，改密码，查个人信息，退出)
		switch(getch())
		{
			case '1': sreach_s();break;
			case '2': sreach_p(p);break;
			case '3': rep_key_stu();break;
			case '4': exit_student();
		}
	}
}

//修改密码
void rep_key_stu()
{
}


//查成绩
void sreach_s(void)
{
	
}

//查个人信息
void sreach_p(int* p)
{
	printf("姓名:%s 性别:%c 学号:%s",stu[*p].name,stu[*p].sex,stu[*p].id);
}

//退出（退出到系统页面）
void exit_student(void)
{
}



