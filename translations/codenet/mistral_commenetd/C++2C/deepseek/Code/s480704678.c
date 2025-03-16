#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <deque>
#include <list>
#include <queue>
#include <stack>
#include <vector>
#include <utility>
#include <algorithm>
#include <map>
#include <set>
#include <complex.h>
#include <math.h>
#include <limits.h>
#include <time.h>
#include <assert.h>
#include <numeric>
#include <functional>
#include <bitset.h>

#define ALL(a) a.begin(),a.end()
#define RALL(a) a.rbegin(),a.rend()

typedef long long int lint;
const lint INF = 1001001001001001LL;
const int inf = 1000000007;
const lint MOD = 1000000007LL;
const double PI = 3.1415926535897932;

// Templates for min and max
void chmin(int *a, const int *b) {
  if (*a > *b) *a = *b; // Set 'a' to the minimum of 'a' and 'b'
}

void chmax(int *a, const int *b) {
  if (*a < *b) *a = *b; // Set 'a' to the maximum of 'a' and 'b'
}

// Define the alias for 'all' elements in a container

/*
 * Main function starts here
 */
int main() {
  // Read the number of elements in the array 'a'
  int n; scanf("%d", &n);

  // Initialize a vector 'a' of size 'n'
  lint *a = (lint *)malloc(n * sizeof(lint));

  // Initialize a vector 'acc' of size 'n+1' with zero as initial value
  lint *acc = (lint *)malloc((n + 1) * sizeof(lint));
  memset(acc, 0, (n + 1) * sizeof(lint));

  // Read the elements of the array 'a' and calculate the cumulative sum
  for (int i = 0; i < n; i++) {
    scanf("%lld", &a[i]);

    // Update the cumulative sum 'acc' for the current index 'i+1'
    acc[i + 1] = acc[i] + a[i];

    // Perform modulo operation to keep the value within the range of 'MOD'
    acc[i + 1] %= MOD;
  }

  // Initialize the answer 'ans' to zero
  lint ans = 0;

  // Calculate the answer using the formula
  for (int i = 0; i < n; i++) {
    // Calculate the contribution of the current element 'a[i]' to the answer
    lint temp = a[i] % MOD * (MOD + acc[n] - acc[i + 1]) % MOD;

    // Add the contribution to the answer
    ans += temp;

    // Perform modulo operation to keep the value within the range of 'MOD'
    ans %= MOD;
  }

  // Print the answer
  printf("%lld\n", ans);

  // Free allocated memory
  free(a);
  free(acc);

  // Terminate the program
  return 0;
}
