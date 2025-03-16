#include <stdio.h>
#include <stdlib.h>

#define MOD 1000000007

// Function to compare two integers for qsort
int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

// Function to read a list of integers from input
int* readInts(int *size) {
    scanf("%d", size);  // Read the size of the array
    int *arr = (int *)malloc((*size) * sizeof(int));  // Allocate memory for the array
    for (int i = 0; i < *size; i++) {
        scanf("%d", &arr[i]);  // Read each integer
    }
    return arr;  // Return the array
}

// Main function to execute the logic
int main() {
    int n;
    scanf("%d", &n);  // Reading an integer input for 'n'
    
    int size;
    int *A = readInts(&size);  // Reading a list of integers
    
    // Sorting the array in ascending order
    qsort(A, size, sizeof(int), compare);
    
    long long ans = 0;  // Initializing the answer variable to accumulate the result
    
    // Looping through the last 2*n elements of the sorted list in reverse order
    for (int i = size - 2; i >= size - 2 * n; i -= 2) {
        ans += A[i];  // Adding the current element to the answer
    }
    
    printf("%lld\n", ans);  // Printing the final accumulated answer
    
    free(A);  // Freeing the allocated memory
    return 0;  // Return success
}

// <END-OF-CODE>
