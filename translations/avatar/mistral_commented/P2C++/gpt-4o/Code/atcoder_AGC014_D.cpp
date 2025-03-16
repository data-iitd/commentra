#include <iostream>
#include <vector>
#include <deque>

using namespace std;

// Function to read input
#define input cin

int main() {
    // Define number of vertices in the graph
    int N;
    input >> N;

    // Initialize adjacency list with empty vectors for each vertex
    vector<vector<int>> adj(N + 1);

    // Read edges and add them to the adjacency list
    for (int i = 0; i < N - 1; ++i) {
        int a, b;
        input >> a >> b;
        // Add edge between vertices a and b in both directions
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    // Initialize empty deque for BFS traversal
    deque<int> que;

    // Mark starting vertex as visited and add it to the queue
    que.push_back(1);

    // Initialize vectors to store parent, seen, and child count for each vertex
    vector<int> seen(N + 1, 0);
    vector<int> par(N + 1, 0);
    vector<int> child_num(N + 1, 0);

    // BFS traversal starting from the starting vertex
    while (!que.empty()) {
        int v = que.front();
        que.pop_front();
        // Iterate through neighbors of the current vertex
        for (int u : adj[v]) {
            // If neighbor is not yet visited, mark it as visited, update parent and child count
            if (seen[u] == 0) {
                seen[u] = 1;
                par[u] = v;
                child_num[v]++;
                que.push_back(u);
            }
        }
    }

    // Initialize empty deque for storing vertices in topological order
    deque<int> seq;

    // Find vertices with no incoming edges and add them to the sequence
    for (int i = 1; i <= N; ++i) {
        if (child_num[i] == 0) {
            seq.push_back(i);
        }
    }

    // Topological sort using the sequence of vertices with no incoming edges
    while (!seq.empty()) {
        int c = seq.back();
        seq.pop_back();
        // If parent of the current vertex is not yet processed, print "First" and exit
        if (seen[par[c]] == 0) {
            cout << "First" << endl;
            return 0;
        }
        // Mark parent as not visited and update child count of its parent
        seen[par[c]] = 0;
        child_num[par[par[c]]]--;
        // If the parent of the parent has no children, add it to the sequence
        if (child_num[par[par[c]]] == 0) {
            seq.push_back(par[par[c]]);
        }
    }

    // Print "Second" if all vertices have been processed
    cout << "Second" << endl;

    return 0;
}

// <END-OF-CODE>
