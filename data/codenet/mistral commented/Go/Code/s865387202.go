// Package main contains the entry point of the program.
package main

import (
	// Import the 'fmt' package for input/output operations.
	"fmt"
	// Import the 'sort' package for sorting.
	"sort"
	// Import the 'strings' package for joining strings.
	"strings"
)

// Define a custom city type with three fields: prefecture, position, and year.
type city struct {
	prefecture int
	position   int
	year       int
}

// Define a custom cities type as a slice of pointers to city structs.
type cities []*city

// Define a custom cMap type as a map with an integer key and a cities slice as the value.
type cMap map[int]cities

// Main function is the entry point of the program.
func main() {
	// Read the number of cities and events from the standard input.
	var n, m int
	fmt.Scanf("%d %d\n", &n, &m)

	// Initialize an empty cMap named h.
	h := make(cMap)

	// Read m pairs of integers x and y from the standard input.
	for i := 0; i < m; i++ {
		// Read an integer x from the standard input.
		var x int
		fmt.Scanf("%d ", &x)

		// Read an integer y from the standard input.
		var y int
		fmt.Scanf("%d\n", &y)

		// Check if the prefecture x already exists in the cMap.
		_, exists := h[x]

		// If the prefecture x does not exist in the cMap, create a new cities slice with one element and assign it to the key x in the cMap.
		if !exists {
			h[x] = cities{{prefecture: x, year: y, position: i}}
		} else {
			// If the prefecture x already exists in the cMap, append a new city struct to the existing cities slice.
			h[x] = append(h[x], &city{prefecture: x, year: y, position: i})
		}
	}

	// Initialize a slice named results with length m and zeroed elements.
	results := make([]string, m)

	// Iterate through each value v in the cMap.
	for _, v := range h {
		// Sort the cities slice v using the Less method.
		sort.Sort(v)

		// Iterate through each city struct ci in the sorted cities slice v.
		for idx, ci := range v {
			// Format the result string using fmt.Sprintf and assign it to the corresponding index in the results slice.
			results[ci.position] = fmt.Sprintf("%06d%06d", ci.prefecture, idx+1)
		}
	}

	// Print the final result using strings.Join and fmt.Println.
	fmt.Println(strings.Join(results, "\n"))
}

// Define custom methods for the cities type: Len, Swap, and Less.
func (c cities) Len() int {
	return len(c)
}

func (c cities) Swap(i, j int) {
	c[i], c[j] = c[j], c[i]
}

func (c cities) Less(i, j int) bool {
	return c[i].year < c[j].year
}

// End of code
