#include <stdio.h>

void merge(int arr[], int l, int m, int r, int *count) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    i = 0;
    j = 0;
    k = l;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        (*count)++;
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int l, int r, int *count) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m, count);
        mergeSort(arr, m + 1, r, count);
        merge(arr, l, m, r, count);
    }
}

int main() {
    //int a[7] = {62, 14, 5, 27, 72, 11, 90};
    //int a[7] = {5,11,14,27,62,72,90};
    int a[7] = {90,72,62,27,14,11,5};
    int count = 0;

    printf("Merge Sort\n");
    printf("Original array: ");
    for (int i = 0; i < 7; i++)
        printf("%d ", a[i]);
    printf("\n");

    mergeSort(a, 0, 6, &count);

    printf("Array after sorting: ");
    for (int i = 0; i < 7; i++)
        printf("%d ", a[i]);
    printf("\nNumber of swaps performed: %d", count);

    return 0;
}
