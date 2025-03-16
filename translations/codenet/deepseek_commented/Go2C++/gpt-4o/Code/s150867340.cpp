#include <iostream> // Including the iostream library for input and output

int main() {
    int a, b; // Declaring two integer variables `a` and `b`
    std::cin >> a >> b; // Reading two integers from the standard input
    int product = a * b; // Calculating the product
    if (product % 2 == 0) { // Checking if the product is even
        std::cout << "Even" << std::endl; // Printing "Even" if the product is even
    } else {
        std::cout << "Odd" << std::endl; // Printing "Odd" if the product is odd
    }
    return 0; // Returning 0 to indicate successful execution
}

// <END-OF-CODE>
