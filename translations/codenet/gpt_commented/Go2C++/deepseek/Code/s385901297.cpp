#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    // Initialize a vector to hold four integers
    std::vector<int> ns(4);

    // Read four integers from standard input
    for (int i = 0; i < 4; ++i) {
        std::cin >> ns[i];
    }

    // Sort the vector of integers in ascending order
    std::sort(ns.begin(), ns.end());

    // Check if the sorted integers match the specific sequence [1, 4, 7, 9]
    if (ns[0] == 1 && ns[1] == 4 && ns[2] == 7 && ns[3] == 9) {
        // If they match, print "YES"
        std::cout << "YES" << std::endl;
    } else {
        // If they do not match, print "NO"
        std::cout << "NO" << std::endl;
    }

    return 0;
}
