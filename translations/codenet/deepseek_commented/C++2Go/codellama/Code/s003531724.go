
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

// Structure to represent an edge in the graph
type edge struct {
	to, pre, c int
}

// Array to store the head of each vertex's adjacency list
var u [100001]int

// Function to insert an edge into the graph
func ins(a, b, c int) {
	e := edge{b, u[a], c} // Create a new edge
	u[a] = len(e)         // Update the head of the adjacency list for vertex 'a'
	u = append(u, e)      // Add the new edge to the graph
}

// Macros for accessing edge properties
func v(i int) int {
	return u[i].to
}
func ec(i int) int {
	return u[i].c
}
func reg(i int) {
	for i = u[i].pre; i != 0; i = u[i].pre {
		T++ // Increment the total count for the component
		if !vis[v(i)] { // If the adjacent vertex has not been visited
			dfs(v(i), (l+ec(i))%3) // Recursively visit it with the new color
		} else if (l+ec(i))%3 != d[v(i)] { // If the adjacent vertex is visited but has a different color
			ok = false // Mark the component as invalid
		}
	}
}

// Global variables
var n, m int // Number of vertices and edges
var vis [100001]bool // vis[i] indicates if vertex i has been visited, ok indicates if the graph is valid
var ok bool
var cnt [3]int // Count of vertices in each of the three color classes
var d [100001]int // Array to store the color of each vertex
var T int // Total number of vertices in the current connected component

// Depth-first search function to traverse the graph
func dfs(x, l int) {
	vis[x] = true // Mark the current vertex as visited
	cnt[l]++      // Increment the count for the current color class
	d[x] = l      // Assign the color to the current vertex

	// Iterate through all edges of the current vertex
	reg(u[x].pre)
}

func main() {
	// Read the number of vertices and edges
	fmt.Scan(&n, &m)

	// Read edges and construct the graph
	for i := 1; i <= m; i++ {
		var a, b int
		fmt.Scan(&a, &b) // Read each edge
		ins(a, b, 1)     // Insert edge from a to b with color 1
		ins(b, a, 2)     // Insert edge from b to a with color 2
	}

	ans := 0 // Variable to store the final answer

	// Iterate through all vertices
	for i := 1; i <= n; i++ {
		if !vis[i] { // If the vertex has not been visited
			T = 0 // Reset the total count for the new component
			for j := 0; j < 3; j++ {
				cnt[j] = 0 // Reset color counts
			}
			ok = true // Assume the component is valid
			dfs(i, 0) // Start DFS from the current vertex with color 0

			// Calculate the size of the current component
			s := cnt[0] + cnt[1] + cnt[2]

			// If the component is invalid, add the square of its size to the answer
			if !ok {
				ans += s * s
			} else {
				// If all three color classes are present, calculate combinations
				if cnt[0] != 0 && cnt[1] != 0 && cnt[2] != 0 {
					ans += cnt[0] * cnt[1] + cnt[1] * cnt[2] + cnt[2] * cnt[0]
				} else {
					ans += T / 2 // If not all color classes are present, add half of the total vertices
				}
			}
		}
	}

	// Output the final answer
	fmt.Println(ans)
}

