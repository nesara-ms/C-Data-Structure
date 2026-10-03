#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Employee
{
    int id;
    char name[50];
    char designation[50];
    float basicSalary;
    float allowances;
    float deductions;
    float grossSalary;
    float netSalary;
};

void calculateSalary(struct Employee *e)
{
    e->grossSalary = e->basicSalary + e->allowances;
    e->netSalary = e->grossSalary - e->deductions;
}

void createEmployees(struct Employee *e, int n)
{
    int i;

    for (i = 0; i < n; i++)
    {
        printf("\nEnter details of Employee %d\n", i + 1);

        printf("Employee ID: ");
        scanf("%d", &e[i].id);

        printf("Name: ");
        scanf(" %[^\n]", e[i].name);

        printf("Designation: ");
        scanf(" %[^\n]", e[i].designation);

        printf("Basic Salary: ");
        scanf("%f", &e[i].basicSalary);

        printf("Allowances: ");
        scanf("%f", &e[i].allowances);

        printf("Deductions: ");
        scanf("%f", &e[i].deductions);

        calculateSalary(&e[i]);
    }
}

void displayEmployees(struct Employee *e, int n)
{
    int i;

    printf("\n========== EMPLOYEE PAYROLL DETAILS ==========\n");

    for (i = 0; i < n; i++)
    {
        printf("\nEmployee ID   : %d", e[i].id);
        printf("\nName          : %s", e[i].name);
        printf("\nDesignation   : %s", e[i].designation);
        printf("\nBasic Salary  : %.2f", e[i].basicSalary);
        printf("\nAllowances    : %.2f", e[i].allowances);
        printf("\nDeductions    : %.2f", e[i].deductions);
        printf("\nGross Salary  : %.2f", e[i].grossSalary);
        printf("\nNet Salary    : %.2f\n", e[i].netSalary);
    }
}

void searchEmployee(struct Employee *e, int n)
{
    int id, i, found = 0;

    printf("\nEnter Employee ID to search: ");
    scanf("%d", &id);

    for (i = 0; i < n; i++)
    {
        if (e[i].id == id)
        {
            printf("\nEmployee Found!\n");
            printf("Employee ID  : %d\n", e[i].id);
            printf("Name         : %s\n", e[i].name);
            printf("Designation  : %s\n", e[i].designation);
            printf("Basic Salary : %.2f\n", e[i].basicSalary);
            printf("Allowances   : %.2f\n", e[i].allowances);
            printf("Deductions   : %.2f\n", e[i].deductions);
            printf("Gross Salary : %.2f\n", e[i].grossSalary);
            printf("Net Salary   : %.2f\n", e[i].netSalary);

            found = 1;
            break;
        }
    }

    if (!found)
    {
        printf("\nEmployee ID not found.\n");
    }
}

void updateSalary(struct Employee *e, int n)
{
    int id, i, found = 0;

    printf("\nEnter Employee ID to update salary: ");
    scanf("%d", &id);

    for (i = 0; i < n; i++)
    {
        if (e[i].id == id)
        {
            printf("\nEnter new Basic Salary: ");
            scanf("%f", &e[i].basicSalary);

            printf("Enter new Allowances: ");
            scanf("%f", &e[i].allowances);

            printf("Enter new Deductions: ");
            scanf("%f", &e[i].deductions);

            calculateSalary(&e[i]);

            printf("\nSalary details updated successfully!\n");
            printf("Gross Salary: %.2f\n", e[i].grossSalary);
            printf("Net Salary  : %.2f\n", e[i].netSalary);

            found = 1;
            break;
        }
    }

    if (!found)
    {
        printf("\nEmployee ID not found.\n");
    }
}

int main()
{
    struct Employee *employees;
    int n, choice;

    printf("Enter number of employees: ");
    scanf("%d", &n);

    /* Dynamic memory allocation */
    employees = (struct Employee *)malloc(n * sizeof(struct Employee));

    if (employees == NULL)
    {
        printf("Memory allocation failed!\n");
        return 1;
    }

    do
    {
        printf("\n\n========== EMPLOYEE PAYROLL MANAGEMENT SYSTEM ==========");
        printf("\n1. Create Employee Records");
        printf("\n2. Calculate Gross and Net Salary");
        printf("\n3. Display Employee Payroll Details");
        printf("\n4. Search Employee");
        printf("\n5. Update Salary Details");
        printf("\n6. Exit");

        printf("\n\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                createEmployees(employees, n);
                break;

            case 2:
                for (int i = 0; i < n; i++)
                {
                    calculateSalary(&employees[i]);
                }

                printf("\nSalary calculated successfully!\n");
                break;

            case 3:
                displayEmployees(employees, n);
                break;

            case 4:
                searchEmployee(employees, n);
                break;

            case 5:
                updateSalary(employees, n);
                break;

            case 6:
                printf("\nExiting program...\n");
                break;

            default:
                printf("\nInvalid choice!\n");
        }

    } while (choice != 6);

    /* Free dynamically allocated memory */
    free(employees);

    return 0;
}
