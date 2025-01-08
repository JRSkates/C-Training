#include <stdio.h>
#include <string.h>

int main() {
     struct Employee {
        int id;
        char name[50];
        char position[50];
        float salary;
    };

    struct Employee e1 = {1, "John Doe", "Software Engineer", 80000.0};
    struct Employee e2 = {2, "Jog Bloggs", "Solutions Architect", 65000.0};

    printf("Employee ID %d\n", e1.id);
    printf("Employee Name: %s\n", e1.name);
    printf("Employee Position: %s\n", e1.position);
    printf("Employee Salary: £%.2f\n", e1.salary);

    printf("Employee ID %d\n", e2.id);
    printf("Employee Name: %s\n", e2.name);
    printf("Employee Position: %s\n", e2.position);
    printf("Employee Salary: £%.2f\n", e2.salary);
}

// gcc -o struct_values struct_values.c
// ./struct_values

