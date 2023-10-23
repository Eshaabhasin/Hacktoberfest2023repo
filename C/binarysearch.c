#include <stdio.h>

int bs(int arr[], int size, int key) {
    int low = 0, high = size - 1, mid;
    
    while (low <= high) {
        mid = (low + high) / 2;
        if (arr[mid] == key) {
            return mid;
        }
        else if (arr[mid] < key) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }
    return -1; // element not found
}

int main() {
    int x[20]={76,34,65,24,98,67,54,23,12,82,77,14,6,28,8,7,57,21,58,89};
    int size = 20;
    int element;
    printf("\nEnter the num you want:");
    scanf("%d",&element);
    int index = bs(x, size, element);
    
    if (index == -1) {
        printf("Element not found\n");
    }
    else {
        printf("Element found at index %d\n", index);
    }
    
    return 0;
}

