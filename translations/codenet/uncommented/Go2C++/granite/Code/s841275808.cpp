
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <string>
#include <cstring>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <bitset>
#include <utility>
#include <numeric>
#include <iomanip>
#include <cassert>
#include <random>
#include <chrono>
#include <complex>
#include <tuple>
#include <regex>
#include <valarray>
#include <cstdlib>
using namespace std;

typedef long long ll;
typedef unsigned long long vll;
typedef pair<int,int> P;
typedef vector<int> vi;
typedef vector<vector<int> > vvi;
typedef vector<long long> vl;
typedef vector<vector<long long> > vvl;
typedef vector<double> vd;
typedef vector<vector<double> > vvd;
typedef vector<P> vp;
typedef vector<vector<P> > vvp;
typedef vector<string> vs;
typedef vector<vector<string> > vvs;
typedef vector<char> vc;
typedef vector<vector<char> > vvc;
typedef vector<bool> vb;
typedef vector<vector<bool> > vvb;
typedef complex<double> cd;
typedef tuple<int,int,int> tap;
typedef vector<tap> vtap;

#define REP(i,n) for(int i=0;i<(n);i++)
#define REPN(i,n) for(int i=1;i<=(n);i++)
#define FOR(i,k,n) for(int i=(k);i<(n);i++)
#define FORN(i,k,n) for(int i=(k);i<=(n);i++)
#define ALL(a) a.begin(),a.end()
#define MS(m,v) memset(m,v,sizeof(m))
#define D10 fixed<<setprecision(10)

template<typename T> inline T CHMAX(T& a, const T b) { return a = (a < b)? b : a; }
template<typename T> inline T CHMIN(T& a, const T b) { return a = (a > b)? b : a; }
template<typename T> inline T CHABS(T a) { return (a >= 0)? a : (-a); }
template<typename T> inline T SQ(T a) { return a*a; }

const int dx[] = { 1, 0, -1, 0 }; const int dy[] = { 0, 1, 0, -1 };
const int dx8[] = { 1, 1, 0, -1, -1, -1, 0, 1 }; const int dy8[] = { 0, 1, 1, 1, 0, -1, -1, -1 };
const int MOD = 100000007;
const double EPS = 1e-10;
const bool debug = 0;
// const bool debug = 1;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;
	vi x(n), y(n);
	REP(i, n) {
		cin >> x[i];
		y[i] = x[i];
	}
	sort(ALL(y));
	int m1 = y[n / 2 - 1];
	int m2 = y[n / 2];
	REP(i, n) {
		if (x[i] <= m1) {
			cout << m2 << endl;
		}
		else {
			cout << m1 << endl;
		}
	}
	return 0;
}
