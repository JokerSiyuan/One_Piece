#ifndef STUDENT_H
#define STUDENT_H
#include <stdio.h>
#include <string.h>
void show_student(void);
void sreach_s(int* p);
void sreach_p(int* p);
void exit_student(void);
void rep_key_stu(int* p);
extern int stu_id;
int stu_cmp_Chinese(const void* p1,const void* p2);
int stu_cmp_Math(const void* p1,const void* p2);
int stu_cmp_English(const void* p1,const void* p2);
int stu_cmp_sum(const void* p1,const void* p2);
void rank_C(void);
void rank_M(void);
void rank_E(void);
void rank_S(void);
#endif//STUDENT_H

