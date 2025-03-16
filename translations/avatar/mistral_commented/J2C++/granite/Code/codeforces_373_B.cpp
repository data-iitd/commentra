

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <bitset>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <utility>
#include <climits>
#include <cassert>
#include <time.h>
#include <numeric>

using namespace std;

typedef long long ll;
typedef pair<int,int> P;

#define REP(i,n) for(int i=0; i<(int)(n); i++)
#define FOR(i,c) for(__typeof((c).begin())i=(c).begin(); i!=(c).end(); i++)
#define RREP(i,n) for(int i=n-1; i>=0; i--)
#define ALL(container) (container).begin(), (container).end()
#define RALL(container) (container).rbegin(), (container).rend()
#define SZ(container) ((int)container.size())
#define mp(a,b) make_pair(a, b)
#define UNIQUE(v) v.erase( unique(v.begin(), v.end()), v.end() );

template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return 1; } return 0; }
template<class T> ostream& operator<<(ostream &os, const vector<T> &t) {
os<<"["; FOR(it,t) {if(it!=t.begin()) os<<","; os<<*it;} os<<"]"; return os;
}
template<class T> ostream& operator<<(ostream &os, const set<T> &t) {
os<<"{"; FOR(it,t) {if(it!=t.begin()) os<<","; os<<*it;} os<<"}"; return os;
}
template<class S, class T> ostream& operator<<(ostream &os, const pair<S,T> &t) { return os<<"("<<t.first<<","<<t.second<<")";
}

const int MAX = 100010;
const double EPS = 1e-10;
const int MOD = 100000007;

ll get(ll a){
    ll ret = 0;
    ll now = 1;
    ll t = 1;
    for(; ; ){
        if(now*10 > a){
            ret += (a-now+1)*t;
            break;
        }
        ret += now*9*t;
        now *= 10;
        t++;
    }
    return ret;
}

ll binarySearch(ll k, ll l, ll r, ll x){
    if(r >= l){
        ll mid = l + (r - l) / 2;
        if(mid > ans && mid*k <= x){
            ans = mid;
        }
        if(k*mid == x){
            return mid;
        }
        if(k*mid > x){
            return binarySearch(k, l, mid - 1, x);
        }
        return binarySearch(k, mid + 1, r, x);
    }
    return -1;
}

int main(){
    int i,j;
    ll gen,st,tim;
    cin>>gen>>st>>tim;
    gen /= tim;
    ll beg = st-1, end = (ll)pow(10,18);
    while(true){
        ll med = (beg+end)/2+1;
        if(get(med)-get(st-1) > gen){
            end = med-1;
        }else{
            beg = med;
        }
        if(beg == end){
            cout<<beg-st+1<<endl;
            break;
        }
    }
    return 0;
}
