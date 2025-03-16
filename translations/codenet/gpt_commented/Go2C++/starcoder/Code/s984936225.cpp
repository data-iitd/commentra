#include <bits/stdc++.h>

using namespace std;

int main() {
	int N, M;
	// Read the number of vertices (N) and edges (M) from input
	cin >> N >> M;

	// Define a large constant value to represent infinity
	const int Inf = 1 << 62; // Using a large value for infinity, considering the maximum possible distance

	// Initialize slices to hold the edges and their weights
	vector<int> a(M); // Array to store the starting vertices of edges
	vector<int> b(M); // Array to store the ending vertices of edges
	vector<int> c(M); // Array to store the weights of edges

	// Read the edges and their weights from input
	for (int i = 0; i < M; i++) {
		cin >> a[i] >> b[i] >> c[i];
		c[i] = -c[i]; // Negate the weights for the algorithm (to handle maximization)
	}

	// Initialize the distance array to hold the minimum cost to reach each vertex
	vector<int> dist(N); // Array to store the minimum cost to reach each vertex
	for (int i = 0; i < N; i++) {
		dist[i] = Inf; // Set all distances to infinity initially
	}
	dist[0] = 0; // The starting vertex (0) has a distance of 0

	// Relax edges N times to find the shortest paths
	for (int loop = 0; loop < N; loop++) {
		for (int i = 0; i < M; i++) {
			// Skip if the starting vertex distance is infinity (not reachable)
			if (dist[a[i]-1] == Inf) {
				continue;
			}
			// If a shorter path to vertex b[i] is found, update the distance
			if (dist[b[i]-1] > dist[a[i]-1]+c[i]) {
				dist[b[i]-1] = dist[a[i]-1] + c[i]; // Update the distance to b[i]
			}
		}
	}

	// Store the minimum distance to the last vertex (N-1)
	int ans = dist[N-1]; // The answer is the distance to the last vertex
	vector<bool> navigate(N); // Array to track reachable vertices

	// Check for negative cycles and update reachable vertices
	for (int loop = 0; loop < N; loop++) {
		for (int i = 0; i < M; i++) {
			// Skip if the starting vertex distance is infinity (not reachable)
			if (dist[a[i]-1] == Inf) {
				continue;
			}
			// If a shorter path to vertex b[i] is found, update the distance and mark it as reachable
			if (dist[b[i]-1] > dist[a[i]-1]+c[i]) {
				dist[b[i]-1] = dist[a[i]-1] + c[i];
				navigate[b[i]-1] = true; // Mark b[i] as reachable
			}
			// If a[i] is reachable, then b[i] is also reachable
			if (navigate[a[i]-1]) {
				navigate[b[i]-1] = true;
			}
		}
	}

	// Output the result based on the reachability of the last vertex
	if (navigate[N-1]) {
		cout << "inf" << endl; // If the last vertex is reachable, print "inf" (indicating a negative cycle)
	} else {
		cout << -ans << endl; // Otherwise, print the negative of the answer (since weights were negated)
	}
}

