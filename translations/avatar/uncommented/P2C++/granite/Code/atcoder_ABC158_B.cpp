
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <map>
#include <cmath>
#include <iomanip>
#include <functional>
#include <tuple>
#include <queue>
#include <stack>
#include <array>
using namespace std;
using ll = long long;
const ll MOD = 100000007;
const ll INF = 1LL << 60;
const double PI = 3.14159265359;
#define rep(i,n) for(int i=0;i<n;i++)
#define REP(i,a,b) for(int i=a;i<b;i++)
#define ALL(a) (a).begin(),(a).end()
#define fs first
#define sc second
#define print(a) cout<<a<<endl;
#definePrintln(a) cout<<a<<endl;
#define chmin(a,b) a=min(a,b);
#define chmax(a,b) a=max(a,b);
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

int main() {
    ll N, A, B; cin >> N >> A >> B;
    ll ans = 0;
    ll rep = N / (A + B);
    ans += rep * A;
    ll res = N - rep * (A + B);
    ans += min(res, A);
    cout << ans << endl;
    return 0;
}
