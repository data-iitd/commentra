
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <sys/time.h>
#include <assert.h>
#include <string>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>
#include <set>
#include <iostream>
#include <memory>
#include <bitset>
#include <numeric>

using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int,int> PII;
typedef vector<int> VI;

#define REP(i,n) for(int i=0; i<(int)(n); i++)
#define FOR(i,a,n) for(int i=(a); i<(int)(n); i++)
#define FORD(i,a,n) for(int i=(a); i>=(int)(n); i--)
#define pb push_back
#define mp make_pair
#define SZ(v) (int)((v).size())
#define ALL(v) (v).begin(), (v).end()
#define UNIQUE(v) v.erase( unique(v.begin(), v.end()), v.end() )
#define DUMP(v) REP(aa, (SZ(v))) { cout<<v[aa]<<" "; } cout<<endl;
#define CP(a,b) memcpy(a,b,sizeof(a))
#define RST(v) memset(v, 0, sizeof(v))
#define ZER(v) memset(v, 0, sizeof(v))
#define MINUS(v) memset(v, 0xff, sizeof(v))
#define MAXN 100005
#define MAXLOG 20
#define EPS 1e-12
#define MOD 1000000007LL

inline int toInt(string s) { int v; istringstream sin(s);sin>>v;return v; }
template<class T> inline string toString(T x) { ostringstream sout; sout<<x;return sout.str(); }

inline LL modPlus(LL a, LL b) { return (a+b)%MOD; }
inline LL modMinus(LL a, LL b) { return (a+MOD-b)%MOD; }
inline LL modMul(LL a, LL b) { return (a*b)%MOD; }
inline LL modPower(LL a, LL b) { LL res = 1, v = a; while(b) { if(b&1) res = modMul(res, v); v = modMul(v, v); b >>= 1; } return res; }

LL power(LL x, LL n) {
    if (n == 0) {
        return 1;
    }
    LL val = power(x, n / 2);
    val = val * val;
    if (n % 2 == 1) {
        val = val * x;
    }
    return val;
}

int main() {
    int n;
    scanf("%d", &n);
    vector<int> c(n);
    REP(i, n) scanf("%d", &c[i]);
    sort(ALL(c));
    LL b = power(2, n);
    LL a = power(2, n - 2);
    LL ans = 0;
    REP(i, n) {
        LL val = a * (i + 2) % MOD;
        val = val * c[n - 1 - i] % MOD;
        ans = modPlus(ans, val);
    }
    ans = ans * b % MOD;
    cout<<ans<<endl;
    return 0;
}

