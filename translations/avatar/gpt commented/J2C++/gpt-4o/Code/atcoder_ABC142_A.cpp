#include <iostream>
#include <iomanip>
#include <stdexcept>

int main() {
    try {
        // Read a line of input and parse it as a double
        double input;
        std::cin >> input;

        // Calculate the count of odd numbers based on the input
        double countOdd = std::round(input / 2);

        // Calculate the result of the division
        double result = countOdd / input;

        // Set the precision of the result to 10 decimal places
        std::cout << std::fixed << std::setprecision(10) << result << std::endl;
    } catch (const std::ios_base::failure& e) {
        // Handle input/output exceptions
        std::cerr << e.what() << std::endl;
        return 1;
    } catch (const std::exception& e) {
        // Handle any other exceptions that may occur
        std::cerr << e.what() << std::endl;
        return 1;
    }
    return 0;
}

// <END-OF-CODE>
