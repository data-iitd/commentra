
#include <stdio.h> // Include the standard input/output library

int main() {
    // Declare two integer variables to hold user input
    int a, b;
    
    // Read two integers from user input
    scanf("%d %d", &a, &b);
    
    // Initialize a counter to keep track of the number of pairs processed
    int count = 0;
    
    // Loop to process pairs of a and b while both are greater than zero
    while (true) {
        // Check if both a and b are positive
        if (a > 0 && b > 0) {
            // Increment the count of pairs
            count++;
            // Decrement both a and b
            a--;
            b--;
        } else {
            // Break the loop if either a or b is not positive
            break;
        }
    }
    
    // Calculate the number of pairs that can be formed from the remaining a and b
    int ans = a / 2 + b / 2;
    
    // Output the count of pairs processed and the calculated answer
    printf("%d %d\n", count, ans);
    
    return 0; // Return 0 to indicate successful execution
}
