
#include <stdio.h>

int main() {
    // Read an integer input which represents the number of lists to be processed
    int n;
    scanf("%d", &n);

    // Initialize an empty list to store the input lists
    char *q[n];

    // Initialize a counter to keep track of the matching conditions
    int count = 0;

    // Loop to read 'n' lines of input and store them in the list 'q'
    for (int i = 0; i < n; i++) {
        // Read a line of input, split it into a list of strings, and store it in 'q'
        char a[100];
        scanf("%s", a);
        q[i] = a;
    }

    // Nested loop to compare each list in 'q' with every other list
    for (int j = 0; j < n; j++) {
        for (int k = 0; k < n; k++) {
            // Skip comparison if both lists are the same
            if (k == j) {
                continue;
            }
            // Check if the first element of list 'j' matches the last element of list 'k'
            else if (q[j][0] == q[k][strlen(q[k]) - 1]) {
                // Increment the count if the condition is met
                count++;
            }
            else {
                // Continue to the next iteration if the condition is not met
                continue;
            }
        }
    }

    // Print the final count of matching conditions
    printf("%d", count);

    return 0;
}
