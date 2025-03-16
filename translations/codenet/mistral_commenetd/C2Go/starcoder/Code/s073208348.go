
// This is a Go code for finding the diameter of a tree using Depth-First Search (DFS) algorithm.
//
// package main
//
// import (
// 	"bufio"
// 	"fmt"
// 	"os"
// 	"sort"
// )
//
// // Define the structure for the edge and graph.
// type E struct {
// 	s, g, c int
// }
// type G struct {
// 	vcnt, ecnt int
// 	e          [200010]E
// 	id         [100010]int
// }
//
// // Comparison function for qsort to sort edges based on their source vertex.
// func esort(a, b interface{}) int {
// 	p := a.(*E)
// 	q := b.(*E)
// 	if p.s < q.s {
// 		return -1
// 	}
// 	if p.s > q.s {
// 		return 1
// 	}
// 	if p.g < q.g {
// 		return -1
// 	}
// 	if p.g > q.g {
// 		return 1
// 	}
// 	return 0
// }
//
// // Initialize the graph structure.
// var g G
//
// // Read the graph from the standard input.
// func readgraph() {
// 	// Read the number of vertices.
// 	var n int
// 	fmt.Fscanf(os.Stdin, "%d\n", &n)
// 	// Allocate memory for the vertices and edges.
// 	g.vcnt = n
// 	g.ecnt = 2*n - 2
// 	// Allocate memory for the edge array and sort it.
// 	e := make([]E, g.ecnt+10)
// 	for i := 0; i < n-1; i++ {
// 		var x, y, c int
// 		fmt.Fscanf(os.Stdin, "%d%d%d\n", &x, &y, &c)
// 		// Add an edge from x to y and y to x with the given cost.
// 		e[i].s = x
// 		e[i].g = y
// 		e[i].c = c
// 		e[i+g.ecnt].s = y
// 		e[i+g.ecnt].g = x
// 		e[i+g.ecnt].c = c
// 	}
// 	// Set the number of edges.
// 	g.ecnt *= 2
// 	// Sort the edges using qsort.
// 	sort.Slice(e, func(i, j int) bool { return esort(&e[i], &e[j]) < 0 })
// 	// Initialize the id array.
// 	p := 0
// 	for i := 0; i < g.vcnt; i++ {
// 		// Find the index of the current vertex in the sorted edge list.
<<<<<<< HEAD
// 		for ; p < g.ecnt && e[p].s < i; p++ {
=======
// 		for p < g.ecnt && e[p].s < i {
// 			p++
>>>>>>> 98c87cb78a (data updated)
// 		}
// 		g.id[i] = p
// 	}
// 	// Set the last index as a sentinel.
// 	g.id[g.vcnt] = g.ecnt
// }
//
// // Function to find the diameter of the tree using DFS algorithm.
// // *tyokkeitemp is an array to store the depth of each vertex from the root.
// var tyokkeitemp []int
// func tyokkeidfs(s int) {
// 	// Iterate through the edges connected to the current vertex.
// 	for i := g.id[s]; i < g.id[s+1]; i++ {
// 		// If the destination vertex has not been visited yet, recursively call tyokkeidfs.
// 		if tyokkeitemp[g.e[i].g] == 0 {
// 			tyokkeitemp[g.e[i].g] = tyokkeitemp[s] + g.e[i].c
// 			tyokkeidfs(g.e[i].g)
// 		}
// 	}
// }
// func tyokkei() int {
// 	// Allocate memory for tyokkeitemp array.
// 	tyokkeitemp = make([]int, g.vcnt+10)
// 	// Initialize the root vertex depth to 1.
// 	tyokkeitemp[0] = 1
// 	// Perform DFS from the root vertex.
// 	tyokkeidfs(0)
// 	// Find the maximum depth.
// 	M, Mi := 0, 0
// 	for i := 0; i < g.vcnt; i++ {
// 		// If the current vertex depth is greater than the maximum depth, update it.
// 		if tyokkeitemp[i] > M {
// 			M = tyokkeitemp[i]
// 			Mi = i
// 		}
// 	}
// 	// Free the memory allocated for tyokkeitemp.
// 	tyokkeitemp = nil
// 	// Return the diameter which is the maximum depth minus 1.
// 	return M - 1
// }
// // Main function to read the graph and print the diameter.
// func main() {
// 	// Read the graph.
// 	readgraph()
// 	// Call the tyokkei function to find the diameter.
// 	fmt.Printf("%d\n", tyokkei())
// }
//
// 