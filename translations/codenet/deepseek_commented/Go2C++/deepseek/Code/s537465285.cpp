#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>

using namespace std;

// Function to read a line of input
string NextLine() {
    string line;
    getline(cin, line);
    return line;
}

// Function to read an integer from input
int NextInt() {
    int n;
    cin >> n;
    cin.ignore(); // To ignore the newline character after reading the integer
    return n;
}

// Function to print a line to the output
void Write(int s) {
    cout << s << endl;
}

// Bipartite check function
bool Bipartite(vector<string>& S) {
    int N = S.size();
    vector<int> D(N, 0); // Distance array
    D[0] = 1; // Start from the first vertex
    queue<int> Q;
    Q.push(0);
    while (!Q.empty()) {
        int q = Q.front();
        Q.pop();
        for (int j = 0; j < N; ++j) {
            if (S[q][j] == '0') continue;
            if (D[j] == 0) {
                D[j] = D[q] + 1;
                Q.push(j);
            } else if (D[j] % 2 == D[q] % 2) {
                return false;
            }
        }
    }
    return true;
}

// Warshall-Floyd algorithm to find the shortest paths
int WarshallFloyd(vector<string>& S) {
    int N = S.size();
    vector<vector<int>> G(N, vector<int>(N, 0));
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (i == j) continue;
            if (S[i][j] == '0') {
                G[i][j] = N; // Set distance to a large number
            } else {
                G[i][j] = 1; // Direct edge weight
            }
        }
    }
    for (int k = 0; k < N; ++k) {
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                if (G[i][k] + G[k][j] < G[i][j]) {
                    G[i][j] = G[i][k] + G[k][j]; // Update shortest path
                }
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (ans < G[i][j]) ans = G[i][j]; // Find the maximum distance
        }
    }
    return ans + 1; // Return the result
}

// Main function to execute the program
int main() {
    int N = NextInt();
    vector<string> S(N);
    for (int i = 0; i < N; ++i) {
        S[i] = NextLine();
    }
    if (!Bipartite(S)) {
        Write(-1); // If not bipartite, write -1
    } else {
        Write(WarshallFloyd(S)); // Otherwise, compute and write the result
    }
    return 0;
}
