#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct employee {
    int id;
    char name[50];
    int salary;
};

int main() {
    int No_employee, i, sum;
    struct employee *arr;

    printf("Enter the number of employees: ");
    scanf("%d", &No_employee);


    arr = (struct employee *)malloc(No_employee * sizeof(struct employee));


    if (arr == NULL) {
        printf("Memory is not allocated!\n");
        return 1;
    }

    for (i = 0; i < No_employee; i++) {
        printf("\nEmployee %d:\n", i + 1);

        printf("Enter ID: ");
        scanf("%d", &arr[i].id);

        printf("Enter Name: ");
        scanf("%49s", arr[i].name);

        printf("Enter Salary: ");
        scanf("%d", &arr[i].salary);
    }


    printf("\nEmployee Details:\n");
    for (i = 0; i < No_employee; ++i) {
        printf("\nEmployee %d\n", i + 1);
        printf("ID     : %d\n", arr[i].id);
        printf("Name   : %s\n", arr[i].name);
        printf("Salary : %d\n", arr[i].salary);
    }


    sum = 0;
    for (i = 0; i < No_employee; i++) {
        sum = sum + arr[i].salary;
    }

    printf("\nThe total sum of salaries is: %d\n", sum);

    free(arr);

    return 0;
}
