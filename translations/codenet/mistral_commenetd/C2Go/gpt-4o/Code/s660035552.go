package main

import (
	"fmt"
	"sort"
)

// Pair struct to hold the elements and their corresponding queries
type Pair struct {
	a int
	b int
}

// Function to perform quicksort on the array of pairs
func quicksort(pairs []Pair) {
	sort.Slice(pairs, func(i, j int) bool {
		return pairs[i].a < pairs[j].a
	})
}

// Main function to read input and call quicksort
func main() {
	var n, m int // Initialize variables
	fmt.Scan(&n, &m) // Read number of elements 'n' and queries 'm'

	pairs := make([]Pair, m) // Initialize slice of pairs

	for i := 0; i < m; i++ {
		fmt.Scan(&pairs[i].a, &pairs[i].b) // Read elements and their corresponding queries
	}

	quicksort(pairs) // Call quicksort function to sort elements

	cnt := 0 // Initialize counter for unique elements
	t := 0   // Initialize temporary storage

	for i := 0; i < m; i++ { // Iterate through sorted elements
		if t <= pairs[i].a { // If current element is greater than previous element, increment counter
			t = pairs[i].b // Set current query as new temporary storage
			cnt++          // Increment counter
		}
	}

	fmt.Println(cnt) // Print the number of unique queries
}

// <END-OF-CODE>
