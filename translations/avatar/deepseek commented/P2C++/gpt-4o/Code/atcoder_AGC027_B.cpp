#include <iostream>
#include <vector>
#include <numeric>
#include <limits>

int main() {
    // Step 1: Reading Input
    int N, X;
    std::cin >> N >> X;
    std::vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        std::cin >> A[i];
    }

    // Step 2: Accumulating Sums
    std::vector<long long> S(N);
    S[0] = A[0];
    for (int i = 1; i < N; ++i) {
        S[i] = S[i - 1] + A[i];
    }

    // Step 3: Initializing Answer
    long long ans = std::numeric_limits<long long>::infinity();

    // Step 4: Calculating Energy
    for (int k = 1; k <= N; ++k) {
        long long E = k * X;
        for (int j = N - 2 * k - 1; j >= 0; j -= k) {
            E += 2 * S[j];
        }
        ans = std::min(ans, E);
    }

    // Step 5: Final Calculation
    std::cout << ans + N * X + 5 * S[N - 1] << std::endl;

    return 0;
}
// <END-OF-CODE>
