
#include <iostream>

int main() {
    // Declare two integer variables to hold the input values
    int a, b;

    // Read two integers from the user input
    std::cin >> a >> b;

    // Check if 500 times the value of 'a' is greater than or equal to 'b'
    if (500 * a >= b) 
        // If the condition is true, print "Yes"
        std::cout << "Yes\n";
    else 
        // If the condition is false, print "No"
        std::cout << "No\n";

    // Return 0 to indicate successful execution of the program
    return 0;
}


