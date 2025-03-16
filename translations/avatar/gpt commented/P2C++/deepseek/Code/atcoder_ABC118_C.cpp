#include <iostream>
#include <vector>
#include <numeric> // For std::gcd in C++17 and later

int main() {
    int N;
    std::cin >> N;

    std::vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        std::cin >> A[i];
    }

    // Calculate the GCD of all elements in the list A using std::gcd
    int gcd = A[0];
    for (int i = 1; i < N; ++i) {
        gcd = std::gcd(gcd, A[i]);
    }

    // Print the calculated GCD
    std::cout << gcd << std::endl;

    return 0;
}
