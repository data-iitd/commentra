
#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <bitset>
#include <functional>
#include <numeric>
#include <utility>
#include <iomanip>
#include <cctype>
#include <random>
#include <time.h>
#include <assert.h>
using namespace std;

typedef long long ll;

//conversion
//------------------------------------------
inline int toInt(string s) { int v; istringstream sin(s); sin >> v; return v; }
template<class T> inline string toString(T x) { ostringstream sout; sout << x; return sout.str(); }
inline int readInt() { int x; scanf("%d", &x); return x; }

//typedef
//------------------------------------------
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef pair<int, int> PII;
typedef pair<ll, ll> PLL;
typedef pair<int, PII> TIII;
typedef vector<PII> VPII;
typedef vector<TIII> VTIII;
template<class T> using V = vector<T>;
template<class T> using VV = vector<vector<T>>;

//container util

//------------------------------------------
#define ALL(a)  (a).begin(),(a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define PB push_back
#define MP make_pair
#define SZ(a) int((a).size())
#define SQ(a) ((a)*(a))
#define EACH(i,c) for(typeof((c).begin()) i=(c).begin(); i!=(c).end(); ++i)
#define EXIST(s,e) ((s).find(e)!=(s).end())
#define SORT(c) sort((c).begin(),(c).end())

//repetition
//------------------------------------------
#define FOR(i,s,n) for(int i=s;i<(int)n;++i)
#define REP(i,n) FOR(i,0,n)
#define MOD 100000007

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const double EPS = 1E-8;

#define chmin(x,y) x=min(x,y)
#define chmax(x,y) x=max(x,y)

const int INF = 100000000;
const ll LLINF = 1000000000000000000;
const ll MOD = 100000007;

int dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0};

//IO
//------------------------------------------
#define READ(in) freopen(in, "r", stdin)
#define WRITE(out) freopen(out, "w", stdout)
//------------------------------------------
int dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0};

int main(int argc, char const *argv[])
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    double ans = 0;
    rep(i, 0, n) {
        int a;
        cin >> a;
        ans += 1.0 / a;
    }
    cout << 1 / ans << endl;
    return 0;
}
