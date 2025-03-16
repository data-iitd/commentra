package main

import (
	"fmt"
	"sort"
)

func main() {
	var N int
	fmt.Scan(&N) // Read the integer input N
	A := make([]int, N)
	for i := 0; i < N; i++ {
		fmt.Scan(&A[i]) // Read the list of integers A
	}

	// Initialize variables to track the minimum and maximum indices where the condition is true
	mn, mx := N+1, -1

	// Iterate over the range of N to find the indices where the condition is true
	for i := 0; i < N; i++ {
		if (i+1 != A[i]) {
			if i < mn {
				mn = i // Update mn if a smaller index is found
			}
			if i > mx {
				mx = i // Update mx if a larger index is found
			}
		}
	}

	// Check if no indices satisfy the condition
	if mx == -1 {
		fmt.Println("0 0") // Print '0 0' if no indices satisfy the condition
	} else {
		// Reverse the sublist from index mn to mx + 1 and update A
		reverse(A[mn : mx+1])
		
		// Check if the list A is sorted
		if isSorted(A) {
			fmt.Println(mn+1, mx+1) // Print the indices if A is sorted
		} else {
			fmt.Println("0 0") // Print '0 0' if A is not sorted
		}
	}
}

// Function to reverse a slice of integers
func reverse(s []int) {
	for i, j := 0, len(s)-1; i < j; i, j = i+1, j-1 {
		s[i], s[j] = s[j], s[i]
	}
}

// Function to check if a slice of integers is sorted
func isSorted(s []int) bool {
	for i := 1; i < len(s); i++ {
		if s[i] < s[i-1] {
			return false
		}
	}
	return true
}
