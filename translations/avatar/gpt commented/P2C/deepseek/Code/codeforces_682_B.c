#include <stdio.h>
#include <stdlib.h>

// Function to read an array of integers from stdin
int* read_ints() {
    int n;
    scanf("%d", &n);
    int* arr = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    return arr;
}

// Function to sort an array of integers
void sort_ints(int* arr, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Main function
int main() {
    // Read the number of elements
    int n;
    scanf("%d", &n);

    // Read the list of integers
    int* l = read_ints();

    // Sort the list
    sort_ints(l, n);

    // Initialize a variable to track unique counts
    int f = 1;

    // Initialize a counter for unique elements
    int c = 0;

    // Iterate through the sorted list to count unique elements
    for (int i = 0; i < n; i++) {
        if (l[i] > c) {
            c += 1;
        }
    }

    // Output the total count of unique elements
    printf("%d\n", c + 1);

    // Free the allocated memory
    free(l);

    return 0;
}
