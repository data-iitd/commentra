#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

#define N 100000
#define INF INT_MAX

struct Edge {
    int go, back, cost;
};

int n, d[N];
vector<Edge> a[500000]; // Array to store the adjacency list and cost for each edge

void root(int b); // Function to perform Dijkstra's algorithm

int main()
{
    int i, j, k, u; // Variables for input and iteration
    int count = 0; // Variable to keep track of the number of edges

    cin >> n; // Read the number of vertices

    for (i = 0; i < n; i++) // Iterate through each vertex
    {
        cin >> u >> k; // Read the number of edges and their destinations

        for (j = 0; j < k; j++) // Iterate through each edge
        {
            Edge e;
            e.back = u; // Set the back pointer to the current vertex
            cin >> e.go >> e.cost; // Read the destination vertex and the cost
            a[u].push_back(e); // Add the edge to the adjacency list
            count++; // Increment the edge counter
        }
    }

    root(count); // Call the Dijkstra's algorithm function

    for (i = 0; i < n; i++) // Print the shortest distance from the source to each vertex
        cout << i << " " << (d[i] == INF ? -1 : d[i]) << endl;

    return 0;
}

void root(int b)
{
    int i, flag = 1; // Variables for iteration and algorithm termination flag

    for (i = 0; i < n; i++) // Initialize the shortest distance array with infinite values
        d[i] = INF;

    d[0] = 0; // Set the shortest distance to the source vertex to 0

    while (flag != 0) // While there are still vertices with updated shortest distances
    {
        flag = 0; // Assume no vertices have updated shortest distances

        for (i = 0; i < b; i++) // Iterate through all the edges
        {
            Edge e = a[i].back();
            if (e.cost + d[e.back] < d[e.go]) // If the cost of the edge plus the shortest distance to the previous vertex is less than the current shortest distance
            {
                d[e.go] = e.cost + d[e.back]; // Update the shortest distance to the current vertex
                flag = 1; // Set the flag to indicate that there are still vertices with updated shortest distances
            }
        }
    }
}

