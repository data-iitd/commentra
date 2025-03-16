
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

// Function prototype for the recursive solve function
func solve(i int, m int) bool {
	// Base case: if index exceeds the number of elements
	if i > n {
		return false
	}
	// Base case: if the remaining sum is negative
	if m < 0 {
		return false
	}
	// Base case: if the remaining sum is zero (solution found)
	if m == 0 || m-A[i+1] == 0 {
		flag = true // Set flag to TRUE indicating a solution is found
		return true // Return TRUE
	} else {
		// Recursive case: do not use the current element A[i]
		solve(i+1, m)
		// Recursive case: use the current element A[i]
		solve(i+1, m-A[i])
	}
}

func main() {
	var q, M int
	var i, j, k int
	var err error

	// Read the number of elements in the array
	fmt.Scan(&n)
	// Read the elements into the array A
	A = make([]int, n)
	for i = 0; i < n; i++ {
		fmt.Scan(&A[i])
	}

	// Read the number of queries
	fmt.Scan(&q)
	// Process each query
	for i = 0; i < q; i++ {
		// Read the target sum for the current query
		fmt.Scan(&M)
		flag = false // Reset flag for each query

		// Call the solve function to check if a subset sums to M
		solve(-1, M)
		// Output the result based on the flag
		if flag == true {
			fmt.Println("yes")
		} else {
			fmt.Println("no")
		}
	}
}

// Global variables: n for the number of elements, A for the array of elements
var n int
var A []int
var flag bool

// Read the number of elements in the array
fmt.Scan(&n)
// Read the elements into the array A
A = make([]int, n)
for i = 0; i < n; i++ {
	fmt.Scan(&A[i])
}

// Read the number of queries
fmt.Scan(&q)
// Process each query
for i = 0; i < q; i++ {
	// Read the target sum for the current query
	fmt.Scan(&M)
	flag = false // Reset flag for each query

	// Call the solve function to check if a subset sums to M
	solve(-1, M)
	// Output the result based on the flag
	if flag == true {
		fmt.Println("yes")
	} else {
		fmt.Println("no")
	}
}

// Global flag to indicate if a solution is found
var flag bool

// Recursive function to determine if a subset of A can sum to m
func solve(i int, m int) bool {
	// Base case: if index exceeds the number of elements
	if i > n {
		return false
	}
	// Base case: if the remaining sum is negative
	if m < 0 {
		return false
	}
	// Base case: if the remaining sum is zero (solution found)
	if m == 0 || m-A[i+1] == 0 {
		flag = true // Set flag to TRUE indicating a solution is found
		return true // Return TRUE
	} else {
		// Recursive case: do not use the current element A[i]
		solve(i+1, m)
		// Recursive case: use the current element A[i]
		solve(i+1, m-A[i])
	}
}

// Read the number of elements in the array
fmt.Scan(&n)
// Read the elements into the array A
A = make([]int, n)
for i = 0; i < n; i++ {
	fmt.Scan(&A[i])
}

// Read the number of queries
fmt.Scan(&q)
// Process each query
for i = 0; i < q; i++ {
	// Read the target sum for the current query
	fmt.Scan(&M)
	flag = false // Reset flag for each query

	// Call the solve function to check if a subset sums to M
	solve(-1, M)
	// Output the result based on the flag
	if flag == true {
		fmt.Println("yes")
	} else {
		fmt.Println("no")
	}
}

// Global flag to indicate if a solution is found
var flag bool

// Recursive function to determine if a subset of A can sum to m
func solve(i int, m int) bool {
	// Base case: if index exceeds the number of elements
	if i > n {
		return false
	}
	// Base case: if the remaining sum is negative
	if m < 0 {
		return false
	}
	// Base case: if the remaining sum is zero (solution found)
	if m == 0 || m-A[i+1] == 0 {
		flag = true // Set flag to TRUE indicating a solution is found
		return true // Return TRUE
	} else {
		// Recursive case: do not use the current element A[i]
		solve(i+1, m)
		// Recursive case: use the current element A[i]
		solve(i+1, m-A[i])
	}
}

// Read the number of elements in the array
fmt.Scan(&n)
// Read the elements into the array A
A = make([]int, n)
for i = 0; i < n; i++ {
	fmt.Scan(&A[i])
}

// Read the number of queries
fmt.Scan(&q)
// Process each query
for i = 0; i < q; i++ {
	// Read the target sum for the current query
	fmt.Scan(&M)
	flag = false // Reset flag for each query

	// Call the solve function to check if a subset sums to M
	solve(-1, M)
	// Output the result based on the flag
	if flag == true {
		fmt.Println("yes")
	} else {
		fmt.Println("no")
	}
}

// Global flag to indicate if a solution is found
var flag bool

// Recursive function to determine if a subset of A can sum to m
func solve(i int, m int) bool {
	// Base case: if index exceeds the number of elements
	if i > n {
		return false
	}
	// Base case: if the remaining sum is negative
	if m < 0 {
		return false
	}
	// Base case: if the remaining sum is zero (solution found)
	if m == 0 || m-A[i+1] == 0 {
		flag = true // Set flag to TRUE indicating a solution is found
		return true // Return TRUE
	} else {
		// Recursive case: do not use the current element A[i]
		solve(i+1, m)
		// Recursive case: use the current element A[i]
		solve(i+1, m-A[i])
	}
}

// Read the number of elements in the array
fmt.Scan(&n)
// Read the elements into the array A
A = make([]int, n)
for i = 0; i < n; i++ {
	fmt.Scan(&A[i])
}

// Read the number of queries
fmt.Scan(&q)
// Process each query
for i = 0; i < q; i++ {
	// Read the target sum for the current query
	fmt.Scan(&M)
	flag = false // Reset flag for each query

	// Call the solve function to check if a subset sums to M
	solve(-1, M)
	// Output the result based on the flag
	if flag == true {
		fmt.Println("yes")
	} else {
		fmt.Println("no")
	}
}

// Global flag to indicate if a solution is found
var flag bool

// Recursive function to determine if a subset of A can sum to m
func solve(i int, m int) bool {
	// Base case: if index exceeds the number of elements
	if i > n {
		return false
	}
	// Base case: if the remaining sum is negative
	if m < 0 {
		return false
	}
	// Base case: if the remaining sum is zero (solution found)
	if m == 0 || m-A[i+1] == 0 {
		flag = true // Set flag to TRUE indicating a solution is found
		return true // Return TRUE
	} else {
		// Recursive case: do not use the current element A[i]
		solve(i+1, m)
		// Recursive case: use the current element A[i]
		solve(i+1, m-A[i])
	}
}

// Read the number of elements in the array
fmt.Scan(&n)
// Read the elements into the array A
A = make([]int, n)
for i = 0; i < n; i++ {
	fmt.Scan(&A[i])
}

// Read the number of queries
fmt.Scan(&q)
// Process each query
for i = 0; i < q; i++ {
	// Read the target sum for the current query
	fmt.Scan(&M)
	flag = false // Reset flag for each query

	// Call the solve function to check if a subset sums to M
	solve(-1, M)
	// Output the result based on the flag
	if flag == true {
		fmt.Println("yes")
	} else {
		fmt.Println("no")
	}
}

// Global flag to indicate if a solution is found
var flag bool

// Recursive function to determine if a subset of A can sum to m
func solve(i int, m int) bool {
	// Base case: if index exceeds the number of elements
	if i > n {
		return false
	}
	// Base case: if the remaining sum is negative
	if m < 0 {
		return false
	}
	// Base case: if the remaining sum is zero (solution found)
	if m == 0 || m-A[i+1] == 0 {
		flag = true // Set flag to TRUE indicating a solution is found
		return true // Return TRUE
	} else {
		// Recursive case: do not use the current element A[i]
		solve(i+1, m)
		// Recursive case: use the current element A[i]
		solve(i+1, m-A[i])
	}
}

// Read the number of elements in the array
fmt.Scan(&n)
// Read the elements into the array A
A = make([]int, n)
for i = 0; i < n; i++ {
	fmt.Scan(&A[i])
}

// Read the number of queries
fmt.Scan(&q)
// Process each query
for i = 0; i < q; i++ {
	// Read the target sum for the current query
	fmt.Scan(&M)
	flag = false // Reset flag for each query

	// Call the solve function to check if a subset sums to M
	solve(-1, M)
	// Output the result based on the flag
	if flag == true {
		fmt.Println("yes")
	} else {
		fmt.Println("no")
	}
}

// Global flag to indicate if a solution is found
var flag bool

// Recursive function to determine if a subset of A can sum to m
func solve(i int, m int) bool {
	// Base case: if index exceeds the number of elements
	if i > n {
		return false
	}
	// Base case: if the remaining sum is negative
	if m < 0 {
		return false
	}
	// Base case: if the remaining sum is zero (solution found)
	if m == 0 || m-A[i+1] == 0 {
		flag = true // Set flag to TRUE indicating a solution is found
		return true // Return TRUE
	} else {
		// Recursive case: do not use the current element A[i]
		solve(i+1, m)
		// Recursive case: use the current element A[i]
		solve(i+1, m-A[i])
	}
}

// Read the number of elements in the array
fmt.Scan(&n)
// Read the elements into the array A
A = make([]int, n)
for i = 0; i < n; i++ {
	fmt.Scan(&A[i])
}

// Read the number of queries
fmt.Scan(&q)
// Process each query
for i = 0; i < q; i++ {
	// Read the target sum for the current query
	fmt.Scan(&M)
	flag = false // Reset flag for each query

	// Call the solve function to check if a subset sums to M
	solve(-1, M)
	// Output the result based on the flag
	if flag == true {
		fmt.Println("yes")
	} else {
		fmt.Println("no")
	}
}

// Global flag to indicate if a solution is found
var flag bool

// Recursive function to determine if a subset of A can sum to m
func solve(i int, m int) bool {
	// Base case: if index exceeds the number of elements
	if i > n {
		return false
	}
	// Base case: if the remaining sum is negative
	if m < 0 {
		return false
	}
	// Base case: if the remaining sum is zero (solution found)
	if m == 0 || m-A[i+1] == 0 {
		flag = true // Set flag to TRUE indicating a solution is found
		return true // Return TRUE
	} else {
		// Recursive case: do not use the current element A[i]
		solve(i+1, m)
		// Recursive case: use the current element A[i]
		solve(i+1, m-A[i])
	}
}

// Read the number of elements in the array
fmt.Scan(&n)
// Read the elements into the array A
A = make([]int, n)
for i = 0; i < n; i+