#include <iostream>
#include <vector>

int main() {
    // Declare variables
    int i = 0;
    std::vector<int> x(10000, 0); // Initialize the vector x with zeros

    // Read the first input value into the vector
    std::cin >> x[i];

    // Continue reading input values until a zero is encountered
    while (x[i] != 0) {
        i++;
        std::cin >> x[i];
    }

    // Print the case number and the corresponding value from the vector
    for (int j = 0; j < i; j++) {
        std::cout << "Case " << (j + 1) << ": " << x[j] << std::endl;
    }

    return 0; // Indicate that the program ended successfully
} // <END-OF-CODE>
