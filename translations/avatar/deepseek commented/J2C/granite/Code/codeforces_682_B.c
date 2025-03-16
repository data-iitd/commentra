
#include <stdio.h> // Include necessary header files
#include <stdlib.h>
#include <string.h>

int main() {
    int n; // Declaring variables
    scanf("%d", &n); // Reading the number of elements
    int *arr = (int*)malloc(n * sizeof(int)); // Dynamically allocating memory for the array
    
    // Reading the elements and storing them in the array
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    qsort(arr, n, sizeof(int), compare); // Sorting the array
    
    int c = 1; // Initializing the counter variable
    
    // Iterating through the sorted array to find the smallest missing positive integer
    for (int i = 0; i < n; i++) {
        if (arr[i] >= c) {
            c++;
        }
    }
    
    printf("%d\n", c); // Printing the result
    
    free(arr); // Freeing the dynamically allocated memory
    return 0;
}

int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b); // Custom comparison function for qsort
}

// Debug method for debugging purposes
void debug(void) {
    printf("Debug information goes here\n");
}

// End of code marker
