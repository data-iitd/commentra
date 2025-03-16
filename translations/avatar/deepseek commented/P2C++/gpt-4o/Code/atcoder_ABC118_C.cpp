#include <iostream>
#include <vector>
#include <numeric> // For std::gcd
#include <algorithm> // For std::reduce

int main() {
    int N; // Declare an integer N
    std::cin >> N; // Take an integer input N
    std::vector<int> A(N); // Create a vector A of size N

    for (int i = 0; i < N; ++i) {
        std::cin >> A[i]; // Take space-separated integers and assign them to the vector A
    }

    // Compute the GCD of all elements in the vector A
    int gcd = std::accumulate(A.begin(), A.end(), A[0], [](int a, int b) {
        return std::gcd(a, b); // Use std::gcd to compute the GCD
    });

    std::cout << gcd << std::endl; // Print the computed GCD
    return 0; // Return 0 to indicate successful completion
}

// <END-OF-CODE>
