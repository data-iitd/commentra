
#include <stdio.h>

int main() {
    // Create a Scanner object to read input from the console
    int n, k, l = 0, c = 1;
    scanf("%d %d", &n, &k);

    // Loop through each element to count consecutive occurrences
    for (int i = 0; i < n; i++) {
        // Read the next integer from input
        int a;
        scanf("%d", &a);

        // Check if the current number is the same as the last one
        if (a == l)
            c += 1; // Increment the count of consecutive occurrences
        else
            c = 1; // Reset the count if the number changes

        // Update the last number to the current one
        l = a;
    }

    // Check if the count of consecutive numbers plus k exceeds n
    if (c + k > n)
        // If true, print the number of elements that are not part of the consecutive sequence
        printf("%d\n", n - c);
    else
        // Otherwise, print -1 indicating the condition is not met
        printf("-1\n");

    return 0;
}
