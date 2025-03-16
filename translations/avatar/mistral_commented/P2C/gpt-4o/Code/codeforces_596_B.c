#include <stdio.h>
#include <stdlib.h>

int main() {
    // Ask the user for the number of elements in the list
    int n;
    scanf("%d", &n);

    // Declare an array to store the elements
    int r[n];

    // Ask the user to input the elements of the list separated by spaces
    for (int i = 0; i < n; i++) {
        scanf("%d", &r[i]);
    }

    // Initialize a variable to store the answer
    int ans = abs(r[0]);

    // Use a for loop to calculate the sum of the absolute differences between consecutive elements
    for (int i = 1; i < n; i++) {
        ans += abs(r[i] - r[i-1]);
    }

    // Print the final answer
    printf("%d\n", ans);

    return 0;
}

// <END-OF-CODE>
