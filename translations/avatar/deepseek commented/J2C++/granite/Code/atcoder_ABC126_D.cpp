
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int colors[100000]; // Step 2: Declare an array to store the color of each node

void dfs(vector<pair<int, int>> *graph, int node, int length) {
    bool alreadyKnown = colors[node]!= -1; // Check if the color of the current node is already known
    if (alreadyKnown) return; // If the color is already known, return

    if (length % 2 == 0) { // Check if the length of the path is even
        colors[node] = 0; // Color the current node as 0
    } else {
        colors[node] = 1; // Color the current node as 1
    }

    for (pair<int, int> edge : graph[node]) { // Iterate through the edges of the current node
        int friend = edge.first; // Get the friend node
        int length2 = edge.second; // Get the length of the edge to the friend
        dfs(graph, friend, length + length2); // Recursively call DFS for the friend
    }
}

int main() {
    int n, m;
    cin >> n >> m; // Read the number of nodes and edges

    vector<pair<int, int>> *graph = new vector<pair<int, int>>[n]; // Step 3: Create a vector of vectors to store the graph
    for (int i = 0; i < n; i++) {
        graph[i] = vector<pair<int, int>>(); // Initialize each vector of vectors
    }

    for (int i = 0; i < m; i++) { // Step 4: Read the edges and their lengths
        int me, you, length;
        cin >> me >> you >> length; // Read the first node, second node, and length of the edge
        graph[me - 1].push_back(make_pair(you - 1, length)); // Add the edge to the graph
        graph[you - 1].push_back(make_pair(me - 1, length)); // Add the edge to the graph
    }

    fill(colors, colors + n, -1); // Step 2: Set all colors to -1 initially

    dfs(graph, 0, 0); // Step 5: Perform a DFS starting from the first node

    for (int i = 0; i < n; i++) { // Step 6: Output the color of each node
        cout << colors[i] << endl;
    }

    return 0;
}

