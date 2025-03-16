#include <iostream>
#include <vector>
#include <deque>
#include <map>
#include <algorithm>

using namespace std;

// Function to perform Breadth-First Search (BFS) to color the graph
int bfs(int v, int N, vector<deque<int>>& G, map<pair<int, int>, int>& E) {
    // Initialize visited vector to keep track of visited nodes
    vector<int> visited(N, 0);
    // Initialize a queue for BFS using deque
    deque<int> queue;
    // Initialize the maximum color index K
    int K = -1;
    // Vector to store the color of each node, initialized to -1 (no color)
    vector<int> node2color(N, -1);
    // Start BFS from vertex v
    queue.push_back(v);
    visited[v] = 1;

    while (!queue.empty()) {
        // Dequeue the front node
        int q = queue.front();
        queue.pop_front();
        // Initialize color for the current node
        int color = 0;

        // Iterate over all adjacent nodes
        for (int nex : G[q]) {
            if (visited[nex]) {
                continue;
            }
            visited[nex] = 1;
            color++;
            // Ensure the color is different from the parent node's color
            if (color == node2color[q]) {
                color++;
            }
            // Assign the color to the node and record the edge color
            node2color[nex] = color;
            E[{min(q, nex), max(q, nex)}] = color;
            // Enqueue the adjacent node for further exploration
            queue.push_back(nex);
        }
        // Update the maximum color used
        K = max(K, color);
    }
    return K;
}

// Main function to read input, construct the graph, and execute the BFS
int main() {
    // Read the number of nodes N
    int N;
    cin >> N;
    // Initialize a list of deque objects to represent the graph
    vector<deque<int>> G(N);
    // Initialize an empty dictionary to store edge colors
    map<pair<int, int>, int> E;

    // Read edges to populate the graph and edge dictionary
    for (int i = 0; i < N - 1; i++) {
        int a, b;
        cin >> a >> b;
        a--; // Convert to 0-based index
        b--; // Convert to 0-based index
        G[a].push_back(b);
        G[b].push_back(a);
        E[{min(a, b), max(a, b)}] = 0;
    }

    // Perform BFS to determine the maximum color and edge colors
    int K = bfs(0, N, G, E);
    // Print the maximum color used
    cout << K << endl;
    // Print the colors of all edges
    for (const auto& value : E) {
        cout << value.second << endl;
    }

    return 0;
}

// <END-OF-CODE>
