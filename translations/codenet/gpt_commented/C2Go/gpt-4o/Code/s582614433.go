package main

import (
	"fmt"
	"sort"
	"strings"
)

// Define a struct to hold edge information
type Edge struct {
	Weight int64  // Weight or value associated with the edge
	Index  int64  // Index of the edge
	Name   string // Name or identifier of the edge
}

// Function to sort edges based on the defined criteria
type ByEdge []Edge

func (a ByEdge) Len() int           { return len(a) }
func (a ByEdge) Less(i, j int) bool {
	if a[i].Name != a[j].Name {
		return a[i].Name < a[j].Name
	}
	return a[i].Weight > a[j].Weight // Sort by weight in descending order
}
func (a ByEdge) Swap(i, j int) { a[i], a[j] = a[j], a[i] }

func main() {
	var n int64
	// Read the number of edges
	fmt.Scan(&n)

	// Create a slice to hold edge data
	data := make([]Edge, n)

	// Read edge data from input
	for i := int64(0); i < n; i++ {
		var name string
		var weight int64
		fmt.Scan(&name, &weight) // Read string and weight
		data[i] = Edge{Weight: weight, Index: i, Name: name} // Store edge data
	}

	// Sort the edges based on the defined sorting criteria
	sort.Sort(ByEdge(data))

	// Output the original indices of the sorted edges
	for _, edge := range data {
		fmt.Println(edge.Index + 1) // Print original index (1-based)
	}
}

// <END-OF-CODE>
