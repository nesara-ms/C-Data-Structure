#include <stdio.h>
#include <string.h>

struct Employee {
    char name[50];
    int employee_id;
    float salary;
};
void main() {
    struct Employee e1;
    strcpy(e1.name, "Alex");
    e1.employee_id = 12345;
    e1.salary = 50000.0;

    printf("Name: %s\n", e1.name);
    printf("Employee ID: %d\n", e1.employee_id);
    printf("Salary: %.2f\n", e1.salary);
}