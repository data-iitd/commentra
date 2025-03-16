// 深さ優先探索
#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

// genid generates a unique identifier for an edge between two nodes.
int genid(int a, int b) {
    if (b < a) {
        swap(a, b);
    }
    return a * 100000 + b;
}

int main() {
    // Read the number of nodes from standard input.
    int N;
    cin >> N;

    // Initialize a vector to store edges and an adjacency list for the graph.
    vector<pair<int, int>> ab(N - 1);
    vector<vector<int>> edges(N);
    for (int i = 0; i < N - 1; i++) {
        // Read edge information and populate the adjacency list.
        int a, b;
        cin >> a >> b;
        a--; b--; // Convert to 0-based index
        ab[i] = {a, b};
        edges[a].push_back(b);
        edges[b].push_back(a);
    }

    // Initialize a map to store the color of each edge and a stack for DFS traversal.
    unordered_map<int, int> colors;
    vector<tuple<int, int, int>> stack;
    stack.emplace_back(0, -1, -1); // (currentNode, usedColor, parentNode)
    
    while (!stack.empty()) {
        auto [currentNode, usedColor, parentNode] = stack.back();
        stack.pop_back();
        int color = 1;
        for (int childNode : edges[currentNode]) {
            if (childNode == parentNode) {
                continue;
            }
            if (color == usedColor) {
                color++;
            }
            colors[genid(currentNode, childNode)] = color;
            stack.emplace_back(childNode, color, currentNode);
            color++;
        }
    }

    // Determine the maximum degree of any node in the graph.
    int K = -1;
    for (int i = 0; i < N; i++) {
        int t = edges[i].size();
        K = max(K, t);
    }
    cout << K << endl;

    // Output the colors of the edges.
    for (int i = 0; i < N - 1; i++) {
        cout << colors[genid(ab[i].first, ab[i].second)] << endl;
    }

    return 0;
}

// <END-OF-CODE>
