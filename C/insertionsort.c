#include <stdio.h>

void insertionSort(int arr[], int n) {
    int i, j, key, count = 0;

    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j+1] = arr[j];
            j = j - 1;
            count++;
        }
        arr[j+1] = key;
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

    insertionSort(a, 7);

    return 0;
}
