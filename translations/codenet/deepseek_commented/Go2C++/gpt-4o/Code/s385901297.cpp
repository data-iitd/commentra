#include <iostream> // Importing the iostream library for input and output operations
#include <vector>   // Importing the vector library for using dynamic arrays
#include <algorithm> // Importing the algorithm library for sorting operations

int main() {
    std::vector<int> ns(4); // Create a vector of integers with a size of 4

    for (int i = 0; i < 4; ++i) {
        std::cin >> ns[i]; // Read four integers from the input and store them in the vector ns
    }

    std::sort(ns.begin(), ns.end()); // Sort the vector ns in ascending order

    // Check if the sorted vector ns contains the numbers 1, 4, 7, and 9 in that order
    if (ns[0] == 1 && ns[1] == 4 && ns[2] == 7 && ns[3] == 9) {
        std::cout << "YES" << std::endl; // Print "YES" if the condition is true
    } else {
        std::cout << "NO" << std::endl; // Print "NO" if the condition is false
    }

    return 0; // Return 0 to indicate successful execution
}

// <END-OF-CODE>
