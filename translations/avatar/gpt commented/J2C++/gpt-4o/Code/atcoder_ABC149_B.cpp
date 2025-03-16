#include <iostream>
#include <string>
#include <sstream>

class Main {
    // Declare variables to hold the values of A, B, K, and the results x, y
    long long A, B, K; 
    long long x, y; 

public:
    // Constructor to read input values A, B, and K from standard input
    Main() {
        std::cin >> A >> B >> K;
    } 

    // Method to perform the main calculation based on A, B, and K
    void calc() {
        // Initialize x with the value of A and y with the value of B
        x = A; 
        y = B; 
        
        // Subtract K from A and assign the result to x
        x = A - K; 
        
        // Check if the result x is negative
        if (x < 0) {
            // If x is negative, adjust y by adding the negative value of x to B
            y = B + x; 
            // Set x to 0 since it cannot be negative
            x = 0; 
            
            // Ensure y is not negative
            if (y < 0) {
                y = 0; 
            } 
        } 
    } 

    // Method to display the results of the calculations
    void showResult() {
        // Print the values of x and y
        std::cout << x << " " << y << std::endl; 
    } 
};

int main() {
    // Create an instance of Main class
    Main ins; 
    
    // Perform calculations based on the input values
    ins.calc(); 
    
    // Display the results of the calculations
    ins.showResult(); 
    
    return 0;
}

// <END-OF-CODE>
