#include <iostream>
#include <vector>
#include <numeric> // for std::accumulate
#include <unordered_map>

int main() {
    int N, M;
    std::cin >> N >> M;
    std::vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        std::cin >> A[i];
    }

    std::vector<long long> cum_remainders(N + 1, 0);
    for (int i = 0; i < N; ++i) {
        cum_remainders[i + 1] = (cum_remainders[i] + A[i]) % M;
    }

    std::unordered_map<int, int> remainder_counts;
    for (const auto& remainder : cum_remainders) {
        ++remainder_counts[remainder];
    }

    long long combinations = 0;
    for (const auto& pair : remainder_counts) {
        int count = pair.second;
        combinations += static_cast<long long>(count) * (count - 1) / 2;
    }

    std::cout << combinations << std::endl;
    return 0;
}
