#ifndef STUDENT_H
#define STUDENT_H

#define MAX_NAME 50

typedef struct
{
    int id;
    char name[MAX_NAME];
    float grade;
} Student;

void add_student(Student *student_list, int *count, int id, const char *name, float grade);
void view_student(const Student *student);
void find_student_by_id(const Student *student_list, int count, int id);
void delete_student_by_id(Student *student_list, int *count, int id);
#endif