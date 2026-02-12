#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "student.h"
#include "file.h"

int generate_id()
{
    FILE *file = fopen("id_counter.txt", "r+");
    int id = 0;

    if (!file)
    {
        file = fopen("id_counter.txt", "w+");
        id = 1;
    }
    else
    {
        fscanf(file, "%d", &id);
        id++;
    }

    rewind(file);
    fprintf(file, "%d", id);
    fclose(file);

    return id;
}

void add_student()
{
    Student s;

    int id = generate_id();
    s.id = id;

    printf("Enter student name: ");
    scanf("%s", s.name);

    printf("Enter student age: ");
    scanf("%d", &s.age);

    save_student(s);
}
