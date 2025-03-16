#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
    // Initialize variables
    int n;

    // Read the number of elements in the array from the standard input
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    // Allocate memory for the array and read its elements
    int* a = (int*)malloc(n * sizeof(int));
    if (a == NULL) {
        printf("Memory allocation failed\n");
        return 1; // Exit if memory allocation fails
    }

    for(int i = 0; i < n; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &a[i]);
    }

    // Initialize a counter to keep track of the current element in the array
    int curr = 0;

    // Iterate through the array and increment the counter whenever the current element is one more than the previous one
    for(int i = 0; i < n; i++) {
        if(a[i] == curr + 1) curr++;
    }

    // Check if the counter is greater than zero, and if so, print the number of elements that are not consecutive
    if(curr > 0) {
        printf("The array has %d non-consecutive elements.\n", n - curr);
    }
    // If the counter is zero, print -1 to indicate that all elements are not consecutive
    else {
        printf("-1\n");
    }

    // Free the allocated memory
    free(a);

    return 0;
}

// <END-OF-CODE>
