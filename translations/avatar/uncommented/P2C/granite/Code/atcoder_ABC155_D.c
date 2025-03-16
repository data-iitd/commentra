
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <assert.h>
#include <time.h>
#include <ctype.h>
#include <limits.h>
#include <stdarg.h>
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <stack>
#include <bitset>
#include <numeric>
#include <utility>
#include <iterator>
#include <json/json.h>
#include <fstream>

using namespace std;

typedef long long ll;
typedef unsigned long long llu;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef pair<int,int> pii;
typedef vector<pii> vpii;
typedef map<int,int> mii;
typedef multimap<int,int> mmi;
typedef map<string,int> msi;
typedef pair<ll,ll> pll;
typedef vector<pll> vpll;

#define FOR(i,a,b) for ( int i = (a); i < (b); i++)
#define REP(i,n) FOR(i,0,n)
#define ALL(v) (v).begin(), (v).end()
#define REV(s) (s).rbegin(), (s).rend()
#define UNQ(s) sort(ALL(s)), (s).erase(unique(ALL(s)),(s).end())
#define CNT(s,v) count((s).begin(),(s).end(),v)
#define PARITY(n) (n&1)
#define EACH(it,c) for(typeof((c).begin()) it=(c).begin(); it!=(c).end(); ++it)
#define EXIST(s,e) ((s).find(e)!=(s).end())
#define range(i,a,b) for(int i = (a); i < (b); i++)
#define mp(a,b) make_pair(a, b)
#define pr(a) cout << (a) << endl
#define PR(a,b) cout << (a) << " " << (b) << endl
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define SZ(a) int((a).size())
#define EACH(i,c) for(typeof((c).begin()) i=(c).begin(); i!=(c).end(); ++i)
#define EXIST(s,e) ((s).find(e)!=(s).end())
#define SORT(c) sort((c).begin(),(c).end())

#define __ FastIO
class FastIO{
    public:
    FastIO(){
        cin.tie(0);
        cout.tie(0);
        ios::sync_with_stdio(0);
    }
} __FastIO;

const int N = 100005;
const int MAXN = int(1e6) + 5;

int n, k;
ll a[N];

bool check(ll x){
    ll cnt = 0;
    REP(i,n){
        int l = -1, r = n;
        while(l + 1 < r){
            int mid = (l + r) / 2;
            if(a[i] * a[mid] < x) r = mid;
            else l = mid;
        }
        cnt += n - r;
        l = -1, r = n;
        while(l + 1 < r){
            int mid = (l + r) / 2;
            if(a[i] * a[mid] < x) l = mid;
            else r = mid;
        }
        cnt += l + 1;
        if(a[i] * a[i] < x) cnt--;
    }
    return cnt / 2 >= k;
}

int main(){
    cin >> n >> k;
    REP(i,n) cin >> a[i];
    SORT(a);
    ll l = -1e18, r = 1e18;
    while(l + 1 < r){
        ll mid = (l + r) / 2;
        if(check(mid)) r = mid;
        else l = mid;
    }
    cout << r << endl;
    return 0;
}

/* stuff you should look for
    * int overflow, array bounds
    * special cases (n=1?), set tle
    * do smth instead of nothing and stay organized
*/