#include <iostream>
#include <vector>
#include <numeric>
#include <functional>
#include <iterator>

int main() {
    int N;
    std::cin >> N;
    std::vector<int> a(N);
    for (int i = 0; i < N; ++i) {
        std::cin >> a[i];
    }

    int total = std::accumulate(a.begin(), a.end(), 0, std::bit_xor<int>());

    for (const auto& ai : a) {
        std::cout << (ai ^ total) << " ";
    }
    std::cout << std::endl;

    return 0;
}

// <END-OF-CODE>
