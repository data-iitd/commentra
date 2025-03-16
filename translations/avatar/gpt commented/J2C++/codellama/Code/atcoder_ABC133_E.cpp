#include <iostream> 
#include <vector> 
#include <list> 
#include <cmath> 

using namespace std; 

// Inner class to represent a node in the tree
class Node { 
    public: 
        long pattern = 0; // Variable to store the pattern value
        int index; // Index of the node
        list<int> children; // List of child nodes
        int parent = -1; // Parent index, -1 indicates no parent

        // Constructor to initialize the node with its index
        Node(int i) { 
            this->index = i; 
        } 

        // Method to set the parent of the node and calculate the pattern
        void setParent(int K, int parent, int use, vector<Node> &nodes) { 
            this->pattern = K - use; // Calculate the pattern based on K and used count
            this->parent = parent; // Set the parent index
            int count = 1; // Initialize count of used nodes

            // If the node has a parent, increment the count
            if (parent != -1) { 
                count++; 
            } 
            
            // Recursively set the parent for each child node
            for (int n : children) { 
                if (n == this->parent) { // Skip the parent node
                    continue; 
                } 
                nodes[n].setParent(K, index, count, nodes); // Recursive call for child
                count++; // Increment count for each child processed
            } 
        } 
}; 

// Main logic to solve the problem
void solve() { 
    int N, K; // Number of nodes and value of K
    cin >> N >> K; // Read the number of nodes and value of K
    vector<Node> nodes(N); // Array to hold all nodes

    // Initialize nodes
    for (int i = 0; i < N; i++) { 
        nodes[i] = Node(i); // Create a new node for each index
    } 

    // Read edges and build the tree structure
    for (int i = 0; i < N - 1; i++) { 
        int a, b; // Read first and second node of the edge
        cin >> a >> b; 
        a--; b--; // Adjust for 0-based indexing
        nodes[a].children.push_back(b); // Add b as a child of a
        nodes[b].children.push_back(a); // Add a as a child of b (undirected tree)
    } 

    // Set the parent for the root node (node 0)
    nodes[0].setParent(K, -1, 0, nodes); 

    long patterns = 1; // Variable to store the product of patterns

    // Calculate the product of all node patterns
    for (int i = 0; i < N; i++) { 
        patterns = (patterns * nodes[i].pattern) % 1000000007; // Update patterns with modulo
    } 

    // Output the final result
    cout << patterns << endl; 
} 

// Main method to execute the program
int main() { 
    solve(); // Call the solve method to execute the logic
    return 0; 
} 

