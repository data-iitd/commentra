#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    const int mod = 1000000007;
    int N, A, B;
    cin >> N >> A >> B;
    int ans = 0;
    int rep = N / (A + B);
    ans += rep * A;
    int res = N - rep * (A + B);
    ans += min(res, A);
    cout << ans << '\n';

    return 0;
}

