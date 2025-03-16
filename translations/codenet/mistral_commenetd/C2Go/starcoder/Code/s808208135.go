<<<<<<< HEAD
=======
package main
>>>>>>> 98c87cb78a (data updated)

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
    "strings"
)

// Global variables
var (
    n int
    a [500000]Date // Array to store the adjacency list and cost for each edge
    d [N]int       // Array to store the shortest distance from the source to each vertex
)

// Date struct to store the adjacency list and cost for each edge
type Date struct {
    go, back, cost int
}

// Function to perform Dijkstra's algorithm
func root(b int) {
    var i, flag int // Variables for iteration and algorithm termination flag

    for i = 0; i < n; i++ { // Initialize the shortest distance array with infinite values
        d[i] = INF
    }

    d[0] = 0 // Set the shortest distance to the source vertex to 0

    for i = 0; i < b; i++ { // Iterate through all the edges
        if a[i].cost+d[a[i].back] < d[a[i].go] { // If the cost of the edge plus the shortest distance to the previous vertex is less than the current shortest distance
            d[a[i].go] = a[i].cost + d[a[i].back] // Update the shortest distance to the current vertex
            flag = 1 // Set the flag to indicate that there are still vertices with updated shortest distances
        }
    }
}

func main() {
    var i, j, k, u int // Variables for input and iteration
    var count int       // Variable to keep track of the number of edges

    fmt.Scanf("%d", &n) // Read the number of vertices

    for i = 0; i < n; i++ { // Iterate through each vertex
        fmt.Scanf("%d%d", &u, &k) // Read the number of edges and their destinations

        for j = 0; j < k; j++ { // Iterate through each edge
            a[count].back = u // Set the back pointer to the current vertex
            fmt.Scanf("%d%d", &a[count].go, &a[count].cost) // Read the destination vertex and the cost
            count++ // Increment the edge counter
        }
    }

    root(count) // Call the Dijkstra's algorithm function

    for i = 0; i < n; i++ { // Print the shortest distance from the source to each vertex
        fmt.Printf("%d %d\n", i, d[i])
    }
}

