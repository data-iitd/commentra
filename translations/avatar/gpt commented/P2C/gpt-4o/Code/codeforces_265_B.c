#include <stdio.h>
#include <stdlib.h>

int main() {
    // Read the number of elements from user input
    int n;
    scanf("%d", &n);

    // Initialize an array to store the elements
    int *l = (int *)malloc(n * sizeof(int));

    // Loop to read 'n' integers from user input and store them in the array
    for (int i = 0; i < n; i++) {
        scanf("%d", &l[i]);
    }

    // Initialize the answer variable to n - 1 (to account for n-1 gaps between n elements)
    long long ans = n - 1;

    // Initialize a variable to keep track of the last element processed
    int last = 0;

    // Loop through each element in the array
    for (int i = 0; i < n; i++) {
        // Calculate the distance from the last element to the current element
        // and add 1 for the step to the current element
        ans += abs(last - l[i]) + 1;

        // Update 'last' to the current element for the next iteration
        last = l[i];
    }

    // Print the final calculated answer
    printf("%lld\n", ans);

    // Free the allocated memory
    free(l);

    return 0;
}

// <END-OF-CODE>
