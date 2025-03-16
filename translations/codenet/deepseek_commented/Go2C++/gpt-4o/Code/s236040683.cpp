#include <iostream>
#include <vector>

using namespace std;

void out(int x) {
    cout << x << endl;
}

int main() {
    int N, M;
    cin >> N >> M;

    // Initialize a vector of vectors to represent the adjacency list
    vector<vector<int>> adj(N);

    // Read M pairs of edges and populate the adjacency list for each node
    for (int i = 0; i < M; i++) {
        int from, to;
        cin >> from >> to;
        adj[from - 1].push_back(to - 1);
        adj[to - 1].push_back(from - 1);
    }

    // Print the size of the adjacency list for each node
    for (int i = 0; i < N; i++) {
        out(adj[i].size());
    }

    return 0;
}

// <END-OF-CODE>
