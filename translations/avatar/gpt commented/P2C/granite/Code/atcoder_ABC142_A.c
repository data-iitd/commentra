
#include <stdio.h>
#include <math.h>

// Function to read a single integer from input
int next_int() {
    int x;
    scanf("%d", &x);
    return x;
}

// Function to read a list of integers from input
int* next_ints(int n) {
    int* arr = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    return arr;
}

int main() {
    // Read the number of iterations or elements
    int n = next_int();

    // Initialize a counter for odd indices
    int t = 0;

    // Loop through the range of n
    for (int i = 0; i < n; i++) {
        // Check if the current index (i + 1) is odd
        if ((i + 1) % 2 == 1) {
            t++;  // Increment the counter for odd indices
        }
    }

    // Calculate and print the ratio of odd indices to total elements
    printf("%f\n", (float)t / n);

    return 0;
}
