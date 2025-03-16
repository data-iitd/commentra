
#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
const ll mod = 998244353;
int main() {
    int A, B, C, D;
    cin >> A >> B >> C >> D;
    vector<vector<ll>> d(C + 1, vector<ll>(D + 1));
    d[A][B] = 1;
    for (int i = A; i <= C; i++) {
        for (int j = B; j <= D; j++) {
            d[i][j] = (d[i][j - 1] * i % mod + d[i - 1][j] * j % mod - d[i - 1][j - 1] * (i - 1) % mod * (j - 1) % mod + mod) % mod;
        }
    }
    cout << d[C][D] << endl;
    return 0;
}
