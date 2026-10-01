#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SUBJECTS 3

struct Student
{
    char usn[20];
    char name[50];
    int semester;
    float marks[SUBJECTS];
    float average;
    char grade;
};

struct Student *students = NULL;
int count = 0;

/* Calculate average and grade */
void calculateGrade(struct Student *s)
{
    int i;
    float sum = 0;

    for (i = 0; i < SUBJECTS; i++)
    {
        sum += s->marks[i];
    }

    s->average = sum / SUBJECTS;

    if (s->average >= 90)
        s->grade = 'A';
    else if (s->average >= 80)
        s->grade = 'B';
    else if (s->average >= 70)
        s->grade = 'C';
    else if (s->average >= 60)
        s->grade = 'D';
    else if (s->average >= 50)
        s->grade = 'E';
    else
        s->grade = 'F';
}

/* Create student record */
void createStudent()
{
    int i;

    students = realloc(students, (count + 1) * sizeof(struct Student));

    if (students == NULL)
    {
        printf("Memory allocation failed!\n");
        exit(1);
    }

    printf("\nEnter USN: ");
    scanf("%s", students[count].usn);

    printf("Enter Name: ");
    scanf(" %[^\n]", students[count].name);

    printf("Enter Semester: ");
    scanf("%d", &students[count].semester);

    printf("Enter marks for %d subjects:\n", SUBJECTS);

    for (i = 0; i < SUBJECTS; i++)
    {
        printf("Subject %d: ", i + 1);
        scanf("%f", &students[count].marks[i]);
    }

    calculateGrade(&students[count]);

    count++;

    printf("\nStudent record created successfully!\n");
}

/* Display all students */
void displayStudents()
{
    int i, j;

    if (count == 0)
    {
        printf("\nNo student records found.\n");
        return;
    }

    printf("\n---------- STUDENT RECORDS ----------\n");

    for (i = 0; i < count; i++)
    {
        printf("\nStudent %d\n", i + 1);
        printf("USN       : %s\n", students[i].usn);
        printf("Name      : %s\n", students[i].name);
        printf("Semester  : %d\n", students[i].semester);

        printf("Marks     : ");
        for (j = 0; j < SUBJECTS; j++)
        {
            printf("%.2f ", students[i].marks[j]);
        }

        printf("\nAverage   : %.2f\n", students[i].average);
        printf("Grade     : %c\n", students[i].grade);
    }
}

/* Search student by USN */
void searchStudent()
{
    char usn[20];
    int i;

    printf("\nEnter USN to search: ");
    scanf("%s", usn);

    for (i = 0; i < count; i++)
    {
        if (strcmp(students[i].usn, usn) == 0)
        {
            printf("\nStudent Found!\n");
            printf("USN       : %s\n", students[i].usn);
            printf("Name      : %s\n", students[i].name);
            printf("Semester  : %d\n", students[i].semester);
            printf("Average   : %.2f\n", students[i].average);
            printf("Grade     : %c\n", students[i].grade);
            return;
        }
    }

    printf("\nStudent with USN %s not found.\n", usn);
}

/* Update student details */
void updateStudent()
{
    char usn[20];
    int i, j;

    printf("\nEnter USN to update: ");
    scanf("%s", usn);

    for (i = 0; i < count; i++)
    {
        if (strcmp(students[i].usn, usn) == 0)
        {
            printf("\nEnter new name: ");
            scanf(" %[^\n]", students[i].name);

            printf("Enter new semester: ");
            scanf("%d", &students[i].semester);

            printf("Enter new marks:\n");

            for (j = 0; j < SUBJECTS; j++)
            {
                printf("Subject %d: ", j + 1);
                scanf("%f", &students[i].marks[j]);
            }

            calculateGrade(&students[i]);

            printf("\nStudent record updated successfully!\n");
            return;
        }
    }

    printf("\nStudent not found.\n");
}

/* Delete student by USN */
void deleteStudent()
{
    char usn[20];
    int i, j;

    printf("\nEnter USN to delete: ");
    scanf("%s", usn);

    for (i = 0; i < count; i++)
    {
        if (strcmp(students[i].usn, usn) == 0)
        {
            for (j = i; j < count - 1; j++)
            {
                students[j] = students[j + 1];
            }

            count--;

            if (count == 0)
            {
                free(students);
                students = NULL;
            }
            else
            {
                students = realloc(students,
                                   count * sizeof(struct Student));
            }

            printf("\nStudent record deleted successfully!\n");
            return;
        }
    }

    printf("\nStudent not found.\n");
}

/* Main function */
int main()
{
    int choice;

    while (1)
    {
        printf("\n\n===== STUDENT RECORD MANAGEMENT =====");
        printf("\n1. Create Student Record");
        printf("\n2. Display All Students");
        printf("\n3. Search Student by USN");
        printf("\n4. Update Student");
        printf("\n5. Delete Student");
        printf("\n6. Exit");

        printf("\n\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                createStudent();
                break;

            case 2:
                displayStudents();
                break;

            case 3:
                searchStudent();
                break;

            case 4:
                updateStudent();
                break;

            case 5:
                deleteStudent();
                break;

            case 6:
                free(students);
                printf("\nProgram ended.\n");
                return 0;

            default:
                printf("\nInvalid choice!\n");
        }
    }

    return 0;
}
