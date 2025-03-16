#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>

int main() {
	int n; // 1. Reading the input number of elements (n)
	scanf("%d", &n);

	int* a = malloc(n * sizeof(int)); // 2. Reading the elements into a slice (a)
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}

	int* b = malloc(0); // 3. Creating a slice (b) to store the longest increasing subsequence
	for (int i = 0; i < n; i++) { // 4. Finding the longest increasing subsequence
		int x = bsearch(b, 0, b_len, a[i], sizeof(int), compare);
		if (x == b_len) {
			b = realloc(b, (b_len + 1) * sizeof(int));
			b[b_len] = a[i];
			b_len++;
		} else {
			b[x] = a[i];
		}
	}

	printf("%d\n", b_len); // 5. Outputting the length of the longest increasing subsequence
	free(a);
	free(b);
}

int compare(const void* a, const void* b) {
	return *(int*)a - *(int*)b;
}

int bsearch(void* a, int l, int r, int x, int size, int (*compare)(const void*, const void*)) {
	while (l < r) {
		int m = (l + r) / 2;
		if (compare((char*)a + m * size, &x) < 0) {
			l = m + 1;
		} else {
			r = m;
		}
	}
	return l;
}

