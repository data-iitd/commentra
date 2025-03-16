
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <bitset>
#include <functional>
#include <utility>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <climits>
#include <cstring>
#include <cassert>

using namespace std;

typedef long long ll;
typedef pair<int,int> P;

#define fr first
#define sc second

const int MOD=1e9+7;
const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};

const int MAX_N = 1e5+10;
const ll INFL = 1e18+7;

ll ans = 0;

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
        if(mid > ans && mid*k <= x) ans = mid;

        if(k*mid == x) return mid;

        if(k*mid > x) return binarySearch(k, l, mid - 1, x);

        return binarySearch(k, mid + 1, r, x);
    }

    return -1;
}

int main(){
    ll gen, st, tim;
    cin >> gen >> st >> tim;
    gen /= tim;
    ll beg = st - 1, end = (ll)pow(10, 18);
    while(true){
        ll med = (beg + end) / 2 + 1;
        if(get(med) - get(st - 1) > gen){
            end = med - 1;
        }else{
            beg = med;
        }
        if(beg == end){
            cout << beg - st + 1 << endl;
            break;
        }
    }

    return 0;
}

