#include <iostream>
#include <vector>
#include <numeric> // for std::accumulate
#include <functional> // for std::bit_xor

int main() {
    // Reading input
    int N;
    std::cin >> N;
    std::vector<int> a(N);
    for (int i = 0; i < N; ++i) {
        std::cin >> a[i];
    }

    // Calculating the XOR of all elements in the vector 'a'
    int total = std::accumulate(a.begin(), a.end(), 0, std::bit_xor<int>());

    // Printing the result
    for (const auto& ai : a) {
        std::cout << (ai ^ total) << " ";
    }
    std::cout << std::endl;

    return 0;
}

// <END-OF-CODE>
