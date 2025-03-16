#include <stdio.h>

int main() {
    // Take an integer 'n' as input from the user
    int n;
    scanf("%d", &n);

    // Initialize a counter 'c' to 0
    int c = 0;

    // Iterate through the range of 'n'
    for (int i = 0; i < n; i++) {
        // Take 'n' lists of integers as input from the user
        int sum = 0;
        int num;

        // Read integers until a newline is encountered
        while (scanf("%d", &num) == 1) {
            sum += num;
            // Check for the end of the line
            if (getchar() == '\n') {
                break;
            }
        }

        // Check if the sum of the elements in the current list is greater than 1
        if (sum > 1) {
            // Increment the counter 'c' by 1 if the condition is true
            c++;
        }
    }

    // Print the value of the counter 'c'
    printf("%d\n", c);

    return 0;
}

// <END-OF-CODE>
