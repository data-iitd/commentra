
#####
# Code
#####

# Include necessary libraries
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

// Function to perform Breadth First Search (BFS)
int bfs(int v, int N, std::vector<std::vector<int>>& G, std::vector<std::pair<int, int>>& E) {
    // Initialize visited array and queue
    std::vector<int> visited(N, 0);
    std::queue<int> queue;

    // Initialize variables for coloring nodes
    int K = -1;
    std::vector<int> node2color(N, -1);

    // Add starting node to the queue and mark it as visited
    queue.push(v);
    visited[v] = 1;

    // BFS algorithm
    while (!queue.empty()) {
        // Dequeue the next node from the queue
        int q = queue.front();
        queue.pop();

        // Initialize color for the current node
        int color = 0;

        // Traverse through all neighbors of the current node
        for (int nex : G[q]) {
            // Skip if the neighbor is already visited
            if (visited[nex]) {
                continue;
            }

            // Mark the neighbor as visited and assign it a color
            visited[nex] = 1;
            color += 1;

            // If the color of the current node is same as its neighbor, assign a new color to the neighbor
            if (color == node2color[q]) {
                color += 1;
            }

            // Update node2color and E vector with the new color
            node2color[nex] = color;
            E.push_back({std::min(q, nex), std::max(q, nex)});

            // Add the neighbor to the queue
            queue.push(nex);
        }

        // Update the maximum color found so far
        K = std::max(K, color);
    }

    // Return the maximum color
    return K;
}

// Main function to read input and call bfs function
int main() {
    // Read number of nodes from the input
    int N;
    std::cin >> N;

    // Initialize graph as a vector of vectors and vector for edges
    std::vector<std::vector<int>> G(N);
    std::vector<std::pair<int, int>> E;

    // Read edges from the input and add them to the graph
    for (int i = 0; i < N - 1; i++) {
        int a, b;
        std::cin >> a >> b;
        a--;
        b--;
        G[a].push_back(b);
        G[b].push_back(a);
        E.push_back({a, b});
    }

    // Call bfs function and print the result
    int K = bfs(0, N, G, E);
    std::cout << K << std::endl;

    // Print colors of all edges
    for (const auto& edge : E) {
        std::cout << node2color[edge.first] << std::endl;
    }

    return 0;
}

