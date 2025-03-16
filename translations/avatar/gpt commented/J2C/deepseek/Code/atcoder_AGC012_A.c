#include <stdio.h>
#include <stdlib.h>

// Function to compare two integers for qsort
int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int main() {
    int n;
    scanf("%d", &n);
    
    // Calculating the size of the array
    int size = 3 * n;
    int array[size];
    
    // Filling the array with user input values
    for (int i = 0; i < size; i++) {
        scanf("%d", &array[i]);
    }
    
    // Sorting the array in ascending order
    qsort(array, size, sizeof(int), compare);
    
    // Setting the head pointer to the second last element of the sorted array
    int head = size - 2;
    
    // Initializing a variable to accumulate the result
    long long res = 0;
    
    // Looping n times to sum up the required elements from the sorted array
    for (int i = 0; i < n; i++) {
        res += array[head]; // Adding the current element pointed by head to the result
        head -= 2; // Moving the head pointer two positions to the left for the next iteration
    }
    
    // Printing the final result
    printf("%lld\n", res);
    
    return 0;
}
