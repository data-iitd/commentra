<<<<<<< HEAD

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
    "strings"
)

// Step 2: Define global variables
// G is a map of slices representing the graph.
var G map[int][]int
=======
package main

import "fmt"

// Step 1: Define the type of the graph
// G is a map of integers to integers representing the graph.
var G map[int]map[int]int

// Step 2: Define global variables
>>>>>>> 98c87cb78a (data updated)
// used is a boolean array to keep track of visited nodes.
var used [100000]bool
// grundy is an array to store the Grundy number of each node.
var grundy [100000]int

// Step 3: Define the dfs function
// The function dfs is used to perform a depth-first search on the graph.
<<<<<<< HEAD
func dfs(v int) {
=======
func dfs(v int){
>>>>>>> 98c87cb78a (data updated)
    // It marks the current node as visited.
    used[v] = true
    // It initializes the Grundy number of the current node to 0.
    grundy[v] = 0
    // It iterates through all the neighbors of the current node.
<<<<<<< HEAD
    for _, w := range G[v] {
        // If a neighbor has not been visited, it recursively calls dfs on that neighbor.
        if!used[w] {
            dfs(w)
            // It updates the Grundy number of the current node by performing the XOR operation with (grundy[G[v][i]] + 1).
            grundy[v] ^= (grundy[w] + 1)
=======
    for _, w := range G[v]{
        // If a neighbor has not been visited, it recursively calls dfs on that neighbor.
        if!used[w]{
            dfs(w)
            // It updates the Grundy number of the current node by performing the XOR operation with (grundy[G[v][i]] + 1).
            grundy[v] ^= (grundy[w]+1)
>>>>>>> 98c87cb78a (data updated)
        }
    }
}

// Step 4: Main function
<<<<<<< HEAD
func main() {
    // It reads the number of nodes N.
    reader := bufio.NewReader(os.Stdin)
    fmt.Fscan(reader, &N)
    // It reads the edges of the graph and constructs the adjacency list.
    G = make(map[int][]int)
    for i := 0; i < N-1; i++ {
        var x, y int
        fmt.Fscan(reader, &x, &y)
        x--
        y--
        G[x] = append(G[x], y)
        G[y] = append(G[y], x)
=======
func main(){
    // It reads the number of nodes N.
    var N int
    fmt.Scanf("%d\n", &N)
    // It initializes the graph G.
    G = make(map[int]map[int]int)
    // It reads the edges of the graph and constructs the adjacency list.
    for i := 0; i < N-1; i++{
        var x, y int
        fmt.Scanf("%d %d\n", &x, &y)
        x--
        y--
        if _, ok := G[x];!ok{
            G[x] = make(map[int]int)
        }
        if _, ok := G[y];!ok{
            G[y] = make(map[int]int)
        }
        G[x][y] = 1
        G[y][x] = 1
>>>>>>> 98c87cb78a (data updated)
    }
    // It calls the dfs function starting from node 0.
    dfs(0)
    // It checks the Grundy number of the root node (node 0).
<<<<<<< HEAD
    if grundy[0]!= 0 {
        // It prints "Alice" if the Grundy number is not 0, otherwise it prints "Bob".
        fmt.Println("Alice")
    } else {
=======
    if grundy[0]!= 0{
        // It prints "Alice" if the Grundy number is not 0, otherwise it prints "Bob".
        fmt.Println("Alice")
    }else{
>>>>>>> 98c87cb78a (data updated)
        fmt.Println("Bob")
    }
}

