#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n); // Read the number of elements in the list `w`

    int w[n]; // Declare an array to store the integers
    for (int i = 0; i < n; i++) {
        scanf("%d", &w[i]); // Read `n` integers from the standard input
    }

    long long x = 0; // Initialize sum variable
    for (int i = 0; i < n; i++) {
        x += w[i]; // Calculate the sum of all elements in the list `w`
    }

    int d[n]; // Array to store the indices of elements that satisfy the condition
    int count = 0; // Counter for valid indices

    // Iterate over each element in the list `w`
    for (int i = 0; i < n; i++) {
        // Check if the current element `w[i]` is equal to the average of the total sum `x` and the number of elements `n` minus one
        if ((x - w[i]) / (n - 1) == w[i]) {
            d[count++] = i + 1; // Store the 1-based index of the element
        }
    }

    printf("%d\n", count); // Print the length of the list `d`
    for (int i = 0; i < count; i++) {
        printf("%d", d[i]); // Print the indices in `d`
        if (i < count - 1) {
            printf(" "); // Print space between indices
        }
    }
    printf("\n");

    return 0;
}

// <END-OF-CODE>
