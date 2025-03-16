#include <iostream>
#include <iomanip>
#include <cmath>
#include <exception>

int main() {
    try {
        double input;
        std::cin >> input;

        // Calculate the number of odd numbers in the input
        double countOdd = std::round(input / 2);

        // Calculate the ratio
        double ratio = countOdd / input;

        // Print the result with 10 decimal places
        std::cout << std::fixed << std::setprecision(10) << ratio << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}
