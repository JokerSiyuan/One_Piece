#include "teacher.h"
#include "tools.h"
#include "system.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//显示界面
void show_teacher(void)
{
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
		//登录
		printf("请输入教师工号：\n");
		char tid[9] = {};
		char tkey[7] = {};
		get_str(tid,20);
        for(int i = 0;i < 100;i++)
		{
			if(0 == strcmp(tid,tea[i].id))
			{
				printf("请输入密码：\n");
				get_str(tkey,7);
				if(0 == strcmp(tkey,tea[i].key))
				{
					//swhich,获取键值(添加学生，删除学生，查找学生，修改学生基本信息，录入学生成绩，重置学生密码，显示所有在校学生信息，显示所有退学学生信息，显示被锁定学生，解锁被锁定学生，退出)
		puts("1、添加学生");
		puts("2、删除学生");
		puts("3、修改学生");
		puts("4、查找学生");
		puts("5、录入学生成绩");
		puts("6、重置学生密码");
		puts("7、显示在校所有学生");
		puts("8、显示退学所有学生");
		puts("9、显示密码被锁定的所有学生");
		puts("a、解锁账号");
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
			case 'a': unlock_student();break;
			case 'b': exit_teacher();return;
            default:
			        puts("输入的指令有误!\n");
		
		}
				}
			}
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

	 printf("请输入学生学号:");
	 get_str(stu[index].id,20);
	 
	 puts("添加学生成功!");
}

//删除学生
void del_student(void)
{
     printf("\n%s\n",__func__);
	 char str1[20] = {};
	 char str2[20] = {};
	 printf("请输入你想要删除学生的学号:");
	 get_str(str1,20);
	 get_str(str2,20);
	 FILE* fwp = fopen("stu_out.bin","w+");//w+,写的条件下增加读权限
     printf("%d\n",access((const char*)"tea_dat",F_OK));
     if(NULL == fwp)
     {
	   puts("文件打开失败，请检查权限");
       return;
     }
	 if(0 == strcmp(str1,str2))
	 {
	   for(int i = 0;i < 100;i++)
	   {
		 if(!stu[i].in_out && stu[i].sex && 0 == strcmp(str1,stu[i].id))
		 {
			 stu[i].in_out = 1;
			 for(int j = 0;j < 100;j++)
			 {
			    if(stu[i].in_out)
			    {
			       fwrite(&stu[i],sizeof(stu[i]),1,fwp);
			    }
			 }
			 puts("删除学生成功!");
			 fclose(fwp);
	         fwp = NULL;
			 return;
		 } 
	   }
	 }
	 else
	 {
	   printf("两次输入的学号不同，请重新输入\n");
	 }
	 
	 puts("此学生不存在,请重新输入");
}

//查找学生
void find_student(void)
{
     printf("\n%s\n",__func__);
	 char str[20] = {};
	 printf("请输入要查找的学生姓名或学号:");
	 get_str(str,20);
	 for(int i = 0; i < 100; i++)
	 {
		 if((!stu[i].in_out) && (stu[i].sex) && (0 == strcmp(str,stu[i].name)))
		 {
		 	 printf("%s %c %s %hhd %hhd %hhd\n",stu[i].name,stu[i].sex,stu[i].id,stu[i].Chinese,stu[i].Math,stu[i].English);
		 	 return;
		 }
	 }

}

//修改学生信息
void rep_student(void)
{
     printf("\n%s\n",__func__);
	 char str[20] = {};
	 printf("请输入你想要修改的学生学号:");
	 get_str(str,20);
	 for(int i = 0;i < 100;i++)
	 {
		 if(!stu[i].in_out && stu[i].sex && 0 == strcmp(str,stu[i].id))
		 {
			 printf("请重新输入学生姓名:");
			 get_str(stu[i].name,20);

			 printf("请重新输入性别(m男/w女):");
			 stu[i].sex = getch();
			 printf("%c\n",stu[i].sex);

			 printf("请重新输入学生学号:");
			 get_str(stu[i].id,20);

			 
			 printf("请重新输入学生成绩:");
			 printf("%hhd\n",stu[i].Chinese);
			 printf("%hhd\n",stu[i].Math);
			 printf("%hhd\n",stu[i].English);
			 
			 puts("修改学生成功!");
			 return;
			 
		 }
		 
	 }
	 puts("要修改的学生不存在,请重新输入");
}

//录入学生成绩
void input_student(void)
{
     printf("\n%s\n",__func__);
	 char str[20] = {};
	 printf("请输入你想要录入的学生的学号:");
	 get_str(str,20);
	 for(int i = 0;i < 100;i++)
	 {
		 if(!stu[i].in_out && stu[i].sex && 0 == strcmp(str,stu[i].id))
		 {
		    scanf("%hhd%hhd%hhd",&stu[i].Chinese,&stu[i].Math,&stu[i].English);
		    printf("录入成绩成功\n");
		    return;
		 }
     }   		 
		    
   
}

//重置学生密码
void reset_student(void)
{
     printf("\n%s\n",__func__);
	 char str[20] = {};
	 printf("请输入你想要重置密码的学生学号:");
	 get_str(str,20);
	 for(int i = 0;i < 100;i++)
	 {
		 if(strcmp("123456",stu[i].key) && 0 == strcmp(str,stu[i].id))
		 {
		    strcpy(stu[i].key,"123456");
		    stu[i].lock = 1;
		    printf("密码重置成功\n");
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
          printf("%s %c %s %hhd %hhd %hhd\n",stu[i].name,stu[i].sex,stu[i].id,stu[i].Chinese,stu[i].Math,stu[i].English);
       }
    }

}

//显示所有退学
void show_all_out_student(void)
{
      for(int i = 0;i < 100;i++)
    {
       if(stu[i].in_out && stu[i].sex)
       {
          printf("%s %c %s %hhd %hhd %hhd\n",stu[i].name,stu[i].sex,stu[i].id,stu[i].Chinese,stu[i].Math,stu[i].English);
       }
    }
}

//显示所有被锁定账号
void show_all_lock_student(void)
{
    for(int i = 0;i < 100;i++)
    {
       if(!stu[i].lock)
       {
          printf("%s %c %s %hhd %hhd %hhd\n",stu[i].name,stu[i].sex,stu[i].id,stu[i].Chinese,stu[i].Math,stu[i].English);
       }
    }
}
//解锁账号
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
}
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
		for(int i = 0;i < 100;i++)
		{
			if(stu[i].in_out)
			{
			fwrite(&stu[i],1,sizeof(stu[i]),fwp);
			}	
		}
	}
		fclose(fwp);
	    fwp = NULL;//指针置空

		run_system();
}

