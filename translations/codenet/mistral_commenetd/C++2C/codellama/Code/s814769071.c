
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>
#include <stdint.h>

#define rep(i, s, e) for (int(i) = (s); (i) < (e); ++(i))
#define rep(i, e) for (int(i) = 0; (i) < (e); ++(i))
#define rrep(i, s) for (int(i) = (s) - 1; (i) >= 0; --(i))
#define all(x) x.begin(),x.end()

int main()
{
	// Initialize variables
	long long n, k;
	scanf("%lld %lld", &n, &k);
	long long MOD = 1e9 + 7;

	// Calculate the maximum number of unique elements in a subset of size k from 1 to n
	long long mx = n * (n + 1) / 2 - (n - k)*(n - k + 1) / 2;

	// Calculate the minimum number of unique elements in a subset of size k from 1 to n
	long long mn = k * (k - 1) / 2;

	// Initialize result variable
	long long res = 0;

	// Iterate through all possible subset sizes from k to n+1
	for (int i = k; i <= n + 1; ++i)
	{
		// Calculate the number of unique elements in the current subset
		res += mx - mn + 1;

		// Update the maximum and minimum number of unique elements for the next iteration
		mx += n - i;
		mn += i;

		// Update the result variable
		res %= MOD;
	}

	// Print the final result
	printf("%lld\n", res);
}

