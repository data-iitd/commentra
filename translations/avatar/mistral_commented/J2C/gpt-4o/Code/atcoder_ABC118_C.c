#include <stdio.h>
#include <stdlib.h>

int* func(int* A, int* size);

int main() {
    int n;
    scanf("%d", &n); // Read the first integer from the input

    // Check if the input is 1
    if (n == 1) {
        int singleValue;
        scanf("%d", &singleValue); // Read the only integer
        printf("%d\n", singleValue); // Print the only integer
        return 0; // Exit the program
    }

    // Initialize an array to store the integers
    int* a = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]); // Read the rest of the integers
    }

    // Sort the array in ascending order
    qsort(a, n, sizeof(int), (int (*)(const void*, const void*))compare);

    // Check if the last integer in the array is 0
    if (a[n - 1] == 0) {
        printf("0\n"); // Print 0
        free(a); // Free allocated memory
        return 0; // Exit the program
    }

    // Initialize the answer variable
    int ans = 0;

    // Use a while loop to keep applying the function to the array until it contains only one element
    while (1) {
        if (n == 1) {
            ans = a[0]; // Assign the only remaining integer to the answer variable
            break; // Exit the loop
        }
        a = func(a, &n); // Apply the function to the array and assign the result back to it
    }

    // Print the answer
    printf("%d\n", ans);
    free(a); // Free allocated memory
    return 0;
}

// Define a function to apply the logic to the array
int* func(int* A, int* size) {
    int* a = (int*)malloc(*size * sizeof(int)); // Create a copy of the array
    int min = 0;
    int newSize = 0;

    // Iterate through the array and apply the logic to each integer
    for (int i = 0; i < *size; i++) {
        if (A[i] == 0) { // If the current integer is 0, skip it
            continue;
        } else {
            if (min != 0) { // If there is already a minimum value
                int modValue = A[i] % min;
                if (modValue == 1) { // If the result is 1, print 1 and exit the program
                    printf("1\n");
                    free(a); // Free allocated memory
                    exit(0);
                }
                a[newSize++] = modValue; // Store the modified value
            } else { // If there is no minimum value yet
                min = A[i];
                a[newSize++] = A[i]; // Store the current integer as the minimum value
            }
        }
    }

    // Update the size of the new array
    *size = newSize;

    // Sort the array in ascending order
    qsort(a, *size, sizeof(int), (int (*)(const void*, const void*))compare);
    return a;
}

// Comparison function for qsort
int compare(const int* a, const int* b) {
    return (*a - *b);
}
