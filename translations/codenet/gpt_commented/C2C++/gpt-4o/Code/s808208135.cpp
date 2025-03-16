#include <iostream>
#include <vector>
#include <limits>

#define N 100000  // Define a constant for the maximum number of nodes
#define INF 1000000  // Define a constant for representing infinity

// Structure to represent a directed edge with a cost
struct Date {
    int go;    // Destination node
    int back;  // Source node
    int cost;  // Cost of the edge
};

int n;  // Number of nodes
std::vector<int> d(N);  // Array to store the shortest distances
std::vector<Date> a;  // Vector to store edges

void root(int);  // Function prototype for the root function

int main() {
    int u, k;  // Variables for current node and number of edges
    std::cin >> n;  // Read the number of nodes

    // Read edges for each node
    a.reserve(500000);  // Reserve space for edges
    for (int i = 0; i < n; i++) {
        std::cin >> u >> k;  // Read the current node and number of edges
        for (int j = 0; j < k; j++) {
            Date edge;  // Create a new edge
            edge.back = u;  // Set the source node for the edge
            std::cin >> edge.go >> edge.cost;  // Read destination and cost
            a.push_back(edge);  // Add the edge to the vector
        }
    }

    // Call the root function to compute shortest paths
    root(a.size());

    // Print the shortest distances from the source node to each node
    for (int i = 0; i < n; i++)
        std::cout << i << " " << d[i] << std::endl;  // Output the node index and its distance

    return 0;  // Exit the program
}

// Function to compute shortest paths using the Bellman-Ford algorithm
void root(int b) {
    int flag = 1;  // Flag to indicate changes

    // Initialize distances to all nodes as infinity
    std::fill(d.begin(), d.begin() + n, INF);
    d[0] = 0;  // Set the distance to the source node (node 0) as 0

    // Repeat the process until no changes occur
    while (flag != 0) {
        flag = 0;  // Reset flag for this iteration
        // Relax all edges
        for (int i = 0; i < b; i++) {
            // Check if the current edge can provide a shorter path
            if (a[i].cost + d[a[i].back] < d[a[i].go]) {
                d[a[i].go] = a[i].cost + d[a[i].back];  // Update the shortest distance
                flag = 1;  // Set flag to indicate a change occurred
            }
        }
    }
}

// <END-OF-CODE>
