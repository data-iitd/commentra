package main

import (
	"fmt"
)

const LEN = 300
const TRUE = 1
const FALSE = -1

var n int
var A [LEN]int // Array of elements
var flag int   // Flag to indicate if a solution is found

// Function prototype for the recursive solve function
func solve(i int, m int) int {
	// Base case: if index exceeds the number of elements
	if i >= n {
		return FALSE
	}
	// Base case: if the remaining sum is negative
	if m < 0 {
		return FALSE
	}
	// Base case: if the remaining sum is zero (solution found)
	if m == 0 || m-A[i+1] == 0 {
		flag = TRUE // Set flag to TRUE indicating a solution is found
		return TRUE // Return TRUE
	} else {
		// Recursive case: do not use the current element A[i]
		solve(i+1, m)
		// Recursive case: use the current element A[i]
		solve(i+1, m-A[i])
	}
	return FALSE
}

func main() {
	var q, M int // q for the number of queries, M for the target sum

	// Read the number of elements in the array
	fmt.Scan(&n)
	// Read the elements into the array A
	for i := 0; i < n; i++ {
		fmt.Scan(&A[i])
	}

	// Read the number of queries
	fmt.Scan(&q)
	// Process each query
	for i := 0; i < q; i++ {
		// Read the target sum for the current query
		fmt.Scan(&M)
		flag = FALSE // Reset flag for each query

		// Call the solve function to check if a subset sums to M
		solve(-1, M)
		// Output the result based on the flag
		if flag == TRUE {
			fmt.Println("yes")
		} else {
			fmt.Println("no")
		}
	}
}

// <END-OF-CODE>
