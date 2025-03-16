#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> e;
int n, m;

// Function to print the edges of the graph in a readable format
void printEdge(const vector<vector<int>>& e) {
    for (int i = 1; i <= n; i++) {
        cout << i << ": ";
        for (int v : e[i]) {
            cout << v << " ";
        }
        cout << endl;
    }
}

// Depth-First Search (DFS) function to count connected components in the graph
int dfs(int v, vector<bool>& visited) {
    // Mark the current node as visited
    // cout << v << " " << visited[v] << endl;

    // Check if all nodes are visited
    bool comp = true;
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            comp = false;
        }
    }

    if (comp) {
        return 1;
    }

    int count = 0;
    for (int ne : e[v]) {
        if (visited[ne]) {
            continue;
        }
        visited[ne] = true;
        int rst = dfs(ne, visited);
        count += rst;
        visited[ne] = false;
    }
    return count;
}

// Main function to read input, initialize the graph, and perform DFS
int main() {
    cin >> n >> m;

    // Initialize the graph edges
    e.resize(n + 1);
    for (int i = 1; i <= n; i++) {
        e[i] = vector<int>();
    }

    // Read the edges and populate the graph
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        e[a].push_back(b);
        e[b].push_back(a);
    }
    // printEdge(e);

    // Initialize visited vector and start DFS from node 1
    vector<bool> visited(n + 1, false);
    visited[1] = true;
    int count = dfs(1, visited);
    cout << count << endl;

    return 0;
}

// <END-OF-CODE>
