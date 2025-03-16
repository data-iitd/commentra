#include <stdio.h>

// Function to read a single integer from input
int next_int() {
    int value;
    scanf("%d", &value);
    return value;
}

// Function to read a list of integers from input
void next_ints(int *arr, int *n) {
    scanf("%d", n);
    for (int i = 0; i < *n; i++) {
        scanf("%d", &arr[i]);
    }
}

// Read the number of iterations or elements
int n = next_int();

// Initialize a counter for odd indices
int t = 0;

// Loop through the range of n
for (int i = 0; i < n; i++) {
    // Check if the current index (i + 1) is odd
    if ((i + 1) % 2 != 0) {
        t += 1;  // Increment the counter for odd indices
    }
}

// Calculate and print the ratio of odd indices to total elements
printf("%.10f\n", (double)t / n);

