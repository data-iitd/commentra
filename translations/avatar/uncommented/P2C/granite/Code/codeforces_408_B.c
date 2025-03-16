
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <assert.h>
#include <limits.h>
#include <stdarg.h>
#include <iostream>
#include <algorithm>
#include <numeric>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <bitset>
#include <functional>
#include <random>
#include <unordered_set>
#include <unordered_map>
#include <iomanip>
#include <complex>

using namespace std;

typedef long long ll;

#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define for1(i, n) for (int i = 1; i <= (int)(n); ++i)
#define ford(i, n) for (int i = (int)(n) - 1; i >= 0; --i)
#define fore(i, a, b) for (int i = (int)(a); i <= (int)(b); ++i)

template<class T> bool umin(T& a, T b) { return a > b? (a = b, true) : false; }
template<class T> bool umax(T& a, T b) { return a < b? (a = b, true) : false; }

ll readInt(ll l, ll r, char endd) {
ll x=0;
int cnt=0;
int fi=-1;
bool is_neg=false;
while(true) {
char g=getchar();
if(g=='-') {
assert(fi==-1);
is_neg=true;
continue;
}
if('0'<=g&&g<='9') {
x*=10;
x+=g-'0';
if(cnt==0) {
fi=g-'0';
}
cnt++;
assert(fi!=0 || cnt==1);
assert(fi!=0 || is_neg==false);

assert(!(cnt>19 || ( cnt==19 && fi>1) ));
} else if(g==endd) {
if(is_neg) {
x= -x;
}

if(!(l <= x && x <= r)) {
cerr << l <<'' << r <<'' << x << '\n';
assert(1 == 0);
}

return x;
}
}
string readString(int l, int r, char endd) {
string ret="";
int cnt=0;
while(true) {
char g=getchar();
assert(g!=-1);
if(g==endd) {
break;
}
cnt++;
ret+=g;
}
assert(l<=cnt&&cnt<=r);
return ret;
}
long long readIntSp(long long l, long long r) {
}
long long readIntLn(long long l, long long r) {
}
string readStringLn(int l, int r) {
}
string readStringSp(int l, int r) {
}

int main() {
ios_base::sync_with_stdio(false); cin.tie(NULL);
#ifndef ONLINE_JUDGE
freopen("input.txt","r",stdin);
freopen("output.txt","w",stdout);
#endif

int t=1;
//cin>>t;
while(t--) {
auto solve = [&]() {
string s;
cin>>s;
map<char,int> mp;
for(auto c:s) {
mp[c]++;
}
cin>>s;
int ans=0;
for(auto c:s) {
if(mp[c]>0) {
ans++;
mp[c]--;
}
}
cout<<ans<<endl;
};
solve();
}
assert(getchar()==EOF);
return 0;
}

Translate the above C code to Java and end with comment "