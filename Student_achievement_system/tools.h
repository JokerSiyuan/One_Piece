#ifndef TOOLS_H
#define TOOLS_H

void get_password(char* pass, size_t len,bool is_show);
void cmp_password(char* pass,char* key);
void anykey_continue(void);
void show_msg(void);
void login(void);
char rep_password(char* pass,char* new_key);
char reset_password(char* pass);
#endif//TOOLS_H
