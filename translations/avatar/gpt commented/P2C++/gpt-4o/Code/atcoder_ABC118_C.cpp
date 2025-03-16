#include <iostream>
#include <vector>
#include <numeric> // for std::gcd
#include <algorithm> // for std::reduce

int main() {
    // Read an integer input N, which represents the number of elements in the list
    int N;
    std::cin >> N;

    // Read the elements into a vector A
    std::vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        std::cin >> A[i];
    }

    // Calculate the GCD of all elements in the vector A
    int gcd = A[0];
    for (int i = 1; i < N; ++i) {
        gcd = std::gcd(gcd, A[i]);
    }

    // Print the calculated GCD
    std::cout << gcd << std::endl;

    return 0;
}

// <END-OF-CODE>
