#include <stdio.h>
#include <stdlib.h>

int main() {
    // Ask the user for the number of elements in the list
    int n;
    scanf("%d", &n);

    // Initialize an array to store the integers
    int *l = (int *)malloc(n * sizeof(int));

    // Iterate n times and read each integer into the array
    for (int i = 0; i < n; i++) {
        scanf("%d", &l[i]);
    }

    // Initialize a variable to store the answer
    long long ans = n - 1;

    // Initialize a variable to store the previous integer in the list
    int last = 0;

    // Iterate through each integer in the array
    for (int i = 0; i < n; i++) {
        // Calculate the absolute difference between the previous integer and the current integer
        // Add 1 to account for the number of steps between the two integers
        ans += abs(last - l[i]) + 1;

        // Update the value of the previous integer
        last = l[i];
    }

    // Print the value of the answer
    printf("%lld\n", ans);

    // Free the allocated memory
    free(l);

    return 0;
}

// <END-OF-CODE>
