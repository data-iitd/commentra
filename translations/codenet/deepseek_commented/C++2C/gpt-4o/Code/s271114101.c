#include <stdio.h>

int main() {
    // Include the stdio.h library for input and output operations
    
    // Declare three integer variables 'a', 'b', and 'c'
    int a, b, c;
    
    // Read three integers from the standard input and store them in 'a', 'b', and 'c'
    scanf("%d %d %d", &a, &b, &c);
    
    // Check if any of the following conditions are true:
    // - a + b equals c
    // - b + c equals a
    // - a + c equals b
    if (a + b == c || b + c == a || a + c == b) {
        // If any of these conditions are true, print "Yes"
        printf("Yes\n");
    } else {
        // Otherwise, print "No"
        printf("No\n");
    }
    
    return 0; // Return 0 to indicate successful completion of the program
}

// <END-OF-CODE>
