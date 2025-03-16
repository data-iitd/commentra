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

// Define a structure to store connection details
type Date struct {
    go, back, cost int
}

// Define the maximum number of nodes and the distance array
<<<<<<< HEAD
var n int
var d [100000]int
var a [500000]Date
=======
var n, d [100000]int
>>>>>>> 98c87cb78a (data updated)

// Declare the root function
func root(b int) {
    var i, flag int

    // Initialize all distances to INF except the root node (node 0)
<<<<<<< HEAD
    for i = 0; i < n; i++ {
=======
    for i = 0; i < n[0]; i++ {
>>>>>>> 98c87cb78a (data updated)
        d[i] = 1000000
    }
    d[0] = 0

    // Use a while loop to update distances based on connections
    for {
        flag = 0
        for i = 0; i < b; i++ {
<<<<<<< HEAD
            if a[i].cost + d[a[i].back] < d[a[i].go] {
                d[a[i].go] = a[i].cost + d[a[i].back]
=======
            if d[a[i].back]+a[i].cost < d[a[i].go] {
                d[a[i].go] = d[a[i].back] + a[i].cost
>>>>>>> 98c87cb78a (data updated)
                flag = 1
            }
        }
        if flag == 0 {
            break
        }
    }
}

func main() {
    // Declare variables for iteration and input
    var i, j, k, u, count int

    // Read the number of nodes
<<<<<<< HEAD
    fmt.Scanf("%d", &n)

    // Read each node's connections and store them in the array 'a'
    for i = 0; i < n; i++ {
=======
    fmt.Scanf("%d", &n[0])

    // Read each node's connections and store them in the array 'a'
    for i = 0; i < n[0]; i++ {
>>>>>>> 98c87cb78a (data updated)
        fmt.Scanf("%d%d", &u, &k)
        for j = 0; j < k; j++ {
            a[count].back = u
            fmt.Scanf("%d%d", &a[count].go, &a[count].cost)
            count++
        }
    }

    // Call the root function to initialize distances
    root(count)

    // Print the shortest distances from the root node to each node
<<<<<<< HEAD
    for i = 0; i < n; i++ {
=======
    for i = 0; i < n[0]; i++ {
>>>>>>> 98c87cb78a (data updated)
        fmt.Printf("%d %d\n", i, d[i])
    }
}

