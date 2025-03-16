
#include <iostream>
#include <numeric>
#include <vector>

int main() {
    int N, X;
    std::cin >> N >> X;
    std::vector<int> A(N);
    for (int i = 0; i < N; i++) {
        std::cin >> A[i];
    }
    std::vector<int> S(N);
    std::partial_sum(A.begin(), A.end(), S.begin());
    int ans = 1 << 30;
    for (int k = 1; k <= N / 3; k++) {
        int E = k * X + 2 * std::accumulate(S.begin(), S.end() - k * 2, 0);
        ans = std::min(ans, E);
    }
    std::cout << ans + N * X + 5 * S.back() << std::endl;
    return 0;
}

