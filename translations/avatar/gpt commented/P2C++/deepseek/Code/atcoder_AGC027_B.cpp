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

    // Calculate the cumulative sum of the list A
    std::vector<int> S(N);
    std::partial_sum(A.begin(), A.end(), S.begin());

    // Initialize the answer to a very large number (infinity)
    int ans = std::numeric_limits<int>::max();

    // Iterate through the cumulative sums with an index starting from 1
    for (int k = 1; k <= N; ++k) {
        int E = k * X + 2 * (S[N - 1] - S[k - 1] - (N - k - 1) * S[k - 1]);
        ans = std::min(ans, E);
    }

    // Print the final result, which includes the minimum value found, adjusted by N * X and 5 times the last cumulative sum
    std::cout << ans + N * X + 5 * S[N - 1] << std::endl;

    return 0;
}
