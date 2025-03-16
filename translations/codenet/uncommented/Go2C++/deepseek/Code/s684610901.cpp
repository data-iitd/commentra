#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <sstream>
#include <iomanip>
#include <map>
#include <set>
#include <utility>
#include <queue>
#include <numeric>
#include <functional>
#include <bitset>
#include <stack>
#include <array>
#include <regex>

using namespace std;

#define rep(i, n) for (int i = 0; i < (n); ++i)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define endl '\n'

using ll = long long;
using P = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vi>;
using vl = vector<ll>;
using vvl = vector<vl>;
using vs = vector<string>;
using vP = vector<P>;

const int INF = 1e9;
const ll LINF = 1e18;
const double PI = acos(-1.0);
const double EPS = 1e-10;
const int MOD = 1e9 + 7;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int A, B, C;
    cin >> A >> B >> C;
    if (C >= A && C <= B) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}
