#include <stdio.h>  // Including standard input-output library
#include <stdlib.h> // Including standard library for memory allocation and sorting

// Function to compare two integers for qsort
int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int main() {
    int n; // Variable to store the number of elements
    scanf("%d", &n); // Reading the number of elements in the array from user input
    int *a = (int *)malloc(n * sizeof(int)); // Dynamically allocating memory for the array

    // Initializing the array with user input
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]); // Reading an integer value from user input and storing it in the array
    }

    qsort(a, n, sizeof(int), compare); // Sorting the array in ascending order using qsort

    int min = a[0]; // Assigning the minimum value in the array to the min variable

    // Checking if all the elements in the array are multiples of the minimum value
    for (int i = 0; i < n; i++) {
        if (a[i] % min != 0) { // Checking if the current element is not a multiple of the minimum value
            printf("-1\n"); // Printing -1 if any non-multiple of the minimum value is found
            free(a); // Freeing the allocated memory
            return 0; // Exiting the program if any non-multiple of the minimum value is found
        }
    }

    // Printing the minimum value if all elements are multiples of the minimum value
    printf("%d\n", min);

    free(a); // Freeing the allocated memory
    return 0; // Returning 0 to indicate successful completion
}

// <END-OF-CODE>
