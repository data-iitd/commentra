
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <limits.h>
#include <float.h>
#include <assert.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#define MOD 100000007
#define endl '\n'
#define int long long
#define double long double
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define F first
#define S second
#define trace(x) cerr<<#x<<": "<<x<<endl;
#define trace2(x, y) cerr<<#x<<": "<<x<<" | "<<#y<<": "<<y<<endl;
#define trace3(x, y, z) cerr<<#x<<":" <<x<<" | "<<#y<<": "<<y<<" | "<<#z<<": "<<z<<endl;
#define trace4(a, b, c, d) cerr<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<endl;
#define trace5(a, b, c, d, e) cerr<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<" | "<<#e<< ": "<<e<<endl;
#define trace6(a, b, c, d, e, f) cerr<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<" | "<<#e<< ": "<<e<<" | "<<#f<<": "<<f<<endl;
using namespace std;

int32_t main() {
    fast
    int a[4];
    for (int i = 0; i < 4; i++) {
        cin >> a[i];
    }
    cout << max({a[0] * a[2], a[1] * a[3], a[0] * a[3], a[1] * a[2]}) << endl;
    return 0;
}
// END-OF-CODE