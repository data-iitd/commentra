#include <stdio.h> // Including standard input-output library
#include <stdlib.h> // Including standard library for dynamic memory allocation

int main() {
    int a; // Variable to store the size of the array
    printf("Enter the size of the array: ");
    scanf("%d", &a); // Reading the size of the array from user input

    int *ar = (int *)malloc(a * sizeof(int)); // Dynamically allocating memory for the array

    // Reading array elements from user input
    printf("Enter the elements of the array:\n");
    for (int i = 0; i < a; i++) {
        scanf("%d", &ar[i]); // Reading an integer value from user input and storing it in the array
    }

    // Initializing variables for storing maximum and minimum differences
    int max = 0, min = 0;

    // Finding maximum and minimum differences between consecutive elements in the array
    for (int i = 0; i < a; i++) {
        // Finding maximum difference between current element and first element
        max = (ar[i] - ar[0] > ar[a - 1] - ar[i]) ? (ar[i] - ar[0]) : (ar[a - 1] - ar[i]);

        // Finding minimum difference between current element and previous element
        if (i == 0) {
            min = ar[i + 1] - ar[i]; // For the first element, minimum difference is between current and next element
        } else if (i == a - 1) {
            min = ar[i] - ar[i - 1]; // For the last element, minimum difference is between current and previous element
        } else {
            min = (ar[i] - ar[i - 1] < ar[i + 1] - ar[i]) ? (ar[i] - ar[i - 1]) : (ar[i + 1] - ar[i]); // For other elements, minimum difference is between current and previous or next element, whichever is smaller
        }

        // Printing minimum and maximum differences for each pair of consecutive elements
        printf("%d %d\n", min, max);
    }

    free(ar); // Freeing the dynamically allocated memory
    return 0; // Returning 0 to indicate successful execution
}

// <END-OF-CODE>
