#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <deque>
#include <list>
#include <queue>
#include <stack>
#include <vector>
#include <utility>
#include <algorithm>
#include <map>
#include <set>
#include <complex>
#include <cmath>
#include <limits>
#include <climits>
#include <ctime>
#include <cassert>
#include <numeric>
#include <functional>
#include <bitset>

using namespace std;

// Define long long type alias for convenience
using lint = long long int;

// Constants for large values and mathematical constants
long long int INF = 1001001001001001LL;
int inf = 1000000007;
long long int MOD = 1000000007LL;
double PI = 3.1415926535897932;

// Function to update the minimum value
template<typename T1,typename T2>inline void chmin(T1 &a,const T2 &b){if(a>b) a=b;}

// Function to update the maximum value
template<typename T1,typename T2>inline void chmax(T1 &a,const T2 &b){if(a<b) a=b;}

// Macros for convenience in iterating through containers
#define ALL(a) a.begin(),a.end()
#define RALL(a) a.rbegin(),a.rend()

/* do your best */

int main() {
  
  // Read the number of elements
  int n; 
  cin >> n;

  // Initialize a vector to store the input values and a vector for prefix sums
  vector<lint> a(n);
  vector<lint> acc(n + 1, 0);

  // Read input values and compute prefix sums modulo MOD
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    acc[i + 1] = acc[i] + a[i]; // Update prefix sum
    acc[i + 1] %= MOD; // Ensure the prefix sum is within MOD
  }

  // Initialize the answer variable
  lint ans = 0;

  // Calculate the final answer using the prefix sums
  for (int i = 0; i < n; i++) {
    ans += a[i] % MOD * (MOD + acc[n] - acc[i + 1]) % MOD; // Update answer based on current element and remaining sum
    ans %= MOD; // Ensure the answer is within MOD
  }

  // Output the final result
  cout << ans << endl;

  return 0; // End of the program
}
