#include "tools.h"
#include "system.h"
#include "student.h"
#include "teacher.h"


int stu_id = 20201000;
//显示界面("欢迎进入学生系统！")
void show_student(void)
{
	int login_id = 0;
	char password[7] = {};
	printf("请输入学号和密码");
	scanf("%d", &login_id);

	int cnt = 0;
	int index=0;
	int* p =&index;

	for(index=0;index<max;index++)
	{
		if(stu[index].id==login_id)
		{
			if(stu[index].in_out == 1)
			{
				puts("用户名错误!");
				sleep(1);
				return;
			}
			if(stu[index].lock == 1)
			{
				puts("账户已锁定！");
				sleep(1);
				return;
			}
			for(int j=0; j<3;j++)
			{
				printf("请输入密码:\n");
				get_password(password,7,true);
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
				stu[index].lock = 1;
				printf("账号已被锁定，请联系带师兄\n");
				sleep(1);

				return;
			}
		}
	}
	
	if(0==strcmp("123456",stu[index].key))
	{
		char tmp[7] = {};
		puts("首次登录系统，请修改密码");
		get_password(tmp,7,true);
		rep_password(stu[index].key,tmp);

	}
	for(;;)
	{	
		system("clear");
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
			case '1': sreach_s(p);break;
			case '2': sreach_p(p);break;
			case '3': rep_key_stu(p);break;
			case 'q': exit_student();return;
		}
	}
}

//修改密码
void rep_key_stu(int* p)
{
	char key[7] = {};
	puts("请输入密码以验证:");
	gets(key);
	if(0 != strcmp(key,stu[*p].key))
	{
		puts("密码错误，爪巴");
	anykey_continue();
		return ;
	}
	puts("请输入新密码");
	char new_key[7] = {};
	gets(new_key);
	strcpy(stu[*p].key,new_key);
	return;
}


//查个人信息
void sreach_p(int* p)
{
	printf("姓名:%s 性别:%c 学号:%d\n",stu[*p].name,stu[*p].sex,stu[*p].id);
	anykey_continue();
}

//退出（退出到系统页面）
void exit_student(void)
{
	FILE* fwp = fopen("./data/stu.bin","w");
	if(NULL == fwp)
	{
		puts("保存失败!");
		return;
	}
	fwrite(&stu,sizeof(stu[0]),100,fwp);
	
	FILE* fwp_s = fopen("./data/score.txt","w+");
	if(NULL == fwp_s)
	{
		puts("保存失败!");
		return;
	}

	for(int i = 0; i<n;i++)
	{
		fscanf(fwp_s,"%hhd %hhd %hhd\n",&stu[i].Chinese,&stu[i].Math,&stu[i].English);
	}

	fclose(fwp);
	fclose(fwp_s);

	fwp=NULL;
	fwp_s=NULL;
}



int id_student(void)
{
	FILE* fp = fopen("./data/stu_id.txt", "r+");
	if(NULL == fp)
	{
		fp = fopen("./data/stu.id.txt","w+");
	}
	else
	{
		fscanf(fp,"%d",&stu_id);
		rewind(fp);
	}

	fprintf(fp,"%d\n",++stu_id);
	fclose(fp);
	return stu_id;
}



void sreach_s(int* p)
{
	for(;;)
	{	
		system("clear");
		/*
		____________________________________
		|									|
		|									|
		|		   欢迎进入学生系统			|
		|									|
		|___________________________________|
		*/
		printf("$~~~~~~~~~~~欢迎进入查成绩系统~~~~~~~~~~~~~~$\n");
		puts("$~~~~~~~~~1、查询成绩~~~~~~~~~~~~~~~~~~~$");
		puts("$~~~~~~~~~2、查询语文排名~~~~~~~~~~~~~~~$");
		puts("$~~~~~~~~~3、查询数学排名~~~~~~~~~~~~~~~$");
		puts("$~~~~~~~~~4、查询英语排名~~~~~~~~~~~~~~~$");
		puts("$~~~~~~~~~5、查询总成绩排名~~~~~~~~~~~~~$");
		puts("$~~~~~~~~~6、查询平均分~~~~~~~~~~~~~~~~~$");
		switch(getch())
		{
			case '1': printf("语文：%hhd,数学:%hhd,英语:%hhd\n",stu[*p].Chinese,stu[*p].Math,stu[*p].English);break;
			case '2': rank_C();printf("语文排名全班第：%d",stu[*p].rank);break;
			case '3': rank_M();printf("数学排名全班第：%d",stu[*p].rank);break;
			case '4': rank_E();printf("英语排名全班第：%d",stu[*p].rank);break;
			case '5': rank_S();printf("总分排名全班第：%d",stu[*p].rank);break;
			case '6': printf("平均分:%d",(stu[*p].Chinese+stu[*p].Math+stu[*p].English)/3);break;
			case 'q': return;
		}
	}
}

//语文排序
int stu_cmp_Chinese(const void* p1,const void* p2)
{
	return ((Student*)p1)->Chinese < ((Student*)p2)->Chinese;
}

//数学排序
int stu_cmp_Math(const void* p1,const void* p2)
{
	return ((Student*)p1)->Math < ((Student*)p2)->Math;
}

//英语排序
int stu_cmp_English(const void* p1,const void* p2)
{
	return ((Student*)p1)->English < ((Student*)p2)->English;
}

//总分排序
int stu_cmp_sum(const void* p1,const void* p2)
{
	return ((Student*)p1)->sum < ((Student*)p2)->sum;
}

void rank_C(void)
{
	qsort(stu1,n,sizeof(Student),stu_cmp_Chinese);
	for(int i =0; i<n; i++)
	{
		stu1[i].rank = i+1;
	}
}

void rank_M(void)
{
	qsort(stu1,n,sizeof(Student),stu_cmp_Math);
	for(int i =0; i<n ;i++)
	{
		stu1[i].rank = i+1;
	}
}

void rank_E(void)
{
	qsort(stu1,n,sizeof(Student),stu_cmp_English);
	for(int i =0; i<n ;i++)
	{
		stu1[i].rank = i+1;
	}
}

void rank_S(void)
{
	qsort(stu1,n,sizeof(Student),stu_cmp_sum);
	for(int i =0; i<n ;i++)
	{
		stu1[i].rank = i+1;
	}
}

