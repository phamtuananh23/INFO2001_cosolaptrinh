#include <stdio.h>
//bubble sort
void swap(int *xp, int *yp) {
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n-1; i++) {      
        for (int j = 0; j < n-i-1; j++) {         
            if (arr[j] > arr[j+1])
                swap(&arr[j], &arr[j+1]);
        }
    }
}
int main() {
    int arr[] = {38, 62, 27, 12, 42, 31, 96};
    int n = sizeof(arr)/sizeof(arr[0]);
    printf("cac so khai bao ban dau: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    bubbleSort(arr, n);
    printf("\ncac so sau khi sap xep: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    return 0;
}



//selection sort
void swap(int *xp, int *yp) {
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}
void selectionSort(int arr[], int n) {
    int i, j, min_index;
    for (i = 0; i < n-1; i++) {
        min_index = i;
        for (j = i+1; j < n; j++) {
            if (arr[j] < arr[min_index])
                min_index = j;
        }
        swap(&arr[min_index], &arr[i]);
    }
}
int main() {
    int arr[] = {79, 82, 12, 55, 31, 43, 76};
    int n = sizeof(arr)/sizeof(arr[0]);
    printf("cac so dc khai bao ban dau: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);   
    selectionSort(arr, n);
    printf("\ncac so sau khi duoc sap xep bang Selection Sort: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    return 0;
}
