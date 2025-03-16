#include <stdio.h>
#include <stdlib.h>

int main() {
<<<<<<< HEAD
    // Read two integers n and m from input
    int n, m;
=======
    int n, m;

    // Read two integers n and m from input
>>>>>>> 98c87cb78a (data updated)
    scanf("%d %d", &n, &m);

    // Initialize an array to hold m integers
    int *a = (int *)malloc(m * sizeof(int));
    if (a == NULL) {
        perror("Failed to allocate memory");
        return 1; // Exit if memory allocation fails
    }

    // Initialize a variable to hold the sum of the integers read
    int sum = 0;

    // Read m integers from input and calculate their sum
    for (int i = 0; i < m; i++) {
        scanf("%d", &a[i]); // Read an integer and store it in the array
        sum += a[i]; // Add the integer to the sum
    }

    // Check if the sum of the integers exceeds n
    if (sum > n) {
        printf("-1\n"); // Print -1 if the sum is greater than n
        free(a); // Free allocated memory
        return 0; // Exit the function
    }

    // Print the difference between n and the sum of the integers
    printf("%d\n", n - sum);

    free(a); // Free allocated memory
    return 0; // Exit the program
}

// <END-OF-CODE>
