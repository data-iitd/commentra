#include <stdio.h> // Including standard input-output library

int main() {
    int a, b; // Declaring two integer variables
    int sum = 0; // Initializing a variable to hold the sum of selected integers

    // Reading two integers from the user
    scanf("%d %d", &a, &b);

    // Loop to iterate twice to calculate the sum
    for (int i = 0; i < 2; i++) {
        // Check if 'a' is greater than or equal to 'b'
        if (a >= b) {
            sum += a; // Add 'a' to the sum
            a = a - 1; // Decrement 'a' by 1
        } else {
            sum += b; // Add 'b' to the sum
            b = b - 1; // Decrement 'b' by 1
        }
    }

    // Output the final sum to the console
    printf("%d\n", sum);

    return 0; // Indicating that the program ended successfully
}

// <END-OF-CODE>
