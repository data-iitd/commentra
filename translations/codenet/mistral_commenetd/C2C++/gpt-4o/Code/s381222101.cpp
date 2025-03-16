#include <iostream> // Include the iostream library for input/output

int main() // Declare the main function
{
    int a, b, h; // Declare three integer variables: a, b, and h

    std::cout << "Enter the values of a, b, and h: "; // Print a message asking for user input
    std::cin >> a >> b >> h; // Read three integers from the user and store them in variables a, b, and h

    // Calculate the area of the rectangle using the formula: area = (a + b) * h / 2
    std::cout << (a + b) * h / 2 << std::endl; // Print the result, which is the area of the rectangle

    return 0; // Indicate that the program has run successfully
}

// <END-OF-CODE>
