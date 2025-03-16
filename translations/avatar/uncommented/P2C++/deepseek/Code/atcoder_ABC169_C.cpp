#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <functional>
#include <cmath>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <bitset>
#include <sstream>
#include <cassert>
#include <fstream>
#include <cstring>
#include <chrono>
#include <random>
#include <climits>
#include <utility>
#include <cstdlib>

using namespace std;

#define debug(...) fprintf(stderr, __VA_ARGS__)
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define t_max3(x, y, z) max(x, max(y, z))
#define t_min3(x, y, z) min(x, min(y, z))
#define t_max4(a, b, c, d) max(max(a, b), max(c, d))
#define t_min4(a, b, c, d) min(min(a, b), min(c, d))
#define t_umax(a, b) if (b > a) a = b;
#define t_umin(a, b) if (b < a) a = b;
#define t_swap(a, b) {a = a ^ b; b = a ^ b; a = a ^ b;}

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vpii;
typedef pair<ll, ll> pll;
typedef vector<ll> vll;
typedef vector<pll> vpll;

const int MOD = 1e9 + 7;
const int INF = 1e9 + 10;
const ll LINF = 1LL << 60;

void main_() {
    string sa, sb;
    cin >> sa >> sb;
    int a = stoi(sa);
    int b = static_cast<int>(stod(sb) * 100 + 0.1);
    cout << (a * b) / 100 << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    main_();
    return 0;
}
