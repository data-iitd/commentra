

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Function to calculate modular exponentiation
int modpow(int a, int n) {
	int res = 1;
	for ( ; n > 0; n >>= 1) {
		if (n & 1) {
			res = (res * a) % 1000000007;
		}
		a = (a * a) % 1000000007;
	}
	return res;
}

// Function to sort an array of integers
void sort(int *a, int n) {
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (a[i] > a[j]) {
				int temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
		}
	}
}

// Function to calculate the answer
int calc(int *c, int n) {
	int ans = 0;
	sort(c, n);
	for (int i = 0; i < n; i++) {
		ans = (ans + (n + 1 - i) * c[i] % 1000000007) % 1000000007;
	}
	return ans * modpow(4, n - 1) % 1000000007;
}

// Driver function
int main() {
	int n;
	scanf("%d", &n);
	int *c = (int *) malloc(n * sizeof(int));
	for (int i = 0; i < n; i++) {
		scanf("%d", &c[i]);
	}
	printf("%d\n", calc(c, n));
	return 0;
}

Time Complexity: O(nlogn)
Space Complexity: O(n)

