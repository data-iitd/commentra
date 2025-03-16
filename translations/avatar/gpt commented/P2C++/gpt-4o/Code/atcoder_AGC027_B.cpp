#include <iostream>
#include <vector>
#include <numeric>
#include <limits>

int main() {
    // Read input values: N (number of elements), X (a constant), and A (the list of integers)
    int N, X;
    std::cin >> N >> X;
    std::vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        std::cin >> A[i];
    }

    // Calculate the cumulative sum of the list A
    std::vector<long long> S(N);
    std::partial_sum(A.begin(), A.end(), S.begin());

    // Initialize the answer to a very large number (infinity)
    long long ans = std::numeric_limits<long long>::max();

    // Iterate through the cumulative sums with an index starting from 1
    for (int k = 1; k <= N; ++k) {
        // Calculate the expression E based on the current index k and the cumulative sums
        long long E = k * X;
        for (int j = N - 2 * k - 1; j >= 0; j -= k) {
            E += 2 * S[j];
        }

        // Update the answer with the minimum value found so far
        ans = std::min(ans, E);
    }

    // Print the final result, which includes the minimum value found, adjusted by N * X and 5 times the last cumulative sum
    std::cout << ans + N * X + 5 * S.back() << std::endl;

    return 0;
}
// <END-OF-CODE>
