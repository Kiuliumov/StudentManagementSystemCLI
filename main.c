#include <stdio.h>
#include "student.h"

int main()
{
    int choice;

    while (1)
    {
        printf("\nStudent Management System\n");
        printf("1. Add Student\n");
        printf("2. View Students\n");
        printf("3. Search Student\n");
        printf("4. Exit\n");
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
            search_student();
            break;
        case 4:
            return 0;
        default:
            printf("Invalid choice.\n");
        }
    }

    return 0;
}
