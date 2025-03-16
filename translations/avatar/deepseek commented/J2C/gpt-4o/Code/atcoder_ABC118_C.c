#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int main() {
    int n;
    scanf("%d", &n); // Read the number of integers
    int *a = (int *)malloc(n * sizeof(int)); // Create an array to store integers

    if (n == 1) { // Check if there is only one integer
        scanf("%d", &a[0]); // Read the single integer
        printf("%d\n", a[0]); // Print the single integer
        free(a); // Free allocated memory
        return 0; // Exit the program
    }

    for (int i = 0; i < n; i++) { // Read n integers and add them to the array
        scanf("%d", &a[i]);
    }

    qsort(a, n, sizeof(int), compare); // Sort the array

    if (a[n - 1] == 0) { // Check if the largest element is 0
        printf("0\n"); // Print 0 and exit the program
        free(a); // Free allocated memory
        return 0;
    }

    int ans = 0; // Initialize the result variable

    while (1) { // Enter an infinite loop to process the array
        if (n == 1) { // Check if there is only one element left
            ans = a[0]; // Assign the single element to ans
            break; // Exit the loop
        }
        n = func(a, n); // Call the func method to update the array
    }

    printf("%d\n", ans); // Print the final result
    free(a); // Free allocated memory
    return 0;
}

int func(int *A, int n) {
    int *a = (int *)malloc(n * sizeof(int)); // Create a copy of the input array
    int min = 0; // Initialize the minimum variable
    int newSize = 0; // Variable to track the new size of the array

    for (int i = 0; i < n; i++) { // Iterate through the array
        if (A[i] == 0) { // Skip elements that are zero
            continue;
        } else { // Process non-zero elements
            if (min != 0) { // Check if min is not zero
                a[newSize] = A[i] % min; // Perform modulo operation
                if (a[newSize] == 1) { // Check if the result is 1
                    printf("1\n"); // Print 1 and exit the program
                    free(a); // Free allocated memory
                    exit(0);
                }
            } else { // Find the minimum non-zero element
                min = A[i];
                a[newSize] = A[i]; // Add the current element to the new array
            }
            newSize++; // Increment the new size
        }
    }

    qsort(a, newSize, sizeof(int), compare); // Sort the new array
    free(A); // Free the original array
    return newSize; // Return the new size of the array
}

// <END-OF-CODE>
