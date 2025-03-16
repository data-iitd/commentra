#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    vi arr;
    while (n % 2 == 0) {
        arr.pb(2);
        n /= 2;
    }
    int f = 3;
    while (f * f <= n) {
        if (n % f == 0) {
            arr.pb(f);
            n /= f;
        } else {
            f += 2;
        }
    }
    if (n!= 1) arr.pb(n);
    int ans = 0;
    for (int p : arr) {
        int x = p;
        for (int i = 1; i < 100000000; i++) {
            if (x >= i) {
                x -= i;
                ans++;
            } else {
                break;
            }
        }
    }
    cout << ans << "\n";
    return 0;
}

