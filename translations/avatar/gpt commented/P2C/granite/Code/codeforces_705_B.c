
#include <stdio.h>

int main() {
    // Use readline for faster input reading
    int n;
    scanf("%d", &n);

    // Read the list of integers from input
    int w[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &w[i]);
    }

    // Initialize a variable 'c' to track the output state
    int c = 2;

    // Iterate through each element in the list 'w'
    for (int i = 0; i < n; i++) {
        // If the current element is 1, print the current value of 'c'
        if (w[i] == 1) {
            printf("%d\n", c);
        }
        // If the current element is even, toggle 'c' between 2 and 3
        else if (w[i] % 2 == 0) {
            c = 3 - c;  // This will switch c between 2 and 3
            printf("%d\n", c);
        }
        // If the current element is odd (and not 1), print the current value of 'c'
        else {
            printf("%d\n", c);
        }
    }

    return 0;
}
