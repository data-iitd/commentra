#include <stdio.h>
#include <stdlib.h>

void sort(int *arr, int n) {
    // Simple bubble sort for demonstration purposes
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    int N;
    // Read the number of elements
    scanf("%d", &N);
    
    // Initialize arrays to hold the original values and a sorted copy
    int *X = (int *)malloc(N * sizeof(int));
    int *Y = (int *)malloc(N * sizeof(int));
    
    // Read N integers into array X and copy them to array Y
    for (int i = 0; i < N; i++) {
        scanf("%d", &X[i]);
        Y[i] = X[i];
    }
    
    // Sort the array Y to find the median values
    sort(Y, N);
    
    // Calculate the two middle values (medians) for even-sized arrays
    int m1 = Y[N / 2 - 1]; // First median
    int m2 = Y[N / 2];     // Second median
    
    // For each element in X, print the appropriate median based on its value
    for (int i = 0; i < N; i++) {
        if (X[i] <= m1) {
            printf("%d\n", m2); // If X[i] is less than or equal to m1, print m2
        } else {
            printf("%d\n", m1); // Otherwise, print m1
        }
    }
    
    // Free allocated memory
    free(X);
    free(Y);
    
    return 0;
}

// <END-OF-CODE>
