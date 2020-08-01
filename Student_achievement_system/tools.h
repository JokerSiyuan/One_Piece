#ifndef TOOLS_H
#define TOOLS_H
#include <stdbool.h>
#include <string.h>
void get_password(char* pass, size_t len,bool is_show);//接受输入的密码password,可通过调整布尔值，决定是否明文显示
bool cmp_password(char* pass,char* key);//将获取到的password，与结构体中的key对比
void anykey_continue(void);//按任意键继续
bool is_locked(char lock);//判断是否账号被锁
#endif//TOOLS_H
