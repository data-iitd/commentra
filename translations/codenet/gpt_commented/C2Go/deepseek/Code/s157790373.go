package main

import (
	"fmt"
)

const LEN = 300
const TRUE = 1
const FALSE = -1

// Function prototype for the recursive solve function
func solve(i, m int) int

var n int
var A [LEN]int
var flag int

func main() {
	var q, M int
	var i, j, k int

	// Read the number of elements in the array
	fmt.Scan(&n)
	// Read the elements into the array A
	for i = 0; i < n; i++ {
		fmt.Scan(&A[i])
	}

	// Read the number of queries
	fmt.Scan(&q)
	// Process each query
	for i = 0; i < q; i++ {
		// Read the target sum for the current query
		fmt.Scan(&M)
		flag = FALSE

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

// Recursive function to determine if a subset of A can sum to m
func solve(i, m int) int {
	// Base case: if index exceeds the number of elements
	if i > n {
		return FALSE
	}
	// Base case: if the remaining sum is negative
	if m < 0 {
		return FALSE
	}
	// Base case: if the remaining sum is zero (solution found)
	if m == 0 || m-A[i+1] == 0 {
		flag = TRUE
		return TRUE
	}
	// Recursive case: do not use the current element A[i]
	solve(i+1, m)
	// Recursive case: use the current element A[i]
	solve(i+1, m-A[i])
}

