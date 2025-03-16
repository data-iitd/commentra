#include <stdio.h>

int main() {
	// Initialize variables
	int N, M;
	scanf("%d %d", &N, &M);

	// Constants and initializations
	int Inf = 1 << 62;
	// a, b, and c are arrays of size M
	int a[M], b[M], c[M];

	// Read input values for a, b, and c
	for (int i = 0; i < M; i++) {
		scanf("%d %d %d", &a[i], &b[i], &c[i]);
		// Set c to its negation
		c[i] = -c[i];
	}

	// Initialize the dist array with the maximum value
	int dist[N];
	for (int i = 0; i < N; i++) {
		dist[i] = Inf;
	}
	// Set the initial distance of the source node to 0
	dist[0] = 0;

	// Dijkstra's algorithm loop
	for (int loop = 0; loop < N; loop++) {
		for (int i = 0; i < M; i++) {
			// Skip if the current node's distance is still the maximum value
			if (dist[a[i]-1] == Inf) {
				continue;
			}
			// Update the distance if the new path is shorter
			if (dist[b[i]-1] > dist[a[i]-1] + c[i]) {
				dist[b[i]-1] = dist[a[i]-1] + c[i];
			}
		}
	}

	// Calculate the answer
	int ans = dist[N-1];
	int navigate[N];

	// Dijkstra's algorithm loop (second pass)
	for (int loop = 0; loop < N; loop++) {
		for (int i = 0; i < M; i++) {
			// Skip if the current node's distance is still the maximum value
			if (dist[a[i]-1] == Inf) {
				continue;
			}
			// Update the distance if the new path is shorter
			if (dist[b[i]-1] > dist[a[i]-1] + c[i]) {
				dist[b[i]-1] = dist[a[i]-1] + c[i];
				navigate[b[i]-1] = 1;
			}
			// If the previous node is in the navigate array, set the current node's navigate array value to true
			if (navigate[a[i]-1] == 1) {
				navigate[b[i]-1] = 1;
			}
		}
	}

	// Print the result
	if (navigate[N-1] == 1) {
		printf("inf\n");
	} else {
		printf("%d\n", -ans);
	}

	// End of the code
	return 0;
}

