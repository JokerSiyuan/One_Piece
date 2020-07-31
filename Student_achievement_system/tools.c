#include <ctype.h>
#include <unistd.h>
#include <stdbool.h>
#include <stdio.h>
#include "tools.h"
#include "system.h"

//接收密码函数
void get_password(char* pass, size_t len,bool is_show)
{
	size_t index= 0;
	while(index < len-1)
	{
		int val = getch();
		if('\n' == val) break;

		if(127 == val)
		{
			if(index > 0)
			{
				(index)--;
				is_show && printf("\b \b");
			}
			continue;
		}

		pass[(index)++] = val;
		is_show && printf("*");
	}

	pass[index] = '\0';
	printf("\n");
}

//密码对比函数
bool cmp_password(char* pass,char* key)
{
	if(0 == strcmp(pass,key))
	{
		return true;
	}
	else
	{
		return false;
	}
}


//任意建继续
void anykey_continue(void)
{
	stdin->_IO_read_ptr = stdin->_IO_read_end;
	puts("任意键继续...");
	getch();
}

//视觉暂留（1.5秒）
/*void show_msg(void)
{
	printf("%s",msg);
	fflush(stdout);
	usleep(sec*1000000);
}*/

//改密码
void rep_password(char* old_key,char* new_key)
{
	strcpy(old_key,new_key);//注意old是结构体.key的值
}

//重置密码为123456
/*void reset_password(char* old_key)
{
	*old_key = "123456";
}*/


//判断是否被锁
bool is_locked(char lock)
{
	if(0 == lock)
	{
		return true;
	}
	else
	{
		return false;
	}
}


