#include <stdio.h>
#include <stdlib.h>

<<<<<<< HEAD
void sort(int *arr, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
=======
// Function to compare two integers for qsort
int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
>>>>>>> 98c87cb78a (data updated)
}

int main() {
    int N;
<<<<<<< HEAD
    scanf("%d", &N);
    
    int *X = (int *)malloc(N * sizeof(int));
    int *Y = (int *)malloc(N * sizeof(int));
    
=======
    
    // Reads the number of elements N.
    scanf("%d", &N);
    
    // Initializes arrays X and Y to store N integers.
    int *X = (int *)malloc(N * sizeof(int));
    int *Y = (int *)malloc(N * sizeof(int));
    
    // Reads N integers into array X and copies them to array Y.
>>>>>>> 98c87cb78a (data updated)
    for (int i = 0; i < N; i++) {
        scanf("%d", &X[i]);
        Y[i] = X[i];
    }
    
<<<<<<< HEAD
    sort(Y, N);
    
    int m1 = Y[N / 2 - 1];
    int m2 = Y[N / 2];
    
=======
    // Sorts array Y in ascending order.
    qsort(Y, N, sizeof(int), compare);
    
    // Calculates the two middle values of the sorted array Y.
    int m1 = Y[N / 2 - 1];
    int m2 = Y[N / 2];
    
    // For each element in array X, prints the corresponding median value.
>>>>>>> 98c87cb78a (data updated)
    for (int i = 0; i < N; i++) {
        if (X[i] <= m1) {
            printf("%d\n", m2);
        } else {
            printf("%d\n", m1);
        }
    }
    
<<<<<<< HEAD
=======
    // Free allocated memory
>>>>>>> 98c87cb78a (data updated)
    free(X);
    free(Y);
    
    return 0;
}

// <END-OF-CODE>
