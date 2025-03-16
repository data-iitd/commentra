#include <iostream> // Include the standard input/output library

int main(){ // Start of the main function
    int a, b; // Declare two integer variables 'a' and 'b'

    std::cin >> a >> b; // Read two integers from the standard input and store them in variables 'a' and 'b'

    std::cout << a*b << " " << 2*(a+b) << std::endl; // Print the product of 'a' and 'b' followed by the double of their sum

    return 0; // Indicate successful execution of the program
}

