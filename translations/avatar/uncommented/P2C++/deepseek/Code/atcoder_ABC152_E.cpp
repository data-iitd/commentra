#include <iostream>
#include <vector>
#include <numeric> // for gcd
#include <cmath> // for pow

using namespace std;

const int MOD = 1000000007;

int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int lcm(int a, int b) {
    return a * b / gcd(a, b);
}

int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    int _lcm = 1;
    for (int a : A) {
        _lcm = _lcm * a / gcd(_lcm, a);
    }

    long long ans = 0;
    for (int s : A) {
        ans += pow(s, MOD - 2) % MOD;
    }
    ans = _lcm * ans % MOD;
    cout << ans % MOD << endl;

    return 0;
}
