#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int solve() {
    // Read the number of elements in the array
    int N;
    scanf("%d", &N);
    
    // Initialize an array to hold the input values
    int *arr = (int *)malloc(N * sizeof(int));
    
    // Populate the array with user input
    for (int i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
    }
    
    // Initialize a variable to keep track of the count of elements
    int sum = 0;
    
    // Create a temporary array to manage the elements
    int *q = (int *)malloc(N * sizeof(int));
    int q_size = 0;
    
    // Iterate through the array to process each element
    for (int i = 0; i < N; i++) {
        // Add the current element to the temporary array
        q[q_size++] = arr[i];
        
        // Sort the temporary array to find the smallest element
        qsort(q, q_size, sizeof(int), compare);
        
        // Check if the current element is less than or equal to the smallest element in the array
        if (arr[i] <= q[0]) {
            // Increment the count if the condition is met
            sum++;
        }
    }
    
    // Free allocated memory
    free(arr);
    free(q);
    
    // Return the final count of elements that met the condition
    return sum;
}

int main() {
    // Call the solve function and print the result
    printf("%d\n", solve());
    return 0;
}

// <END-OF-CODE>
