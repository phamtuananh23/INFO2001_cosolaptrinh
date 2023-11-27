#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Employee {
    int employeeID;
    char name[50];
    char position[50];
    float salary;
};

void displayEmployee(struct Employee employee) {
    printf("ID: %d\n", employee.employeeID);
    printf("Name: %s\n", employee.name);
    printf("Position: %s\n", employee.position);
    printf("Salary: %.2f\n", employee.salary);
    printf("\n");
}

void displayAllEmployees(struct Employee *employees, int numEmployees) {
    printf("\nEmployee List:\n");
    for (int i = 0; i < numEmployees; ++i) {
        displayEmployee(employees[i]);
    }
}

void addEmployee(struct Employee **employees, int *numEmployees) {
    *employees = (struct Employee *)realloc(*employees, (*numEmployees + 1) * sizeof(struct Employee));

    struct Employee newEmployee;
    printf("nhap nhan vien ID: ");
    scanf("%d", &newEmployee.employeeID);

    printf("nhap ten nhan vien: ");
    scanf("%s", newEmployee.name);

    printf("nhap nghe cua nhan vien: ");
    scanf("%s", newEmployee.position);

    printf("nhap muc luong cua nhan vien: ");
    scanf("%f", &newEmployee.salary);

    (*employees)[*numEmployees] = newEmployee;
    (*numEmployees)++;

    printf("them nhan vien thanh cong!\n");
}

void deleteEmployee(struct Employee **employees, int *numEmployees, int employeeID) {
    for (int i = 0; i < *numEmployees; ++i) {
        if ((*employees)[i].employeeID == employeeID) {
            // D?ch chuy?n các ph?n t? sau v? phía tru?c
            for (int j = i; j < *numEmployees - 1; ++j) {
                (*employees)[j] = (*employees)[j + 1];
            }

            *employees = (struct Employee *)realloc(*employees, (*numEmployees - 1) * sizeof(struct Employee));
            (*numEmployees)--;
            printf("Employee with ID %d deleted successfully!\n", employeeID);
            return;
        }
    }
    printf("Employee with ID %d not found!\n", employeeID);
}

int compareByName(const void *a, const void *b) {
    return strcmp(((struct Employee *)a)->name, ((struct Employee *)b)->name);
}

void sortEmployeesByName(struct Employee *employees, int numEmployees) {
    qsort(employees, numEmployees, sizeof(struct Employee), compareByName);
    printf("Employee list sorted by name!\n");
}

int main() {
    struct Employee *employees = NULL;
    int numEmployees = 0;
    int choice, employeeID;

    do {
        printf("\nHe thong quan li nhan vien\n");
        printf("1. Them nhan vien\n");
        printf("2. Xoa nhan vien\n");
        printf("3. Hien thi tat ca nhan vien\n");
        printf("4. Sap xep nhan vien theo ten\n");
        printf("0. Thoat\n");
        printf("Chon: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addEmployee(&employees, &numEmployees);
                break;
            case 2:
                printf("Chon id cua nhan vien de xoa: ");
                scanf("%d", &employeeID);
                deleteEmployee(&employees, &numEmployees, employeeID);
                break;
            case 3:
                displayAllEmployees(employees, numEmployees);
                break;
            case 4:
                sortEmployeesByName(employees, numEmployees);
                break;
            case 0:
                printf("Dang thoat khoi he thong\n");
                break;
            default:
                printf("vui long thu lai.\n");
                break;
        }
    } while (choice != 0);

    free(employees);

    return 0;
}



