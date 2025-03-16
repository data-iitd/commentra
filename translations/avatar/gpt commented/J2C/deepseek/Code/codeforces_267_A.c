#include <stdio.h>
#include <stdlib.h>

// Function to perform a specific subtraction-like operation
int sub(int a, int b) {
    // Determine the minimum and maximum of the two numbers
    int min = a < b ? a : b;
    int max = a > b ? a : b;
    
    // Initialize the result variable to store the final output
    int result = 0;
    
    // Continue the process while min is greater than 0
    while (min > 0) {
        // Add the quotient of max divided by min to the result
        result += max / min;
        
        // Update max to be the remainder of max divided by min
        max = max % min;
        
        // Update min and max for the next iteration
        int curr_min = min < max ? min : max;
        int curr_max = min > max ? min : max;
        min = curr_min;
        max = curr_max;
    }
    
    // Return the final result
    return result;
}

int main() {
    // Create a Scanner object to read input from the console
    int n;
    scanf("%d", &n);
    
    // Loop through each test case
    for (int i = 0; i < n; i++) {
        // Read two integers a and b from user input
        int a, b;
        scanf("%d %d", &a, &b);
        
        // Call the sub method and print the result
        printf("%d\n", sub(a, b));
    }
    
    return 0;
}
