#include <stdio.h>
#include <stdlib.h>

<<<<<<< HEAD
// Function to read an integer from standard input
=======
// Function to read a single integer from standard input
>>>>>>> 98c87cb78a (data updated)
int readInt() {
    int i;
    scanf("%d", &i);
    return i;
}

// Main function to execute the program
int main() {
    // Read two integers n and m from the input
    int n = readInt();
    int m = readInt();

    // Initialize an array to hold m integers
    int *a = (int *)malloc(m * sizeof(int));
    int sum = 0;

    // Read m integers into the array a and calculate their sum
    for (int i = 0; i < m; i++) {
        a[i] = readInt();
        sum += a[i];
    }

    // Check if the sum of integers exceeds n
    if (sum > n) {
        // Print -1 if the sum exceeds n and exit
        printf("-1\n");
        free(a); // Free allocated memory
        return 0;
    }

    // Print the difference between n and the sum if it's within bounds
    printf("%d\n", n - sum);

    free(a); // Free allocated memory
    return 0;
}

// <END-OF-CODE>
