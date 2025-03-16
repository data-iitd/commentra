package main

import (
	"fmt"
	"sort"
	"strconv"
)

// Define a long long integer type for convenience
type ll int64

// Define a structure to hold edge information
type Edge struct {
	p  ll
	i  int
	s  string
}

// Array to hold edge data
var data []Edge

// Main function
func main() {
	// Read the number of edges
	var n ll
	fmt.Scan(&n)

	// Read each edge's string and long long value, and store the index
	data = make([]Edge, n)
	for i := 0; i < int(n); i++ {
		fmt.Scan(&data[i].s, &data[i].p)
		data[i].i = i + 1
	}

	// Sort the edges using sort.Slice and a custom Less function
	sort.Slice(data, func(i, j int) bool {
		if data[i].s != data[j].s {
			return data[i].s < data[j].s
		}
		return data[i].p > data[j].p
	})

	// Print the indices of the edges in the sorted order
	for _, edge := range data {
		fmt.Println(edge.i)
	}
}
