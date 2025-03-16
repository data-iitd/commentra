package main

import (
	"fmt"
	"sort"
	"strings"
)

// Define a struct to hold edge information
type Edge struct {
	p int64
	i int
	s string
}

// Function to sort edges based on the string and then by the long long value
type ByEdge []Edge

func (a ByEdge) Len() int           { return len(a) }
func (a ByEdge) Less(i, j int) bool {
	if a[i].s != a[j].s {
		return a[i].s < a[j].s
	}
	return a[i].p > a[j].p
}
func (a ByEdge) Swap(i, j int)      { a[i], a[j] = a[j], a[i] }

func main() {
	var n int64
	// Read the number of edges
	fmt.Scan(&n)

	// Create a slice to hold edge data
	data := make([]Edge, n)

	// Read each edge's string and long long value, and store the index
	for i := int64(0); i < n; i++ {
		var p int64
		var s string
		fmt.Scan(&s, &p)
		data[i] = Edge{p: p, i: int(i), s: s}
	}

	// Sort the edges using the custom sort
	sort.Sort(ByEdge(data))

	// Print the indices of the edges in the sorted order
	for _, edge := range data {
		fmt.Println(edge.i + 1)
	}
}

// <END-OF-CODE>
