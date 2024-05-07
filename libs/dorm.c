#include "dorm.h"
#include <stdio.h>
#include <string.h>

 

struct dorm_t create_dorm(char *_name, unsigned short _capacity, enum gender_t _gender)
{
    struct dorm_t temp;
    memset(temp.name, '\0', sizeof(temp.name));
    strcpy(temp.name, _name);
    temp.capacity = _capacity;
    temp.residents_num = 0;
    temp.gender = _gender;
    return temp;
}

void print_dorm(struct dorm_t *dorm, int tempshow)
{
    int j;
    for (j = 0; j < tempshow; j++)
    {
        printf("%s|%d|", dorm[j].name, dorm[j].capacity);
        if (dorm[j].gender == GENDER_MALE)
        {
            printf("male\n");
        }
        else
        {
            printf("female\n");
        }
    }
}

void print_dorm_detail(struct dorm_t *dorm, int tempshow)
{
    int j;
    for (j = 0; j < tempshow; j++)
    {
        printf("%s|%d|", dorm[j].name, dorm[j].capacity);
        if (dorm[j].gender == GENDER_MALE)
        {
            printf("male|");
        }
        else
        {
            printf("female|");
        }
        printf("%d\n", dorm[j].residents_num);
    }
}

void CPdorm(struct dorm_t *dorm, struct dorm_t *dorm_modified, int dorm_size)
{
    int i = 0;
    for (i = 0; i < dorm_size; i++)
    {
        strcpy(dorm_modified[i].name, dorm[i].name);
        dorm_modified[i].gender = dorm[i].gender;
        dorm_modified[i].capacity = dorm[i].capacity;
        dorm_modified[i].residents_num = dorm[i].residents_num;
    }
}