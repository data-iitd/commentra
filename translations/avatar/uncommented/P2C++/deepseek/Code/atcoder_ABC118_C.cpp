#include <iostream>
#include <vector>
#include <numeric> // Include the numeric header for std::gcd

int main() {
    int N;
    std::cin >> N;
    std::vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        std::cin >> A[i];
    }
    int gcd = std::reduce(A.begin(), A.end(), 0, std::gcd<int, int>);
    std::cout << gcd << std::endl;
    return 0;
}
