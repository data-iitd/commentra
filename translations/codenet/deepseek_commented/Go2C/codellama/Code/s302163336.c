#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	int n, m, i, ai, bi, ans;
	int *h, *good;
	char *line, *token;

	// Read the number of elements
	scanf("%d", &n);

	// Allocate memory for the heights and "good" status
	h = (int *)malloc(n * sizeof(int));
	good = (int *)malloc(n * sizeof(int));

	// Read the heights of each element
	for (i = 0; i < n; i++) {
		scanf("%d", &h[i]);
		good[i] = 1; // Assume all elements are initially good
	}

	// Read the number of comparisons
	scanf("%d", &m);

	// Read the comparisons and update "good" status
	for (i = 0; i < m; i++) {
		scanf("%d %d", &ai, &bi);
		if (h[ai] > h[bi]) {
			good[bi] = 0; // Mark the second element as not good if overshadowed
		} else if (h[ai] < h[bi]) {
			good[ai] = 0; // Mark the first element as not good if overshadowed
		} else {
			good[ai] = 0; // Mark both elements as not good if heights are equal
			good[bi] = 0;
		}
	}

	// Count the number of good elements
	ans = 0;
	for (i = 0; i < n; i++) {
		if (good[i]) { // Count the elements that are still good
			ans++;
		}
	}

	// Print the number of good elements
	printf("%d\n", ans);

	// Free memory
	free(h);
	free(good);

	return 0;
}

