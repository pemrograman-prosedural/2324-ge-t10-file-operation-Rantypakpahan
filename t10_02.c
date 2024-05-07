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
    int banyak_murid = 0;
    int banyak_asrama = 0;
    
    char DORM[100];
    char MAHASISWA[100];

    FILE *drm;
    FILE *std;
    drm = fopen("./storage/dorm-repository.txt", "r");  // r untuk membaca, a untuk menulis
    std = fopen("./storage/student-repository.txt", "r");

    int counter = 0;
    while(fgets(DORM, 100 , drm) != NULL && counter < 5){
        DORM[strcspn(DORM, "\n\r")] = '\r';
        char *input = strtok(DORM, "|");
            strcpy(asrama[banyak_asrama].name, input);
            input = strtok(NULL, "|");
            asrama[banyak_asrama].capacity = atoi(input);
            input = strtok(NULL, "|");
            if (strcmp(input, "male\r") == 0)
            {
                asrama[banyak_asrama].gender = 0;
            }
            else if (strcmp(input, "female\r") == 0)
            {
                asrama[banyak_asrama].gender = 1;
            }
            banyak_asrama++;
            counter++;
    }
    
    while(fgets(MAHASISWA, 100 , std) != NULL && counter < 5){
        MAHASISWA[strcspn(MAHASISWA, "\n\r")] = '\r';
        char *input = strtok(MAHASISWA, "|");
            strcpy(murid[banyak_murid].id, input);
            input = strtok(NULL, "|");
            strcpy(murid[banyak_murid].name, input);
            input = strtok(NULL, "|");
            strcpy(murid[banyak_murid].year, input);
            input = strtok(NULL, "|");
            if (strcmp(input, "male\r") == 0)
            {
                murid[banyak_murid].gender = 0;
            }
            else if (strcmp(input, "female\r") == 0)
            {
                murid[banyak_murid].gender = 1;
            }
            banyak_murid++;
            counter++;
              
    }
    fclose(drm);
    fclose(std);

    drm = fopen("./storage/dorm-repository.txt", "a");  // r untuk membaca, a untuk menulis
    std = fopen("./storage/student-repository.txt", "a");

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
        std = fopen("./storage/student-repository.txt", "a");
        if (strcmp(input, "student-add") == 0)
        {
            input = strtok(NULL, "#");
            strcpy(murid[banyak_murid].id, input);
            input = strtok(NULL, "#");
            strcpy(murid[banyak_murid].name, input);
            input = strtok(NULL, "#");
            strcpy(murid[banyak_murid].year, input);
            input = strtok(NULL, "#");
            if (strcmp(input, "male") == 0)
            {
                murid[banyak_murid].gender = 0;
            }
            else if (strcmp(input, "female") == 0)
            {
                murid[banyak_murid].gender = 1;
            }

            if (murid[banyak_murid].gender == 0)
            {
                fprintf(std, "%s|%s|%s|male\n", murid[banyak_murid].id, murid[banyak_murid].name, murid[banyak_murid].year);
            }   else {
                fprintf(std, "%s|%s|%s|female\n", murid[banyak_murid].id, murid[banyak_murid].name, murid[banyak_murid].year);
            }
            banyak_murid++;
            fclose(std);
        }
        if (strcmp(input, "student-print-all") == 0)
        {
            for (int i = 0; i < banyak_murid; i++)
            {
                if (murid[i].gender != 1)
            {
                printf("%s|%s|%s|male\n", murid[i].id, murid[i].name, murid[i].year);
                
            }
            else 
            {
                printf("%s|%s|%s|female\n", murid[i].id, murid[i].name, murid[i].year);
            }
            } 
        }
     
        if (strcmp(input, "student-print-all-detail") == 0)
        {
            for (int i = 0; i < banyak_murid; i++)
            {
                if (murid[i].gender != 1)
                {
                    if (murid[i].dorm != NULL)
                    {
                        printf("%s|%s|%s|male|%s\n", murid[i].id, murid[i].name, murid[i].year, murid[i].dorm->name);
                    }   else {
                        printf("%s|%s|%s|male|unassigned\n", murid[i].id, murid[i].name, murid[i].year);
                    }
                }
                else 
                {
                    if (murid[i].dorm != NULL)
                    {
                        printf("%s|%s|%s|female|%s\n", murid[i].id, murid[i].name, murid[i].year, murid[i].dorm->name);
                    }   else {
                        printf("%s|%s|%s|female|unassigned\n", murid[i].id, murid[i].name, murid[i].year);
                    }
                }   
            }
        }
        

        if (strcmp(input, "dorm-add") == 0)
        {
            input = strtok(NULL, "#");
            strcpy(asrama[banyak_asrama].name, input);
            input = strtok(NULL, "#");
            asrama[banyak_asrama].capacity = atoi(input);
            input = strtok(NULL, "#");
            if (strcmp(input, "male") == 0)
            {
                asrama[banyak_asrama].gender = 0;
            }
            else if (strcmp(input, "female") == 0)
            {
                asrama[banyak_asrama].gender = 1;
            }
            asrama[banyak_asrama].residents_num = 0;
            
            if (asrama[banyak_asrama].gender == 0)
            {
                fprintf(drm, "%s|%d|male\n", asrama[banyak_asrama].name, asrama[banyak_asrama].capacity);
            }   else {
                fprintf(drm, "%s|%d|female\n", asrama[banyak_asrama].name, asrama[banyak_asrama].capacity);
            }
            banyak_asrama++;
            
        }
        if (strcmp(input, "dorm-print-all-detail") == 0)
        {
            for (int i = 0; i < banyak_asrama; i++)
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
        if (strcmp(input, "dorm-print-all") == 0)
        {
            for (int i = 0; i < banyak_asrama; i++)
            {
                if (asrama[i].gender != 1)
                {
                    printf("%s|%d|male\n", asrama[i].name, asrama[i].capacity);
                }
                else 
                {
                    printf("%s|%d|female\n", asrama[i].name, asrama[i].capacity);
                }   
            }
        }

        if (strcmp(input, "assign-student") == 0)
        {
            int indexMurid = 0;
            int indexAsrama = 0;
            char *nim = strtok(NULL, "#");
            char *namaAsrama = strtok(NULL, "#");
            for (int i = 0; i < banyak_murid; i++)
            {
                if(strcmp(nim, murid[i].id) == 0 )
                {
                    indexMurid = i;
                } 
                
            }

            for (int i = banyak_asrama; i >= 0 ; i--)
            {
                if (strcmp(namaAsrama, asrama[i].name) == 0)
                {
                    indexAsrama = i;
                }
            }
            
            if (asrama[indexAsrama].capacity > asrama[indexAsrama].residents_num)
            {
                if (murid[indexMurid].gender == asrama[indexAsrama].gender)
                {
                    murid[indexMurid].dorm = &asrama[indexAsrama];
                    asrama[indexAsrama].residents_num++;
                }   
            }
        }

        if (strcmp(input, "---") == 0)
        {
            looping = 1;
        }
    }

    fclose(drm);
    fclose(std);

    return 0;
}
