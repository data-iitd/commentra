#include <iostream>
#include <vector>
#include <numeric> // for accumulate
#include <limits> // for numeric_limits

int main() {
    int N, X;
    std::cin >> N >> X;
    std::vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        std::cin >> A[i];
    }

    // Accumulate sums
    std::vector<int> S = A;
    std::partial_sum(A.begin(), A.end(), S.begin());

    // Initialize answer to infinity
    int ans = std::numeric_limits<int>::max();

    // Calculate energy
    for (int k = 1; k <= N; ++k) {
        int E = k * X + 2 * (S[N - 2 * k - 1] - (k > 1 ? S[k - 2] : 0));
        ans = std::min(ans, E);
    }

    // Final calculation and output
    std::cout << ans + N * X + 5 * S[N - 1] << std::endl;

    return 0;
}
