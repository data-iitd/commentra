package main

import (
	"fmt"
	"sort"
)

func main() {
	var A [4]int

	// Read input and populate the array A
	for i := 0; i < 4; i++ {
		fmt.Scan(&A[i])
	}

	// Check if the second or third element of the array A is less than or equal to the first element
	if A[1] <= A[2] || A[3] <= A[0] {
		// If the condition is true, print '0'
		fmt.Println(0)
	} else {
		// If the condition is false, sort the array A in ascending order
		sort.Ints(A[:])

		// Print the difference between the third and second elements of the sorted array
		fmt.Println(A[2] - A[1])
	}
}

// <END-OF-CODE>
