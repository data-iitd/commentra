#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <queue>
#include <set>
#include <map>
#include <iomanip>
#include <functional>
#include <cstring>
#include <stack>
#include <sstream>
#include <list>
#include <bitset>
#include <assert.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

#define all(x) (x).begin(), (x).end()
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define fi first
#define se second
#define gcd __gcd
#define lcm(a, b) (a) * (b) / gcd(a, b)
#define setp(x) fixed << setprecision(x)
#define INF 1000000000
#define LINF 1000000000000000000
#define EPS 1e-9
#define PI 3.14159265358979323846264338327950288419716939937510

const int MOD = 1e9 + 7;
const int MAXN = 1e5 + 5;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string s;
    int k;
    cin >> s >> k;

    int l = 0;
    for (char c : s) {
        if (c != '1') {
            break;
        }
        l++;
    }

    if (l >= k) {
        cout << 1 << endl;
    } else {
        cout << s[l] << endl;
    }

    return 0;
}
