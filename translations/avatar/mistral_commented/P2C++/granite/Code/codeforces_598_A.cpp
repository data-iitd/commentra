
#####
# Code
#####

# Include the necessary header file
#include <iostream>

// Define the main function
int main() {
    // Take an integer input from the user
    int t;
    std::cin >> t;
    
    // Run the loop 't' number of times
    while (t--) {
        // Take an integer input from the user for 'n'
        int n;
        std::cin >> n;
        
        // Define a variable's' and initialize it with the value 1
        int s = 1;
        
        // Run the while loop as long as's' is less than or equal to 'n'
        while (s <= n) {
            // Subtract the contribution of's' from the sum 'n'
            n -= 2 * s;
            
            // Multiply the value of's' by 2 and update its value
            s *= 2;
        }
        
        // Print the final value of 'n'
        std::cout << n << std::endl;
    }
    
    // End the program
    return 0;
}

