#include <iostream>
#include <vector>
#include <cstdint>

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

        int64_t contribution = bs * (N - bs) * (1LL << b);
        result = (result + contribution) % 1000000007;
    }

    std::cout << result << std::endl;

    return 0;
}

