#include <iostream>
#include <vector>
#include <numeric>
#include <limits>

int main() {
    // Define input variables
    int N, X;
    std::cin >> N >> X;
    std::vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        std::cin >> A[i];
    }

    // Create a new vector S by applying the accumulate function to the vector A
    std::vector<long long> S(N);
    std::partial_sum(A.begin(), A.end(), S.begin());

    // Initialize a variable ans with a large value
    long long ans = std::numeric_limits<long long>::max();

    // Iterate through each element s in the vector S
    for (int k = 1; k <= N / 2; ++k) {
        // Calculate the energy consumption E for the current index k
        long long E = k * X;
        for (int j = N - 2 * k - 1; j >= 0; j -= k) {
            E += 2 * S[j];
        }

        // Update the minimum energy consumption ans if the current energy consumption E is smaller
        ans = std::min(ans, E);
    }

    // Print the result
    std::cout << ans + N * X + 5 * S.back() << std::endl;

    return 0;
}

// <END-OF-CODE>
