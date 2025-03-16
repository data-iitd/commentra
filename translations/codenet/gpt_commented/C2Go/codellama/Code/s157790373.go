package main

import "fmt"

const LEN = 300
const TRUE = 1
const FALSE = -1

var n int // Global variable: n for the number of elements
var A [LEN]int // Global variable: A for the array of elements
var flag int // Global variable: flag to indicate if a solution is found

func main() {
	var q, M int // q for the number of queries, M for the target sum
	var i, j, k int

	// Read the number of elements in the array
	fmt.Scanf("%d", &n)
	// Read the elements into the array A
	for i = 0; i < n; i++ {
		fmt.Scanf("%d", &A[i])
	}

	// Read the number of queries
	fmt.Scanf("%d", &q)
	// Process each query
	for i = 0; i < q; i++ {
		// Read the target sum for the current query
		fmt.Scanf("%d", &M)
		flag = FALSE // Reset flag for each query

		// Call the solve function to check if a subset sums to M
		solve(-1, M)
		// Output the result based on the flag
		if flag == TRUE {
			fmt.Printf("yes\n")
		} else {
			fmt.Printf("no\n")
		}
	}
}

// Recursive function to determine if a subset of A can sum to m
func solve(i, m int) int {
	// Base case: if index exceeds the number of elements
	if i > n {
		return FALSE
	}
	// Base case: if the remaining sum is negative
	else if m < 0 {
		return FALSE
	}
	// Base case: if the remaining sum is zero (solution found)
	else if m == 0 || m-A[i+1] == 0 {
		flag = TRUE // Set flag to TRUE indicating a solution is found
		return TRUE  // Return TRUE
	} else {
		// Recursive case: do not use the current element A[i]
		solve(i + 1, m)
		// Recursive case: use the current element A[i]
		solve(i + 1, m - A[i])
	}
}

