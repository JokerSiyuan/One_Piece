#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "teacher.h"
#include "tools.h"
#include "system.h"
#include "student.h"



int tea_id = 20200000;
//显示界面
void show_teacher(void)
{
    char tmp = 0;
    for(;;)
	{
		//登录
		printf("请输入教师工号：\n");
		int tid = 0;
		char tkey1[7] = {};
		char tkey2[7] = {};
		int cnt = 0;
		int a= 0;
		scanf("%d",&tid);
        for(int i = 0;i < 100;i++)
		{
			if(tid == tea[i].id)
			{
				i = cnt;
				break;
			}
			a++;
		}
		if(100 == a) 
		{
		  printf("工号输入错误，请重新输入\n");
		  continue;
		}
         stdin->_IO_read_ptr =stdin->_IO_read_end;
		
				printf("请输入密码：\n");
				get_password(tkey1,7,true);
			    sleep(1);
				get_password(tkey2,7,true);
				if(0 == strcmp(tkey1,tea[cnt].key) && 0 == strcmp(tkey2,tea[cnt].key))
				{
					//swhich,获取键值(添加学生，删除学生，查找学生，修改学生基本信息，录入学生成绩，重置学生密码，显示所有在校学生信息，显示所有退学学生信息，显示被锁定学生，解锁被锁定学生，退出)
					if(0 == strcmp(tkey1,"123456"))
					{
						printf("您好，您是第一次登录，请修改密码为与默认密码不同！\n");
						char tkey[7] = {};
				        get_str(tkey,7);
						strcpy(tea[cnt].key,tkey);
						break;
					}
					else
					{
						printf("登陆成功！\n");
						break;
					}
				}
				else if(!tea[cnt].lock)
				{
					printf("密码输入错误！请重新输入密码\n");
					tmp++;
					if(2 == tmp)
					{
						tea[cnt].lock = 1;
					}
					continue;
				}
				else
				{
					printf("密码错误三次，账号已被锁定！\n");
					return;
				}
			
		
	}


				
	for(;;)
	{
	    system("clear");
		/*
		____________________________________
		|									|
		|									|
		|		   欢迎进入教师系统			|
		|									|
		|___________________________________|
		*/
		printf("-------------------------------\n");
		for(int i = 0;i < 5;i++)
		{
		    if(2 == i)
		    {
		       printf("|       欢迎进入教师系统　　  |\n");
		    }
		    else
		    {
			   printf("|                             |\n");
		    }
		}
		printf("-------------------------------\n");
		//视觉暂留
	    //show_msg();
		//任意键继续
	    //anykey_continue();
		puts("1、添加学生");
		puts("2、删除学生");
		puts("3、修改学生");
		puts("4、查找学生");
		puts("5、录入学生成绩");
		puts("6、重置学生密码");
		puts("7、显示在校所有学生");
		puts("8、显示退学所有学生");
		puts("9、显示密码被锁定的所有学生");
	//	puts("a、解锁学生账号");
		puts("b、退出");
		printf("请输入指令:\n");
		switch(getch())
		{
			case '1': add_student();break;
			case '2': del_student();break;
			case '3': rep_student();break;
			case '4': find_student();break;
			case '5': input_student();break;
			case '6': reset_student();break;
			case '7': show_all_in_student();break;
			case '8': show_all_out_student();break;
			case '9': show_all_lock_student();break;
		//	case 'a': unlock_student();break;
			case 'b': exit_teacher();return;
            default:
			        puts("输入的指令有误!\n");
		
		}
		sleep(1);
	}
}

//封装fgets
char* get_str(char* str,int size)
{
	fgets(str,size,stdin);//会在末尾处产生一个\n
	int len = strlen(str);
	if('\n' == str[len-1])
	{
		str[len-1] = '\0';
	}
	else
	{
         stdin->_IO_read_ptr =stdin->_IO_read_end;
	}
	return str;
}

//添加学生
void add_student(void)
{
     printf("\n%s\n",__func__);//作用：编译时会替换__func__为该语句所在的函数名
	 //找到一个空位置
	 int index = 0;
	 while(stu[index].sex)
	 {
		 index++;
	 }
	 printf("请输入姓名:");
	 get_str(stu[index].name,20);

	 printf("请输入性别(m男/w女):");
     stu[index].sex = getch();
	 printf("%c\n",stu[index].sex);

	stu[index].id = id_student();

	 puts("添加学生成功!");
	anykey_continue();
	 n++;
}

//删除学生
void del_student(void)
{
     printf("\n%s\n",__func__);
	 int del_id1 = 0;
	 int del_id2 = 0;
	 printf("请输入你想要删除学生的学号:\n");
	 scanf("%d",&del_id1);
	 printf("请再次输入学生学号！\n");
	 scanf("%d",&del_id2);
	 if(del_id1 != del_id2)
	 {
		puts("两次输入不一致！操作失败");
	anykey_continue();
	 	return;
	 }
	 for(int i = 0; i<max;i++)
	 {
		 if(del_id1 == stu[i].id )
		 {
			 stu[i].in_out = 1;
			 puts("删除学生成功！可惜!");
			 n--;
	anykey_continue();
			 return;
		 }
	 }
	puts("学号错误，查无此人！");
	return;
}

//查找学生
void find_student(void)
{
     printf("\n%s\n",__func__);
	 char str[20] = {};
	 printf("请输入要查找的学生姓名: \n");
	 get_str(str,20);
	 for(int i = 0; i < 100; i++)
	 {
		 if((!stu[i].in_out) && (stu[i].sex) && (0 == strcmp(str,stu[i].name)))
		 {
		 	 printf("%s %c %d %hhd %hhd %hhd\n",stu[i].name,stu[i].sex,stu[i].id,stu[i].Chinese,stu[i].Math,stu[i].English);
	anykey_continue();
		 	 return;
		 }
	 }

}

//修改学生信息
void rep_student(void)
{
     printf("\n%s\n",__func__);
	 int rep_id = 0;
	 printf("请输入你想要修改的学生学号:");
	 scanf("%d",&rep_id);
	 for(int i = 0;i < 100;i++)
	 {
		 if(!stu[i].in_out && stu[i].sex && rep_id==stu[i].id)
		 {
			printf("请重新输入学生姓名:");
			get_str(stu[i].name,20);

			printf("请重新输入性别(m男/w女):");
			stu[i].sex = getch();
			printf("%c\n",stu[i].sex);
				
			stu[i].id = id_student();
			 
			printf("请重新输入学生成绩:");
			printf("%hhd\n",stu[i].Chinese);
			printf("%hhd\n",stu[i].Math);
			printf("%hhd\n",stu[i].English);
			 
			puts("修改学生成功!");
	anykey_continue();
			return;
			 
		 }
		 
	 }
	 puts("要修改的学生不存在,请重新输入");
	anykey_continue();
}

//录入学生成绩
void input_student(void)
{
     printf("\n%s\n",__func__);
	 int input_id = 0;;
	 printf("请输入你想要录入的学生的学号:");
	 scanf("%d",&input_id);
         stdin->_IO_read_ptr =stdin->_IO_read_end;
	 for(int i = 0;i < 100;i++)
	 {
		 if(!(stu[i].in_out) && stu[i].sex &&  input_id==stu[i].id)
		 {
			 puts("请分别输入语文、数学、英语成绩:");
		    scanf("%hhd%hhd%hhd",&stu[i].Chinese,&stu[i].Math,&stu[i].English);
		    printf("录入成绩成功\n");
			stu[i].sum = stu[i].Chinese+stu[i].Math+stu[i].English;
	anykey_continue();
		    return;
		 }
     }
		    
   
}

//批量录入学生成绩
void input_student_fast(void)
{
}


//重置学生密码
void reset_student(void)
{
     printf("\n%s\n",__func__);
	 int reset_id = 0;
	 printf("请输入你想要重置密码的学生学号:");
	 scanf("%d",&reset_id);
	 for(int i = 0;i < 100;i++)
	 {
		 if(reset_id == stu[i].id && stu[i].lock == 1)
		 {
		    strcpy(stu[i].key,"123456");
		    stu[i].lock = 0;
		    printf("密码重置成功\n");
	anykey_continue();
		    return;
		 }
     }   		 
		
}

//显示所有在校
void show_all_in_student(void)
{
    for(int i = 0;i < 100;i++)
    {
       if(!stu[i].in_out && stu[i].sex)
       {
          printf("%s %c %d %hhd %hhd %hhd\n",stu[i].name,stu[i].sex,stu[i].id,stu[i].Chinese,stu[i].Math,stu[i].English);

       }
    }
	anykey_continue();
}

//显示所有退学
void show_all_out_student(void)
{
      for(int i = 0;i < 100;i++)
    {
       if(stu[i].in_out && stu[i].sex)
       {
          printf("姓名:%s 性别:%c 学号:%d 语文:%hhd 数学:%hhd 英语:%hhd\n",stu[i].name,stu[i].sex,stu[i].id,stu[i].Chinese,stu[i].Math,stu[i].English);

       }
    }
	anykey_continue();
}

//显示所有被锁定账号
void show_all_lock_student(void)
{
    for(int i = 0;i < 100;i++)
    {
       if(stu[i].lock)
       {
          printf("姓名：%s 性别：%c 学号：%d\n",stu[i].name,stu[i].sex,stu[i].id);

       }
    }
	anykey_continue();
}
/*//解锁账号
void unlock_student(void)
{
     
	 for(int i = 0;i < 100;i++)
	 {
		 if(!stu[i].in_out)
		 {
		    strcpy(stu[i].key,"123456");
		    stu[i].lock = 1;
		    printf("解锁成功\n");
		    return;
		 }
     }   
}*/
//退出
void exit_teacher(void)
{

    FILE* fwp = fopen("stu.bin","w");
	if(NULL == fwp)
	{
		puts("文件保存失败!");
		
	}
	else
	{
		fwrite(&stu,sizeof(stu[0]),100,fwp);
	}
		fclose(fwp);
	    fwp = NULL;//指针置空
	FILE* fwp_s = fopen("./data/score.txt","w+");
	if(NULL == fwp_s)
	{
		puts("保存失败!");
		return ;
	}
	for(int i = 0;i<n;i++)
	{
		fscanf(fwp_s,"%hhd %hhd %hhd\n",&stu[i].Chinese,&stu[i].Math,&stu[i].English);
	}
	fclose(fwp_s);
	fwp_s=NULL;
	run_system();
}
 

//自动生成教师ID
int id_teacher(void)
{
	FILE* fp = fopen("./data/tea_id.txt", "r+");
	if(NULL == fp)
	{
		fp = fopen("./data/tea.id.txt","w");
	}
	else
	{
		fscanf(fp,"%d",&tea_id);
		rewind(fp);
	}
	tea_id++;
	fprintf(fp,"%d\n",tea_id);
	fclose(fp);
	return tea_id;
}
