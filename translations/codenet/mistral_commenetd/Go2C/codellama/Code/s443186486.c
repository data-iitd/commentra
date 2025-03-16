#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to calculate the number of combinations of 'n' elements taken 'r' at a time
int combi(int n, int r) {
	int c = 1;
	for (int i = 1; i <= r; i++) {
		c = c * (n - i + 1) / i;
	}
	return c;
}

int main() {
	// Read the number of elements in the array from the standard input
	int n;
	scanf("%d", &n);

	// Initialize an array 'a' of size 'n' to store the input elements
	int a[n];
	for (int i = 0; i < n; i++) {
		// Read each element of the array 'a' from the standard input
		scanf("%d", &a[i]);
	}

	// Initialize a slice 's' of size 'n+1' to store the cumulative sum of elements in 'a'
	int s[n+1];
	for (int i = 0; i < n; i++) {
		// Calculate the cumulative sum of elements in 'a' and store it in 's'
		s[i+1] = s[i] + a[i];
	}

	// Sort the slice 's' in ascending order
	qsort(s, n+1, sizeof(int), compare);

	// Initialize variables 'ans' and 'count' to calculate the answer
	int ans = 0;
	int count = 0;
	// Iterate through the sorted slice 's' to find the answer
	for (int i = 0; i < n; i++) {
		// If the current element in 's' is equal to the next element, increment 'count'
		if (s[i] == s[i+1]) {
			count++;
		} else { // If 'count' is greater than zero, calculate the number of combinations of 'count+1' elements taken 2 at a time and add it to 'ans'
			if (count > 0) {
				ans += combi(count+1, 2);
				count = 0;
			}
		}
	}
	// If 'count' is greater than zero after the loop, calculate the number of combinations of 'count+1' elements taken 2 at a time and add it to 'ans'
	if (count > 0) {
		ans += combi(count+1, 2);
	}

	// Print the answer
	printf("%d\n", ans);

	return 0;
}

int compare(const void *a, const void *b) {
	return (*(int*)a - *(int*)b);
}

