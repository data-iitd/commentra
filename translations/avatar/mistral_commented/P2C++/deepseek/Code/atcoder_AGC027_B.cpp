#include <iostream>
#include <vector>
#include <numeric> // for std::accumulate
#include <algorithm> // for std::min

int main() {
    int N, X;
    std::cin >> N >> X;
    std::vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        std::cin >> A[i];
    }

    // Create a new vector S by applying the accumulate function to the vector A
    std::vector<int> S(N);
    std::partial_sum(A.begin(), A.end(), S.begin());

    // Initialize a variable ans with a large value
    long long ans = std::numeric_limits<long long>::max();

    // Iterate through each element s in the vector S
    for (int k = 1; k <= N; ++k) {
        int s = S[k - 1];
        // Calculate the energy consumption E for the current index k
        long long E = k * X + 2 * (S.back() - S[k - 1] - (N - 2 * k) * S[k - 1]);

        // Update the minimum energy consumption ans if the current energy consumption E is smaller
        ans = std::min(ans, E);
    }

    // Print the result
    std::cout << ans + N * X + 5 * S.back() << std::endl;

    return 0;
}
