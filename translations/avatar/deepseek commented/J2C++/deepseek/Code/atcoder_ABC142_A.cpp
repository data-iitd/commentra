#include <iostream>
#include <iomanip>
#include <cmath>
#include <exception>

// Include statements to handle input/output operations and mathematical calculations

int main() {
    try {
        double input;
        std::cin >> input;

        // Reading a double value from the input

        double countOdd = std::round(input / 2);

        // Calculating the number of odd numbers up to the given input

        double result = countOdd / input;

        // Using double for the result to handle precise decimal calculations

        std::cout << std::fixed << std::setprecision(10) << result << std::endl;

        // Printing the result with a precision of 10

    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
        return 1;

        // Handling any exceptions to ensure program termination

    }

    return 0;
}

