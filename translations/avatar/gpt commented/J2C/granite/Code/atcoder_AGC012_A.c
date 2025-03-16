
#include <stdio.h> // Including the standard input/output library
#include <stdlib.h> // Including the standard library for dynamic memory allocation

int main() {
    // Creating a variable to store the size of the array
    int n;
    
    // Reading the integer n which determines the size of the array
    scanf("%d", &n);
    
    // Dynamically allocating memory for an array of size 3*n to hold the input values
    int *array = (int*)malloc(3 * n * sizeof(int));
    
    // Filling the array with user input values
    for (int i = 0; i < 3 * n; i++) {
        scanf("%d", &array[i]);
    }
    
    // Sorting the array in ascending order
    qsort(array, 3 * n, sizeof(int), NULL);
    
    // Setting the head pointer to the second last element of the sorted array
    int head = 3 * n - 2;
    
    // Initializing a variable to accumulate the result
    long res = 0;
    
    // Looping n times to sum up the required elements from the sorted array
    for (int i = 0; i < n; i++) {
        res += array[head]; // Adding the current element pointed by head to the result
        head -= 2; // Moving the head pointer two positions to the left for the next iteration
    }
    
    // Printing the final result
    printf("%ld\n", res);
    
    // Freeing the dynamically allocated memory
    free(array);
    
    return 0;
}
