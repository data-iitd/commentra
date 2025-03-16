
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
	G [101][101]int
)

// Function to perform Prim's Algorithm
func prim() {
	var (
		i, j, u, v, min int
		d [101]int
		pi [101]int
		color [101]int
		sum int
	)

	// Initialize all vertices with INF distance, NIL previous vertex, and WHITE color
	for i = 0; i < n; i++ {
		d[i] = 100000
		pi[i] = -1
		color[i] = 0
	}

	// Set the distance of the source vertex to 0
	d[0] = 0

	// While there are still unvisited vertices
	for {
		min = 100000
		u = -1 // Initialize min and u to uninitialized values
		for i = 0; i < n; i++ {
			// Find the unvisited vertex with the minimum distance
			if color[i] == 0 && d[i] < min {
				min = d[i]
				u = i
			}
		}
		// If all vertices have been visited, break the loop
		if u == -1 {
			break
		}
		// Mark the current vertex as visited (Black color)
		color[u] = 1
		// Update the distances of all adjacent vertices
		for v = 0; v < n; v++ {
			if color[v] == 0 && G[u][v]!= 100000 {
				// If the distance through the current vertex is shorter than the current distance, update it
				if d[v] > G[u][v] {
					d[v] = G[u][v]
					pi[v] = u
					color[v] = 1
				}
			}
		}
	}
	// Calculate and print the total weight of the minimum spanning tree
	for i = 0; i < n; i++ {
		if pi[i]!= -1 {
			sum += G[i][pi[i]]
		}
	}
	fmt.Println(sum)
}

func main() {
	var (
		i, j, e int
		line string
	)

	// Read the number of vertices from the standard input
<<<<<<< HEAD
	fmt.Scanf("%d\n", &n)

	// Initialize the adjacency matrix with INF for unconnected vertices and input edges with their weights
	for i = 0; i < n; i++ {
		line, _ = bufio.NewReader(os.Stdin).ReadString('\n')
		line = strings.TrimSpace(line)
		line = strings.Replace(line, " ", "", -1)
		line = strings.Replace(line, "\n", "", -1)
		line = strings.Replace(line, "\r", "", -1)
		line = strings.Replace(line, "\t", "", -1)
		for j = 0; j < n; j++ {
			e, _ = strconv.Atoi(string(line[j]))
			G[i][j] = e
=======
	fmt.Scanf("%d", &n)

	// Initialize the adjacency matrix with INF for unconnected vertices and input edges with their weights
	for i = 0; i < n; i++ {
		for j = 0; j < n; j++ {
			fmt.Scanf("%d", &e)
			if e == -1 {
				G[i][j] = 100000
			} else {
				G[i][j] = e
			}
>>>>>>> 98c87cb78a (data updated)
		}
	}

	// Call the Prim's Algorithm function to find the minimum spanning tree
	prim()
}

