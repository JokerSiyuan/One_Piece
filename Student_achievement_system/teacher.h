#ifndef TEACHER_H
#define TEACHER_H

extern int tea_id;
void show_teacher(void);
void add_student(void);
void find_student(void);
void del_student(void);
void input_student(void);
void rep_student(void);
void show_all_in_student(void);
void reset_student(void);
void show_all_lock_student(void);
void show_all_out_student(void);
void unlock_student(void);
void exit_teacher(void);
char* get_str(char* str,int size);
int id_teacher(void);
void input_student_fast(void);
#endif//TEACHER_H
