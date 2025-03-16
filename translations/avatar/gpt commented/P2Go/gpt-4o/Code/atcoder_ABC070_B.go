package main

import (
	"fmt"
	"sort"
)

func main() {
	var A [4]int

	// Read a line of input and split it into components
	for i := 0; i < 4; i++ {
		fmt.Scan(&A[i])
	}

	// Check if the second element is less than or equal to the third element, or if the fourth element is less than or equal to the first element
	if A[1] <= A[2] || A[3] <= A[0] {
		// If the condition is true, print 0
		fmt.Println(0)
	} else {
		// If the condition is false, sort the array A in ascending order
		sort.Ints(A[:])
		// Calculate the difference between the largest and the second largest elements in the sorted array and print the result
		fmt.Println(A[2] - A[1])
	}
}

// <END-OF-CODE>
