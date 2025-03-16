#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

int main() {
    int N, L, R, QL, QR;
    std::cin >> N >> L >> R >> QL >> QR;
    std::vector<int> W(N);
    std::vector<int> sum(N + 1, 0);

    for (int n = 0; n < N; n++) {
        std::cin >> W[n];
        sum[n + 1] = sum[n] + W[n];
    }

    long long min = LLONG_MAX;

    for (int firstR = 0; firstR <= N; firstR++) {
        int lCount = firstR;
        int rCount = N - lCount;

        long long cand = sum[lCount] * L + (sum[N] - sum[lCount]) * R;

        int llCount = std::max(0, lCount - rCount - 1);
        int rrCount = std::max(0, rCount - lCount - 1);
        cand += llCount * QL;
        cand += rrCount * QR;

        min = std::min(cand, min);
    }

    std::cout << min << std::endl;

