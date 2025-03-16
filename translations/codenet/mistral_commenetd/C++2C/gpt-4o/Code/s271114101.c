#include <stdio.h> // This line includes the standard input-output library for C.

int main() { // The main function is the entry point of the program.
    int a, b, c; // Declare three integer variables named a, b, and c.
    scanf("%d %d %d", &a, &b, &c); // Read three integers from the standard input and assign them to the variables a, b, and c.
    
    // The following if statement checks if any of the following conditions are true:
    // (a + b) == c // If the sum of a and b is equal to c
    // (b + c) == a // If the sum of b and c is equal to a
    // (a + c) == b // If the sum of a and c is equal to b
    if ((a + b == c) || (b + c == a) || (a + c == b)) { // If any of the above conditions are true, the following code is executed.
        printf("Yes\n"); // Output the string "Yes" followed by a newline character.
    }
    else { // If none of the above conditions are true, the following code is executed.
        printf("No\n"); // Output the string "No" followed by a newline character.
    }
    
    return 0; // Return 0 to indicate that the program finished successfully.
}

// <END-OF-CODE>
