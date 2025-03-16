
#include <stdio.h>
#include <stdlib.h>

int main() {
	// Initialize variables n, m, x for input
	int n, m, x;
	scanf("%d %d %d", &n, &m, &x);

	// Allocate memory for 2D array a and 1D array p
	int **a = (int **)malloc(n * sizeof(int *));
	int *p = (int *)malloc(n * sizeof(int));

	// Read input for p and initialize a with empty rows
	for (int i = 0; i < n; i++) {
		// Read input for p[i]
		scanf("%d", &p[i]);

		// Allocate memory for row i of a
		a[i] = (int *)malloc(m * sizeof(int));

		// Read input for each element of row i of a
		for (int j = 0; j < m; j++) {
			scanf("%d", &a[i][j]);
		}
	}

	// Initialize variables ans, tot, and ok
	int ans = 1200001;
	int tot;
	int ok;

	// Iterate through all possible combinations of bits
	for (int bits = 0; bits < 1<<n; bits++) {
		// Initialize skill array
		int *skill = (int *)malloc(m * sizeof(int));

		// Calculate total points and update skill array for the current combination of bits
		tot = 0;
		ok = 1;
		for (int i = 0; i < n; i++) {
			// Check if the current bit is set
			if (bits>>i)&1 == 1 {
				// Add points from p[i] to total
				tot += p[i];

				// Update skill array for each skill
				for (int j = 0; j < m; j++) {
					skill[j] += a[i][j];
				}
			}
		}

		// Check if the current combination of skills is valid
		for (int i = 0; i < m; i++) {
			if (skill[i] < x) {
				ok = 0;
				break;
			}
		}

		// If the current combination is valid, update ans if the total points are less than the current answer
		if (ok) {
			if (ans > tot) {
				ans = tot;
			}
		}

		// Free memory for skill array
		free(skill);
	}

	// Print the answer
	if (ans!= 1200001) {
		printf("%d\n", ans);
	} else {
		printf("-1\n");
	}

	// Free memory for 2D array a and 1D array p
	for (int i = 0; i < n; i++) {
		free(a[i]);
	}
	free(a);
	free(p);

	return 0;
}

// 