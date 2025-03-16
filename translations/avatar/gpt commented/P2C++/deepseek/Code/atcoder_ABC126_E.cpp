#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

// Function to read input from standard input
string input() {
    string line;
    getline(cin, line);
    return line;
}

void main() {
    // Read the number of nodes (N) and edges (M)
    int N, M;
    cin >> N >> M;
    cin.ignore();  // To ignore the newline character after reading N and M
    
    // Initialize an adjacency list to represent the graph
    vector<vector<int>> edge(N);
    
    // Read each edge and populate the adjacency list
    for (int i = 0; i < M; ++i) {
        int X, Y, Z;
        cin >> X >> Y >> Z;
        --X; --Y;  // Convert to 0-based index
        edge[X].push_back(Y);
        edge[Y].push_back(X);
    }
    
    // Array to track visited nodes
    vector<bool> used(N, false);
    
    // Variable to count the number of connected components
    int ans = 0;
    
    // Iterate through each node to find connected components
    for (int i = 0; i < N; ++i) {
        if (!used[i]) {  // If the node has not been visited
            ++ans;  // Increment the count of connected components
            queue<int> queue;  // Initialize a queue for BFS
            queue.push(i);  // Start BFS from the current node
            
            // Perform BFS to mark all reachable nodes from the current node
            while (!queue.empty()) {
                int node = queue.front();  // Dequeue a node
                queue.pop();  // Dequeue a node
                used[node] = true;  // Mark the node as visited
                
                // Explore all adjacent nodes
                for (int nextnode : edge[node]) {
                    if (!used[nextnode]) {  // If the adjacent node has not been visited
                        queue.push(nextnode);  // Enqueue the adjacent node
                    }
                }
            }
        }
    }
    
    // Output the number of connected components found
    cout << ans << endl;
}
