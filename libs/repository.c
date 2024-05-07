#include "repository.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/**
 * @brief Define the complete function definition here. Be sure to enlist the prototype of each function
 * defined here in the corresponding header file.
 *
 */

void repository(struct student_t *student, struct dorm_t *dorm, int *dormc, int *studentc)
{
    int temp_size_student = *studentc;
    int temp_size_dorm = *dormc;
    FILE *dorm_repo, *student_repo;
    dorm_repo = fopen("storage/dorm-repository.txt", "r");
    student_repo = fopen("storage/student-repository.txt", "r");
    if (dorm_repo == NULL || student_repo == NULL)
    {
        printf("File not found\n");
        return;
    }
    else
    {
        while (!feof(dorm_repo))
        {
            char fdorm_name[255], fgender[255];
            int fcapacity = 0;
            fscanf(dorm_repo, "%[^|]|%d|%[^\n]\n", fdorm_name, &fcapacity, fgender);
            if (fdorm_name != NULL && fcapacity != 0 && fgender != NULL)
            {
                if (strcmp(fgender, "female") == 0)
                {
                    dorm[temp_size_dorm] = create_dorm(fdorm_name, fcapacity, GENDER_FEMALE);
                }
                else if (strcmp(fgender, "male") == 0)
                {
                    dorm[temp_size_dorm] = create_dorm(fdorm_name, fcapacity, GENDER_MALE);
                }
            }
            temp_size_dorm++;
        }
        while (!feof(student_repo))
        { 
            char fnim[255], fnama[255], fyear[255], fgender[255];
            fscanf(student_repo, "%[^|]|%[^|]|%[^|]|%[^\n]\n", fnim, fnama, fyear, fgender);
            if (fnim != NULL && fnama != NULL && fyear != NULL && fgender != NULL)
            {
                if (strcmp(fgender, "female") == 0)
                {
                    student[temp_size_student] = create_student(fnim, fnama, fyear, GENDER_FEMALE);
                }
                else if (strcmp(fgender, "male") == 0)
                {
                    student[temp_size_student] = create_student(fnim, fnama, fyear, GENDER_MALE);
                }
            }
            temp_size_student += 1;
        }
    }
    *dormc = temp_size_dorm;
    *studentc = temp_size_student;
}

void fdorm_print(struct dorm_t *dorm, int dormc)
{
    FILE *dorm_repo;
    dorm_repo = fopen("storage/dorm-repository.txt", "w");

    if (dorm_repo == NULL)
    {
        printf("File not found\n");
        return;
    }
    else
    {
        int j;
        for (j = 0; j < dormc; j++)
        {
            fprintf(dorm_repo, "%s|%d|", dorm[j].name, dorm[j].capacity);
            if (dorm[j].gender == GENDER_MALE)
            {
                fprintf(dorm_repo, "male\n");
            }
            else
            {
                fprintf(dorm_repo, "female\n");
            }
        }
    }
}

void fdorm_print_detail(struct dorm_t *dorm, int dormc)
{
    FILE *dorm_repo;
    dorm_repo = fopen("storage/dorm-repository.txt", "r");

    if (dorm_repo == NULL)
    {
        printf("File not found\n");
        return;
    }
    else
    {
        int j;
        for (j = 0; j < dormc; j++)
        {
            fprintf(dorm_repo, "%s|%d|", dorm[j].name, dorm[j].capacity);
            if (dorm[j].gender == GENDER_MALE)
            {
                fprintf(dorm_repo, "male|");
            }
            else
            {
                fprintf(dorm_repo, "female|");
            }
            fprintf(dorm_repo, "%d\n", dorm[j].residents_num);
        }
    }
}

void fstudent_print(struct student_t *student, int studentc)
{
    FILE *student_repo;

    student_repo = fopen("storage/student-repository.txt", "w");
    if (student_repo == NULL)
    {
        printf("File not found\n");
        return;
    }
    else
    {
        int j = 0;
        for (j = 0; j < studentc; j++)
        {
            fprintf(student_repo, "%s|%s|%s|", student[j].id, student[j].name, student[j].year);
            if (student[j].gender == GENDER_MALE)
            {
                fprintf(student_repo, "male\n");
            }
            else
            {
                fprintf(student_repo, "female\n");
            }
        }
    }
}

void fstudent_print_detail(struct student_t *student, int studentc)
{
    FILE *student_repo;

    student_repo = fopen("storage/student-repository.txt", "r");
    if (student_repo == NULL)
    {
        printf("File not found\n");
        return;
    }
    else
    {
        int j;
        for (j = 0; j < studentc; j++)
        {
            fprintf(student_repo, "%s|%s|%s|", student[j].id, student[j].name, student[j].year);
            if (student[j].gender == GENDER_MALE)
            {
                fprintf(student_repo, "male|");
            }
            else
            {
                fprintf(student_repo, "female|");
            }
            if (student[j].dorm != NULL)
            {
                fprintf(student_repo, "%s", student[j].dorm->name);
            }
            else
            {
                fprintf(student_repo, "unassigned");
            }
        }
    }
}