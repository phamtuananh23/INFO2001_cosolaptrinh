#include <stdio.h>
#include <stdlib.h>
#include <string.h>
                                // sap xep theo ten 
struct Student {
    int id;
    char name[50];
    float gpa;
};
int compareByName(const void *a, const void *b) {
    return strcmp(((struct Student *)a)->name, ((struct Student *)b)->name);
}

void displayStudent(struct Student student) {
    printf("ID: %d\n", student.id);
    printf("Name: %s\n", student.name);
    printf("GPA: %.2f\n", student.gpa);
    printf("\n");
}

int main() {
    int n; 
    printf("nhap so luong sinh vien: ");
    scanf("%d", &n);

    struct Student *students = (struct Student *)malloc(n * sizeof(struct Student));

    for (int i = 0; i < n; ++i) {
        printf("nhap thong tin cua sinh vien %d:\n", i + 1);
        students[i].id = i + 1;
        printf("Name: ");
        scanf("%s", students[i].name);
        printf("GPA: ");
        scanf("%f", &students[i].gpa);
    }

    qsort(students, n, sizeof(struct Student), compareByName);

    printf("\n hien thi lai thong tin cua sinh vien sau khi sap xep :\n");
    for (int i = 0; i < n; ++i) {
        displayStudent(students[i]);
    }

    free(students);

    return 0;
}
                               // sap xep theo diem so 
struct Student {
    int id;
    char name[50];
    float gpa;
};

int compareByGPA(const void *a, const void *b) {
  
    if (((struct Student *)a)->gpa > ((struct Student *)b)->gpa) {
        return -1; 
    } else if (((struct Student *)a)->gpa < ((struct Student *)b)->gpa) {
        return 1; 
    } else {
        return 0; 
    }
}
 
void displayStudent(struct Student student) {
    printf("ID: %d\n", student.id);
    printf("Name: %s\n", student.name);
    printf("GPA: %.2f\n", student.gpa);
    printf("\n");
}

int main() {
    int n; 
    printf("nhap so luong sinh vien: ");
    scanf("%d", &n);

    struct Student *students = (struct Student *)malloc(n * sizeof(struct Student));

    for (int i = 0; i < n; ++i) {
        printf("thong tin sinh vien %d:\n", i + 1);
        students[i].id = i + 1;
        printf("Name: ");
        scanf("%s", students[i].name);
        printf("GPA: ");
        scanf("%f", &students[i].gpa);
    }

    qsort(students, n, sizeof(struct Student), compareByGPA);
 
    printf("\n thong tin sinh vien sau khi sap xep:\n");
    for (int i = 0; i < n; ++i) {
        displayStudent(students[i]);
    }
    
    free(students);

    return 0;
}
 

