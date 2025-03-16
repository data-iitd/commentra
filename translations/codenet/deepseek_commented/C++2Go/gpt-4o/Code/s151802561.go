package main

import (
	"fmt"
)

func main() {
	var n int
	fmt.Scan(&n)
	A := make([]int, n)

	// Step 2: Reading the elements of the array
	for i := 0; i < n; i++ {
		fmt.Scan(&A[i])
	}

	// Step 3: Selection Sort Implementation
	sw := 0
	for i := 0; i < n; i++ {
		mini := i
		// Find the index of the minimum element in the unsorted part of the array
		for j := i; j < n; j++ {
			if A[j] < A[mini] {
				mini = j
			}
		}
		// Swap the found minimum element with the first element of the unsorted part
		if i != mini {
			A[i], A[mini] = A[mini], A[i]
			sw++
		}
	}

	// Step 5: Printing the sorted array
	for i := 0; i < n; i++ {
		if i > 0 {
			fmt.Print(" ")
		}
		fmt.Print(A[i])
	}
	fmt.Println()

	// Step 6: Printing the number of swaps
	fmt.Println(sw)
}

// <END-OF-CODE>
