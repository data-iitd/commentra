

#include <stdio.h>

#define MOD 1000000007LL

int main() {
  // Read the number of elements in the array 'a'
  int n; scanf("%d", &n);

  // Initialize an array 'a' of size 'n'
  long long int a[n];

  // Initialize an array 'acc' of size 'n+1' with zero as initial value
  long long int acc[n + 1] = {0};

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

