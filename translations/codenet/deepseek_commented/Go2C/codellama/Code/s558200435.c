#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	int n; // 1. Reading the input number of elements (n)
	scanf("%d", &n);

	int *a = (int *)malloc(n * sizeof(int)); // 2. Reading the elements into a slice (a)
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}

	int *b = (int *)malloc(n * sizeof(int)); // 3. Creating a slice (b) to store the longest increasing subsequence
	for (int i = 0; i < n; i++) { // 4. Finding the longest increasing subsequence
		int x = 0;
		while (x < n && b[x] < a[i]) {
			x++;
		}
		if (x == n) {
			b[n] = a[i];
		} else {
			b[x] = a[i];
		}
	}

	printf("%d\n", n); // 5. Outputting the length of the longest increasing subsequence

	free(a);
	free(b);

	return 0;
}

