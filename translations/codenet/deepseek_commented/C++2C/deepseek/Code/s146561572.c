#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <vector>
#include <iostream>
#include <iomanip> 
#include <algorithm>
#include <queue>
#include <list>
#include <numeric>
#include <stack>
#include <unordered_map>
#include <map>
#include <set>

// Macros for convenience
#define sz(a) int((a).size())
#define all(x) x.begin(), x.end()
#define pb push_back
#define endl '\n'
#define watch(x) printf("%s : %d\n", #x, x)

// Fast input/output
#define FastIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

// Type definitions for ease of use
typedef long long ll;
typedef vector< int > vi;
typedef vector< vi > vvi;
typedef pair< int,int > ii;

// Constants for limits and modulo
const int N = int(2e5)+10;
const int K = int(2e6)+10;
const int MOD = int(1e9)+7;
const int INF = int(1e9)+5;
const ll INF64 = 2e18;

// Function to solve the problem
void solve () {
    ll ans = 0; // Initialize the answer variable
    int n; scanf("%d", &n); // Read the number of nodes

    // Calculate the contribution of each node to the answer
    for (int i = 1; i <= n; i++) {
        ans += i * 1ll * (n - i + 1); // Contribution of node i
    }

    // Adjust the answer based on the edges between nodes
    for (int i = 1; i < n; i++) {
        int u, v; scanf("%d %d", &u, &v); // Read the edge connecting nodes u and v
        int a = u > v ? u : v; // Determine the maximum node
        int b = u < v ? u : v; // Determine the minimum node
        ans -= b * 1ll * (n - a + 1); // Subtract the contribution of the edge
    }

    // Output the final answer
    printf("%lld\n", ans);
}

int main () {
    FastIO // Enable fast input/output

    // Uncomment the following lines for file input/output during local testing
    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt", "r", stdin);
    //     freopen("output.txt", "w", stdout);
    // #endif

    int t; // Variable to hold the number of test cases
    // scanf("%d", &t); // Uncomment to read the number of test cases
    t = 1; // For now, we will just run one test case
    while (t--) {
        solve(); // Call the solve function for each test case
    }
    return 0; // Return success
}
