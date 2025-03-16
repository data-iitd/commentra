#include <iostream>
#include <vector>
#include <numeric> // for accumulate
#include <algorithm> // for min

int main() {
    int N, X;
    std::cin >> N >> X;
    std::vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        std::cin >> A[i];
    }

    std::vector<int> S = A;
    std::partial_sum(A.begin(), A.end(), S.begin());

    int ans = std::numeric_limits<int>::max();
    for (int k = 1; k <= N; ++k) {
        int E = k * X + 2 * (S[N - 2 * k - 1] - (N - 2 * k - 1 >= 0 ? S[N - 2 * k - 1] : 0));
        ans = std::min(ans, E);
    }

    std::cout << ans + N * X + 5 * S.back() << std::endl;
    return 0;
}
