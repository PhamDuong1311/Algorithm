// Problem: https://www.hackerearth.com/practice/algorithms/sorting/heap-sort/practice-problems/algorithm/raghu-vs-sayan/

#include <stdio.h>
#include <stdlib.h>

void heapify(int arr[], int n, int i) {
    int largest = i;   
    int right = 2 * i + 2; 

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;

        heapify(arr, n, largest);
    }
}

void heap_sort(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    for (int i = n - 1; i >= 0; i--) {
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;

        heapify(arr, i, 0);
    }
}

void determine_winner(int A, int B, int dishes[], int N) {
    heap_sort(dishes, N); 

    int raghu_sum = 0, sayan_sum = 0;
    int raghu_count = 0, sayan_count = 0;

    for (int i = 0; i < N; i++) {
        if (raghu_sum + dishes[i] <= A) {
            raghu_sum += dishes[i];
            raghu_count++;
        }
        if (sayan_sum + dishes[i] <= B) {
            sayan_sum += dishes[i];
            sayan_count++;
        }
    }

    if (raghu_count > sayan_count) {
        printf("Raghu Won\n");
    } else if (sayan_count > raghu_count) {
        printf("Sayan Won\n");
    } else {
        printf("Tie\n");
    }
}

int main() {
    int T;
    scanf("%d", &T); 

    while (T--) {
        int A, B, N;
        scanf("%d %d %d", &A, &B, &N); 

        int dishes[N];
        for (int i = 0; i < N; i++) {
            scanf("%d", &dishes[i]); 
        }

        determine_winner(A, B, dishes, N);  
    }

    return 0;
}
