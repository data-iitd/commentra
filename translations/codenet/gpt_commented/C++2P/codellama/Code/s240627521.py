#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
#include<cstring>
#include<vector>
#include<list>
#include<algorithm>
#include<map>
#include<set>
#include<queue>
#include<stack>
using namespace std;

// Define long long type as ll for convenience
typedef long long ll;

// Define macros for easier access to pair elements and loop iterations
#define fi first
#define se second
#define mp make_pair
#define rep(i, n) for(int i=0;i<n;++i)
#define rrep(i, n) for(int i=n;i>=0;--i)

// Define constants for large values and mathematical constants
const int inf=1e9+7;
const ll mod=1e9+7;
const ll mod1=998244353;
const ll big=1e18;
const double PI=2*asin(1);

int main() {
  // Read the number of elements
  int N;
  cin >> N;

  // Initialize a vector to store the elements
  vector<ll> A(N);

  // Input the elements into the vector
  for(int i = 0; i < N; ++i) cin >> A[i];

  # <START-OF-CODE>
  # Initialize a variable to store the minimum difference and the corresponding index
  min_diff = inf
  min_index = 0

  # Iterate through the vector and find the element that minimizes the difference with twice the second largest element
  for i in range(1, N):
    # Calculate the absolute difference and update if it's smaller than the current min_diff
    if min_diff > abs(A[0] - 2 * A[i]):
      min_diff = abs(A[0] - 2 * A[i])
      min_index = i

  # Output the largest element and the element that minimizes the difference
  print(A[0], A[min_index])
  # 