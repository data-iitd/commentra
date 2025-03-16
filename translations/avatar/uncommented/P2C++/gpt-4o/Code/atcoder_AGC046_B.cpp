#include <iostream>
#include <vector>

using namespace std;

int main() {
    int A, B, C, D;
    cin >> A >> B >> C >> D;
    const int m = 998244353;
    vector<vector<long long>> d(C + 1, vector<long long>(D + 1, 0));
    d[A][B] = 1;

    for (int i = A; i <= C; ++i) {
        for (int j = B; j <= D; ++j) {
            d[i][j] = (d[i][j] + (d[i][j - 1] * i % m + d[i - 1][j] * j % m - d[i - 1][j - 1] * (i - 1) % m * (j - 1) % m + m) % m)) % m;
        }
    }

    cout << d[C][D] << endl;
    return 0;
}

// <END-OF-CODE>
