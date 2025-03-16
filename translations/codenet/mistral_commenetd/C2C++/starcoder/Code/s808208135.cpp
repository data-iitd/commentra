#include <bits/stdc++.h>

using namespace std;

#define N 100000
#define INF 1000000

typedef struct
{
    int go, back, cost;
} Date;

int n, d[N];
Date a[500000]; // Array to store the adjacency list and cost for each edge

void root(int b); // Function to perform Dijkstra's algorithm

int main()
{
    int i, j, k, u; // Variables for input and iteration
    int count = 0; // Variable to keep track of the number of edges

    scanf("%d", &n); // Read the number of vertices

    for (i = 0; i < n; i++) // Iterate through each vertex
    {
        scanf("%d%d", &u, &k); // Read the number of edges and their destinations

        for (j = 0; j < k; j++) // Iterate through each edge
        {
            a[count].back = u; // Set the back pointer to the current vertex
            scanf("%d%d", &a[count].go, &a[count].cost); // Read the destination vertex and the cost
            count++; // Increment the edge counter
        }
    }

    root(count); // Call the Dijkstra's algorithm function

    for (i = 0; i < n; i++) // Print the shortest distance from the source to each vertex
        printf("%d %d\n", i, d[i]);

    return 0;
}

void root(int b)
{
    int i, flag = 1; // Variables for iteration and algorithm termination flag

    for (i = 0; i < n; i++) // Initialize the shortest distance array with infinite values
        d[i] = INF;

    d[0] = 0; // Set the shortest distance to the source vertex to 0

    while (flag!= 0) // While there are still vertices with updated shortest distances
    {
        flag = 0; // Assume no vertices have updated shortest distances

        for (i = 0; i < b; i++) // Iterate through all the edges
        {
            if (a[i].cost + d[a[i].back] < d[a[i].go]) // If the cost of the edge plus the shortest distance to the previous vertex is less than the current shortest distance
            {
                d[a[i].go] = a[i].cost + d[a[i].back]; // Update the shortest distance to the current vertex
                flag = 1; // Set the flag to indicate that there are still vertices with updated shortest distances
            }
        }
    }
}

