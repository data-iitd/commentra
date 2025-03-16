#include <iostream>
#include <vector>
#include <climits>

int main() {
    int N, M;
    std::cin >> N >> M; // Read the number of vertices (N) and the number of edges (M)

    const long long Inf = 1LL << 62; // Set Inf to 2^62, representing a large number
    std::vector<int> a(M), b(M), c(M);
    for (int i = 0; i < M; i++) {
        std::cin >> a[i] >> b[i] >> c[i]; // Read the start vertex, end vertex, and cost of each edge
        c[i] = -c[i]; // Negate the cost for the Bellman-Ford algorithm
    }

    std::vector<long long> dist(N, Inf); // Initialize the dist array to store the minimum cost to reach each vertex
    dist[0] = 0; // The starting vertex has a cost of 0

    // Bellman-Ford Algorithm
    for (int loop = 0; loop < N; loop++) {
        for (int i = 0; i < M; i++) {
            if (dist[a[i] - 1] == Inf) {
                continue; // Skip if the start vertex is at infinite distance
            }
            if (dist[b[i] - 1] > dist[a[i] - 1] + c[i]) {
                // Update the distance if a shorter path is found
                dist[b[i] - 1] = dist[a[i] - 1] + c[i];
            }
        }
    }

    long long ans = dist[N - 1]; // The minimum cost to reach the last vertex
    std::vector<bool> navigate(N, false);

    // Negative Cycle Detection
    for (int loop = 0; loop < N; loop++) {
        for (int i = 0; i < M; i++) {
            if (dist[a[i] - 1] == Inf) {
                continue; // Skip if the start vertex is at infinite distance
            }
            if (dist[b[i] - 1] > dist[a[i] - 1] + c[i]) {
                dist[b[i] - 1] = dist[a[i] - 1] + c[i];
                navigate[b[i] - 1] = true; // Mark the end vertex as part of a negative cycle
            }
            if (navigate[a[i] - 1]) {
                navigate[b[i] - 1] = true; // Propagate the negative cycle
            }
        }
    }

    if (navigate[N - 1]) {
        std::cout << "inf" << std::endl; // Print "inf" if a negative cycle is detected
    } else {
        std::cout << -ans << std::endl; // Print the negative of the minimum cost to reach the last vertex
    }

    return 0;
}
