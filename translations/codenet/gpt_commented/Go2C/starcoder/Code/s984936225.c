

#include <stdio.h>
#include <stdlib.h>

// Function to read input from stdin
int read_input(int *a, int *b, int *c, int *N, int *M) {
	scanf("%d %d", N, M);
	for (int i = 0; i < *M; i++) {
		scanf("%d %d %d", &a[i], &b[i], &c[i]);
	}
}

// Function to print output to stdout
void print_output(int *dist, int *navigate, int *N) {
	if (navigate[*N-1]) {
		printf("inf\n");
	} else {
		printf("%d\n", -dist[*N-1]);
	}
}

// Function to find the shortest path from vertex 0 to all other vertices
void find_shortest_path(int *a, int *b, int *c, int *dist, int *navigate, int *N, int *M) {
	// Initialize the distance array to hold the minimum cost to reach each vertex
	for (int i = 0; i < *N; i++) {
		dist[i] = INT_MAX; // Set all distances to infinity initially
	}
	dist[0] = 0; // The starting vertex (0) has a distance of 0

	// Relax edges N times to find the shortest paths
	for (int loop = 0; loop < *N; loop++) {
		for (int i = 0; i < *M; i++) {
			// Skip if the starting vertex distance is infinity (not reachable)
			if (dist[a[i]-1] == INT_MAX) {
				continue;
			}
			// If a shorter path to vertex b[i] is found, update the distance
			if (dist[b[i]-1] > dist[a[i]-1]+c[i]) {
				dist[b[i]-1] = dist[a[i]-1] + c[i]; // Update the distance to b[i]
			}
		}
	}

	// Check for negative cycles and update reachable vertices
	for (int loop = 0; loop < *N; loop++) {
		for (int i = 0; i < *M; i++) {
			// Skip if the starting vertex distance is infinity (not reachable)
			if (dist[a[i]-1] == INT_MAX) {
				continue;
			}
			// If a shorter path to vertex b[i] is found, update the distance and mark it as reachable
			if (dist[b[i]-1] > dist[a[i]-1]+c[i]) {
				dist[b[i]-1] = dist[a[i]-1] + c[i];
				navigate[b[i]-1] = true; // Mark b[i] as reachable
			}
			// If a[i] is reachable, then b[i] is also reachable
			if (navigate[a[i]-1] == true) {
				navigate[b[i]-1] = true;
			}
		}
	}
}

// Driver code
int main() {
	int N, M;
	int a[100000], b[100000], c[100000];
	int dist[100000], navigate[100000];
	read_input(a, b, c, &N, &M);
	find_shortest_path(a, b, c, dist, navigate, &N, &M);
	print_output(dist, navigate, &N);
	return 0;
}

Time Complexity: O(N*M)
Space Complexity: O(N)

