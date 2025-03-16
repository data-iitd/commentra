#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int solve() {
    // Read the integer N from the input
    int N;
    scanf("%d", &N);
    
    // Initialize an array of size N to store the integers
    int *arr = (int *)malloc(N * sizeof(int));
    
    // Read N integers from the input and store them in the array
    for (int i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
    }
    
    // Initialize a sum variable to 0
    int sum = 0;
    
    // Sort the array in ascending order
    qsort(arr, N, sizeof(int), compare);
    
    // Iterate through the array and count elements
    for (int i = 0; i < N; i++) {
        // Check if the current element is less than or equal to the smallest element in the sorted array
        if (arr[i] <= arr[0]) {
            sum++;
        }
    }
    
    // Free the allocated memory
    free(arr);
    
    // Return the sum
    return sum;
}

int main() {
    printf("%d\n", solve());
    return 0;
}

// <END-OF-CODE>
