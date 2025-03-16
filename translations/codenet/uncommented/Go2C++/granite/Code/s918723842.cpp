
#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <string>
#include <cassert>
#include <cstdlib>
#include <ctime>
#include <queue>
#include <stack>
#include <bitset>
#include <numeric>
#include <iomanip>
#include <cctype>
#include <random>
#include <chrono>

using namespace std;

typedef long long ll;
typedef pair<int, int> P;
typedef pair<ll, ll> Pll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<ll> vll;
typedef vector<vector<ll>> vvll;
typedef vector<char> vc;
typedef vector<string> vs;
typedef vector<P> vp;
typedef vector<vp> vvp;
typedef priority_queue<int> PQ;

#define rep(i, n) for (int i = 0; i < (n); i++)
#define rrep(i, n) for (int i = (n)-1; i >= 0; i--)
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define debug(x) cout << #x << ": " << x << endl;
#define debug2(x, y) cout << #x << ": " << x << ", " << #y << ": " << y << endl;
#define debug3(x, y, z) cout << #x << ": " << x << ", " << #y << ": " << y << ", " << #z << ": " << z << endl;
#define debug_v(v) cout << #v << ": "; for (auto x : v) cout << x << " "; cout << endl;
#define debug_v2(v) cout << #v << ": " << endl; for (auto x : v) cout << x.first << " " << x.second << endl;
#define debug_v_all(v) cout << #v << ": "; for (auto &x : v) cout << x << " "; cout << endl;
#define debug_vp(v) cout << #v << ": " << endl; for (auto &x : v) cout << x.first << " " << x.second << endl;
#define debug_vpp(v) cout << #v << ": " << endl; for (auto &x : v) cout << x.first.first << " " << x.first.second << " " << x.second << endl;
#define debug_vpll(v) cout << #v << ": " << endl; for (auto &x : v) cout << x.first.first << " " << x.first.second << " " << x.second.first << " " << x.second.second << endl;
#define debug_vppp(v) cout << #v << ": " << endl; for (auto &x : v) cout << x.first.first << " " << x.first.second << " " << x.second.first.first << " " << x.second.first.second << " " << x.second.second.first << " " << x.second.second.second << endl;
#define debug_vll(v) cout << #v << ": "; for (auto x : v) cout << x << " "; cout << endl;
#define debug_vpll(v) cout << #v << ": "; for (auto x : v) cout << x.first << " " << x.second << endl;
#define debug_vplll(v) cout << #v << ": " << endl; for (auto &x : v) cout << x.first << " " << x.second.first << " " << x.second.second << endl;
#define debug_vpllll(v) cout << #v << ": " << endl; for (auto &x : v) cout << x.first << " " << x.second.first.first << " " << x.second.first.second << " " << x.second.second.first << " " << x.second.second.second << endl;
#define debug_vplllll(v) cout << #v << ": " << endl; for (auto &x : v) cout << x.first << " " << x.second.first.first << " " << x.second.first.second << " " << x.second.second.first.first << " " << x.second.second.first.second << " " << x.second.second.second.first << " " << x.second.second.second.second << endl;
#define debug_vpllllll(v) cout << #v << ": " << endl; for (auto &x : v) cout << x.first << " " << x.second.first.first << " " << x.second.first.second << " " << x.second.second.first.first << " " << x.second.second.first.second << " " << x.second.second.second.first << " " << x.second.second.second.second << " " << x.second.second.second.second << endl;
#define debug_vplllllll(v) cout << #v << ": " << endl; for (auto &x : v) cout << x.first << " " << x.second.first.first << " " << x.second.first.second << " " << x.second.second.first.first << " " << x.second.second.first.second << " " << x.second.second.second.first << " " << x.second.second.second.second << " " << x.second.second.second.second << " " << x.second.second.second.second << endl;
#define debug_vpllllllll(v) cout << #v << ": " << endl; for (auto &x : v) cout << x.first << " " << x.second.first.first << " " << x.second.first.second << " " << x.second.second.first.first << " " << x.second.second.first.second << " " << x.second.second.second.first << " " << x.second.second.second.second << " " << x.second.second.second.second << " " << x.second.second.second.second << " " << x.second.second.second.second << endl;
#define debug_vplllllllll(v) cout << #v << ": " << endl; for (auto &x : v) cout << x.first << " " << x.second.first.first << " " << x.second.first.second << " " << x.second.second.first.first << " " << x.second.second.first.second << " " << x.second.second.second.first << " " << x.second.second.second.second << " " << x.second.second.second.second << " " << x.second.second.second.second << " " << x.second.second.second.second << " " << x.second.second.second.second << endl;
#define debug_vpllllllllll(v) cout << #v << ": " << endl; for (auto &x : v) cout << x.first << " " << x.second.first.first << " " << x.second.first.second << " " << x.second.second.first.first << " " << x.second.second.first.second << " " << x.second.second.second.first << " " << x.second.second.second.second << " " << x.second.second.second.second << " " << x.second.second.second.second << " " << x.second.second.second.second << " " << x.second.second.second.second << " " << x.second.second.second.second << endl;
#define debug_vplllllllllll(v) cout << #v << ": " << endl; for (auto &x : v) cout << x.first << " " << x.second.first.first << " " << x.second.first.second << " " << x.second.second.first.first << " " << x.second.second.first.second << " " << x.second.second.second.first << " " << x.second.second.second.second << " " << x.second.second.second.second << " " << x.second.second.second.second << " " << x.second.second.second.second << " " << x.second.second.second.second << " " << x.second.second.second.second << " " << x.second.second.second.second << endl;
#define debug_vpllllllllllll(v) cout << #v << ": " << endl; for (auto &x : v) cout << x.first << " " << x.second.first.first << " " << x.second.first.second << " " << x.second.second.first.first << " " << x.second.second.first.second << " " << x.second.second.second.first << " " << x.second.second.second.second << " " << x.second.second.second.second << " " << x.second.second.second.second << " " << x.second.second.second.second << " " << x.second.second.second.second << " " << x.second.second.second.second << " " << x.second.second.second.second << " " << x.second.second.second.second << endl;
#define debug_vplllllllllllll(v) cout << #v << ": " << endl; for (auto &x : v) cout << x.first << " " << x.second.first.first << " " << x.second.first.second << " " << x.second.second.first.first << " " << x.second.second.first.second << " " << x.second.second.second.first << " " << x.second.second.second.second << " " << x.second.second.second.second << " " << x.second.second.second.second << " " << x.second.second.second.second << " " << x.second.second.second.second << " " << x.second.second.second.second << " " << x.second.second.second.second << " " << x.second.second.second.second << " " << x.second.second.second.second << endl;
#define debug_vpllllllllllllll(v) cout << #v << ": " << endl; for (auto &x : v) cout << x.first << " " << x.second.first.first << " " << x.second.first.second << " " << x.second.second.first.first << " " << x.second.second.first.second << " " << x.second.second.second.first << " " << x.second.second.second.second << " " << x.second.second.second.second << " " << x.second.second.second.second << " " << x.second.second.second.second << " " << x.second.second.second.second << " " << x.second.second.second.second << " " << x.second.second.second.second << " " << x.second.second.second.second << " " << x.second.second.second.second << " " << x.second.second.second.second << endl;
#define debug_vplllllllllllllll(v) cout << #v << ": " << endl; for (auto &x : v) cout << x.first << " " << x.second.first.first << " " << x.second.first.second << " " << x.second.second.first.first << " " << x.second.second.first.second << " " << x.second.second.second.first << " " << x.second.second.second.second << " " << x.second.second.second.second << " " << x.second.second.second.second << " " << x.second.second.second.second << " " << x.second.second.second.second << " " << x.second.second.second.second << " " << x.second.second.second.second << " " << x.second.second.second.second << " " << x.second.second.second.second << " " << x.second.second.second.second << " " << x.second.second.second.second << endl;
#define debug_vpllllllllllllllll(v) cout << #v << ": " << endl; for (auto &x : v) cout << x.first << " " << x.second.first.first << " " << x.second.first.second << " " << x.second.second.first.first << " " << x.second.second.first.second << " " << x.second.second.second.first << " " << x.second.second.second.second << " " << x.second.second.second.second << " " << x.second.second.second.second << " " << x.second.second.second.second << " " << x.second.second.second.second << " " << x.second.second.second.second << " " << x.second.second.second.second << " " << x.second.second.second.second << " " << x.second.second.second.second << " " << x.second.second.second.second << " " << x.second.second.second.second << endl;
#define debug_vplllllllllllllllll(v) cout << #v << ": " << endl; for (auto &x : v) cout << x.first << " " << x.second.first.first << " " << x.second.first.second << " " << x.second.second.first.first << " " << x.second.second.first.second << " " << x.second.second.second.first << " " << x.second.second.second.second << " " << x.second.second.second.second << " " << x.second.second.second.second << " " << x.second.second.second.second << " " << x.second.second.second.second << " " << x.second.second.second.second << " " << x.second.second.second.second << " " << x.second.second.second.second << " " << x.second.second.second.second << " " << x.second.second.second.second << " " << x.second.second.second.second << endl;
#define debug_vplllllllllllllllllll(v) cout << #v << ": " << endl; for (auto &x : v) cout << x.first << " " << x.second.first.first << " " << x.second.first.second << " " << x.second.second.fir