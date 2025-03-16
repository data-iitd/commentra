#include <stdio.h>
#include <stdlib.h>

int main() {
    // Get the number of elements in the array from user input
    int N;
    scanf("%d", &N);

    // Initialize an array 'n' of size N
    int *n = (int *)malloc(N * sizeof(int));

    // Get the elements of the array from user input and store them in 'n'
    for (int i = 0; i < N; i++) {
        scanf("%d", &n[i]);
    }

    // Initialize variables 'a' and 'pos'
    int a = 1;
    int pos = 0;

    // Iterate through the array 'n' starting from the second element
    for (int i = 1; i < N; i++) {
        // Check if the current element is greater than the previous one
        if (n[pos] > n[i]) {
            // Increment the variable 'a' if the condition is true
            a++;
            // Update the position of the previous greater element
            pos = i;
        }
    }

    // Print the value of 'a' as the output
    printf("%d\n", a);

    // Free the allocated memory
    free(n);

    return 0;
}

// <END-OF-CODE>
