#include <stdio.h>
#include <stdlib.h>

#define N 100000
#define INF 1000000

type Date struct {
    go, back, cost int
}

var n int
var d [N]int
var a [500000]Date // Array to store the adjacency list and cost for each edge

func root(b int) {
    var i, flag int = 0, 1 // Variables for iteration and algorithm termination flag

    for i = 0; i < n; i++ { // Initialize the shortest distance array with infinite values
        d[i] = INF
    }

    d[0] = 0 // Set the shortest distance to the source vertex to 0

    for i = 0; i < b; i++ { // Iterate through all the edges
        if a[i].cost + d[a[i].back] < d[a[i].go] { // If the cost of the edge plus the shortest distance to the previous vertex is less than the current shortest distance
            d[a[i].go] = a[i].cost + d[a[i].back] // Update the shortest distance to the current vertex
            flag = 1 // Set the flag to indicate that there are still vertices with updated shortest distances
        }
    }
}

func main() {
    var i, j, k, u int // Variables for input and iteration
    var count int = 0 // Variable to keep track of the number of edges

    fmt.Scan(&n) // Read the number of vertices

    for i = 0; i < n; i++ { // Iterate through each vertex
        fmt.Scan(&u, &k) // Read the number of edges and their destinations

        for j = 0; j < k; j++ { // Iterate through each edge
            a[count].back = u // Set the back pointer to the current vertex
            fmt.Scan(&a[count].go, &a[count].cost) // Read the destination vertex and the cost
            count++ // Increment the edge counter
        }
    }

    root(count) // Call the Dijkstra's algorithm function

    for i = 0; i < n; i++ { // Print the shortest distance from the source to each vertex
        fmt.Printf("%d %d\n", i, d[i])
    }
}

