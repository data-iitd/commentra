#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <limits>

using namespace std;

// Function to read an integer from input
int NextInt() {
    int n;
    cin >> n;
    return n;
}

// Function to write output
void Write(int s) {
    cout << s << endl;
}

// Function to check if a graph is bipartite
bool Bipartite(const vector<string>& S) {
    int N = S.size();
    vector<int> D(N, 0); // Distance array
    D[0] = 1; // Start from the first vertex
    queue<int> Q; // Queue for BFS
    Q.push(0);
    bool ret = true; // Return value

    while (!Q.empty() && ret) {
        int q = Q.front();
        Q.pop();
        for (int j = 0; j < N; j++) {
            if (S[q][j] == '0') {
                continue;
            }
            if (D[j] == 0) {
                D[j] = D[q] + 1;
                Q.push(j);
            } else if (D[j] % 2 == D[q] % 2) {
                ret = false;
                break;
            }
        }
    }
    return ret;
}

// Function to compute the shortest paths between all pairs of vertices
int WarshallFloyd(const vector<string>& S) {
    int N = S.size();
    vector<vector<int>> G(N, vector<int>(N, numeric_limits<int>::max()));
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (i == j) {
                G[i][j] = 0; // Distance to self is zero
            } else if (S[i][j] == '1') {
                G[i][j] = 1; // Direct edge weight
            }
        }
    }

    for (int k = 0; k < N; k++) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (G[i][k] != numeric_limits<int>::max() && G[k][j] != numeric_limits<int>::max() && G[i][k] + G[k][j] < G[i][j]) {
                    G[i][j] = G[i][k] + G[k][j]; // Update shortest path
                }
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (G[i][j] != numeric_limits<int>::max()) {
                ans = max(ans, G[i][j]); // Find the maximum distance
            }
        }
    }
    return ans + 1; // Return the result
}

// Main function to execute the program
int main() {
    int N = NextInt();
    vector<string> S(N);
    for (int i = 0; i < N; i++) {
        cin >> S[i];
    }
    if (!Bipartite(S)) {
        Write(-1); // If not bipartite, write -1
    } else {
        Write(WarshallFloyd(S)); // Otherwise, compute and write the result
    }
    return 0; // End of program
}

// <END-OF-CODE>
