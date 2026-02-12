#ifndef STUDENT_H
#define STUDENT_H

#define MAX_NAME 50

typedef struct
{
    int id;
    char name[MAX_NAME];
    int age;
    float grade;
} Student;

int generate_id();
void add_student();
void view_student();
void find_student_by_id();
void delete_student_by_id();
#endif