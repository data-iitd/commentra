#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

const int MOD = 1e9 + 7;

// Function to calculate nCr (combination)
int64_t combi(int n, int k) {
    int64_t min_val = static_cast<int64_t>(k - 1) * k / 2;
    int64_t max_val = static_cast<int64_t>(2 * n - k + 1) * k / 2;
    return max_val - min_val + 1;
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
