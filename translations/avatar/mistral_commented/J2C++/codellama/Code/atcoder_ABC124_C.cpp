
#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <climits>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <bitset>
#include <cassert>
#include <iomanip>
#include <random>
#include <chrono>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define ll long long
#define int long long
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define clr(x) memset(x, 0, sizeof(x))
#define sortall(x) sort(all(x))
#define tr(it, a) for(auto it = a.begin(); it != a.end(); it++)
#define PI 3.1415926535897932384626
#define lcm(a, b) ((a/__gcd(a,b))*b)

typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<pii> vpii;
typedef vector<pll> vpll;

const int INF = 1e9;
const int MOD = 1e9+7;
const int MAX = 1e5+5;

// <START-OF-CODE>

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string x;
    cin >> x;

    string a = x;
    string b = x;

    int a1 = 0;
    int a2 = 0;

    for (int i = 1; i < x.length(); i++) {
        if (a[i] == a[i-1]) {
            if (a[i] == '1') a[i] = '0';
            else a[i] = '1';
            a1++;
        }
    }

    for (int i = x.length()-1; i > 0; i--) {
        if (b[i] == b[i-1]) {
            if (b[i-1] == '1') b[i-1] = '0';
            else b[i-1] = '1';
            a2++;
        }
    }

    cout << min(a1, a2) << endl;

    return 0;
}

// 