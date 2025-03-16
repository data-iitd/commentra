#include <stdio.h> // For input and output functions
#include <stdlib.h> // For the qsort function

// Comparison function for qsort
int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int main() {
    // Reading the integer n which determines the size of the array
    int n;
    scanf("%d", &n);
    
    // Initializing an array of size 3*n to hold the input values
    int array[3 * n];
    
    // Filling the array with user input values
    for (int i = 0; i < 3 * n; i++) {
        scanf("%d", &array[i]);
    }
    
    // Sorting the array in ascending order
    qsort(array, 3 * n, sizeof(int), compare);
    
    // Setting the head pointer to the second last element of the sorted array
    int head = 3 * n - 2;
    
    // Initializing a variable to accumulate the result
    long long res = 0; // Use long long to handle large sums
    
    // Looping n times to sum up the required elements from the sorted array
    for (int i = 0; i < n; i++) {
        res += array[head]; // Adding the current element pointed by head to the result
        head -= 2; // Moving the head pointer two positions to the left for the next iteration
    }
    
    // Printing the final result
    printf("%lld\n", res);
    
    return 0; // Indicating successful completion
}

// <END-OF-CODE>
