#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <limits>

using namespace std;

// Function to read an integer from standard input
int NextInt() {
    int n;
    cin >> n;
    return n;
}

// Function to write a value to standard output
void Write(int s) {
    cout << s << endl;
}

// Function to check if a given graph is bipartite
bool Bipartite(const vector<string>& S) {
    int N = S.size();
    vector<int> D(N, 0);
    queue<int> Q;
    bool ret = true;

    // Start with the first vertex
    D[0] = 1;
    Q.push(0);

    // Iterate over each vertex
    while (!Q.empty() && ret) {
        int q = Q.front();
        Q.pop();

        // Iterate over each neighbor of the current vertex
        for (int j = 0; j < N; j++) {
            if (S[q][j] == '0') {
                continue;
            }

            // If neighbor is not visited yet
            if (D[j] == 0) {
                // Mark neighbor as visited
                D[j] = D[q] + 1;
                Q.push(j);
            } else {
                // If degrees of current and neighbor are different
                if (D[j] % 2 == D[q] % 2) {
                    // Graph is not bipartite
                    ret = false;
                    break;
                }
            }
        }
    }

    return ret;
}

// Function to find the shortest distance between all pairs of vertices using Floyd-Warshall algorithm
int WarshallFloyd(const vector<string>& S) {
    int N = S.size();
    vector<vector<int>> G(N, vector<int>(N, numeric_limits<int>::max()));

    // Initialize adjacency matrix
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (i == j) {
                G[i][j] = 0;
            } else if (S[i][j] == '1') {
                G[i][j] = 1;
            }
        }
    }

    // Iterate over all vertices k
    for (int k = 0; k < N; k++) {
        // Iterate over all vertices i
        for (int i = 0; i < N; i++) {
            // Iterate over all vertices j
            for (int j = 0; j < N; j++) {
                // Update shortest distance if found
                if (G[i][k] != numeric_limits<int>::max() && G[k][j] != numeric_limits<int>::max() && G[i][k] + G[k][j] < G[i][j]) {
                    G[i][j] = G[i][k] + G[k][j];
                }
            }
        }
    }

    // Initialize answer as maximum distance
    int ans = 0;

    // Iterate over all vertices i
    for (int i = 0; i < N; i++) {
        // Iterate over all vertices j
        for (int j = 0; j < N; j++) {
            // Update answer if found
            if (G[i][j] != numeric_limits<int>::max()) {
                ans = max(ans, G[i][j]);
            }
        }
    }

    // Return answer plus one
    return ans + 1;
}

// Main function
int main() {
    // Read number of vertices
    int N = NextInt();

    // Initialize graph
    vector<string> S(N);
    for (int i = 0; i < N; i++) {
        cin >> S[i];
    }

    // Check if graph is bipartite
    if (!Bipartite(S)) {
        // Write -1 if graph is not bipartite
        Write(-1);
    } else {
        // Write shortest distance between all pairs of vertices
        Write(WarshallFloyd(S));
    }

    return 0;
}

// <END-OF-CODE>
