#include <iostream>
#include <vector>
#include <limits>

using namespace std;

int main() {
    // Initialize variables
    int N, M;
    cin >> N >> M;

    // Constants and initializations
    long long Inf = 1LL << 62;
    // a, b, and c are vectors of size M
    vector<int> a(M), b(M), c(M);

    // Read input values for a, b, and c
    for (int i = 0; i < M; i++) {
        cin >> a[i] >> b[i] >> c[i];
        // Set c to its negation
        c[i] = -c[i];
    }

    // Initialize the dist array with the maximum value
    vector<long long> dist(N, Inf);
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
    vector<bool> navigate(N, false);

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
            if (navigate[a[i] - 1]) {
                navigate[b[i] - 1] = true;
            }
        }
    }

    // Print the result
    if (navigate[N - 1]) {
        cout << "inf" << endl;
    } else {
        cout << -ans << endl;
    }

    // End of the code
    return 0;
}
