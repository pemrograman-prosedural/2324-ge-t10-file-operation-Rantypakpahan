#ifndef STUDENT_H
#define STUDENT_H

#include "gender.h"
#include "dorm.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct student_t
{
    char id[12];
    char name[40];
    char year[5];
    enum gender_t gender;
    struct dorm_t *dorm;
};


struct student_t create_student(char *_id, char *_name, char *_year,
                                enum gender_t _gender);
void print_student_details(struct student_t *student, int tempallshow);
void print_student(struct student_t *student, int tempshow);
void move_student(struct student_t *student, struct dorm_t *dorm, char *nim, char *ldorm, int size_student, int size_dorm);
void assign_student(struct student_t *student, struct dorm_t *dorm, char *nim, char *ldorm, int size_student, int size_dorm);
void dorm_empty(struct student_t *students, struct dorm_t *dorm, char *dormtemp, int studentsize, int dormsize);
void CPstudent(struct student_t *students, struct student_t *student_modif, int studentsize);
#endif
