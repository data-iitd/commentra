
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <bitset>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <climits>
#include <cctype>
#include <cassert>
#include <ctime>
#include <complex>
#include <iomanip>
#include <numeric>
#include <list>
#include <tuple>
#include <cassert>

using namespace std;

typedef long long ll;
typedef pair<int,int> P;
typedef pair<int,P> iP;
typedef pair<P,P> PP;
typedef pair<P,int> Pi;

#define rep(i,n) for(int i = 0;i < (n);i++)
#define rrep(i,n) for(int i = (n)-1;i >= 0;i--)
#define FOR(i,a,b) for(int i = (a);i < (b);i++)
#define rFOR(i,a,b) for(int i = (b)-1;i >= (a);i--)
#define all(a) (a).begin(),(a).end()
#define mp make_pair
#define pb push_back
#define eb emplace_back

int main(){
    int n;cin >> n;
    vector<int> F(367,0),M(367,0);
    int ans = 0;
    rep(i,n){
        char c;cin >> c;
        int a,b;cin >> a >> b;
        if(c == 'M')FOR(j,a,b+1)M[j]++;
        else FOR(j,a,b+1)F[j]++;
        rep(j,367){
            if(M[j] > F[j])ans = max(ans,M[j]*2);
            else ans = max(ans,F[j]*2);
        }
    }
    cout << ans << endl;
    return 0;
}
//END-OF-CODE