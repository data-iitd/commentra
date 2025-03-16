
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>
#include <queue>
#include <set>
#include <iomanip>
#define MOD 100000007
#define endl "\n"
#define int long long
#define double long double
using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int k;
    cin >> k;
    if (k % 2 == 0 || k % 5 == 0) {
        cout << -1 << endl;
        return 0;
    }
    if (k % 7 == 0) {
        k /= 7;
    }
    k *= 9;
    int ans = 1;
    int rem = 10 % k;
    while (rem!= 1) {
        ans++;
        rem = (rem * 10) % k;
    }
    cout << ans << endl;
    return 0;
}
