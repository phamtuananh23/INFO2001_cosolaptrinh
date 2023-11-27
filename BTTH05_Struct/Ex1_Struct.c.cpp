#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Student {
    int id;
    char name[50];
    float gpa;
};

void displayStudent(struct Student student) {
    printf("ID: %d\n", student.id);
    printf("Name: %s\n", student.name);
    printf("GPA: %.2f\n", student.gpa);
}

int main() {
    int n;
    printf("nhap so luong sinh vien: ");
    scanf("%d", &n);
    struct Student *students = (struct Student *)malloc(n * sizeof(struct Student));
    for (int i = 0; i < n; ++i) {
        printf("nhap thong tin cua sinh vien %d:\n", i + 1);
        students[i].id = i + 1;
        printf("ten: ");
        scanf("%s", students[i].name);
        printf("GPA: ");
        scanf("%f", &students[i].gpa);
    }
    printf("\n hien thi lai thong tin cua sinh vien:\n");
    for (int i = 0; i < n; ++i) {
        displayStudent(students[i]);
    }
    int updateId;
    printf("\n nhap thong tin cua sinh vien tren id: ");
    scanf("%d", &updateId);

    for (int i = 0; i < n; ++i) {
        if (students[i].id == updateId) {
            printf("nhap thong tin moi cho sinh vien %d:\n", updateId);
            printf("ten: ");
            scanf("%s", students[i].name);
            printf("GPA: ");
            scanf("%f", &students[i].gpa);
            break;
        }
    }
    printf("\nhien thi tat ca thong tin sinh vien sau khi cap nhat:\n");
    for (int i = 0; i < n; ++i) {
        displayStudent(students[i]);
    }
    free(students);

    return 0;
}

