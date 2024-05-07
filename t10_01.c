// 12s23008 - Ranty Insen Pakpahan
// 12S23015 - Kevin Kristoforus Samosir

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "./libs/dorm.h"
#include "./libs/student.h"

int main(int _argc, char **_argv) 
{
    int looping = 0;
    char command[100];
    struct student_t *murid = malloc(100 * sizeof(struct student_t));
    struct dorm_t *asrama = malloc(100 *sizeof(struct dorm_t));
    int student_num = 0;
    int banyak_dorm = 0;
    
    char DORM[100];
    char MAHASISWA[100];

    FILE *drm;
    FILE *std;
    drm = fopen("./storage/dorm-repository.txt", "r");  // r untuk membaca, a untuk menulis
    std = fopen("./storage/student-repository.txt", "r");

    while (looping != 1 )
    {
        command[0] = '\0';
        short k = 0;
        while (1 == 1)
        {
            char i = getchar();
            if (i == '\n')
            {
                break;
            }
            if (i == '\r')
            {
                continue;
            }
            command[k] = i;
            command[++k] = '\0';
        }

        char *input = strtok(command, "#");

 if (strcmp(input, "student-print-all-detail") == 0)
{
    int counter = 0;
    while(fgets(MAHASISWA, 100 , std) != NULL && counter < 5){
        input = strtok(MAHASISWA, "|");
        strcpy(murid[student_num].id, input);
        input = strtok(NULL, "|");
        strcpy(murid[student_num].name, input);
        input = strtok(NULL, "|");
        strcpy(murid[student_num].year, input);
        input = strtok(NULL, "|");
        if (strcmp(input, "male\n") == 0)
        {
            murid[student_num].gender = 0;
        }
        else if (strcmp(input, "female\n") == 0)
        {
            murid[student_num].gender = 1;
        }
        student_num++;
        counter++;  
    }


            for (int i = 0; i < student_num; i++)
            {
                if (murid[i].gender != 1)
                {
                    printf("%s|%s|%s|male|unassigned\n", murid[i].id, murid[i].name, murid[i].year);
                }
                else 
                {
                    printf("%s|%s|%s|female|unassigned\n", murid[i].id, murid[i].name, murid[i].year);
                }   
            }
        }

        
  if (strcmp(input, "dorm-print-all-detail") == 0)
{
    int counter = 0;
    while(fgets(DORM, 100 , drm) != NULL && counter < 5)
    {
        input = strtok(DORM, "|");
        strcpy(asrama[banyak_dorm].name, input);
        input = strtok(NULL, "|");
        asrama[banyak_dorm].capacity = atoi(input);
        input = strtok(NULL, "|");
        if (strcmp(input, "male\n") == 0)
        {
            asrama[banyak_dorm].gender = 0;
        }   
        else if (strcmp(input, "female\n") == 0)
        {
            asrama[banyak_dorm].gender = 1;
        }
        banyak_dorm++;
        counter++;
    }

    for (int i = 0; i < banyak_dorm; i++)
    {
        if (asrama[i].gender != 1)
        {
            printf("%s|%d|male|%d\n", asrama[i].name, asrama[i].capacity, asrama[i].residents_num);
        }
        else 
        {
            printf("%s|%d|female|%d\n", asrama[i].name, asrama[i].capacity, asrama[i].residents_num);
        }
    } 
}
        
        if (strcmp(input, "---") == 0)
        {
            looping = 1;
        }
    }

    fclose(std);
    fclose(drm);

    return 0;
}