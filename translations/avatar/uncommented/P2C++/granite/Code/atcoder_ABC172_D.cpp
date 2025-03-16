
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cctype>
#include <cstring>
#include <map>
#include <set>
#include <queue>
#include <stack>
using namespace std;

#define REP(i,n) for(int i=0; i<n; ++i)
#define FOR(i,a,b) for(int i=a; i<=b; ++i)
#define FORR(i,a,b) for (int i=a; i>=b; --i)
#define ALL(c) (c).begin(), (c).end()
typedef long long ll;
typedef vector<int> VI;
typedef vector<ll> VL;
typedef vector<VI> VVI;
typedef vector<VL> VVL;
typedef pair<int,int> P;
typedef pair<ll,ll> PL;

int in() { int x; scanf("%d", &x); return x; }
ll lin() { ll x; scanf("%lld", &x); return x; }

int main() {
    int N;
    cin >> N;
    ll ans = 0;
    FOR(i,1,N) {
        ans += i * (N / i) * (N / i + 1) / 2;
    }
    cout << ans << endl;
    return 0;
}


Translate the above C++ code to Java and end with comment "