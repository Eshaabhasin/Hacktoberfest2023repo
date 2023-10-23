#include <stdio.h>

void selectionSort(int arr[], int n) {
    int i, j, minIdx, temp, count = 0;

    for (i = 0; i < n-1; i++) {
        minIdx = i;
        for (j = i+1; j < n; j++) {
            if (arr[j] < arr[minIdx]) {
                minIdx = j;
            }
        }
        if (minIdx != i) {
            temp = arr[i];
            arr[i] = arr[minIdx];
            arr[minIdx] = temp;
            count++;
        }
    }

    printf("Array after sorting: ");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\nNumber of swaps performed: %d", count);
}

int main() {
    int a[7] = {62, 14, 5, 27, 72, 11, 90};

    //int a[7] = {5,11,14,27,62,72,90};

    //int a[7] = {90,72,62,27,14,11,5};

    printf("Original array: ");
    for (int i = 0; i < 7; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");

    selectionSort(a, 7);

    return 0;
}
