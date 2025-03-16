#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

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
  scanf("%d", &N);

  // Initialize an array to store the elements
  ll A[N];

  // Input the elements into the array
  for(int i = 0; i < N; ++i) scanf("%lld", &A[i]);

  // Sort the array in descending order
  qsort(A, N, sizeof(ll), (int (*)(const void *, const void *))compare);

  // Initialize variables to track the minimum difference and the corresponding index
  int index;
  ll max = inf;

  // Find the element in the array that minimizes the difference with twice the second largest element
  for(int i = 1; i < N; ++i) {
    // Calculate the absolute difference and update if it's smaller than the current max
    if(max > abs(A[0] - 2 * A[i])) {
      max = abs(A[0] - 2 * A[i]);
      index = i; // Store the index of the element that gives the minimum difference
    }
  }

  // Output the largest element and the element that minimizes the difference
  printf("%lld %lld\n", A[0], A[index]);
}

int compare(const void *a, const void *b) {
  ll l = *(ll *)a;
  ll r = *(ll *)b;
  if (l < r) return 1;
  if (l > r) return -1;
  return 0;
}
