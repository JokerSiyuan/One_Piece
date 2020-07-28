#include <stdio.h>
#include <string.h>
#include <getch.h>
#include "tools.h"


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
				index--;
				is_show && printf("\b \b");
			}
			continue;
		}

		pass[index++] = val;
		is_show && printf("*");
	}

	pass[index] = '\0';
	printf("\n");
}

//密码对比函数
void cmp_password(char* pass,char* key)
{
	
}

//登录函数（如果是第一次要强制改密码）
void login(void)
{
	//判断密码是否为初始密码(123456)是的话则要强制改密码

	//	
}

//任意建继续
void anykey_continue(void)
{
}

//视觉暂留（1.5秒）
void show_msg(void)
{
}

//改密码
char rep_password(char* pass,char* new_key)
{
}

//重置密码为123456
char reset_password(char* pass)
{
}
