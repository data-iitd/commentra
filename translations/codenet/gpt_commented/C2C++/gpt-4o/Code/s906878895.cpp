#include <iostream>

int main() 
{ 
    // Declare variables to hold two integers and intermediate results
    int a, b, x, w; 
    
    // Continuously read pairs of integers until EOF (End of File) is reached
    while (std::cin >> a >> b) 
    { 
        // Calculate the sum of the two integers
        x = a + b;
        
        // Initialize a counter for the number of digits in the sum
        w = 0; 
        
        // Count the number of digits in the sum (x)
        while (x) 
        { 
            // Increment the digit counter
            w++; 
            // Remove the last digit from x by dividing by 10
            x /= 10; 
        } 
        
        // Print the number of digits in the sum
        std::cout << w << std::endl; 
    } 
    
    // Return 0 to indicate successful completion of the program
    return 0; 
} 

// <END-OF-CODE>
