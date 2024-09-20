// Problem: https://www.hackerearth.com/practice/algorithms/sorting/merge-sort/practice-problems/algorithm/median-game-june-easy-19-3722be60/

#include <stdio.h>
#include <stdlib.h>

int find_median(int arr[], int size) {
    int mid = size / 2;
    return arr[mid]; 
}

void merge(int arr[], int l, int m, int r) {
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
        } else {
            arr[k] = R[j];
            j++;
        }
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

void merge_sort(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;

        merge_sort(arr, l, m);
        merge_sort(arr, m + 1, r);

        merge(arr, l, m, r);
    }
}

void process_array(int arr[], int n) {
    while (n > 1) {
        int median = -1;


        for (int size = 3; size <= n; size += 2) {  
            for (int i = 0; i <= n - size; i++) {
                int temp[size];
                for (int j = 0; j < size; j++) {
                    temp[j] = arr[i + j];
                }
                merge_sort(temp, 0, size - 1); 
                median = find_median(temp, size);
                break;
            }
        }

        if (median == -1)
            break;

        int pos = -1;
        for (int i = 0; i < n; i++) {
            if (arr[i] == median) {
                pos = i;
                break;
            }
        }

        if (pos != -1) {
            for (int i = pos; i < n - 1; i++) {
                arr[i] = arr[i + 1];
            }
            n--;  
        }
    }
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }
    printf("%d\n", sum);
}

int main() {
    int t;
    scanf("%d", &t);  

    while (t--) {
        int n;
        scanf("%d", &n);  

        int arr[n];
        for (int i = 0; i < n; i++) {
            scanf("%d", &arr[i]);  
        }

        process_array(arr, n);
    }

    return 0;
}
