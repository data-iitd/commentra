#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    // Initialize a vector to store the input integers
    std::vector<int> ns(4);

    // Read the first line of input containing 4 integers
    std::cout << "Reading input" << std::endl;
    std::cin >> ns[0] >> ns[1] >> ns[2] >> ns[3];

    // Sort the ns vector in ascending order
    std::cout << "Sorting the numbers in ns vector" << std::endl;
    std::sort(ns.begin(), ns.end());

    // Check if the sorted ns vector matches the specific condition (1, 4, 7, 9)
    std::cout << "Checking the condition" << std::endl;
    if (ns[0] == 1 && ns[1] == 4 && ns[2] == 7 && ns[3] == 9) {
        std::cout << "The condition is true, print YES" << std::endl;
        std::cout << "Output: YES" << std::endl;
    } else {
        std::cout << "The condition is false, print NO" << std::endl;
        std::cout << "Output: NO" << std::endl;
    }

    std::cout << std::endl;
    std::cout << "End of the program" << std::endl;
    return 0;
}

// <END-OF-CODE>
