
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

// Array to store colors assigned to each point
int colors[100000];

// Function to perform Depth-First Search (DFS) and assign colors based on friendship lengths
void dfs(int node, int length, vector<vector<pair<int, int>>> &graph) {
    // Check if the node has already been colored
    if (colors[node]!= -1) return; // Exit if already colored

    // Assign color based on the length (even or odd)
    if (length % 2 == 0) {
        colors[node] = 0; // Even length -> color 0
    } else {
        colors[node] = 1; // Odd length -> color 1
    }

    // Recursively visit all friends of the current node
    for (auto &friendship : graph[node]) {
        int friendNode = friendship.first; // Get the friend node
        int friendLength = friendship.second; // Get the length of friendship
        dfs(friendNode, length + friendLength, graph); // Recursive DFS call
    }
}

int main() {
    // Create a scanner to read input
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;

    // Calculate the number of edges (m = n - 1 for a tree)
    int m = n - 1;

    // Initialize colors array with -1 (indicating uncolored)
    fill(colors, colors + n, -1);

    // Create a vector of vectors to store the graph
    vector<vector<pair<int, int>>> graph(n);

    // Read edges and establish friendships between points
    while (m-- > 0) {
        int me, you, length;
        cin >> me >> you >> length;
        me--;
        you--;
        // Establish friendship in both directions
        graph[me].push_back({you, length});
        graph[you].push_back({me, length});
    }

    // Start DFS from the first point (index 0)
    dfs(0, 0, graph);

    // Output the colors assigned to each point
    for (int i = 0; i < n; i++) {
        cout << colors[i] << endl;
    }

    return 0;
}

