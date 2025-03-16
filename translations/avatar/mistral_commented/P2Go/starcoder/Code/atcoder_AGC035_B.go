
// Import necessary libraries
import (
	"fmt"
	"math"
	"sort"
)

// Take input number of vertices N and number of edges M
var N, M int
fmt.Scanf("%d %d\n", &N, &M)

// Initialize empty sets for each vertex representing its adjacent vertices
var edges [N]map[int]struct{}

// Initialize degree array to keep track of number of edges for each vertex
var degs [N]int

// Initialize parity array to keep track of parity of each vertex
var parity [N]int

// Initialize flag array to keep track of visited vertices
var flag [N]bool

// Read edges from input and add them to their respective sets and update their degrees
for i := 0; i < M; i++ {
	var a, b int
	fmt.Scanf("%d %d\n", &a, &b)
	// Add edge between vertices a and b in both their sets
	edges[a-1][b-1] = struct{}{}
	edges[b-1][a-1] = struct{}{}
	// Update degrees of both vertices
	degs[a-1]++
	degs[b-1]++
}

// Check if number of edges is even, if not print -1 and exit
if M%2!= 0 {
	fmt.Println(-1)
	return
}

// Initialize empty list Q to store vertices based on their degrees
var Q []struct{
	deg int
	idx int
}

// Iterate through all vertices and add them to Q based on their degrees
for i, d := range degs {
	Q = append(Q, struct{
		deg int
		idx int
	}{d, i})
}

// Sort Q to get vertices with minimum degrees first
sort.Slice(Q, func(i, j int) bool {
	return Q[i].deg < Q[j].deg
})

// Iterate through Q until it is empty
for len(Q) > 0 {
	// Get vertex with minimum degree from Q
	u := Q[0].idx
	Q = Q[1:]
	// Skip if vertex is already visited
	if flag[u] {
		continue
	}
	// Mark vertex as visited
	flag[u] = true
	// Iterate through all adjacent vertices and print their edges and update their parity
	for i, v := range edges[u] {
		// Skip if vertex is already visited
		if flag[v] {
			continue
		}
		// Print edge and update parity of both vertices
		if parity[u]!= 0 && i == 0 {
			fmt.Printf("%d %d\n", u+1, v+1)
			parity[u] = 1 - parity[u]
		} else {
			fmt.Printf("%d %d\n", v+1, u+1)
			parity[v] = 1 - parity[v]
		}
		// Decrease degree of adjacent vertex and add it to Q
		degs[v]--
		Q = append(Q, struct{
			deg int
			idx int
		}{degs[v], v})
	}
}

