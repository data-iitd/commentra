#include <bits/stdc++.h>
using namespace std;

// Read input from standard input
auto input = [](int n) {
    int x;
    cin >> x;
    return x;
};

// Read the number of nodes in the tree
int N = input(0);

// Initialize adjacency list for the tree
vector<int> adj[N + 1];

// Read edges and build the adjacency list
for (int i = 0; i < N - 1; i++) {
    int a, b;
    cin >> a >> b;
    adj[a].push_back(b);
    adj[b].push_back(a);
}

// Initialize a queue for BFS and mark the starting node
queue<int> que;
que.push(1);

// Array to keep track of visited nodes
int seen[N + 1];
seen[1] = 1;  // Mark the root node as seen

// Array to store parent of each node
int par[N + 1];

// Array to count the number of children for each node
int child_num[N + 1];

// Perform BFS to populate parent and child count information
while (!que.empty()) {
    int v = que.front();  // Get the current node
    que.pop();
    for (int u : adj[v]) {  // Iterate through adjacent nodes
        if (!seen[u]) {  // If the node has not been visited
            seen[u] = 1;  // Mark it as seen
            par[u] = v;  // Set the parent of the node
            child_num[v]++;  // Increment the child count for the parent
            que.push(u);  // Add the node to the queue for further exploration
}
}

// Initialize a deque to process leaf nodes
deque<int> seq;

// Identify all leaf nodes (nodes with no children)
for (int i = 1; i <= N; i++) {
    if (!child_num[i]) {
        seq.push_back(i);
}

// Process the leaf nodes in reverse order
while (!seq.empty()) {
    int c = seq.back();  // Get the current leaf node
    seen[c] = 0;  // Mark the leaf node as unseen
    if (!seen[par[c]]) {  // Check if the parent is unseen
        cout << "First" << endl;  // If so, print 'First' and exit
        return 0;
}
    seen[par[c]] = 0;  // Mark the parent as unseen
    child_num[par[par[c]]]--;  // Decrement the child count of the grandparent
    if (!child_num[par[par[c]]]) {  // If the grandparent has no children left
        seq.push_back(par[par[c]]);  // Add the grandparent to the sequence for processing
}
}

// If all nodes are processed without triggering 'First', print 'Second'
cout << "Second" << endl;

