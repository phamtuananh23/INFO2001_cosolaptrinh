#include<stdio.h> 
// tuyen tinh  
int linearSearch(int arr[], int n, int x) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == x) {
            return i;  
        }
    }
    return -1;  
}
int main() {
    int arr[] = {31, 42, 79, 1, 87, 92};
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 1;
    int result = linearSearch(arr, n, x);
    if (result != -1) {
        printf("Gia tri %d duoc tim thay.\n", x, result);
    } else {
        printf("Gia tri %d khong ton tai .\n", x);
    }
    return 0;
}
   
// nhi phan 
int binarySearch(int arr[], int left, int right, int x) {
    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == x) {
            return mid; 
}
        if (arr[mid] < x) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1; 
}

int main() {
    int arr[] = {1, 2, 4, 5, 7, 9};
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 5;

    int result = binarySearch(arr, 0, n - 1, x);

    if (result != -1) {
        printf("gia tri %d duoc tim thay vi tri %d \n", x, result);
    } else {
        printf("gai tri %d khong ton tai.\n", x);
    }

    return 0;
}
								


