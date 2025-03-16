#include <stdio.h>
#include <limits.h>
#include <stdbool.h>

int main() {
    // Initialize variables
    int N, M;
    scanf("%d %d", &N, &M);

    // Constants and initializations
    long long Inf = 1LL << 62;
    // a, b, and c are arrays of size M
    int a[M], b[M];
    long long c[M];

    // Read input values for a, b, and c
    for (int i = 0; i < M; i++) {
        scanf("%d %d %lld", &a[i], &b[i], &c[i]);
        // Set c to its negation
        c[i] = -c[i];
    }

    // Initialize the dist array with the maximum value
    long long dist[N];
    for (int i = 0; i < N; i++) {
        dist[i] = Inf;
    }
    // Set the initial distance of the source node to 0
    dist[0] = 0;

    // Dijkstra's algorithm loop
    for (int loop = 0; loop < N; loop++) {
        for (int i = 0; i < M; i++) {
            // Skip if the current node's distance is still the maximum value
            if (dist[a[i] - 1] == Inf) {
                continue;
            }
            // Update the distance if the new path is shorter
            if (dist[b[i] - 1] > dist[a[i] - 1] + c[i]) {
                dist[b[i] - 1] = dist[a[i] - 1] + c[i];
            }
        }
    }

    // Calculate the answer
    long long ans = dist[N - 1];
    bool navigate[N];
    for (int i = 0; i < N; i++) {
        navigate[i] = false;
    }

    // Dijkstra's algorithm loop (second pass)
    for (int loop = 0; loop < N; loop++) {
        for (int i = 0; i < M; i++) {
            // Skip if the current node's distance is still the maximum value
            if (dist[a[i] - 1] == Inf) {
                continue;
            }
            // Update the distance if the new path is shorter
            if (dist[b[i] - 1] > dist[a[i] - 1] + c[i]) {
                dist[b[i] - 1] = dist[a[i] - 1] + c[i];
                navigate[b[i] - 1] = true;
            }
            // If the previous node is in the navigate array, set the current node's navigate array value to true
            if (navigate[a[i] - 1] == true) {
                navigate[b[i] - 1] = true;
            }
        }
    }

    // Print the result
    if (navigate[N - 1]) {
        printf("inf\n");
    } else {
        printf("%lld\n", -ans);
    }

    // End of the code
    return 0;
}
