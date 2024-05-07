#include "student.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * @brief Define the complete function definition here. Be sure to enlist the prototype of each function
 * defined here in the corresponding header file.
 *
 */

struct student_t create_student(char *_id, char *_name, char *_year, enum gender_t _gender)
{
    struct student_t temp;

    memset(temp.id, '\0', sizeof(temp.id));
    memset(temp.name, '\0', sizeof(temp.name));
    memset(temp.year, '\0', sizeof(temp.year));
    strcpy(temp.id, _id);
    strcpy(temp.name, _name);
    strcpy(temp.year, _year);
    temp.dorm = NULL;

    temp.gender = _gender;
    return temp;
}

void print_student(struct student_t *student, int tempshow)
{
    int j;
    for (j = 0; j < tempshow; j++)
    {
        printf("%s|%s|%s|", student[j].id, student[j].name, student[j].year);
        if (student[j].gender == GENDER_MALE)
        {
            printf("male\r\n");
        }
        else
        {
            printf("female\r\n");
        }
    }
}

void print_student_details(struct student_t *student, int tempallshow)
{
    int j;
    for (j = 0; j < tempallshow; j++)
    {
        printf("%s|%s|%s|", student[j].id, student[j].name, student[j].year);
        if (student[j].gender == GENDER_MALE)
        {
            printf("male|");
        }
        else 
        {
            printf("female|");
        }
        if (student[j].dorm != NULL)
        {
            printf("%s\r\n", student[j].dorm->name);
        }
        else
        {
            printf("unassigned\r\n");
        }
    }
}

void assign_student(struct student_t *student, struct dorm_t *dorm, char *nim, char *ldorm, int size_student, int size_dorm)
{
    int i;
    int temp_dorm = 0;
    for (i = 0; i < size_dorm; i++)
    {
        if (strcmp(dorm[i].name, ldorm) == 0)
        {
            temp_dorm = i;
        }
    }
    for (i = 0; i < size_student; i++)
    {
        if (strcmp(student[i].id, nim) == 0)
        {
            if (student[i].gender == dorm[temp_dorm].gender)
            {
                if (dorm[temp_dorm].capacity > dorm[temp_dorm].residents_num)
                {
                    student[i].dorm = &dorm[temp_dorm];
                    strcpy(student[i].dorm->name, ldorm);
                    dorm[temp_dorm].residents_num++;
                }
            }
        }
    }
}

void move_student(struct student_t *student, struct dorm_t *dorm, char *nim, char *ldorm, int size_student, int size_dorm)
{
    int i;
    int dorm_temp = 0;
    int student_temp = 0;
    char dormname_temp[255];
    for (i = 0; i < size_dorm; i++)
    {
        if (strcmp(dorm[i].name, ldorm) == 0)
        {
            dorm_temp = i;
        }
    }
    for (i = 0; i < size_student; i++)
    {
        if (strcmp(student[i].id, nim) == 0)
        {
            student_temp = i;
        }
    }

    if (student[student_temp].dorm != NULL)
    {
        strcpy(dormname_temp, student[student_temp].dorm->name);
        for (i = 0; i < size_dorm; i++)
        {
            if (strcmp(dorm[i].name, dormname_temp) == 0)
            {
                dorm[i].residents_num--;
            }
        }
    }
    else
    {
        student[student_temp].dorm = malloc(1 * sizeof(struct dorm_t));
    }
    strcpy(student[student_temp].dorm->name, ldorm);
    dorm[dorm_temp].residents_num++;
}

void dorm_empty(struct student_t *students, struct dorm_t *dorm, char *dormtemp, int studentsize, int dormsize)
{
    int i = 0;
    for (i = 0; i < studentsize; i++)
    {
        if (students[i].dorm != NULL)
        {
            if (strcmp(students[i].dorm->name, dormtemp) == 0)
            {
                free(students[i].dorm);
                students[i].dorm = NULL;
            }
        }
    }

    for (i = 0; i < dormsize; i++)
    {
        if (strcmp(dorm[i].name, dormtemp) == 0)
        {
            dorm[i].residents_num = 0;
        }
    }
}

void CPstudent(struct student_t *students, struct student_t *student_modif, int studentsize)
{
    int i;
    for (i = 0; i < studentsize; i++)
    {
        strcpy(student_modif[i].name, students[i].name);
        strcpy(student_modif[i].id, students[i].id);
        strcpy(student_modif[i].year, students[i].year);
        student_modif[i].gender = students[i].gender;
        if (students[i].dorm != NULL)
        {
            student_modif[i].dorm = malloc(1 * sizeof(struct dorm_t));
            strcpy(student_modif[i].dorm->name, students[i].dorm->name);
        }
        else
        {
            student_modif[i].dorm = NULL;
        }
    }
}