#include <iostream> // Include iostream for input and output
#include <iomanip>  // Include iomanip for setting precision
#include <stdexcept> // Include stdexcept for exception handling

int main() {
    try { // Begin try block for handling normal input and calculation
        double input;
        std::cin >> input; // Read input from standard input

        // Calculate the number of odd numbers in the input
        double countOdd = std::round(input / 2);

        // Calculate the result
        double result = countOdd / input;

        // Set the precision for the output
        std::cout << std::fixed << std::setprecision(10) << result << std::endl; // Print the result
    } catch (const std::ios_base::failure& e) { // Catch block for handling I/O errors
        std::cerr << e.what() << std::endl; // Print the error message
        return 0; // Exit the program with a zero status code
    } catch (const std::invalid_argument& e) { // Catch block for handling number format errors
        std::cerr << e.what() << std::endl; // Print the error message
        return 0; // Exit the program with a zero status code
    } catch (const std::exception& e) { // Catch block for handling other exceptions
        std::cerr << e.what() << std::endl; // Print the error message
        return 0; // Exit the program with a zero status code
    }
    return 0; // Exit the program with a zero status code
}

// <END-OF-CODE>
