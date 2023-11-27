#include <stdio.h>
int main() {
    int n;
    printf("so sinh vien trong lop it4 : ");
    scanf("%d", &n);
    if (n <= 0) {
        printf("so luong sinh vien khong hop li .\n");
        return 1;  
    }
    int sum = 0; 
    int score;    

    for (int i = 1; i <= n; i++) {
        printf("nhap diem cua sinh vien %d: ", i);
        scanf("%d", &score);  
        if (score < 0) {
            printf("Vui long nhap lai.\n");
            i--;
        } else {
            sum += score;
        }
    }
    float average = (float)sum / n;
    printf("diem trung binh cua lop la : %.2f\n", average);

    return 0;
}


