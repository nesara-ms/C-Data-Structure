#include <stdio.h>
#include <string.h>
struct Project {
    char project_name[50];
    int project_id;
    float project_cost;
};
struct Employee {
    char name[10];
    int employee_id;
    float salary;
    struct Project project; // Nested structure
};
void main() {
    struct Employee e1;
    strcpy(e1.name, "Alex");
    e1.employee_id = 12345;
    e1.salary = 50000.0;

    // Assign values to the nested structure
    strcpy(e1.project.project_name, "Project A");
    e1.project.project_id = 101;
    e1.project.project_cost = 100000.0;

    printf("Name: %s\n", e1.name);
    printf("Employee ID: %d\n", e1.employee_id);
    printf("Salary: %.2f\n", e1.salary);
    printf("Project Name: %s\n", e1.project.project_name);
    printf("Project ID: %d\n", e1.project.project_id);
    printf("Project Cost: %.2f\n", e1.project.project_cost);
}