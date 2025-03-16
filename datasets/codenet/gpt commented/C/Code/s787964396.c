#include<stdio.h>
#include<stdlib.h>
#define I 10000 // Define a constant for the maximum range of input values

// Function prototype for CountingSort
void CountingSort(int*, int*, int);

int main() {
    int *a, *b, i, max = 0, n;

    // Read the number of elements to be sorted
    scanf("%d", &n);

    // Allocate memory for the input array 'a' and output array 'b'
    a = (int *)malloc((n + 1) * sizeof(int));
    b = (int *)malloc((n + 1) * sizeof(int));

    // Read 'n' elements into the array 'a'
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i + 1]); // Store elements starting from index 1
    }

    // Call the CountingSort function to sort the array 'a' and store the result in 'b'
    CountingSort(a, b, n);

    // Print the sorted elements from array 'b'
    printf("%d", b[1]); // Print the first sorted element
    for (i = 2; i < n + 1; i++) {
        printf(" %d", b[i]); // Print the remaining sorted elements
    }
    printf("\n");

    // Free the allocated memory for arrays 'a' and 'b'
    free(a);
    free(b);
    
    return 0; // Return success
}

// Function to perform Counting Sort
void CountingSort(int a[], int b[], int k) {
    int c[I], i, j;

    // Initialize the counting array 'c' to zero
    for (i = 0; i <= I; i++) {
        c[i] = 0; // Set all counts to zero
    }

    // Count occurrences of each element in array 'a'
    for (j = 0; j < k; j++) {
        c[a[j + 1]]++; // Increment the count for each element
    }

    // Update the counting array 'c' to contain the actual positions of elements
    for (i = 1; i < I + 1; i++) {
        c[i] += c[i - 1]; // Cumulative sum to determine positions
    }

    // Build the output array 'b' using the counting array 'c'
    for (j = k; 0 < j; j--) {
        b[c[a[j]]] = a[j]; // Place the elements in their sorted position
        c[a[j]]--; // Decrement the count for the current element
    }
}
