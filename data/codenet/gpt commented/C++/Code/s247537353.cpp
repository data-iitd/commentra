#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <queue>
#include <numeric>
#include <random>
#include <algorithm>
#include <functional>
#include <cassert>

using namespace std;
typedef long long ll;

// Function to update the value of 'a' to 'b' if 'b' is less than 'a'
template<class T> inline bool chmin(T& a, T b) {
  if (a > b) {
    a = b; // Update 'a' to 'b'
    return true; // Indicate that 'a' was changed
  }
  return false; // Indicate that 'a' was not changed
}

// Function to update the value of 'a' to 'b' if 'b' is greater than 'a'
template<class T> inline bool chmax(T& a, T b) {
  if (a < b) {
    a = b; // Update 'a' to 'b'
    return true; // Indicate that 'a' was changed
  }
  return false; // Indicate that 'a' was not changed
}

// Constants for infinity and modulo operations
const int INF = (1 << 30) - 1; // Integer infinity
const ll INFLL= (1LL << 61) - 1; // Long long infinity
const int MOD = 1000000007; // Modulo value for calculations

// Macros for convenience in iterating and accessing containers
#define ALL(a) (a).begin(),(a).end() // Macro to access all elements of a container
#define rALL(a) (a).rbegin(),(a).rend() // Macro to access all elements in reverse order
#define FOR(i,a,b) for(int i=(a);i<(b);++i) // Macro for a for-loop from a to b
#define REP(i,n) FOR(i,0,n) // Macro for a for-loop from 0 to n

int main(){
  cin.tie(nullptr); // Untie cin from cout for faster input
  ios::sync_with_stdio(false); // Disable synchronization with C I/O for performance

  ll A, B, C, K; // Declare variables for input
  cin >> A >> B >> C >> K; // Read input values for A, B, C, and K

  // Check if the sum of A and B is greater than or equal to K
  if (A + B >= K) {
    // If true, output the minimum of A and K
    cout << min(A, K) << endl;
  } else {
    // If false, calculate and output the remaining value after subtracting (K - (A + B)) from A
    cout << A - (K - (A + B)) << endl;
  }
}
