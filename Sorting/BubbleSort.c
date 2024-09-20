#include <stdio.h>

void bubbleSort(int arr[], int n) {
    int i, j, temp;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    int n, i;
    
    scanf("%d", &n);
    int vaccines[n], patients[n];
    for (i = 0; i < n; i++) {
        scanf("%d", &vaccines[i]);
    }

    for (i = 0; i < n; i++) {
        scanf("%d", &patients[i]);
    }

    bubbleSort(vaccines, n);
    bubbleSort(patients, n);

    for (i = 0; i < n; i++) {
        if (vaccines[i] <= patients[i]) {
            printf("No\n");
            return 0;
        }
    }
    
    printf("Yes\n");
    return 0;
}
