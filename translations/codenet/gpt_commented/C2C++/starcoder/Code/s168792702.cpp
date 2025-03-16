#include <iostream>

int main(void) {
    // Declare three integer variables to hold the input values
    int a, b, c;

    // Read three integers from standard input
    std::cin >> a >> b >> c;
    
    // Check if the first number is less than the second, and the second is less than the third
    if (a < b && b < c) 
        std::cout << "Yes";  // If the condition is true, print "Yes"
    else 
        std::cout << "No";   // If the condition is false, print "No"
    
    return 0; // Return 0 to indicate successful completion of the program
}
