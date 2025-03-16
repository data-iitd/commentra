#include <iostream>
#include <vector>
#include <numeric> // for std::accumulate
#include <functional> // for std::bit_xor
#include <sstream> // for std::ostringstream

int main() {
    int N;
    std::cin >> N; // Read an integer input N (not used in further calculations)

    std::vector<int> a(N); // Create a vector of integers with size N
    for (int i = 0; i < N; ++i) {
        std::cin >> a[i]; // Read the list of integers from input
    }

    // Calculate the total using the XOR operation across all elements in the vector 'a'
    int total = std::accumulate(a.begin(), a.end(), 0, std::bit_xor<int>());

    // For each element in the vector 'a', compute the XOR with 'total' and store results
    std::ostringstream result;
    for (const auto& ai : a) {
        result << (ai ^ total) << " "; // Append the result to the string stream
    }

    // Print the results
    std::cout << result.str() << std::endl;

    return 0;
}

// <END-OF-CODE>
