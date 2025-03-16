#pragma GCC optimize("fast-math")
#pragma GCC optimize("unroll-loops")
#include <iostream>
#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <math.h>
#include <set>
#include <stack>
#include <bitset>
#include <map>
#include <queue>
#include <random>
#include <unordered_set>
#include <unordered_map>
#define DEBUG
#define fi first
#define se second
#define pqueue priority_queue
#define pb(x) push_back(x)
//#define endl '\n'
#define all(x) x.begin(), x.end()
#define int long long
#define mk(a, b) make_pair(a, b)
     
using namespace std;
      
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef vector<int> vi;
typedef vector<vector<int> > vvi;
typedef vector<ull> vull;
typedef vector<ll> vll;
// typedef tuple<ll, ll, ll> tiii;
typedef pair<int, int> pii;
typedef vector<pair<int, int> > vpii;
typedef pair<ll, ll> pll;
typedef vector<bool> vb;
typedef vector<string> vs;
typedef vector< vector<ll> > vvll;
typedef vector<char> vc;
      
const ll INF = 1e9 + 228;
const ll INFLL = 1e18;
const ll MOD = 1e9 + 7;
//static const int maxn = 1e6 + 228;
const ld eps = 1e-6;
const ld eps2 = 1e-9;
const ll MOD2 = 998244353;
const ll dosz = 5e5;
const ll SZ = (1<<18);
const ld PI = atan2l(0, -1);
     
// Global variables and data structures initialization
void fast_io(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
//    freopen("cowjog.in", "r", stdin);
//    freopen("cowjog.out", "w", stdout);
}

void solve(){
	// Input the number of test cases (if any) or the main input
	int n;
	cin >> n;
	// Initialize the vector to store the numbers
	vi nums(n);
	// Initialize variables to keep track of the last number and the previous index of the last number
	int last = 0;
	for(int i=0; i<n; i++){
		// Read the numbers from the input
		cin >> nums[i];	
		// Update the last variable and the map to keep track of the previous index of the last number
		last = nums[i];
	}
	// Initialize a vector to store the prefix sum of the number of ways to reach each index
	vi dp(n+1, 0);
	// Set the initial value of the prefix sum at index 0
	dp[0] = 1;
	// Initialize two maps to keep track of the previous index of each number and the number of ways to reach the previous index
	map<int, int> kek;
	map<int, int> prev;
	// Iterate through the numbers from 1 to n
	for(int i=1; i<=n; i++){
		// Calculate the prefix sum at the current index by adding the number of ways to reach the previous index (if the previous number is not the same as the current number) and updating the maps
		dp[i] = dp[i-1] + (prev[nums[i-1]]!=i-1 ? kek[nums[i-1]]:0);
		dp[i] %= MOD;
		// Update the maps
		kek[nums[i-1]]=dp[i];
		prev[nums[i-1]] = i;
	}
	// Output the result
	cout << dp[n] << endl;
}

// Main function to run the program
int main(){
        fast_io();
	// Run the solve function for each test case (if any) or the main input
	int q = 1;
//	cin >> q;
	while(q--)
		solve();
     
}
