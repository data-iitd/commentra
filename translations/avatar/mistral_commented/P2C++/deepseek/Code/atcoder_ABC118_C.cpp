#include <iostream>
#include <vector>
#include <numeric> // For std::gcd in C++17 and above

int main() {
    int N;
    std::cin >> N;

    std::vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        std::cin >> A[i];
    }

    // Use std::gcd from C++17 to calculate the GCD of all integers in the list A
    int gcd = A[0];
    for (int i = 1; i < N; ++i) {
        gcd = std::gcd(gcd, A[i]);
    }

    // Print the result, which is the GCD of all the integers in the list A
    std::cout << gcd << std::endl;

    return 0;
}
