#include <iostream>
#include <vector>
#include <queue>
#include <map>
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
    int N;
    cin >> N;

    // Initialize a vector to store edges and an adjacency list for the graph.
    vector<pair<int, int>> ab(N - 1);
    vector<vector<int>> edges(N);
    for (int i = 0; i < N - 1; i++) {
        // Read edge information and populate the adjacency list.
        int a, b;
        cin >> a >> b;
        a--; b--;
        ab[i] = {a, b};
        edges[a].push_back(b);
        edges[b].push_back(a);
    }

    // Initialize a map to store the color of each edge and a queue for DFS traversal.
    map<int, int> colors;
    queue<tuple<int, int, int>> q;
    q.push(make_tuple(0, -1, -1));
    while (!q.empty()) {
        // Pop the last element from the queue for DFS traversal.
        int currentNode, usedColor, parentNode;
        tie(currentNode, usedColor, parentNode) = q.front();
        q.pop();
        int color = 1;
        for (int childNode : edges[currentNode]) {
            if (childNode == parentNode) {
                continue;
            }
            if (color == usedColor) {
                color++;
            }
            colors[genid(currentNode, childNode)] = color;
            q.push(make_tuple(childNode, color, currentNode));
            color++;
        }
    }

    // Determine the maximum degree of any node in the graph.
    int K = -1;
    for (int i = 0; i < N; i++) {
        int t = edges[i].size();
        if (t > K) {
            K = t;
        }
    }
    cout << K << endl;

    // Output the colors of the edges.
    for (int i = 0; i < N - 1; i++) {
        cout << colors[genid(ab[i].first, ab[i].second)] << endl;
    }

    return 0;
}
