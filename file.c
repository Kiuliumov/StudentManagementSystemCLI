#include <stdio.h>
#include "file.h"

void save_student(Student s)
{
    FILE *file = fopen("students.txt", "a");
    fprintf(file, "%d %s %.2f\n", s.id, s.name, s.grade);
    fclose(file);
}

void load_students()
{
    FILE *file = fopen("students.txt", "r");
    Student s;

    if (!file)
    {
        printf("No records found.\n");
        return;
    }

    while (fscanf(file, "%d %s %f\n", &s.id, s.name, &s.grade) != EOF)
    {
        printf("%d | %s | %.2f\n", s.id, s.name, s.grade);
    }

    fclose(file);
}
