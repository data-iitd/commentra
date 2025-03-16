#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//=====I/O=====
void scanInt(int &a) {
    cin >> a;
}

void scanInts(int n, vector<int> &res) {
    res.resize(n);
    for (int i = 0; i < n; i++) {
        scanInt(res[i]);
    }
}

void printInts(const vector<int> &a) {
    for (size_t i = 0; i < a.size(); i++) {
        cout << a[i];
        if (i != a.size() - 1) {
            cout << " ";
        }
    }
    cout << endl;
}

//=====main=====
const int mod = 1000000007;

int modpow(int a, int n) {
    int res = 1;
    while (n > 0) {
        if (n & 1) {
            res = (1LL * res * a) % mod;
        }
        a = (1LL * a * a) % mod;
        n >>= 1;
    }
    return res;
}

int main() {
    int n;
    scanInt(n);

    vector<int> c;
    scanInts(n, c);

    long long ans = 0;
    sort(c.begin(), c.end());

    for (int i = 0; i < n; i++) {
        ans = (ans + (long long)(n + 1 - i) * c[i] % mod) % mod;
    }

    cout << (ans * modpow(4, n - 1) % mod) << endl;

    return 0;
}

// <END-OF-CODE>
