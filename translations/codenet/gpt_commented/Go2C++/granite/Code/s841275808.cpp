
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <string>
#include <cstring>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <utility>
#include <numeric>
#include <iterator>
#include <bitset>
#include <complex>
#include <fstream>
using namespace std;
typedef long long ll;
const double EPS = 1e-9;
typedef vector<int> vint;
typedef pair<int, int> pint;
#define rep(i, n) REP(i, 0, n)
#define ALL(v) v.begin(), v.end()
#define MSG(a) cout << #a << " " << a << endl;
#define REP(i, x, n) for(int i = x; i < n; i++)
template<class T> T RoundOff(T a){ return int(a+.5-(a<0)); }
template<class T, class C> void chmax(T& a, C b){ if(a < b) a = b; }
template<class T, class C> void chmin(T& a, C b){ if(b < a) a = b; }
template<class T, class C> pair<T, C> mp(T a, C b){ return make_pair(a, b); }

int main()
{
    int N;
    cin >> N;
    vint X(N), Y(N);
    rep(i, N)
    {
        cin >> X[i];
        Y[i] = X[i];
    }
    sort(ALL(Y));
    int m1 = Y[N / 2 - 1], m2 = Y[N / 2];
    rep(i, N)
    {
        if(X[i] <= m1) cout << m2 << endl;
        else cout << m1 << endl;
    }
    return 0;
}

// 