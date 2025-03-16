package main

import (
	"fmt"
	"sort"
)

const mod = 1000000007

// Function to read a list of integers from input
func readInts() []int {
	var n int
	fmt.Scan(&n)
	A := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&A[i])
	}
	return A
}

// Main function to execute the logic
func main() {
	var n int
	fmt.Scan(&n) // Reading an integer input for 'n'
	A := readInts() // Reading a list of integers
	sort.Ints(A) // Sorting the list of integers in ascending order
	ans := 0 // Initializing the answer variable to accumulate the result

	// Looping through the last 2*n elements of the sorted list in reverse order
	for i := len(A) - 2; i >= len(A)-2*n; i -= 2 {
		ans += A[i] // Adding the current element to the answer
	}

	fmt.Println(ans) // Printing the final accumulated answer
}

// <END-OF-CODE>
