package main

import (
	"fmt"
)

const LEN = 300
const TRUE = 1
const FALSE = -1

// Function prototype for solve
func solve(i, m int) int

// Global variables
var n int
var A [LEN]int
var flag int

func main() {
	// Variables for input
	var q, M int
	var i, j, k int

	// Read the number of elements in the array
	fmt.Scan(&n)
	// Read the elements of the array
	for i = 0; i < n; i++ {
		fmt.Scan(&A[i])
	}

	// Read the number of queries
	fmt.Scan(&q)
	// Iterate over each query
	for i = 0; i < q; i++ {
		// Read the target sum for the current query
		fmt.Scan(&M)
		// Initialize the flag to FALSE
		flag = FALSE

		// Call the solve function to find a subset that sums up to M
		solve(-1, M)
		// Print "yes" if a subset is found, otherwise print "no"
		if flag == TRUE {
			fmt.Println("yes")
		} else {
			fmt.Println("no")
		}
	}
}

// Recursive function to find a subset that sums up to m
func solve(i, m int) int {
	// Base case: if index i exceeds the number of elements, return FALSE
	if i > n {
		return FALSE
	}
	// If the remaining sum m is negative, return FALSE
	if m < 0 {
		return FALSE
	}
	// If the remaining sum m is zero or the current element A[i] equals m, set flag to TRUE and return TRUE
	if m == 0 || m-A[i+1] == 0 {
		flag = TRUE
		return TRUE
	}
	// Recursive call without using the current element A[i]
	solve(i+1, m)
	// Recursive call using the current element A[i]
	solve(i+1, m-A[i])
}

