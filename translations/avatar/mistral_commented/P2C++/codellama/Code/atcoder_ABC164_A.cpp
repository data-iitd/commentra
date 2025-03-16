#include <iostream>

// Define the main function that takes no arguments and returns nothing
int main( ) {

    // Get the input as a list of two integers, S and W, using the cin function
    int S, W;
    std::cin >> S >> W;

    // Check if the condition S <= W is true or false and print the corresponding message
    if ( S <= W ) {
        std::cout << "unsafe" << std::endl;
    } else {
        std::cout << "safe" << std::endl;
    }

    return 0;
}

// End of code
