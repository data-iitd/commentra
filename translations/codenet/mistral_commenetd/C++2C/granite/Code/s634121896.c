
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <assert.h>
#include <iostream>
#include <algorithm>
#include <iomanip>
#include <fstream>
#include <vector>
#include <bitset>
#include <queue>
#include <stack>
#include <map>
#include <set>
#define pii pair<int, int>
#define pll pair<long long, long long>
#define debug(x) cout<<#x<<": "<<x<<endl;
#define debuga(x, l, r) cout<<#x<<"["<<l<<".."<<r<<"] = "; \
    for (int _i=l; _i<=r; _i++) cout<<x[_i]<<" "; cout<<endl;
using namespace std;

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<string> vs;
typedef vector<double> vd;
typedef vector<long long> vll;
typedef vector<vector<int> > vvi;
typedef vector<vll> vvll;
typedef vector<pair<int, int> > vpii;
typedef vector<vpii> vvpii;
typedef vector<pll> vpll;
typedef vector<vpll> vvpll;
typedef vector<char> vc;
typedef vector<vc> vvc;
typedef vector<vs> vvs;

const int MAXN = 100005;
const int MAXM = 1000005;
const int MOD = 100000007;
const int MAXK = 11;
const int MAXQ = 200005;
const ld EPS = 1e-9;
const int LOG = 20;

int n, a[MAXN];
int dp[MAXN];
map<int, int> last, cnt;

int main() {
    scanf("%d", &n);
    for (int i=0; i<n; i++) scanf("%d", &a[i]);
    dp[0] = 1;
    cnt[a[0]] = 1;
    last[a[0]] = 0;
    for (int i=1; i<n; i++) {
        dp[i] = dp[i-1];
        if (last[a[i]]!= i-1) {
            dp[i] += cnt[a[i]];
            if (dp[i] >= MOD) dp[i] -= MOD;
        }
        cnt[a[i]] = dp[i];
        last[a[i]] = i;
    }
    printf("%d\n", dp[n-1]);
    return 0;
}
