#include <iostream>
#include <vector>
#include <numeric> // for std::gcd
#include <algorithm> // for std::reduce

int main() {
    int N;
    std::cin >> N;
    std::vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        std::cin >> A[i];
    }

    // Calculate GCD of the entire array
    int gcd = A[0];
    for (int i = 1; i < N; ++i) {
        gcd = std::gcd(gcd, A[i]);
    }

    std::cout << gcd << std::endl;
    return 0;
}

// <END-OF-CODE>
