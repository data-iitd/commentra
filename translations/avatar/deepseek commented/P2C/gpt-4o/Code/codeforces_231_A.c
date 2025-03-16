#include <stdio.h>

int main() {
    int n, c = 0; // Initialize n and counter c
    scanf("%d", &n); // Take integer input n

    for (int i = 0; i < n; i++) {
        int sum = 0, num; // Initialize sum for each list
        // Read integers until a newline is encountered
        while (scanf("%d", &num) == 1) {
            sum += num; // Add each number to sum
            if (getchar() == '\n') // Check for end of line
                break; // Exit loop if end of line is reached
        }
        
        // If the sum is greater than 1, increment the counter c
        if (sum > 1) {
            c++;
        }
    }

    // Print the final value of c
    printf("%d\n", c);
    return 0;
}

// <END-OF-CODE>
