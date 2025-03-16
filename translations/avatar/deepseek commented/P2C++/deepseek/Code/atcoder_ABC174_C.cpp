#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <unordered_map>
#include <climits>
#include <numeric>
#include <cstring>
#include <set>
#include <queue>
#include <stack>
#include <iomanip>

using namespace std;

#define int long long
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define pb push_back
#define eb emplace_back
#define pq priority_queue
#define f first
#define s second
#define inf 1e18
#define mod 1000000007
#define pi pair<int, int>
#define pii pair<int, pair<int, int>>
#define mii map<int, int>
#define vi vector<int>
#define vvi vector<vector<int>>
#define vpi vector<pair<int, int>>
#define sz(x) (int)x.size()
#define lb lower_bound
#define ub upper_bound
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

int32_t main() {
    FIO;
    int k;
    cin >> k;
    int t = 0;
    for (int i = 1; i <= k; i++) {
        t = (t % k) * 10 + 7;
        if (t % k == 0) {
            cout << i << endl;
            return 0;
        }
    }
    cout << -1 << endl;
    return 0;
}

