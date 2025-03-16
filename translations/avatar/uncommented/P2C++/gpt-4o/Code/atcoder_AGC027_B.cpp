#include <iostream>
#include <vector>
#include <numeric>
#include <limits>

int main() {
    int N, X;
    std::cin >> N >> X;
    std::vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        std::cin >> A[i];
    }

    std::vector<long long> S(N);
    std::partial_sum(A.begin(), A.end(), S.begin());

    long long ans = std::numeric_limits<long long>::infinity();
    for (int k = 1; k <= N / 2; ++k) {
        long long E = k * X + 2 * std::accumulate(S.begin() + std::max(0, N - 2 * k - 1), S.end(), 0LL);
        ans = std::min(ans, E);
    }

    std::cout << ans + N * X + 5 * S.back() << std::endl;

    return 0;
}

// <END-OF-CODE>
