
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <bitset>
#include <functional>
#include <random>
#include <cassert>
using namespace std;

typedef long long ll;
typedef pair<int, int> P;
typedef pair<ll, ll> LP;
typedef pair<P, int> PP;
typedef pair<ll, P> PL;
typedef pair<P, ll> PLL;
typedef pair<ll, PL> PLPLL;

const int MOD = 100000007;
const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};

#define FOR(i,a,b) for (int i=(a);i<(b);i++)
#define RFOR(i,a,b) for (int i=(b)-1;i>=(a);i--)
#define REP(i,n) for (int i=0;i<(n);i++)
#define RREP(i,n) for (int i=(n)-1;i>=0;i--)
#define ALL(a) (a).begin(),(a).end()
#define RALL(a) (a).rbegin(),(a).rend()
#define SORT(c) sort((c).begin(),(c).end())
#define RSORT(c) sort((c).rbegin(),(c).rend())
#define EXIST(s,e) ((s).find(e)!=(s).end())
#define SZ(a) ((int)(a).size())
#define BIT(x, i) (((x) >> (i)) & 1)

template<typename T>
inline bool chmax(T &a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<typename T>
inline bool chmin(T &a, T b) { if (a > b) { a = b; return 1; } return 0; }
template<typename T1, typename T2>
inline ostream &operator <<(ostream &os, const pair<T1, T2> p) { return os << p.first << " " << p.second; }
template<typename T1, typename T2>
inline istream &operator >>(istream &is, pair<T1, T2> &p) { return is >> p.first >> p.second; }
template<typename T>
inline ostream &operator <<(ostream &os, const vector<T> &v) { REP(i, v.size()) { if (i) os << " "; os << v[i]; } return os; }
template<typename T>
inline istream &operator >>(istream &is, vector<T> &v) { for (auto &elem : v) is >> elem; return is; }
template<typename T>
inline ostream &operator <<(ostream &os, const vector<vector<T>> &v) { REP(i, v.size()) { if (i) os << endl; os << v[i]; } return os; }
template<typename T>
inline istream &operator >>(istream &is, vector<vector<T>> &v) { for (auto &elem : v) is >> elem; return is; }
template<typename T>
inline ostream &operator <<(ostream &os, const set<T> &s) { for (auto &elem : s) os << elem << " "; return os; }
template<typename...