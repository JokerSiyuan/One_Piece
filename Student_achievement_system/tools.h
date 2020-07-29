#ifndef TOOLS_H
#define TOOLS_H
#include <stdbool.h>
#include <string.h>
void get_password(char* pass, size_t len,bool is_show);//接受输入的密码password,可通过调整布尔值，决定是否明文显示
bool cmp_password(char* pass,char* key);//将获取到的password，与结构体中的key对比
void anykey_continue(void);//按任意键继续
void show_msg(void);//视觉暂留
void rep_password(char* old_key,char* new_key);//修改密码，参数是结构体的key和新接收的password
void reset_password(char* old_key);//重置密码。参数数是结构体的key
bool is_locked(char lock);//判断是否账号被锁
#endif//TOOLS_H
