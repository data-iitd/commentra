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

// Macros for convenience
#define sz(a) int((a).size())
#define all(x) x.begin(), x.end()
#define pb push_back
#define endl '\n'
#define watch(x) cout << #x << " : " << x << endl;

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
    int n; cin >> n; // Read the number of nodes

    # <START-OF-CODE>
    # 