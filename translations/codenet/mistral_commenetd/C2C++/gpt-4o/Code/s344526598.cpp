#include <iostream>
#include <vector>

int main() {
    // Declare variables
    int i = 0;
    std::vector<int> x(10000, 0); // Initialize vector x with zeros

    // Read the first integer input and store it in the vector x at index i
    std::cin >> x[i];
    // Comment explaining what the line does
    // Read the first integer input and store it in the vector x

    // Read remaining integers and store them in the vector x
    while (x[i] != 0) {
        i++;
        std::cin >> x[i];
        // Comment explaining what the loop does
        // This loop reads and stores the remaining integers in the vector x
    }

    // Print the results
    for (int j = 0; j < i; j++) {
        std::cout << "Case " << j + 1 << ": " << x[j] << std::endl;
        // Comment explaining what the loop does
        // This loop prints the results for each input integer
    }

    // Signal successful termination of the program
    return 0;
}

// <END-OF-CODE>
