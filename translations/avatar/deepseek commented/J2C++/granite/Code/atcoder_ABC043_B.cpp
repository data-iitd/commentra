

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <utility>
#include <queue>
#include <stack>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cassert>

using namespace std;

typedef long long ll;

#define REP(i, n) for(int i = 0; i < (n); i++)
#define FOR(i, a, b) for(int i = (a); i < (b); i++)
#define all(x) x.begin(), x.end()
#define debug(x) cerr << #x << " : " << x << endl

template <typename T>
void chmin(T& a, T b){ a = min(a, b); }
template <typename T>
void chmax(T& a, T b){ a = max(a, b); }

const int INF = 1e9;
const ll INFL = 1e18;
const int MOD = 1e9 + 7;

string s;

int main(){
    cin >> s;
    string ans = "";
    REP(i, s.size()){
        if(s[i] == '0') ans += '0';
        if(s[i] == '1') ans += '1';
        if(s[i] == 'B' && ans.size() > 0) ans.pop_back();
    }
    cout << ans << endl;
    return 0;
}

