#include <iostream>
#include <vector>
#include <cmath>
#include <map>
#include <queue>
#include <algorithm>
#include <limits.h>

using namespace std;

typedef long long ll;

#define INF LLONG_MAX
#define MOD 1000000007

int n;

vector<int> prime_factorize(int n) {
    vector<int> a;
    while (n % 2 == 0) {
        a.push_back(2);
        n /= 2;
    }
    for (int f = 3; f * f <= n; f += 2) {
        while (n % f == 0) {
            a.push_back(f);
            n /= f;
        }
    }
    if (n != 1) {
        a.push_back(n);
    }
    return a;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    if (n == 1) {
        cout << 0 << endl;
        return 0;
    }

    vector<int> fac_ = prime_factorize(n);
    map<int, int> fac;
    for (int p : fac_) {
        fac[p]++;
    }

    int ans = 0;
    for (auto& p : fac) {
        int x = p.second;
        for (int i = 1; i <= 99999999; ++i) {
            if (x >= i) {
                x -= i;
                ans++;
            } else {
                break;
            }
        }
    }

    cout << ans << endl;

    return 0;
}

