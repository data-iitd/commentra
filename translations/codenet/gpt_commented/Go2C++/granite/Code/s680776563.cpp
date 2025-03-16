
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <bitset>
#include <numeric>
#include <stack>
#include <sstream>
#include <climits>
#include <cstring>
#include <cctype>
#include <fstream>
#include <sstream>
#include <cassert>
#include <functional>
#include <complex>
#include <tuple>
#include <array>
#include <cassert>
#include <random>
#include <time.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<double,double> pdd;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<vector<ll>> vvll;
typedef vector<vector<pii>> vvp;
typedef vector<pii> vp;
typedef vector<string> vs;

#define rep(i,a,b) for (int i=a; i<(b); i++)
#define rrep(i,a,b) for (int i=(b)-1; i>=(a); i--)
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
#define sz(x) (int)x.size()
#define UNIQUE(v) v.erase(unique(v.begin(), v.end()), v.end())
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define endl '\n'
#define F first
#define S second
#define chmax(a,b) a = max(a,b)
#define chmin(a,b) a = min(a,b)
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int main() {
    fast_cin();
    int A, B, C;
    cin >> A >> B >> C;
    if (B - A == C - B) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    return 0;
}

// END-OF-CODE