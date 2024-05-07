#ifndef REPOSITORY_H
#define REPOSITORY_H

#include "gender.h"
#include "dorm.h"
#include "student.h"

/** 
 * @brief define your structure, enums, globally accessible variables, and function prototypes here.
 * The actual function implementation should be defined in the corresponding source file.
 *
 */

void repository(struct student_t *student, struct dorm_t *dorm, int *dormc, int *studentc);
void fdorm_print(struct dorm_t *dorm, int dormc);
void fdorm_print_detail(struct dorm_t *dorm, int dormc);
void fstudent_print(struct student_t *student, int studentc);
void fstudent_print_detail(struct student_t *student, int studentc);
#endif