
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <bitset>
#include <iomanip>
#include <cctype>
#include <cassert>
#include <numeric>
#include <complex>
#include <sstream>

using namespace std;

typedef long long ll;
typedef pair<int, int> P;
typedef pair<ll, ll> Pll;
typedef pair<ll, int> Pli;
typedef pair<double, double> Pd;

#define REP(i, n) for(int i = 0; i < (n); i++)
#define FOR(i, a, n) for(int i = a; i < (n); i++)
#define pb push_back
#define mp make_pair
#define ALL(a) (a).begin(),(a).end()
#define RALL(a) (a).rbegin(),(a).rend()
#define CLR(a) memset(a, 0, sizeof(a))
#define fr first
#define sc second

const int dx4[4] = {1, 0, -1, 0};
const int dy4[4] = {0, 1, 0, -1};
const int dx8[8] = {1, 1, 1, 0, 0, -1, -1, -1};
const int dy8[8] = {0, 1, -1, 1, -1, 0, 1, -1};
const double pi = acos(-1.0);
const ll inf = 1LL << 60;

int H, W, N;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> H >> W >> N;
    int A = max(H, W);
    cout << (N + A - 1) / A << endl;
    return 0;
}

// Translate the above C++ code to Java and end with comment "