#include <iostream>
#include <iomanip>

int main() {
    // Declare variables to store input value and average
    double a;
    double ave = 0;
    
    // Loop to read 5 input values
    for (int i = 0; i < 5; i++) {
        // Read a double value from user input
        std::cin >> a;
        
        // Check if the input value is less than or equal to 40
        if (a <= 40) {
            // If so, add 40 to the average instead of the input value
            ave += 40;
        } else {
            // Otherwise, add the input value to the average
            ave += a;
        }
    }
    
    // Calculate the average by dividing the total by the number of inputs (5)
    ave /= 5.0;
    
    // Print the calculated average, formatted as an integer
    std::cout << std::fixed << std::setprecision(0) << ave << std::endl;
    
    // Return 0 to indicate successful completion of the program
    return 0;
}

// <END-OF-CODE>
