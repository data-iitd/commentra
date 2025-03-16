#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <cfloat>
#include <complex>
#include <functional>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

#define ll long long
#define ull unsigned long long
#define P pair<ll, ll>

#define INF 1000000000

vector<vector<ll> > table;
vector<P> roads;
vector<P> qs;

int main() {
  // Read the number of items (N) and the total amount (X)
  ll N, X;
  cin >> N >> X;

  // Initialize the answer and minimum value variables
  ll ans = 0; // Counter for the number of items processed
  ll min = INF; // Initialize min to a large value

  // Process each item
  for (int i = 0; i < N; i++) {
    ll tmp; // Temporary variable to hold the current item's value
    cin >> tmp; // Read the current item's value
    X -= tmp; // Subtract the item's value from total amount X
    ans++; // Increment the count of items processed
    if (tmp < min) min = tmp; // Update min if the current item is smaller
  }

  // Calculate how many more items can be added using the remaining amount
  ans += X / min; // Add the number of additional items that can be bought

  // Output the final answer
  cout << ans << endl;

  return 0; // Indicate successful completion of the program
}

