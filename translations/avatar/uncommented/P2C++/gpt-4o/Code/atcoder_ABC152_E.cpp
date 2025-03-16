#include <iostream>
#include <vector>
#include <numeric> // for std::gcd
using namespace std;

const int MOD = 1e9 + 7;

long long lcm(long long a, long long b) {
    return a * (b / std::gcd(a, b));
}

int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    long long _lcm = 1;
    for (int a : A) {
        _lcm = lcm(_lcm, a);
    }

    long long ans = _lcm;
    for (int s : A) {
        ans = (ans + _lcm * pow(s, MOD - 2) % MOD) % MOD;
    }

    cout << ans << endl;
    return 0;
}

// <END-OF-CODE>
