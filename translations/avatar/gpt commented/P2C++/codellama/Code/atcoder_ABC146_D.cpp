#include <iostream>
#include <deque>
#include <cstring>
#include <algorithm>

using namespace std;

// Use fast input method
#define input(x) scanf("%d", &x)

// Define a structure to store the graph
struct Graph {
    int N;  // Number of nodes
    deque<int> *G;  // Adjacency list
    int *E;  // Edge colors
};

// Define a structure to store the BFS queue
struct Queue {
    int front, rear;  // Front and rear pointers
    int *Q;  // Queue array
};

// Initialize a queue
void initQueue(Queue &Q, int N) {
    Q.front = Q.rear = 0;
    Q.Q = new int[N];
}

// Enqueue a node
void enqueue(Queue &Q, int node) {
    Q.Q[Q.rear++] = node;
}

// Dequeue a node
int dequeue(Queue &Q) {
    return Q.Q[Q.front++];
}

// Check if the queue is empty
bool isEmpty(Queue &Q) {
    return Q.front == Q.rear;
}

// Perform BFS starting from a given vertex
int bfs(int v, Graph &G, Queue &Q) {
    // Initialize visited list to keep track of visited nodes
    bool *visited = new bool[G.N];
    memset(visited, false, sizeof(bool) * G.N);
    
    // Initialize a list to store the color assigned to each node
    int *node2color = new int[G.N];
    memset(node2color, -1, sizeof(int) * G.N);
    
    // Initialize a dictionary to store edge colors
    int *E = new int[G.N * G.N];
    memset(E, 0, sizeof(int) * G.N * G.N);
    
    // Initialize a variable to track the maximum color used
    int K = -1;
    
    // Start BFS from the given vertex 'v'
    enqueue(Q, v);
    visited[v] = true;
    
    while (!isEmpty(Q)) {
        // Dequeue the front node
        int q = dequeue(Q);
        int color = 0;  // Initialize color counter for the current node
        
        // Explore all adjacent nodes
        for (int nex : G.G[q]) {
            if (visited[nex]) {
                continue;  // Skip if the node has already been visited
            }
            
            visited[nex] = true;  // Mark the adjacent node as visited
            color += 1;  // Increment the color counter
            
            // Ensure the color assigned to the next node is different from the current node's color
            if (color == node2color[q]) {
                color += 1;
            }
            
            // Assign the color to the adjacent node
            node2color[nex] = color;
            
            // Store the color used for the edge between the current node and the adjacent node
            E[(min(q, nex) * G.N) + max(q, nex)] = color;
            
            // Enqueue the adjacent node for further exploration
            enqueue(Q, nex);
        }
        
        // Update the maximum color used
        K = max(K, color);
    }
    
    // Free memory
    delete[] visited;
    delete[] node2color;
    delete[] E;
    
    return K;  // Return the maximum color used
}

// Main function
int main() {
    // Read the number of nodes
    int N;
    input(N);
    
    // Initialize the graph as a list of deques
    Graph G;
    G.N = N;
    G.G = new deque<int>[N];
    G.E = new int[N * N];
    
    // Read edges and build the graph
    for (int i = 0; i < N - 1; i++) {
        int a, b;
        input(a);
        input(b);
        G.G[a - 1].push_back(b - 1);  // Add edge from a to b
        G.G[b - 1].push_back(a - 1);  // Add edge from b to a
        G.E[(a - 1) * N + b - 1] = 0;  // Initialize edge color to 0
    }
    
    // Perform BFS starting from node 0
    Queue Q;
    initQueue(Q, N);
    int K = bfs(0, G, Q);
    
    // Print the maximum color used
    cout << K << endl;
    // Print the colors assigned to each edge
    for (int i = 0; i < N * N; i++) {
        cout << G.E[i] << " ";
    }
    cout << endl;
    
    // Free memory
    delete[] G.G;
    delete[] G.E;
    
    return 0;
}

