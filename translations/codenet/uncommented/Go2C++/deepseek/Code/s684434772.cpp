#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

const int MOD = 1000000007;

int64_t pow64(int64_t base, uint exponent) {
    int64_t answer = 1;
    for (uint i = 0; i < exponent; ++i) {
        answer *= base;
        answer %= MOD;
    }
    return answer;
}

int64_t combi(int n, int k) {
    int64_t min = int64_t(k - 1) * int64_t(k) / 2;
    int64_t max = int64_t(2 * n - k + 1) * int64_t(k) / 2;
    return max - min + 1;
}

int main() {
    int n, k;
    cin >> n >> k;

    int64_t total = 0;
    for (int i = k; i <= n + 1; ++i) {
        total += combi(n, i);
        total %= MOD;
    }
    cout << total << endl;

    return 0;
}
