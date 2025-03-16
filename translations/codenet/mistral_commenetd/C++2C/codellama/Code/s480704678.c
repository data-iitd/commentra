
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <math.h>

#define MOD 1000000007LL
#define INF 1001001001001001LL

// Templates for min and max
void chmin(long long int *a, const long long int b){
  if(*a > b) *a = b; // Set 'a' to the minimum of 'a' and 'b'
}

void chmax(long long int *a, const long long int b){
  if(*a < b) *a = b; // Set 'a' to the maximum of 'a' and 'b'
}

// Define the alias for 'all' elements in a container
#define ALL(a) a.begin(),a.end()
#define RALL(a) a.rbegin(),a.rend()

/*
 * Main function starts here
 */
int main() {
  // Read the number of elements in the array 'a'
  int n; scanf("%d", &n);

  // Initialize a vector 'a' of size 'n'
  long long int *a = (long long int *)malloc(n * sizeof(long long int));

  // Initialize a vector 'acc' of size 'n+1' with zero as initial value
  long long int *acc = (long long int *)malloc((n + 1) * sizeof(long long int));

  // Read the elements of the array 'a' and calculate the cumulative sum
  for (int i = 0; i < n; i++) {
    scanf("%lld", &a[i]);

    // Update the cumulative sum 'acc' for the current index 'i+1'
    acc[i + 1] = acc[i] + a[i];

    // Perform modulo operation to keep the value within the range of 'MOD'
    acc[i + 1] %= MOD;
  }

  // Initialize the answer 'ans' to zero
  long long int ans = 0;

  // Calculate the answer using the formula
  for (int i = 0; i < n; i++) {
    // Calculate the contribution of the current element 'a[i]' to the answer
    long long int temp = a[i] % MOD * (MOD + acc[n] - acc[i + 1]) % MOD;

    // Add the contribution to the answer
    ans += temp;

    // Perform modulo operation to keep the value within the range of 'MOD'
    ans %= MOD;
  }

  // Print the answer
  printf("%lld\n", ans);

  // Terminate the program
  return 0;
}

