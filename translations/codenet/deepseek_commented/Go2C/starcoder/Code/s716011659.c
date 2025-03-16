#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
	int n;
	scanf("%d", &n); // Reading the size of the array

	int *arrA = (int *)malloc(n * sizeof(int));
	for (int i = 0; i < n; i++) {
		scanf("%d", &arrA[i]); // Reading the elements of the array
	}

	int *cumSumA = (int *)malloc((n + 1) * sizeof(int));
	cumSumA[0] = 0; // Initialize the cumulative sum array
	for (int i = 0; i < n; i++) {
		cumSumA[i + 1] = cumSumA[i] + arrA[i]; // Calculate cumulative sums
	}

	double ans = 10000000000.0; // Initialize the answer with a large number
	for (int i = 1; i < n; i++) {
		if (fabs(cumSumA[n] - (cumSumA[i] * 2)) < ans) {
			ans = fabs(cumSumA[n] - (cumSumA[i] * 2)); // Update the answer if a smaller difference is found
		}
	}

	printf("%d", (int)ans); // Output the minimum difference
	return 0;
}

