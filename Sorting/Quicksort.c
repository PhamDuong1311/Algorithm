// Problem: https://www.hackerearth.com/practice/algorithms/sorting/quick-sort/practice-problems/algorithm/card-game-1-44e9f4e7/

#include <stdio.h>

void swap(int* a, int* b) {
    int temp = *b;
    *b = *a;
    *a = temp;
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    for(int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}

void quicksort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quicksort(arr, low, pi - 1);
        quicksort(arr, pi + 1, high);
    }
}

int main() {
    int n, a[1111];
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    int m, b[1111];
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        scanf("%d", &b[i]);
    }
    
    quicksort(b, 0, m - 1);
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] < b[m - 1]) {
            count += b[m - 1] - a[i] + 1;
            a[i] = b[m - 1] + 1;
        }
    }
    printf("%d", count);

    return 0;
}
