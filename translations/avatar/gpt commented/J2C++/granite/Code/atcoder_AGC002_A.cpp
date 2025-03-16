
#include <iostream> // Importing the iostream library for input/output operations

int main() {
    // Creating a stream object to read input from the console
    std::cin.sync_with_stdio(false); // Disabling buffering for input/output operations
    
    int a, b; // Declaring two integer variables 'a' and 'b'
    
    // Reading two integer values from the user
    std::cin >> a >> b;
    
    // Checking if the first integer 'a' is positive
    if (a > 0) {
        std::cout << "Positive" << std::endl; // Output "Positive" if 'a' is greater than 0
    } 
    // Checking if the second integer 'b' is non-negative (zero or positive)
    else if (b >= 0) {
        std::cout << "Zero" << std::endl; // Output "Zero" if 'b' is greater than or equal to 0
    } 
    // Checking if the difference between 'b' and 'a' plus 1 is even
    else if ((b - a + 1) % 2 == 0) {
        std::cout << "Positive" << std::endl; // Output "Positive" if the result is even
    } 
    // If none of the above conditions are met, it means the result is negative
    else {
        std::cout << "Negative" << std::endl; // Output "Negative" for all other cases
    }
    
    return 0; // Returning 0 to indicate successful execution of the program
}
