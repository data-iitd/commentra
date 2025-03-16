

#include <iostream> // Include iostream for input and output
#include <cmath> // Include cmath for mathematical functions
#include <iomanip> // Include iomanip for setting precision and rounding mode

int main() {
    try { // Begin try block for handling normal input and calculation
        double input; // Declare input variable as a double
        std::cin >> input; // Read input from standard input

        // Calculate the number of odd numbers in the input
        double countOdd = std::round(input / 2);

        // Create a double variable for the result
        double result = countOdd / input;

        // Set the precision and rounding mode for the result
        result = std::round(result * 1000000000.0) / 1000000000.0;

        // Print the result
        std::cout << std::fixed << std::setprecision(10) << result << std::endl;
    } catch (std::exception& e) { // Begin catch block for handling exceptions
        std::cerr << "Error: " << e.what() << std::endl; // Print the error message
    }

    return 0; // Return a zero status code
}

