package main

import (
	"fmt"
)

func main() {
	var n, m int
	fmt.Scan(&n, &m) // Reading the number of elements and number of queries

	out := make([]int, n) // Initializing the output slice with zeros
	comp := make([]int, n) // Initializing the comparison slice
	for i := 0; i < n; i++ {
		comp[i] = i + 2 // Filling the comparison slice with values from 2 to n+1
	}

	// Processing each query
	for i := 0; i < m; i++ {
		var l, r, x int
		fmt.Scan(&l, &r, &x) // Reading the query parameters
		t := l
		for t <= r {
			nextVal := comp[t-1] // Getting the next value to compare
			if out[t-1] == 0 && t != x { // Checking if the current position should be updated
				out[t-1] = x // Updating the output slice
			}
			if t >= x {
				comp[t-1] = r + 1 // Updating the comparison slice based on the condition
			} else {
				comp[t-1] = x // Updating the comparison slice based on the condition
			}
			t = nextVal // Moving to the next position in the range
		}
	}

	for _, val := range out {
		fmt.Print(val, " ") // Outputting the final result
	}
	fmt.Println()
}

// <END-OF-CODE>
