
#include <iostream> // Importing the iostream library to read input from the user

int main() {
    int a, b; // Declaring two integer variables a and b
    
    std::cin >> a >> b; // Reading the first and second integer inputs from the user
    
    // Checking if the first number is positive
    if (a > 0) {
        std::cout << "Positive" << std::endl; // Printing "Positive" if the first number is greater than 0
    } 
    // Checking if the first number is zero or the second number is non-negative
    else if (b >= 0) {
        std::cout << "Zero" << std::endl; // Printing "Zero" if the second number is non-negative
    } 
    // Checking if the difference between b and a plus one is even
    else if ((b - a + 1) % 2 == 0) {
        std::cout << "Positive" << std::endl; // Printing "Positive" if the difference is even
    } 
    else {
        std::cout << "Negative" << std::endl; // Printing "Negative" if none of the above conditions are met
    }
    
    return 0; // Returning 0 to indicate successful execution of the program
}

