#include <iostream>
#include <vector>
#include <cstdint>

const int MOD = 1000000007;

int main() {
    int N;
    std::cin >> N;
    std::vector<int64_t> A(N);
    for (int i = 0; i < N; ++i) {
        std::cin >> A[i];
    }

    int64_t result = 0;
    for (int b = 0; b < 60; ++b) {
        int64_t bs = 0;
        for (int i = 0; i < N; ++i) {
            bs += (A[i] >> b) & 1;
        }
        result = (result + bs * (N - bs) * (1LL << b)) % MOD;
    }
    
    std::cout << result << std::endl;
    return 0;
}

// <END-OF-CODE>
