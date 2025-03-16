#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

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

  // Initialize a vector to store the elements
  ll *A = (ll*)malloc(N*sizeof(ll));

  // Input the elements into the vector
  for(int i = 0; i < N; ++i) scanf("%lld", &A[i]);

  // Sort the vector in descending order
  qsort(A, N, sizeof(ll), compare);

  // Initialize variables to track the minimum difference and the corresponding index
  int index;
  ll max = inf;

  // Find the element in the vector that minimizes the difference with twice the second largest element
  for(int i = 1; i < N; ++i) {
    // Calculate the absolute difference and update if it's smaller than the current max
    if(max > abs(A[0] - 2 * A[i])) {
      max = abs(A[0] - 2 * A[i]);
      index = i; // Store the index of the element that gives the minimum difference
    }
  }

  // Output the largest element and the element that minimizes the difference
  printf("%lld %lld\n", A[0], A[index]);

  // Free the memory allocated for the vector
  free(A);
}

int compare(const void *a, const void *b) {
  return (*(ll*)b - *(ll*)a);
}

