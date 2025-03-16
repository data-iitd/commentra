#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void sort(float arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                float temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    int n;
    scanf("%d", &n);
    
    float *arr = (float *)malloc(n * sizeof(float));
    for (int i = 0; i < n; i++) {
        int temp;
        scanf("%d", &temp);
        arr[i] = (float)temp;
    }

    sort(arr, n);
    
    float prev = arr[0];
    for (int i = 1; i < n; i++) {
        prev = (prev + arr[i]) / 2;
    }

    printf("%f\n", prev);
    
    free(arr);
    return 0;
}

/* <END-OF-CODE> */
