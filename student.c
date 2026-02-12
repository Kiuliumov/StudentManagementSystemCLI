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

void view_students()
{
    FILE *file = fopen("students.dat", "rb");
    Student s;

    if (!file)
    {
        printf("No students found.\n");
        return;
    }

    printf("ID\tName\tAge\tGrade\n");
    printf("-----------------------------------\n");

    while (fread(&s, sizeof(Student), 1, file))
    {
        printf("%d\t%s\t%d\t%.2f\n", s.id, s.name, s.age, s.grade);
    }

    fclose(file);
}

void find_student_by_id()
{
    int id;
    printf("Enter student ID to find: ");
    scanf("%d", &id);

    FILE *file = fopen("students.dat", "rb");
    Student s;
    int found = 0;

    if (!file)
    {
        printf("No students found.\n");
        return;
    }

    while (fread(&s, sizeof(Student), 1, file))
    {
        if (s.id == id)
        {
            printf("Student found:\n");
            printf("ID: %d\nName: %s\nAge: %d\nGrade: %.2f\n", s.id, s.name, s.age, s.grade);
            found = 1;
            break;
        }
    }

    if (!found)
    {
        printf("Student with ID %d not found.\n", id);
    }

    fclose(file);
}

void delete_student_by_id()
{
    int id;
    printf("Enter student ID to delete: ");
    scanf("%d", &id);

    delete_student_from_file(id);
}
