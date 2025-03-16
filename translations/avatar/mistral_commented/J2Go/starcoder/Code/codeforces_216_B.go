
package main

import (
 "bufio"
 "fmt"
 "os"
 "strconv"
 "strings"
)

// Declaring and initializing the count variable to 0.
var count int = 0

// Declaring and initializing the seen array to keep track of visited nodes.
var seen [100001]bool

// Declaring and initializing the path and cycle variables.
var path, cycle int

// Declaring and initializing the graph as a 2D linked list.
var graph [100001]*[]int

func dfs(child, par int) int {
 if seen[child] { // Checking if the current node has already been visited.
 return cycle // If it has, then there is a cycle in the graph and we return 1.
 }
 seen[child] = true // Marking the current node as visited.

 for _, i := range *graph[child] { // Iterating through the neighbors of the current node.
 if i!= par { // Checking if the neighbor is not the parent node.
 count++ // Incrementing the count of edges traversed.
 if dfs(i, child) == cycle { // Recursively calling the dfs function on the neighbor.
 return cycle // If there is a cycle, then we return 1.
 }
 }
 }
 return path // If there is no cycle, then we return 0.
}

func main() {
 reader := bufio.NewReader(os.Stdin)
 fmt.Println("Enter the number of nodes in the graph:")
 m, _ := strconv.Atoi(strings.TrimSpace(reader.ReadString('\n')))
 fmt.Println("Enter the number of edges in the graph:")
 n, _ := strconv.Atoi(strings.TrimSpace(reader.ReadString('\n')))
 ft := new(Main) // Creating a new instance of the Main class.
 ft.graph = make([]*[]int, m+1) // Initializing the graph as an empty 2D linked list.
 ft.seen = make([]bool, m+1) // Initializing the seen array as a boolean array of size (m+1).

 for i := 0; i <= m; i++ { // Initializing the graph with empty linked lists for each node.
 ft.graph[i] = new([]int)
 }

 for i := 0; i < n; i++ { // Reading the edges from the input and adding them to the graph.
 x, _ := strconv.Atoi(strings.TrimSpace(reader.ReadString('\n')))
 y, _ := strconv.Atoi(strings.TrimSpace(reader.ReadString('\n')))
 *ft.graph[x] = append(*ft.graph[x], y) // Adding an edge from x to y.
 *ft.graph[y] = append(*ft.graph[y], x) // Adding an edge from y to x.
 }

 toremove := 0 // Initializing the toremove variable to 0.
 for i := 1; i <= m; i++ { // Iterating through all the nodes in the graph.
 if!seen[i] { // If the current node has not been visited.
 count = 0 // Resetting the count of edges traversed to 0.
 if dfs(i, 0) == cycle { // If there is a cycle in the subgraph rooted at the current node.
 if count%2 == 1 { // If the number of edges traversed is odd.
 toremove++ // Increment the toremove variable.
 }
 }
 }
 }

 if (m-toremove)%2 == 1 { // Checking if the number of nodes is odd.
 toremove++ // If it is, then increment the toremove variable.
 }

 fmt.Println(toremove) // Printing the result.
}

