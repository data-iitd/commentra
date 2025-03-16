package main

import (
	"fmt"
	"sort"
)

// Main function is the entry point of our program
func main() {
	// Declare variables and initialize them
	var n int
	fmt.Scan(&n)

	// Create a slice of work structures with length "n"
	ws := make([]work, n)

	// Read input data for each work structure and store it in the corresponding index of the "ws" slice
	for i := 0; i < n; i++ {
		var a, n int
		fmt.Scan(&a, &n)
		ws[i] = work{a, n}
	}

	// Sort the "ws" slice based on the "limit" field of each work structure
	sort.Sort(ws)

	// Initialize a variable named "sum" of type int64 and set its value to 0
	sum := int64(0)

	// Iterate through the sorted "ws" slice and check if the total time spent on all works exceeds any work's limit
	for _, w := range ws {
		// Add the time of the current work structure to the "sum" variable
		sum += int64(w.time)

		// Check if the sum is greater than the limit of the current work structure
		if sum > int64(w.limit) {
			// If it is, print "No" and return from the function
			fmt.Println("No")
			return
		}
	}

	// If the loop completes without finding a work structure whose time exceeds its limit, print "Yes"
	fmt.Println("Yes")
}

// Define a type named "work" with two fields: "time" and "limit" of type int
type work struct {
	time, limit int
}

// Define a type named "works" as a slice of "work" structures
type works []work

// Implement Len, Swap, and Less methods for the "works" type to satisfy the sort.Interface interface
func (w works) Len() int           { return len(w) }
func (w works) Swap(i, j int)      { w[i], w[j] = w[j], w[i] }
func (w works) Less(i, j int) bool { return w[i].limit < w[j].limit }
