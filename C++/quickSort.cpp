#include <iostream>
#include <vector>

using namespace std;

void quickSort(vector<int> &arr, int low, int high) {
    if (low < high) {
        int pivot = arr[low]; // Choose the first element as the pivot
        int i = low;
        int j = high;

        while (i < j) {
            while (arr[i] <= pivot && i < high) {
                i++;
            }
            while (arr[j] > pivot) {
                j--;
            }
            if (i < j) {
                swap(arr[i], arr[j]);
            }
        }

        swap(arr[low], arr[j);

        // Recursively sort the elements before and after the pivot
        quickSort(arr, low, j - 1);
        quickSort(arr, j + 1, high);
    }
}

int main() {
    vector<int> arr = {12, 11, 10, 5, 6};
    int n = arr.size();

    cout << "Unsorted array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    quickSort(arr, 0, n - 1);

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
