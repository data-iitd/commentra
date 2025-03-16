#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <string>
#include <cmath>
#include <iomanip>
using namespace std;

// Define long long type for convenience
typedef long long ll;
// Define a pair type for convenience
typedef pair<ll,ll> PP;

// Arrays to store the keys and costs
ll key[1005] = {0};
ll cost[1005] = {0};
// DP table to store the minimum costs for each state
ll dp[(1<<12)+5][1005] = {0};
// Define a large constant for infinity
const ll INF = 123456789012;

int main() {
    // Read the number of keys (n) and the number of items (m)
    ll n, m;
    cin >> n >> m;

    // Initialize the DP table with infinity
    for(int i = 0; i < (1 << 12) + 5; i++) {
        for(int j = 0; j < 1005; j++) {
            dp[i][j] = INF; // Set each entry to infinity
        }
    }

    // Base case: cost of obtaining no keys is 0
    dp[0][0] = 0;

    // Read the costs and keys for each item
    for(int i = 1; i <= m; i++) {
        ll b;
        cin >> cost[i] >> b; // Read cost and number of keys for item i
        for(int j = 0; j < b; j++) {
            ll c;
            cin >> c; // Read each key
            key[i] += (1 << (c - 1)); // Update the key bitmask for item i
        }
    }

    // Fill the DP table
    for(ll i = 0; i < (1 << n); i++) {
        for(int j = 0; j < m; j++) {
            // Update the DP table for not taking the (j+1)th item
            dp[i][j + 1] = min(dp[i][j], dp[i][j + 1]);
            // Update the DP table for taking the (j+1)th item
            dp[i | key[j + 1]][j + 1] = min(dp[i | key[j + 1]][j + 1], dp[i][j] + cost[j + 1]);
        }
    }

    // Check if it's possible to obtain all keys
    if(dp[(1 << n) - 1][m] == INF)
        cout << -1 << endl; // If not possible, print -1
    else
        cout << dp[(1 << n) - 1][m] << endl; // Print the minimum cost to obtain all keys
}
