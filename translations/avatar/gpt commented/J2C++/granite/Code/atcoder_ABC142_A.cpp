
#include <iostream>
#include <cmath>
#include <iomanip>

int main() {
    try {
        // Read a line of input and parse it as a double
        double input;
        std::cin >> input;

        // Calculate the count of odd numbers based on the input
        double countOdd = std::round(input / 2);

        // Create a BigDecimal to hold the result of the division
        double result = countOdd / input;

        // Set the scale of the result to 10 decimal places, rounding half up
        result = std::round(result * std::pow(10, 10)) / std::pow(10, 10);

        // Print the result to the console
        std::cout << std::fixed << std::setprecision(10) << result << std::endl;
    } catch (const std::exception& e) {
        // Handle any exceptions that may occur
        std::cerr << e.what() << std::endl;
        return 1;
    }

    return 0;
}
