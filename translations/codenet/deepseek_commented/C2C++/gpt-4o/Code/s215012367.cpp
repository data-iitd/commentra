#include <iostream> // Step 1: Include the iostream library for input/output.

int main() // Step 2: Define the main function.
{
    int a, b, s; // Step 3: Declare three integer variables: a, b, and s.

    std::cin >> a >> b; // Step 4: Read two integers from the user input and store them in variables a and b.

    s = (a * b) - (a + b) + 1; // Step 5: Calculate the value of s using the formula (a*b) - (a + b) + 1.

    std::cout << s << std::endl; // Step 6: Print the value of s.
}

// <END-OF-CODE>
