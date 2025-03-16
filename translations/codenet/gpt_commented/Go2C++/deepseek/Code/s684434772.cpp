#include <iostream>
#include <vector>
#include <cmath>
#include <string>

using namespace std;

const int MOD = 1e9 + 7;

int64_t combi(int n, int k) {
    int64_t min = int64_t(k - 1) * k / 2;
    int64_t max = int64_t(2 * n - k + 1) * k / 2;
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
