#include <stdio.h>

int main() {
	int N, M;
	scanf("%d %d", &N, &M); // Read the number of vertices (N) and the number of edges (M)

	int Inf = 1 << 62; // Set Inf to 2^62, representing a large number
	int a[M], b[M], c[M];
	for (int i = 0; i < M; i++) {
		scanf("%d %d %d", &a[i], &b[i], &c[i]); // Read the start vertex, end vertex, and cost of each edge
		c[i] = -c[i]; // Negate the cost for the Bellman-Ford algorithm
	}

	int dist[N];
	for (int i = 0; i < N; i++) {
		dist[i] = Inf; // Set initial distances to Inf except for the starting vertex (0)
	}
	dist[0] = 0; // The starting vertex has a cost of 0

	// Bellman-Ford Algorithm
	for (int loop = 0; loop < N; loop++) {
		for (int i = 0; i < M; i++) {
			if (dist[a[i]-1] == Inf) {
				continue; // Skip if the start vertex is at infinite distance
			}
			if (dist[b[i]-1] > dist[a[i]-1]+c[i]) {
				// Update the distance if a shorter path is found
				dist[b[i]-1] = dist[a[i]-1] + c[i];
			}
		}
	}

	int ans = dist[N-1]; // The minimum cost to reach the last vertex
	int navigate[N];

	// Negative Cycle Detection
	for (int loop = 0; loop < N; loop++) {
		for (int i = 0; i < M; i++) {
			if (dist[a[i]-1] == Inf) {
				continue; // Skip if the start vertex is at infinite distance
			}
			if (dist[b[i]-1] > dist[a[i]-1]+c[i]) {
				dist[b[i]-1] = dist[a[i]-1] + c[i];
				navigate[b[i]-1] = 1; // Mark the end vertex as part of a negative cycle
			}
			if (navigate[a[i]-1] == 1) {
				navigate[b[i]-1] = 1; // Propagate the negative cycle
			}
		}
	}

	if (navigate[N-1] == 1) {
		printf("inf\n"); // Print "inf" if a negative cycle is detected
	} else {
		printf("%d\n", -ans); // Print the negative of the minimum cost to reach the last vertex
	}

	return 0;
}
