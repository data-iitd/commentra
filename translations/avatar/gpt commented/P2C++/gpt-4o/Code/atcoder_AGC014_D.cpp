#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    // Read the number of nodes in the tree
    int N;
    cin >> N;

    // Initialize adjacency list for the tree
    vector<vector<int>> adj(N + 1);

    // Read edges and build the adjacency list
    for (int i = 0; i < N - 1; ++i) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    // Initialize a queue for BFS and mark the starting node
    queue<int> que;
    que.push(1);

    // Array to keep track of visited nodes
    vector<int> seen(N + 1, 0);
    seen[1] = 1;  // Mark the root node as seen

    // Array to store parent of each node
    vector<int> par(N + 1, 0);

    // Array to count the number of children for each node
    vector<int> child_num(N + 1, 0);

    // Perform BFS to populate parent and child count information
    while (!que.empty()) {
        int v = que.front();  // Get the current node
        que.pop();
        for (int u : adj[v]) {  // Iterate through adjacent nodes
            if (seen[u] == 0) {  // If the node has not been visited
                seen[u] = 1;  // Mark it as seen
                par[u] = v;  // Set the parent of the node
                child_num[v]++;  // Increment the child count for the parent
                que.push(u);  // Add the node to the queue for further exploration
            }
        }
    }

    // Initialize a queue to process leaf nodes
    deque<int> seq;

    // Identify all leaf nodes (nodes with no children)
    for (int i = 1; i <= N; ++i) {
        if (child_num[i] == 0) {
            seq.push_back(i);
        }
    }

    // Process the leaf nodes in reverse order
    while (!seq.empty()) {
        int c = seq.back();  // Get the current leaf node
        seq.pop_back();  // Remove it from the deque
        seen[c] = 0;  // Mark the leaf node as unseen
        if (seen[par[c]] == 0) {  // Check if the parent is unseen
            cout << "First" << endl;  // If so, print 'First' and exit
            return 0;
        }
        seen[par[c]] = 0;  // Mark the parent as unseen
        child_num[par[par[c]]]--;  // Decrement the child count of the grandparent
        if (child_num[par[par[c]]] == 0) {  // If the grandparent has no children left
            seq.push_back(par[par[c]]);  // Add the grandparent to the sequence for processing
        }
    }

    // If all nodes are processed without triggering 'First', print 'Second'
    cout << "Second" << endl;

    return 0;
}

// <END-OF-CODE>
