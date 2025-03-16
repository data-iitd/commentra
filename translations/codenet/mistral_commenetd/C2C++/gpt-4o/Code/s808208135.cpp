#include <iostream>
#include <vector>
#include <limits>

#define N 100000
#define INF 1000000

struct Date {
    int go, back, cost;
};

int n;
int d[N];
std::vector<Date> a; // Vector to store the adjacency list and cost for each edge

void root(int b); // Function to perform Dijkstra's algorithm

int main() {
    int i, j, k, u; // Variables for input and iteration
    int count = 0; // Variable to keep track of the number of edges

    std::cin >> n; // Read the number of vertices

    a.reserve(500000); // Reserve space for edges

    for (i = 0; i < n; i++) { // Iterate through each vertex
        std::cin >> u >> k; // Read the number of edges and their destinations

        for (j = 0; j < k; j++) { // Iterate through each edge
            Date edge;
            edge.back = u; // Set the back pointer to the current vertex
            std::cin >> edge.go >> edge.cost; // Read the destination vertex and the cost
            a.push_back(edge); // Add the edge to the vector
            count++; // Increment the edge counter
        }
    }

    root(count); // Call the Dijkstra's algorithm function

    for (i = 0; i < n; i++) // Print the shortest distance from the source to each vertex
        std::cout << i << " " << d[i] << std::endl;

    return 0;
}

void root(int b) {
    int i, flag = 1; // Variables for iteration and algorithm termination flag

    for (i = 0; i < n; i++) // Initialize the shortest distance array with infinite values
        d[i] = INF;

    d[0] = 0; // Set the shortest distance to the source vertex to 0

    while (flag != 0) { // While there are still vertices with updated shortest distances
        flag = 0; // Assume no vertices have updated shortest distances

        for (i = 0; i < b; i++) { // Iterate through all the edges
            if (a[i].cost + d[a[i].back] < d[a[i].go]) { // If the cost of the edge plus the shortest distance to the previous vertex is less than the current shortest distance
                d[a[i].go] = a[i].cost + d[a[i].back]; // Update the shortest distance to the current vertex
                flag = 1; // Set the flag to indicate that there are still vertices with updated shortest distances
            }
        }
    }
}

// <END-OF-CODE>
