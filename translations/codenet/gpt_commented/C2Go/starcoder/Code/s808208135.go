package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
    "strings"
)

// Define a constant for the maximum number of nodes
const N = 100000

// Define a constant for representing infinity
const INF = 1000000

// Structure to represent a directed edge with a cost
type Date struct {
    go    int
    back  int
    cost  int
}

var n int
var d [N]int
var a [500000]Date

func main() {
    var i, j, k, u, count int

    // Read the number of nodes
    fmt.Scanf("%d", &n)

    // Read edges for each node
    for i = 0; i < n; i++ {
        fmt.Scanf("%d%d", &u, &k)
        for j = 0; j < k; j++ {
            a[count].back = u
            fmt.Scanf("%d%d", &a[count].go, &a[count].cost)
            count++
        }
    }

    // Call the root function to compute shortest paths
    root(count)

    // Print the shortest distances from the source node to each node
    for i = 0; i < n; i++ {
        fmt.Printf("%d %d\n", i, d[i])
    }
}

// Function to compute shortest paths using the Bellman-Ford algorithm
func root(b int) {
    var i, flag int

    // Initialize distances to all nodes as infinity
    for i = 0; i < n; i++ {
        d[i] = INF
    }
    d[0] = 0

    // Repeat the process until no changes occur
    for {
        flag = 0

        // Relax all edges
        for i = 0; i < b; i++ {
            // Check if the current edge can provide a shorter path
            if a[i].cost + d[a[i].back] < d[a[i].go] {
                d[a[i].go] = a[i].cost + d[a[i].back]
                flag = 1
            }
        }

        if flag == 0 {
            break
        }
    }
}

