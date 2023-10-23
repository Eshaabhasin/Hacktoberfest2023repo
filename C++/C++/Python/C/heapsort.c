#include <stdio.h>

void heapify(int arr[], int n, int i, int *count) {
    int largest = i; 
    int l = 2*i + 1;
    int r = 2*i + 2; 

    if (l < n && arr[l] > arr[largest])
        largest = l;

    if (r < n && arr[r] > arr[largest])
        largest = r;

    if (largest != i) {
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;
        (*count)++;
        heapify(arr, n, largest, count);
    }
}

void heapSort(int arr[], int n) {
    int i, count = 0;
    for (i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i, &count);

    for (i = n-1; i >= 0; i--) {
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;
        count++;
        heapify(arr, i, 0, &count);
    }

    printf("Array after sorting: ");
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\nNumber of swaps performed: %d", count);
}

int main() {
    //int a[7] = {62, 14, 5, 27, 72, 11, 90};
    //int a[7] = {5,11,14,27,62,72,90};
    int a[7] = {90,72,62,27,14,11,5};


    printf("Heap Sort\n");
    printf("Original array: ");
    for (int i = 0; i < 7; i++)
        printf("%d ", a[i]);
    printf("\n");

    heapSort(a, 7);

    return 0;
}
