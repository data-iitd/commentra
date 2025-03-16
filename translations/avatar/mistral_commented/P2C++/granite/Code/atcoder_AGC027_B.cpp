
#include <iostream>
#include <vector>
#include <numeric>

int main() {
    int N, X;
    std::cin >> N >> X;
    std::vector<int> A(N - 1);
    for (int i = 0; i < N - 1; i++) {
        std::cin >> A[i];
    }
    std::vector<int> S(N - 1);
    std::partial_sum(A.begin(), A.end(), S.begin());
    int ans = 1 << 30;
    for (int k = 1; k <= N / 3; k++) {
        int E = k * X + 2 * std::accumulate(S.begin() + N - 2 * k - 1, S.end(), 0, [k](int a, int b) { return a + b / k; });
        ans = std::min(ans, E);
    }
    std::cout << ans + N * X + 5 * S[N - 2] << std::endl;
    return 0;
}

