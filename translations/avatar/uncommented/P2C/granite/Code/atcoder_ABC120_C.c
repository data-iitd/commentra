
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#define MOD 100000007
#define rep(i,n) for(int i=0;i<n;i++)
#define REP(i,s,n) for(int i=s;i<n;i++)
#define IINF 100000000
#define LLINF 100000000000000000LL
#define ll long long
#define pii pair<int,int>
#define pll pair<ll,ll>
#define fs first
#define sc second
#define pb push_back
#define mp make_pair
#define all(a) a.begin(),a.end()
#define vi vector<int>
#define vvi vector<vi>
#define print(x) cout<<x<<endl
#define input(x) cin>>x
#define each(a,b) for(auto &a:b)
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define RFOR(i,a,b) for(int i=b-1;i>=a;i--)
#define SORT(a) sort(all(a))
#define REV(a) reverse(all(a))
#define endl '\n'
#define debug(x) cout<<#x<<":"<<x<<endl
#define DEBUG(v) cout<<#v<<":";each(x,v)cout<<x<<" ";cout<<endl;
#define int ll
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

int32_t main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    string s;
    cin >> s;
    int n = s.size();
    int ans = IINF;
    rep(i,26){
        char c = 'a' + i;
        int cnt = 0;
        rep(j,n){
            if(s[j]!= c) cnt++;
        }
        ans = min(ans,cnt);
    }
    print(ans*2);
}
// END-OF-CODE