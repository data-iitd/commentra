#include <bits/stdc++.h>
using namespace std;

#define int long long
#define rep(i, n) for (int i = 0; i < (n); i++)
#define reps(i, n) for (int i = 1; i <= (n); i++)
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define fi first
#define se second
#define popcount __builtin_popcount
#define eb emplace_back
#define sz(x) (int)(x).size()
#define gcd __gcd
#define INF 1e18
#define MOD 1000000007
#define PI 3.1415926535897932384626433832795028841971
#define endl '\n'

int input() {
    int n;
    cin >> n;
    return n;
}

vector<int> LIST() {
    string s;
    getline(cin, s);
    stringstream ss(s);
    vector<int> v;
    int num;
    while (ss >> num) {
        v.pb(num);
    }
    return v;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N = input();
    vector<int> A = LIST();
    vector<int> B;
    for (int i = 0; i < N; i++) {
        if (i == 0 || A[i] != A[i - 1]) {
            B.pb(A[i]);
        }
    }
    N = B.size();
    int i = 1;
    int ans = 0;
    while (i < N - 1) {
        if ((B[i - 1] < B[i] && B[i] > B[i + 1]) || (B[i - 1] > B[i] && B[i] < B[i + 1])) {
            ans++;
            i += 1;
        }
        i++;
    }
    cout << ans + 1 << endl;

    return 0;
}
