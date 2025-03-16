
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// Set the recursion limit to a high value to handle deep recursions if needed
const int RECURSION_LIMIT = 100000000;

// Define a constant for infinity
const long long INF = 100000000000000000;

// Function to read input from standard input
string input() {
    string s;
    getline(cin, s);
    return s;
}

int main() {
    // Read the number of nodes (N) and edges (M)
    int N, M;
    cin >> N >> M;
    
    // Initialize an adjacency list to represent the graph
    vector<vector<int>> edge(N);
    
    // Read each edge and populate the adjacency list
    for (int i = 0; i < M; i++) {
        int X, Y, Z;
        cin >> X >> Y >> Z;
        X--;
        Y--;
        edge[X].push_back(Y);
        edge[Y].push_back(X);
    }
    
    // Array to track visited nodes
    vector<bool> used(N, false);
    
    // Variable to count the number of connected components
    int ans = 0;
    
    // Iterate through each node to find connected components
    for (int i = 0; i < N; i++) {
        if (!used[i]) {  // If the node has not been visited
            ans++;  // Increment the count of connected components
            queue<int> queue;  // Initialize a queue for BFS
            queue.push(i);  // Start BFS from the current node
            
            // Perform BFS to mark all reachable nodes from the current node
            while (!queue.empty()) {
                int node = queue.front();
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
    
    return 0;
}

// Entry point of the program
int main() {
    // Set the recursion limit to a high value to handle deep recursions if needed
    setrecursionlimit(RECURSION_LIMIT);
    
    // Read the input and call the main function
    string input = input();
    main();
    
    return 0;
}

