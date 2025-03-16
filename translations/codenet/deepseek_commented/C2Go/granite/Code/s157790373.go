
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

// Function prototype for solve
func solve(i int, m int) bool {
	// Base case: if index i exceeds the number of elements, return FALSE
	if i > n {
		return false
	}
	// If the remaining sum m is negative, return FALSE
	if m < 0 {
		return false
	}
	// If the remaining sum m is zero or the current element A[i] equals m, set flag to TRUE and return TRUE
	if m == 0 || m-A[i+1] == 0 {
		flag = true
		return true
	}
	// Recursive call without using the current element A[i]
	solve(i+1, m)
	// Recursive call using the current element A[i]
	solve(i+1, m-A[i])
}

// Global variables
var n int
var A []int
var flag bool

func main() {
	// Variables for input
	var q int
	var M int
	var i int
	var j int
	var k int

	// Read the number of elements in the array
	fmt.Scan(&n)
	// Read the elements of the array
	A = make([]int, n)
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
		flag = false

		// Call the solve function to find a subset that sums up to M
		solve(-1, M)
		// Print "yes" if a subset is found, otherwise print "no"
		if flag == true {
			fmt.Println("yes")
		} else {
			fmt.Println("no")
		}
	}
}

// Translate the above Go code to Python and end with comment "