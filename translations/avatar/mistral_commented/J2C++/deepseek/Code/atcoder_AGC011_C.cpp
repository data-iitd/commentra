#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>

using namespace std;

class Main {
public:
    vector<int> graph[100005]; // Declaring a vector array named graph to store the adjacency list of the graph
    bool visited[100005]; // Declaring a boolean array named visited to keep track of the visited nodes
    int color[100005]; // Declaring an integer array named color to store the color of each node in the graph
    long long one = 0; // Declaring a long long variable named one to store the number of nodes in a single connected component
    long long bipartite = 0; // Declaring a long long variable named bipartite to store the number of bipartite connected components
    long long count = 0; // Declaring a long long variable named count to store the total number of nodes in the graph
    bool mujun = false; // Declaring a boolean variable named mujun to check if there is an odd cycle in the graph

    void run() { // Defining the run method to be executed when the thread is started
        int n, m;
        cin >> n >> m; // Reading the number of nodes and edges from the input
        for (int i = 0; i < m; ++i) { // Iterating through each edge in the graph
            int u, v;
            cin >> u >> v; // Reading the source and destination nodes of the edge from the input
            u--; v--; // Decrementing the node indices to make them 0-based
            graph[u].push_back(v); // Adding the destination node to the adjacency list of the source node
            graph[v].push_back(u); // Adding the source node to the adjacency list of the destination node
        }
        memset(visited, false, sizeof(visited)); // Initializing the visited array with false values
        memset(color, -1, sizeof(color)); // Initializing the color array with -1 values
        for (int i = 0; i < n; ++i) { // Iterating through each node in the graph
            if (visited[i]) continue; // Skipping the node if it has already been visited
            count++; // Incrementing the count of nodes in the graph
            mujun = false; // Resetting the mujun flag
            int kind = dfs(i, 0); // Calling the depth-first search algorithm to find the connected component and its bipartiteness
            if (kind == 1) one++; // Incrementing the count of nodes in a single connected component if it is a single connected component
            else if (!mujun) bipartite++; // Incrementing the count of bipartite connected components if the current component is bipartite and not an odd cycle
        }
        long long total = one * (2 * n - one) + (count - one) * (count - one) + bipartite * bipartite; // Calculating the total number of edges in the graph
        cout << total << endl; // Printing the total number of edges in the graph
    }

    int dfs(int a, int c) { // Defining the depth-first search algorithm to find the connected component and its bipartiteness
        if (visited[a]) { // Checking if the current node has already been visited
            if (color[a] >= 0 && color[a] != c) mujun = true; // Setting the mujun flag if there is an odd cycle in the graph
            return 0; // Returning 0 if the current node is already visited
        }
        visited[a] = true; // Marking the current node as visited
        color[a] = c; // Setting the color of the current node
        int total = 1; // Initializing the total number of nodes in the connected component to 1
        for (int b : graph[a]) { // Iterating through each neighbor of the current node
            total += dfs(b, 1 - c); // Recursively calling the depth-first search algorithm on the neighbor and adding the total number of nodes in its connected component
        }
        return total; // Returning the total number of nodes in the connected component
    }
};

int main() {
    Main obj;
    obj.run(); // Calling the run method to start the program
    return 0;
}

