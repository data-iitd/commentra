
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
#include <assert.h>
#include <limits.h>
#include <float.h>
#include <ctype.h>
#include <time.h>

int main() {
	int n; // Step 1: Read the size of the array
	scanf("%d", &n);

	int a[n]; // Step 1: Create the array 'a' of size 'n'
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]); // Step 1: Read the elements of the array 'a'
	}

	int s[n+1]; // Step 2: Create the prefix sum array's' of size 'n+1'
	for (int i = 0; i < n; i++) {
		s[i+1] = s[i] + a[i]; // Step 2: Calculate the prefix sums
	}

	qsort(s, n+1, sizeof(int), compare); // Step 3: Sort the prefix sum array's'

	int ans = 0; // Step 4: Initialize the answer variable
	int count = 0; // Step 4: Initialize the count variable
	for (int i = 0; i < n; i++) {
		if (s[i] == s[i+1]) { // Step 4: Check for consecutive equal sums
			count++; // Step 4: Increment the count if sums are equal
		} else if (count > 0) { // Step 4: If count is greater than 0, calculate combinations
			ans += combi(count+1, 2); // Step 4: Calculate combinations using the combi function
			count = 0; // Step 4: Reset the count
		}
	}
	if (count > 0) { // Step 4: Check if there are any remaining counts to calculate combinations for
		ans += combi(count+1, 2); // Step 4: Calculate combinations for the remaining counts
	}

	printf("%d", ans); // Step 5: Print the final answer
}

int compare(const void *a, const void *b) {
	return *(int*)a - *(int*)b;
}

int combi(int n, int r) { // Step 4: Define the combi function to calculate combinations
	int c = 1;
	for (int i = 1; i <= r; i++) {
		c = c * (n - i + 1) / i;
	}
	return c;
}

