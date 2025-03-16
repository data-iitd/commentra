#include <iostream>
#include <vector>
#include <numeric>  // For std::gcd

using namespace std;

const long long MOD = 1000000007;

// Function to calculate the least common multiple (LCM) of two numbers
long long lcm(long long a, long long b) {
    return a / gcd(a, b) * b;
}

int main() {
    int N;
    cin >> N;
    vector<long long> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    long long _lcm = 1;
    for (long long a : A) {
        _lcm = lcm(_lcm, a);
    }

    long long ans = 0;
    for (long long s : A) {
        ans = (ans + pow(s, MOD - 2, MOD)) % MOD;
    }
    ans = _lcm * ans % MOD;

    cout << ans << endl;

    return 0;
}
