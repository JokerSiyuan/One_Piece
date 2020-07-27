#include <stdio.h>
#include <stdlib.h>
#include <getch.h>
#include <string.h>

#define COUNT_MAX 100

int inde = 0;

typedef struct Mail
{
	char id[20];
	char sex;
	char tell[13];
}Mail;

Mail mails[COUNT_MAX];

void add(void)
{
	while(mails[inde++].sex)
	puts("请输入联系人姓名:");
	gets(mails[inde].id);
	puts("请输入联系人性别:");
	mails[inde].sex = getch();
	printf("%c\n",mails[inde].sex);
	puts("请输入联系人号码:");
	gets(mails[inde].tell);
	puts("添加联系人成功！");
}

void del(void)
{
	puts("请选择按姓名或电话删除？(n/t)");
	puts("请输入要删除的联系人姓名：");
	char name[20] = {};
	gets(name);
	for(int i = 0; i<COUNT_MAX; i++)
	{
		if(0 == strcmp(name, mails[i].tell))
		{
			mails[i].sex = 0;
			puts("删除联系人成功！");
			return ;
		}
		if(0 == strcmp(name ,mails[i].id))
		{
			mails[i].sex = 0;
			puts("删除联系人成功！");
			return ;
		}
	}
	puts("未找到该联系人！");
}

void rep(void)
{
	puts("请输入要修改的联系人信息:");
	char name[20] = {};
	for(int i=0; i<COUNT_MAX; i++)
	{
		if(0 == strcmp(name,mails[i].tell))
		{
			puts("请输入联系人姓名:");
			gets(mails[inde].id);
			puts("请输入联系人性别:");
			mails[inde].sex = getch();
			printf("%c\n",mails[inde].sex);
			puts("请输入联系人号码:");
			gets(mails[inde].tell);
			puts("添加修改人成功！");
		}
		if(0 == strcmp(name,mails[i].id))
		{
			puts("请输入联系人姓名:");
			gets(mails[inde].id);
			puts("请输入联系人性别:");
			mails[inde].sex = getch();
			printf("%c\n",mails[inde].sex);
			puts("请输入联系人号码:");
			gets(mails[inde].tell);
			puts("添加修改人成功！");
		}
	}
	puts("未找到该联系人！");
}


void find(void)
{
	puts("请输入要查找的联系人信息:");
	char name[20]={};
	for(int i=0 ; i<COUNT_MAX; i++)
	{
		if(0 == strcmp(name,mails[i].id))
		{
			printf("姓名:%s 性别:%c 号码:%s\n",mails[i].id,mails[i].sex,mails[i].tell);
		}
		if(0 == strcmp(name,mails[i].tell))
		{
			printf("姓名:%s 性别:%c 号码:%s\n",mails[i].id,mails[i].sex,mails[i].tell);
		}
	}
	puts("未找到该联系人！");

}

void show(void)
{
	for(int i=0; i<COUNT_MAX; i++)
	{
		if(0!=mails[i].sex)
		{
			printf("姓名:%s 性别:%c 号码:%s\n",mails[i].id,mails[i].sex,mails[i].tell);
		}
	}
}

int main()
{
	for(;;)
	{
		system("clear");
		puts("**********欢迎使用通讯录**********");
		puts("***********1、增加联系人**********");
		puts("***********2、删除联系人**********");
		puts("***********3、修改联系人**********");
		puts("***********4、查找联系人**********");
		puts("***********5、显示所有联系人******");
		switch(getch())
		{
			case '1':add();break;
			case '2':del();break;
			case '3':rep();break;
			case '4':find();break;
			case '5':show();break;
		//	case '6':exit_mail();return 0;
			default:
				puts("输入指令有误！请重新输入！");break;
		}
	sleep(1);
	}
}
