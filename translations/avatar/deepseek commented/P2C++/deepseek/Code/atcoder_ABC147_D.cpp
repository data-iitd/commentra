#include <iostream>
#include <vector>
#include <bitset>
#include <numeric> // for std::accumulate

int main() {
    int N;
    std::cin >> N;

    std::vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        std::cin >> A[i];
    }

    long long result = 0;

    for (int b = 0; b < 60; ++b) {
        int bs = 0;
        for (int i = 0; i < N; ++i) {
            if ((A[i] >> b) & 1) {
                ++bs;
            }
        }
        result = (result + bs * (N - bs) * (1LL << b)) % 1000000007;
    }

    std::cout << result << std::endl;

    return 0;
}
