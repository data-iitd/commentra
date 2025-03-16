#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <numeric> // For std::gcd in C++17 and later

int main() {
    int N;
    std::cin >> N;

    std::vector<int> A(5);
    for (int i = 0; i < 5; ++i) {
        std::cin >> A[i];
    }

    int min_A = *std::min_element(A.begin(), A.end());
    int result = std::ceil(static_cast<double>(N) / min_A) + 4;

    std::cout << result << std::endl;

    return 0;
}
