#include <iostream>
#include <vector>

const int mod = 998244353;
std::vector<std::vector<long long>> nchoosek(4001, std::vector<long long>(4001, 0));

void initialize() {
    for (int i = 0; i < 4001; i++) {
        nchoosek[i][0] = nchoosek[i][i] = 1;
    }
    for (int i = 2; i < 4001; i++) {
        for (int j = 1; j < i; j++) {
            nchoosek[i][j] = (nchoosek[i - 1][j] + nchoosek[i - 1][j - 1]) % mod;
        }
    }
}

int main() {
    initialize();
    int k, n;
    std::cin >> k >> n;

    for (int i = 2; i <= 2 * k; i++) {
        int pairs;
        if (i > k) {
            pairs = k - i / 2;
        } else {
            pairs = (i - 1) / 2;
        }
        int active = k - 2 * pairs;
        if (i % 2 == 0) active -= 1;

        long long times2 = 1;
        long long total = 0;

        for (int j = 0; j <= pairs; j++) {
            long long choice = times2 * nchoosek[pairs][j] % mod;
            times2 = times2 * 2 % mod;
            if (active + j - 1 < 0) continue;
            total += choice * nchoosek[n + active - 1][active + j - 1];
            if (i % 2 == 0) {
                total += choice * nchoosek[n + active - 2][active + j - 1];
            }
            total %= mod;
        }
        std::cout << total << std::endl;
    }
    return 0;
}
