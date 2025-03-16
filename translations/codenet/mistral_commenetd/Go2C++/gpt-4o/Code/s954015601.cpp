// 深さ優先探索
#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <utility>

using namespace std;

// Function to generate unique id based on two integers
int genid(int a, int b) {
    if (b < a) {
        swap(a, b);
    }
    // Multiply the larger number by 100000 and add the smaller number
    return a * 100000 + b;
}

// Main function
int main() {
    // Read the number of edges in the graph
    int N;
    cin >> N;

    // Initialize an adjacency list and a vector to store the edges between nodes
    vector<pair<int, int>> ab(N - 1);
    vector<vector<int>> edges(N);
    for (int i = 0; i < N - 1; i++) {
        // Read two integers representing the nodes connected by an edge
        int a, b;
        cin >> a >> b;
        a--; // Convert to 0-based index
        b--; // Convert to 0-based index
        // Store the nodes in the ab vector
        ab[i] = make_pair(a, b);
        // Add the edge to the adjacency list
        edges[a].push_back(b);
        edges[b].push_back(a);
    }

    // Initialize a map to store the colors of each connected component
    unordered_map<int, int> colors;
    // Initialize a queue to perform DFS
    queue<tuple<int, int, int>> q;
    // Add the first node to the queue with initial color and parent node set to -1
    q.push(make_tuple(0, -1, -1));
    while (!q.empty()) {
        // Dequeue the current node, its color, and its parent node
        auto [currentNode, usedColor, parentNode] = q.front();
        q.pop();
        // Set the color of the current node to the next available color
        int color = 1;
        for (int childNode : edges[currentNode]) {
            if (childNode == parentNode) {
                continue;
            }
            // If the color of the current node is the same as the color of the child node, increment the color
            if (color == usedColor) {
                color++;
            }
            // Assign the color to the child node and add it to the queue with the current node as its parent node
            colors[genid(currentNode, childNode)] = color;
            q.push(make_tuple(childNode, color, currentNode));
            // Increment the color for the next iteration
            color++;
        }
    }

    // Initialize a variable to store the maximum number of edges in a connected component
    int K = -1;
    // Iterate through all nodes in the graph and update the maximum number of edges if necessary
    for (int i = 0; i < N; i++) {
        int t = edges[i].size();
        if (t > K) {
            K = t;
        }
    }
    // Print the maximum number of edges in a connected component
    cout << K << endl;

    // Iterate through all edges in the graph and print their colors
    for (int i = 0; i < N - 1; i++) {
        cout << colors[genid(ab[i].first, ab[i].second)] << endl;
    }

    return 0;
}

// <END-OF-CODE>
