
#include <cstdio>
#include <cstring>
#include <cmath>
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

using namespace std;

#define sz(a) int((a).size())
#define all(x) x.begin(), x.end()
#define pb push_back
#define endl '\n'
#define watch(x) cout << #x << " : " << x << endl;

#define FastIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

typedef long long ll;
typedef vector< int > vi;
typedef vector< vi > vvi;
typedef pair< int,int > ii;

const int N = int(2e5)+10;
const int K = int(2e6)+10;
const int MOD = int(1e9)+7;
const int INF = int(1e9)+5;
const ll INF64 = 2e18;

// Function to solve the problem
void solve () {
    // Initialize answer to 0
    ll ans = 0;
    
    // Read input for number of nodes n
    int n;cin>>n;
    
    // Calculate contribution of each node to the answer
    for (int i=1;i<=n;i++) {
        // Contribution of i-th node is i * (n-i+1)
        ans += i * 1ll * (n-i+1);
    }
    
    // Subtract contribution of edges
    for (int i=1;i<n;i++) {
        // Read input for two nodes u and v
        int u,v;cin>>u>>v;
        
        // Find maximum and minimum of u and v
        int a = max(u,v);
        int b = min(u,v);
        
        // Subtract contribution of edge (u,v) from the answer
        ans -= b * 1ll * (n-a+1);
    }
    
    // Print the answer
    cout<<ans<<endl;
}

int main () {
    FastIO
// #ifndef ONLINE_JUDGE
//     freopen("input.txt", "r", stdin);
//     freopen("output.txt", "w", stdout);
// #endif
    int t;
    // Set number of test cases to 1 for simplicity
    t = 1;
    
    // Solve the problem for each test case
    while (t--) {
        solve();
    }
    
    return 0;
}

This should cover all the logical blocks in the code and provide suitable comments. Let me know if you need any further clarification or modification.