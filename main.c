#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int id;
    char name[50];
    int age;
    float grade;
} Student;

int generate_id();
void add_student();
void view_students();
void delete_student_by_id();
void delete_student_from_file(int id);

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

    s.id = generate_id();

    printf("Enter student name: ");
    scanf("%s", s.name);

    printf("Enter student age: ");
    scanf("%d", &s.age);

    printf("Enter student grade: ");
    scanf("%f", &s.grade);

    FILE *file = fopen("students.dat", "ab");

    if (!file)
    {
        printf("Error opening file.\n");
        return;
    }

    fwrite(&s, sizeof(Student), 1, file);
    fclose(file);

    printf("Student added successfully!\n");
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
            printf("\nStudent found:\n");
            printf("ID: %d\nName: %s\nAge: %d\nGrade: %.2f\n",
                   s.id, s.name, s.age, s.grade);
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

void delete_student_from_file(int id)
{
    FILE *file = fopen("students.dat", "rb");
    FILE *temp = fopen("temp.dat", "wb");
    Student s;
    int found = 0;

    if (!file || !temp)
    {
        printf("Error opening file.\n");
        return;
    }

    while (fread(&s, sizeof(Student), 1, file))
    {
        if (s.id != id)
        {
            fwrite(&s, sizeof(Student), 1, temp);
        }
        else
        {
            found = 1;
        }
    }

    fclose(file);
    fclose(temp);

    remove("students.dat");
    rename("temp.dat", "students.dat");

    if (found)
        printf("Student deleted successfully.\n");
    else
        printf("Student with ID %d not found.\n", id);
}

void delete_student_by_id()
{
    int id;
    printf("Enter student ID to delete: ");
    scanf("%d", &id);

    delete_student_from_file(id);
}

int main()
{
    int choice;

    while (1)
    {
        printf("\nStudent Management System\n");
        printf("1. Add Student\n");
        printf("2. View Students\n");
        printf("3. Search Student\n");
        printf("4. Delete Student\n");
        printf("5. Exit\n");
        printf("Choose: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            add_student();
            break;
        case 2:
            view_students();
            break;
        case 3:
            find_student_by_id();
            break;
        case 4:
            delete_student_by_id();
            break;
        case 5:
            return 0;
        default:
            printf("Invalid choice.\n");
        }
    }

    return 0;
}
