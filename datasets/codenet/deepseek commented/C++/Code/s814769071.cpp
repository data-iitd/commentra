#pragma region
#define _USE_MATH_DEFINES
#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <vector>
#include <map>
#include <queue>
#include <stack>
#include <set>
#include <list>
#include <iomanip>
#include <cstdint>
#include <cstdlib>

using namespace std;
typedef long long ll;
//#define rep(i, s, e) for (int(i) = (s); (i) < (e); ++(i))
#define rep(i, e) for (int(i) = 0; (i) < (e); ++(i))
#define rrep(i, s) for (int(i) = (s) - 1; (i) >= 0; --(i))
#define all(x) x.begin(),x.end()
#pragma endregion

int main()
{
    // Step 2: Read input values
    ll n, k; cin >> n >> k;
    ll MOD = 1e9 + 7;

    // Step 3: Calculate the maximum and minimum sums
    ll mx = n * (n + 1) / 2 - (n - k) * (n - k + 1) / 2;
    ll mn = k * (k - 1) / 2;

    // Step 4: Initialize variables
    ll res = 0;

    // Step 5: Loop through possible lengths
    for (int i = k; i <= n + 1; ++i)
    {
        // Update res, mx, and mn in each iteration
        res += mx - mn + 1;
        mx += n - i;
        mn += i;
        res %= MOD;
    }

    // Step 6: Output the result
    cout << res << endl;
}
