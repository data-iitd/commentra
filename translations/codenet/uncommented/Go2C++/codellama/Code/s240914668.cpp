
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cctype>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iomanip>
#include <cassert>
using namespace std;

#define INF 0x3F3F3F3F
#define PI 3.141592653589793
#define EPS 1e-10
#define LL long long
#define ULL unsigned long long
#define DEBUG(x) cout << #x << " = " << x << endl;
#define FILE_IN "input.txt"
#define FILE_OUT "output.txt"
#define ofile freopen(FILE_IN, "r", stdin); freopen(FILE_OUT, "w", stdout);
#define fout freopen(FILE_OUT, "w", stdout);
#define fin freopen(FILE_IN, "r", stdin);
#define FOR(i, a, b) for (int i=a; i<b; i++)
#define ROF(i, b, a) for (int i=b; i>=a; i--)
#define FORi(i, n) for (int i=0; i<n; i++)
#define FORj(j, n) for (int j=0; j<n; j++)
#define FORij(i, j, n) for (int i=0; i<n; i++) for (int j=0; j<n; j++)
#define ALL(a) a.begin(), a.end()
#define SIZE(a) int(a.size())
#define PERMUTE next_permutation
#define TC(t) while (t--)
#define FAST ios_base::sync_with_stdio(false); cin.tie(NULL);
#define what_is(x) cerr << #x << " is " << x << endl;

const int mxN = 100005;

int n;
int a[mxN];

int main() {
    // <START-OF-CODE>
    cin >> n;
    FORi(i, n) cin >> a[i];

    int ans = 0;
    FORi(i, n) {
        int l = i, r = i + 1;
        while (r + 1 < n && (a[r] - a[l]) * (a[r + 1] - a[r]) >= 0) r++;
        ans++;
        i = r;
    }
    cout << ans << endl;
    // 