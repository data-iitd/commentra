
#include <stdio.h>  // Include the standard input/output library for input/output operations
#include <stdlib.h> // Include the standard library for memory allocation and deallocation
#include <string.h> // Include the string library for string manipulation functions
#include <math.h>   // Include the mathematical library for mathematical operations
#include <time.h>   // Include the time library for time-related functions

int main(){
    int n, k; // Declare two integer variables, n and k, to read the number of elements and the size of the subarray from the user

    scanf("%d %d", &n, &k); // Read the number of elements and the size of the subarray from the user and store them in the variables n and k

    int *l = (int*)malloc(n * sizeof(int)); // Allocate memory for an array l of size n and initialize it with n default-constructed elements

    for(int i = 0; i < n; i++){ // Iterate through the elements of the array l and read each element from the user
        scanf("%d", &l[i]);
    }

    qsort(l, n, sizeof(int), compare); // Sort the array l in ascending order using the qsort function

    int ans=0; // Initialize an integer variable ans to 0 for storing the sum of the first k elements in descending order

    for(int i = 0; i < k; i++){ // Iterate through the first k elements in descending order and add their values to the variable ans
        ans += l[n - 1 - i];
    }

    printf("%d\n", ans); // Output the value of the variable ans to the console

    free(l); // Deallocate the memory allocated for the array l

    return 0; // Return 0 to indicate successful execution of the program
}

int compare(const void *a, const void *b){ // Define a comparison function for sorting the array l in ascending order
    return (*(int*)a - *(int*)b); // Compare two elements of the array l and return their difference
}

