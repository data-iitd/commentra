
package main

import (
	"bufio"
	"fmt"
	"os"
)

// Macros for loop iterations and common operations
func rep(i, a, b int) {
	for i = a; i <= b; i++ {
		// Do something
	}
}

func dep(i, a, b int) {
	for i = a; i >= b; i-- {
		// Do something
	}
}

func Rep(i, a int) {
	for i = 0; i < a; i++ {
		// Do something
	}
}

func pb(a int) {
	// Append element 'a' to the end of the array
}

func mp(a, b int) (int, int) {
	// Create a new pair with values 'a' and 'b'
	return a, b
}

func ab(x int) int {
	if x < 0 {
		return -x
	}
	return x
}

// Type definitions for convenience
type LL int64
type mit map[int]int
type sit set[int]
type pii struct {
	x, y int
}

// Constants
const N = 1e5 + 10

// Structure to represent an edge in the graph
type edge struct {
	to, pre, c int // 'to' is the destination, 'pre' is the previous edge, 'c' is the color
}

// Array to store the head of each vertex's adjacency list
var u [N]int
var l int = 0

// Function to insert an edge into the graph
func ins(a, b, c int) {
	e[l] = edge{b, u[a], c} // Create a new edge
	u[a] = l // Update the head of the adjacency list for vertex 'a'
	l++ // Increment the edge count
}

// Macros for accessing edge properties
var v int
var ec int
var reg func(int, int)

func init() {
	reg = func(i, a int) {
		for i = u[a]; i > 0; i = e[i].pre {
			// Do something
		}
	}
}

// Global variables
var n, m int // Number of vertices and edges
var vis [N]bool // vis[i] indicates if vertex i has been visited
var ok bool // ok indicates if the graph is valid
var cnt [3]int // Count of vertices in each of the three color classes
var d [N]int // Array to store the color of each vertex
var T int // Total number of vertices in the current connected component

// Depth-first search function to traverse the graph
func dfs(x, l int) {
	vis[x] = true // Mark the current vertex as visited
	cnt[l]++ // Increment the count for the current color class
	d[x] = l // Assign the color to the current vertex

	// Iterate through all edges of the current vertex
	reg(i, x) {
		T++ // Increment the total count of vertices in the component
		if!vis[v] { // If the adjacent vertex has not been visited
			dfs(v, (l+ec)%3) // Recursively visit it with the new color
		} else if (l+ec)%3!= d[v] { // If the adjacent vertex is visited but has a different color
			ok = false // Mark the component as invalid
		}
	}
}

func main() {
	// Read the number of vertices and edges
	fmt.Scan(&n, &m)

	// Read edges and construct the graph
	rep(i, 1, m) {
		var a, b int
		fmt.Scan(&a, &b) // Read each edge
		ins(a, b, 1) // Insert edge from a to b with color 1
		ins(b, a, 2) // Insert edge from b to a with color 2
	}

	var ans LL = 0 // Variable to store the final answer

	// Iterate through all vertices
	rep(i, 1, n) {
		if!vis[i] { // If the vertex has not been visited
			T = 0 // Reset the total count for the new component
			rep(j, 0, 2) cnt[j] = 0 // Reset color counts
			ok = true // Assume the component is valid
			dfs(i, 0) // Start DFS from the current vertex with color 0

			// Calculate the size of the current component
			s := cnt[0] + cnt[1] + cnt[2]

			// If the component is invalid, add the square of its size to the answer
			if!ok {
				ans += s * s
			} else {
				// If all three color classes are present, calculate combinations
				if cnt[0] && cnt[1] && cnt[2] {
					ans += LL(cnt[0]) * cnt[1] + LL(cnt[1]) * cnt[2] + LL(cnt[2]) * cnt[0]
				} else {
					// If not all color classes are present, add half of the total vertices
					ans += LL(T) / 2
				}
			}
		}
	}

	// Output the final answer
	fmt.Println(ans)
}

