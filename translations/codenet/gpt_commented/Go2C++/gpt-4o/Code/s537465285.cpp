#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <limits>

using namespace std;

// Function to check if the graph is bipartite
bool Bipartite(const vector<string>& S) {
    int N = S.size(); // Get the number of nodes
    vector<int> D(N, 0); // Distance array to store levels of nodes
    D[0] = 1; // Start with the first node at level 1
    queue<int> Q; // Queue for BFS
    Q.push(0); // Start BFS from the first node
    bool ret = true; // Variable to track if the graph is bipartite

    // Perform BFS to check for bipartiteness
    while (!Q.empty() && ret) {
        int q = Q.front(); Q.pop(); // Current node
        for (int j = 0; j < N; j++) {
            if (S[q][j] == '0') {
                continue; // Skip if there is no edge
            }
            if (D[j] == 0) {
                // Assign level to the adjacent node
                D[j] = D[q] + 1;
                Q.push(j); // Add to queue
            } else {
                // Check if the adjacent node has the same level
                if (D[j] % 2 == D[q] % 2) {
                    ret = false; // Not bipartite
                    break;
                }
            }
        }
    }
    return ret; // Return the result of bipartiteness check
}

// Function to perform the Floyd-Warshall algorithm to find the longest shortest path
int WarshallFloyd(const vector<string>& S) {
    int N = S.size(); // Get the number of nodes
    vector<vector<int>> G(N, vector<int>(N, numeric_limits<int>::max())); // Initialize the graph matrix

    // Initialize the graph with distances
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (i == j) {
                G[i][j] = 0; // Distance to self is 0
            } else if (S[i][j] == '1') {
                G[i][j] = 1; // Edge exists, set distance to 1
            }
        }
    }

    // Floyd-Warshall algorithm to find shortest paths
    for (int k = 0; k < N; k++) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (G[i][k] != numeric_limits<int>::max() && G[k][j] != numeric_limits<int>::max() && G[i][k] + G[k][j] < G[i][j]) {
                    G[i][j] = G[i][k] + G[k][j]; // Update shortest path
                }
            }
        }
    }

    // Find the maximum distance in the graph
    int ans = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (G[i][j] != numeric_limits<int>::max()) {
                ans = max(ans, G[i][j]); // Update maximum distance
            }
        }
    }
    return ans + 1; // Return the maximum distance found
}

// Main function to execute the program
int main() {
    int N;
    cin >> N; // Read the number of nodes
    vector<string> S(N); // Initialize the adjacency matrix
    cin.ignore(); // Ignore the newline after the integer input
    for (int i = 0; i < N; i++) {
        getline(cin, S[i]); // Read each line of the adjacency matrix
    }

    // Check if the graph is bipartite and process accordingly
    if (!Bipartite(S)) {
        cout << -1 << endl; // Output -1 if not bipartite
    } else {
        cout << WarshallFloyd(S) << endl; // Output the longest shortest path if bipartite
    }

    return 0; // End of program
}

// <END-OF-CODE>
