
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
def solve ():
    # Initialize answer to 0
    ans = 0
    
    # Read input for number of nodes n
    n = int(input())
    
    # Calculate contribution of each node to the answer
    for i in range(1,n+1):
        # Contribution of i-th node is i * (n-i+1)
        ans += i * 1ll * (n-i+1)
    
    # Subtract contribution of edges
    for i in range(1,n):
        # Read input for two nodes u and v
        u,v = map(int,input().split())
        
        # Find maximum and minimum of u and v
        a = max(u,v)
        b = min(u,v)
        
        # Subtract contribution of edge (u,v) from the answer
        ans -= b * 1ll * (n-a+1)
    
    # Print the answer
    print(ans)

# 