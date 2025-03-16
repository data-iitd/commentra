
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <cctype>
#include <cassert>
#include <string.h>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <bitset>
#include <functional>
#include <numeric>
using namespace std;

typedef long long LL;
typedef pair<int,int> PII;
typedef vector<int> VI;

#define pb push_back
#define mp make_pair
#define rep(i,n) for(int i=0;i<(n);++i)
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define FORD(i,a,b) for(int i=(a);i>=(b);--i)
#define FORv(i,v) for(int i=0;i<(v).size();++i)

#define MOD 100000007
#define MAXN 100005
#define EPS 1e-9

#define ms(s) memset(s,0,sizeof(s))
#define pb push_back
#define all(a) a.begin(),a.end()
#defineSz(a) int((a).size())
#define EACH(i,c) for(typeof((c).begin()) i=(c).begin(); i!=(c).end(); ++i)
#define EXIST(s,e) ((s).find(e)!=(s).end())
#define SORT(c) sort((c).begin(),(c).end())

// IO macros
#define GET(x) scanf("%d",&x)
#define GETS(x) scanf("%s",x)
#define GETLL(x) scanf("%I64d",&x)
#define PUT(x) printf("%d",x)
#define PUTS(x) printf("%s",x)
#define PUTLL(x) printf("%I64d",x)
#define PUTCHAR(x) printf("%c",x)
#define PUTS(x) printf("%s",x)
#define READ(f) freopen(f,"r",stdin)
#define WRITE(f) freopen(f,"w",stdout)

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> h(n);
    vector<bool> good(n, true);
    for (int i = 0; i < n; i++) {
        cin >> h[i];
    }
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        if (h[a] > h[b]) {
            good[b] = false;
        } else if (h[a] < h[b]) {
            good[a] = false;
        } else {
            good[a] = false;
            good[b] = false;
        }
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (good[i]) {
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}

// Translate the above C++ code to Java and end with comment "