#include <iostream>

int main() {
    int x;
    std::cin >> x; // Read an integer from the input
    bool boolValue = (x == 1); // Convert the integer x to a boolean value boolValue
    int result = !boolValue ? 1 : 0; // Calculate the result based on the boolean value boolValue
    std::cout << result << std::endl; // Print the result
    return 0; // Return 0 to indicate successful execution
}

// <END-OF-CODE>
