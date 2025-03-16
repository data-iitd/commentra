#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    // Creating a Scanner object to read input from the console
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
    long res = 0;
    
    // Looping n times to sum up the required elements from the sorted array
    for (int i = 0; i < n; i++) {
        res += array[head]; // Adding the current element pointed by head to the result
        head -= 2; // Moving the head pointer two positions to the left for the next iteration
    }
    
    // Printing the final result
    printf("%ld\n", res);
    
    return 0;
}

int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

