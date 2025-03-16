// Importing necessary packages
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Global variables initialization
const int mod = 1000000007;
const int INF = 1000000007;

// Helper function to generate all permutations of given slice
void permutations(int arr[], int n, int** res, int* res_size) {
	// Helper function initialization
	void helper(int arr[], int n);
	int i, j, tmp;

	helper = (int arr[], int n) {
		if (n == 1) { // Base case: when only one element left in arr
			tmp = (int*)malloc(n * sizeof(int));
			memcpy(tmp, arr, n * sizeof(int)); // Copying arr to tmp for returning
			*res = (int**)realloc(*res, (*res_size + 1) * sizeof(int*));
			(*res)[*res_size] = tmp; // Adding tmp to result
			*res_size += 1;
			return;
		}

		for (i = 0; i < n; i++) { // Iterating through all elements of arr
			helper(arr, n - 1); // Recursively calling helper function with n-1
			if (n % 2 == 1) { // Swapping first and last elements when n is odd
				tmp = arr[i];
				arr[i] = arr[n - 1];
				arr[n - 1] = tmp;
			} else { // Swapping first and last elements when n is even
				tmp = arr[0];
				arr[0] = arr[n - 1];
				arr[n - 1] = tmp;
			}
		}
	}
	helper(arr, n); // Calling helper function with arr and its length
}

// Main function
int main() {
	// Reading input from standard input
	int n, m, R, a, b, c, i, j, k, tmp, ans;
	scanf("%d", &n); // Reading number of cities n
	scanf("%d", &m); // Reading number of roads m
	scanf("%d", &R); // Reading number of starting points R

	// Initializing rs slice with starting points
	int* rs = (int*)malloc(R * sizeof(int));
	for (i = 0; i < R; i++) {
		scanf("%d", &rs[i]); // Reading starting point i
		rs[i]--; // Decreasing starting point index for matrix indexing
	}

	// Initializing costs matrix with infinite values
	int** costs = (int**)malloc(n * sizeof(int*));
	for (i = 0; i < n; i++) {
		costs[i] = (int*)malloc(n * sizeof(int));
		for (j = 0; j < n; j++) {
			costs[i][j] = INF; // Initializing costs[i][j] with infinite value
			costs[i][i] = 0;   // Initializing costs[i][i] with zero value
		}
	}

	// Reading roads and filling costs matrix with their costs
	for (i = 0; i < m; i++) {
		scanf("%d", &a); // Reading road starting point a
		scanf("%d", &b); // Reading road ending point b
		scanf("%d", &c); // Reading road cost c
		a--;                 // Decreasing starting point index for matrix indexing
		b--;                 // Decreasing ending point index for matrix indexing
		costs[a][b] = c;     // Filling costs[a][b] with cost c
		costs[b][a] = c;     // Filling costs[b][a] with cost c
	}

	// Applying Warshall-Floyd algorithm to find shortest paths between all pairs of cities
	for (k = 0; k < n; k++) {
		for (i = 0; i < n; i++) {
			for (j = 0; j < n; j++) {
				costs[i][j] = min(costs[i][j], costs[i][k] + costs[k][j]); // Updating costs[i][j] with minimum of current value and costs[i][k] + costs[k][j]
			}
		}
	}

	// Calculating minimum cost of visiting all cities in a single tour
	int** res = NULL;
	int res_size = 0;
	permutations(rs, R, &res, &res_size); // Generating all permutations of starting points
	ans = INF; // Initializing answer with infinite value
	for (i = 0; i < res_size; i++) { // Iterating through all permutations
		tmp = 0; // Initializing temporary variable tmp with zero value
		for (j = 1; j < R; j++) { // Iterating through all pairs of consecutive starting points
			from = res[i][j - 1]; // Getting previous starting point
			to = res[i][j]; // Getting current starting point
			tmp += costs[from][to]; // Adding cost of road from from to to tmp
		}
		ans = min(ans, tmp); // Updating answer with minimum of current answer and tmp
	}
	printf("%d\n", ans); // Printing answer
	return 0;
}

