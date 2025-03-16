package main

import (
	"fmt"
)

const N = 1e5 + 10

type Edge struct {
	to, pre, c int // 'to' is the destination, 'pre' is the previous edge, 'c' is the color
}

var (
	e      [N * 2]Edge // Array to store edges
	u      [N]int      // Array to store the head of each vertex's adjacency list
	l      int         // Edge counter
	n, m   int         // Number of vertices and edges
	vis    [N]bool     // vis[i] indicates if vertex i has been visited
	ok     bool        // Indicates if the graph is valid
	cnt    [3]int      // Count of vertices in each of the three color classes
	d      [N]int      // Array to store the color of each vertex
	T      int         // Total number of vertices in the current connected component
)

func ins(a, b, c int) {
	l++
	e[l] = Edge{to: b, pre: u[a], c: c} // Create a new edge
	u[a] = l                             // Update the head of the adjacency list for vertex 'a'
}

func dfs(x, l int) {
	vis[x] = true // Mark the current vertex as visited
	cnt[l]++      // Increment the count for the current color class
	d[x] = l      // Assign the color to the current vertex

	for i := u[x]; i > 0; i = e[i].pre {
		T++ // Increment the total count of vertices in the component
		v := e[i].to
		if !vis[v] { // If the adjacent vertex has not been visited
			dfs(v, (l+e[i].c)%3) // Recursively visit it with the new color
		} else if (l+e[i].c)%3 != d[v] { // If the adjacent vertex is visited but has a different color
			ok = false // Mark the component as invalid
		}
	}
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

	ans := int64(0) // Variable to store the final answer

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
			s := int64(cnt[0] + cnt[1] + cnt[2])

			// If the component is invalid, add the square of its size to the answer
			if !ok {
				ans += s * s
			} else {
				// If all three color classes are present, calculate combinations
				if cnt[0] > 0 && cnt[1] > 0 && cnt[2] > 0 {
					ans += int64(cnt[0]*cnt[1] + cnt[1]*cnt[2] + cnt[2]*cnt[0])
				} else {
					ans += int64(T / 2) // If not all color classes are present, add half of the total vertices
				}
			}
		}
	}

	// Output the final answer
	fmt.Println(ans)
}

// <END-OF-CODE>
