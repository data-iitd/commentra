#include <stdio.h>
#include <limits.h>
#include <stdbool.h>

int main() {
    int N, M;
    scanf("%d %d", &N, &M); // Read the number of vertices (N) and the number of edges (M)

    long long Inf = 1LL << 62; // Set Inf to 2^62, representing a large number
    int a[M], b[M];
    long long c[M];
    for (int i = 0; i < M; i++) {
        scanf("%d %d %lld", &a[i], &b[i], &c[i]); // Read the start vertex, end vertex, and cost of each edge
        c[i] = -c[i]; // Negate the cost for the Bellman-Ford algorithm
    }

    long long dist[N]; // Initialize the dist array to store the minimum cost to reach each vertex
    for (int i = 0; i < N; i++) {
        dist[i] = Inf; // Set initial distances to Inf except for the starting vertex (0)
    }
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
    bool navigate[N]; // Array to track vertices involved in negative cycles
<<<<<<< HEAD
    for (int i = 0; i < N; i++) {
        navigate[i] = false; // Initialize navigate array
    }
=======
>>>>>>> 98c87cb78a (data updated)

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
            if (navigate[a[i] - 1] == true) {
                navigate[b[i] - 1] = true; // Propagate the negative cycle
            }
        }
    }

    if (navigate[N - 1]) {
        printf("inf\n"); // Print "inf" if a negative cycle is detected
    } else {
        printf("%lld\n", -ans); // Print the negative of the minimum cost to reach the last vertex
    }

    return 0;
}
<<<<<<< HEAD

// <END-OF-CODE>
=======
>>>>>>> 98c87cb78a (data updated)
