#include <stdio.h>
#include <math.h>

int n, a[50], p, b = 0, c = 0;

// Function to calculate nPr
long long nPr(long long n, long long r) {
	long long res = 1;
	for (int i = 0; i < r; i++) {
		res *= (n - i);
	}
	return res;
}

// Function to calculate nCr
long long nCr(long long n, long long r) {
	double res = 1;
	for (int i = 0; i < r; i++) {
		res *= (n - i);
		res /= (i+1);
	}
	return (long long)res;
}

int main() {
	scanf("%d %d", &n, &p);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		if (a[i] % 2 == 0) {
			b++;
		}
		else {
			c++;
		}
	}

	// Calculate the number of subsets with even and odd numbers
	long long bsum = (long long)pow(2, b);
	long long csum = 0;

	if (p == 0) {
		// Sum combinations where the number of elements is even
		for (int i = 0; i <= c; i++) {
			if (i % 2 == 0) {
				csum += nCr(c, i);
			}
		}
	}
	else {
		// Sum combinations where the number of elements is odd
		for (int i = 0; i <= c; i++) {
			if (i % 2 == 1) {
				csum += nCr(c, i);
			}
		}
	}

	// Calculate the final answer as the product of bsum and csum
	long long ans = bsum * csum;
	printf("%lld\n", ans);
}

