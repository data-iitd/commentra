#include <iostream>
#include <vector>
using namespace std;

const int mod = 998244353;
vector<vector<long long>> nchoosek;

void compute_nchoosek(int max_n) {
    nchoosek.resize(max_n + 1, vector<long long>(max_n + 1, 0));
    for (int i = 0; i <= max_n; i++) {
        nchoosek[i][0] = nchoosek[i][i] = 1;
    }
    for (int i = 2; i <= max_n; i++) {
        for (int j = 1; j < i; j++) {
            nchoosek[i][j] = (nchoosek[i - 1][j] + nchoosek[i - 1][j - 1]) % mod;
        }
    }
}

int main() {
    int k, n;
    cin >> k >> n;
    compute_nchoosek(4000);

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
        cout << total << endl;
    }
    return 0;
}
