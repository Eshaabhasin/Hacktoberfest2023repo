#include <stdio.h>

void swap(int *a, int *b, int *count) {
    int temp = *a;
    *a = *b;
    *b = temp;
    (*count)++;
}

int partition(int arr[], int low, int high, int *count) {
    int pivot = arr[high];
    int i = (low - 1);
    
    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j], count);
        }
    }
    
    swap(&arr[i + 1], &arr[high], count);
    return (i + 1);
}

void quicksort(int arr[], int low, int high, int *count) {
    if (low < high) {
        int pi = partition(arr, low, high, count);
        
        quicksort(arr, low, pi - 1, count);
        quicksort(arr, pi + 1, high, count);
    }
}

int main() {
    //int arr[] = {62, 14, 5, 27, 72, 11, 90};
    //int arr[7] = {5,11,14,27,62,72,90};
    int arr[7] = {90,72,62,27,14,11,5};
    int n = sizeof(arr) / sizeof(arr[0]);
    int count = 0;

    printf("Original array: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    printf("\n");

    quicksort(arr, 0, n - 1, &count);

    printf("Sorted array: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    
    printf("\nNumber of swaps: %d", count);
    return 0;
}
