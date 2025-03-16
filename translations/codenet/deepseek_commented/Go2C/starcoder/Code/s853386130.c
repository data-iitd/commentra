#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Constants for the modulo operation and infinity value
#define mod 1000000007
#define INF 1000000007

int main() {
	// Read the number of cities, roads, and restaurants
	int n, m, R;
	scanf("%d %d %d", &n, &m, &R);

	// Read the indices of the restaurants and decrement by 1 for 0-based indexing
	int *rs = malloc(sizeof(int) * R);
	for (int i = 0; i < R; i++) {
		scanf("%d", &rs[i]);
		rs[i]--;
	}

	// Initialize the cost matrix with INF and set diagonal to 0
	int **costs = malloc(sizeof(int*) * n);
	for (int i = 0; i < n; i++) {
		costs[i] = malloc(sizeof(int) * n);
		for (int j = 0; j < n; j++) {
			costs[i][j] = INF;
		}
		costs[i][i] = 0;
	}

	// Read the road connections and their costs, updating the cost matrix
	int a, b, c;
	for (int i = 0; i < m; i++) {
		scanf("%d %d %d", &a, &b, &c);
		a--;
		b--;
		costs[a][b] = c;
		costs[b][a] = c;
	}

	// Use the Floyd-Warshall algorithm to compute the shortest paths between all pairs of cities
	for (int k = 0; k < n; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				costs[i][j] = min(costs[i][j], costs[i][k]+costs[k][j]);
			}
		}
	}

	// Generate all permutations of the restaurant indices and find the minimum cost tour
	int **perms = malloc(sizeof(int*) * R);
	for (int i = 0; i < R; i++) {
		perms[i] = malloc(sizeof(int) * R);
	}
	permutations(rs, perms, 0, R-1);
	int ans = INF;
	for (int i = 0; i < R; i++) {
		int tmp = 0;
		for (int j = 1; j < R; j++) {
			int from = perms[i][j-1];
			int to = perms[i][j];
			tmp += costs[from][to];
		}
		ans = min(ans, tmp);
	}
	printf("%d\n", ans);
}

// Function to generate all permutations of a given array
void permutations(int *arr, int **perms, int l, int r) {
	if (l == r) {
		for (int i = 0; i < r+1; i++) {
			perms[l][i] = arr[i];
		}
	} else {
		for (int i = l; i <= r; i++) {
			swap(arr, l, i);
			permutations(arr, perms, l+1, r);
			swap(arr, l, i);
		}
	}
}

// Function to swap two elements in an array
void swap(int *arr, int i, int j) {
	int tmp = arr[i];
	arr[i] = arr[j];
	arr[j] = tmp;
}

// Function to find the minimum of two integers
int min(int a, int b) {
	if (a < b) {
		return a;
	}
	return b;
}

