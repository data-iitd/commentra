#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, s1 = 0, s2 = 0, x, y, i, flag = 0;
    char ch[1000];
    int j = 0;

    // Read the number of pairs of integers to be processed
    scanf("%d", &n);

    // Process each pair of integers
    for (i = 0; i < n; i++) {
        // Read the next pair of integers
        scanf("%d %d", &x, &y);

        // Calculate temporary sums for the current iteration
        int temp1 = s1 + x;
        int temp2 = s2 + y;

        // Check if adding x to s1 keeps the difference within 500
        if (abs(temp1 - s2) <= 500) {
            s1 += x; // Update s1
            ch[j++] = 'A'; // Record the action 'A'
            continue; // Move to the next iteration
        }

        // Check if adding y to s2 keeps the difference within 500
        if (abs(temp2 - s1) <= 500) {
            s2 += y; // Update s2
            ch[j++] = 'G'; // Record the action 'G'
            continue; // Move to the next iteration
        }

        // If neither condition is met, set flag to indicate failure
        flag = 1;
        break; // Exit the loop
    }

    // Check if the loop was exited due to a failure condition
    if (flag == 1)
        printf("-1\n"); // Output -1 to indicate failure
    else {
        // Convert the character array to a string and print the result
        ch[j] = '\0'; // Null-terminate the string
        printf("%s\n", ch); // Output the recorded actions
    }

    return 0;
}
