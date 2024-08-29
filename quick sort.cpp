#include<iostream>
using namespace std;

int partition(int arr[], int s, int e) {
    int count = 0; // Initialize count
    int pivot = arr[s];
    for (int i = s + 1; i <= e; i++) {
        if (arr[i] < pivot) {
            count++;
        }
    }
    int pivotindex = s + count;
    swap(arr[pivotindex], arr[s]);

    // Left and right side elements around the pivot
    int i = s, j = e;
    while (i < pivotindex && j > pivotindex) {
        while (i < pivotindex && arr[i] < pivot) { // Fix condition
            i++;
        }
        while (j > pivotindex && arr[j] > pivot) { // Fix condition
            j--;
        }
        if (i < pivotindex && j > pivotindex) {
            swap(arr[i++], arr[j--]);
        }
    }

    return pivotindex;
}

void quicksort(int arr[], int s, int e) {
    // Base case
    if (s >= e) {
        return;
    }
    int p = partition(arr, s, e);
    // Sort left side
    quicksort(arr, s, p - 1);
    // Sort right side
    quicksort(arr, p + 1, e);
}

int main() {
    int arr[] = {1, 2, 3, 4, 6, 79, 34};
    int n = sizeof(arr) / sizeof(arr[0]);
    quicksort(arr, 0, n - 1);
    for (int i = 0; i < n; i++) { // Fix loop condition
        cout << arr[i] << " ";
    } 
    cout << endl;
    return 0;
}
