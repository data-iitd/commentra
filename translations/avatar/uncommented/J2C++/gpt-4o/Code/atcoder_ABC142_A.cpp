#include <iostream>
#include <iomanip>
#include <stdexcept>

int main() {
    try {
        double input;
        std::cin >> input;

        double countOdd = std::round(input / 2);
        double result = countOdd / input;

        // Set precision to 10 decimal places
        std::cout << std::fixed << std::setprecision(10) << result << std::endl;
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
        return 0;
    }
    return 0;
}

// <END-OF-CODE>
