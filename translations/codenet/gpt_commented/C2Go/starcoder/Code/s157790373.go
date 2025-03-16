package main

import (
	"fmt"
	"os"
	"strconv"
	"strings"
)

// Global variables: n for the number of elements, A for the array of elements
var n int
var A []int

// Global flag to indicate if a solution is found
var flag bool

func main() {
	// Read the number of elements in the array
	n, _ = strconv.Atoi(strings.TrimSpace(string(os.Stdin.ReadByte())))
	// Read the elements into the array A
	A = make([]int, n)
	for i := 0; i < n; i++ {
		A[i], _ = strconv.Atoi(strings.TrimSpace(string(os.Stdin.ReadByte())))
	}

	// Read the number of queries
	q, _ := strconv.Atoi(strings.TrimSpace(string(os.Stdin.ReadByte())))
	// Process each query
	for i := 0; i < q; i++ {
		// Read the target sum for the current query
		m, _ := strconv.Atoi(strings.TrimSpace(string(os.Stdin.ReadByte())))
		flag = false // Reset flag for each query

		// Call the solve function to check if a subset sums to M
		solve(0, m)
		// Output the result based on the flag
		if flag {
			fmt.Println("yes")
		} else {
			fmt.Println("no")
		}
	}
}

// Recursive function to determine if a subset of A can sum to m
func solve(i int, m int) {
	// Base case: if index exceeds the number of elements
	if i > n {
		return
	}
	// Base case: if the remaining sum is negative
	if m < 0 {
		return
	}
	// Base case: if the remaining sum is zero (solution found)
	if m == 0 || m-A[i+1] == 0 {
		flag = true // Set flag to TRUE indicating a solution is found
		return
	}
	// Recursive case: do not use the current element A[i]
	solve(i+1, m)
	// Recursive case: use the current element A[i]
	solve(i+1, m-A[i])
}

