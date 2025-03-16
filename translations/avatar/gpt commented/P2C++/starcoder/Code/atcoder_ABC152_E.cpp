#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    int _lcm = 1;
    for (int a : A) {
        _lcm = _lcm * a / __gcd(_lcm, a);
    }

    int ans = _lcm * accumulate(A.begin(), A.end(), 0, [](int a, int b) { return (a + b) % MOD; }) % MOD;
    cout << ans << "\n";

    return 0;
}

