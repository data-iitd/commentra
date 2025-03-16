
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <cmath>

int main() {
    int N;
    std::cin >> N;

    std::vector<int> A(N);
    for (int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    int gcd = std::accumulate(A.begin(), A.end(), A[0], std::gcd<int>);

    std::cout << gcd << std::endl;

    return 0;
}
