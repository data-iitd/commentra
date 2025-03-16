#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdint.h>
#include <limits.h>
#include <math.h>
#include <float.h>
#include <time.h>
#include <deque>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <string>
#include <bitset>
#include <iterator>
using namespace std;

// Function to perform Breadth-First Search (BFS) to color the graph
int bfs(int v, int N, deque<int> G[], map<pair<int, int>, int> &E) {
    // Initialize visited list to keep track of visited nodes
    bool visited[N];
    memset(visited, 0, sizeof(visited));
    // Initialize a queue for BFS using deque
    deque<int> queue;
    // Initialize the maximum color index K
    int K = -1;
    // List to store the color of each node, initialized to -1 (no color)
    int node2color[N];
    memset(node2color, -1, sizeof(node2color));
    // Start BFS from vertex v
    queue.push_back(v);
    visited[v] = true;
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
            visited[nex] = true;
            color += 1;
            // Ensure the color is different from the parent node's color
            if (color == node2color[q]) {
                color += 1;
            }
            // Assign the color to the node and record the edge color
            node2color[nex] = color;
            E[make_pair(min(q, nex), max(q, nex))] = color;
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
    scanf("%d", &N);
    // Initialize a list of deque objects to represent the graph
    deque<int> G[N];
    // Initialize an empty dictionary to store edge colors
    map<pair<int, int>, int> E;
    // Read edges to populate the graph and edge dictionary
    for (int i = 0; i < N - 1; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        G[a - 1].push_back(b - 1);
        G[b - 1].push_back(a - 1);
        E[make_pair(a - 1, b - 1)] = 0;
    }
    // Perform BFS to determine the maximum color and edge colors
    int K = bfs(0, N, G, E);
    // Print the maximum color used
    printf("%d\n", K);
    // Print the colors of all edges
    for (auto &value : E) {
        printf("%d\n", value.second);
    }
    return 0;
}

