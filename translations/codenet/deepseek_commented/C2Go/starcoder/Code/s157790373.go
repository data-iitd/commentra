<<<<<<< HEAD
=======
package main
>>>>>>> 98c87cb78a (data updated)

import "fmt"

// Global variables
var n int
var A []int
var flag int

<<<<<<< HEAD
func main() {
	// Variables for input
	var q, m int
=======
// Function prototype for solve
func solve(i, m int) int

func main() {
	// Variables for input
	var q, M int
	var i, j, k int
>>>>>>> 98c87cb78a (data updated)

	// Read the number of elements in the array
	fmt.Scanf("%d", &n)
	// Read the elements of the array
	A = make([]int, n)
<<<<<<< HEAD
	for i := 0; i < n; i++ {
=======
	for i = 0; i < n; i++ {
>>>>>>> 98c87cb78a (data updated)
		fmt.Scanf("%d", &A[i])
	}

	// Read the number of queries
	fmt.Scanf("%d", &q)
	// Iterate over each query
<<<<<<< HEAD
	for i := 0; i < q; i++ {
		// Read the target sum for the current query
		fmt.Scanf("%d", &m)
		// Initialize the flag to FALSE
		flag = 0

		// Call the solve function to find a subset that sums up to m
		solve(0, m)
=======
	for i = 0; i < q; i++ {
		// Read the target sum for the current query
		fmt.Scanf("%d", &M)
		// Initialize the flag to FALSE
		flag = 0

		// Call the solve function to find a subset that sums up to M
		solve(-1, M)
>>>>>>> 98c87cb78a (data updated)
		// Print "yes" if a subset is found, otherwise print "no"
		if flag == 1 {
			fmt.Println("yes")
		} else {
			fmt.Println("no")
		}
	}
}

// Recursive function to find a subset that sums up to m
<<<<<<< HEAD
func solve(i int, m int) {
	// Base case: if index i exceeds the number of elements, return FALSE
	if i > n-1 {
		return
	}
	// If the remaining sum m is negative, return FALSE
	if m < 0 {
		return
	}
	// If the remaining sum m is zero or the current element A[i] equals m, set flag to TRUE and return TRUE
	if m == 0 || m-A[i] == 0 {
		flag = 1
		return
	}
	// Recursive call without using the current element A[i]
	solve(i+1, m)
	// Recursive call using the current element A[i]
	solve(i+1, m-A[i])
=======
func solve(i, m int) int {
	// Base case: if index i exceeds the number of elements, return FALSE
	if i > n {
		return 0
	}
	// If the remaining sum m is negative, return FALSE
	if m < 0 {
		return 0
	}
	// If the remaining sum m is zero or the current element A[i] equals m, set flag to TRUE and return TRUE
	if m == 0 || m-A[i+1] == 0 {
		flag = 1
		return 1
	} else {
		// Recursive call without using the current element A[i]
		solve(i+1, m)
		// Recursive call using the current element A[i]
		solve(i+1, m-A[i])
	}
	return 0
>>>>>>> 98c87cb78a (data updated)
}

