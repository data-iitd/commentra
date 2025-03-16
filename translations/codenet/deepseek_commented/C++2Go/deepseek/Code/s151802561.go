package main

import (
	"fmt"
)

func main() {
	var A [100]int
	var n, i, j, t, sw, mini int

	// Step 1: Reading the number of elements (n)
	fmt.Scan(&n)
	for i = 0; i < n; i++ {
		fmt.Scan(&A[i])
	}

	// Step 3: Selection Sort Implementation
	for i = 0; i < n; i++ {
		mini = i
		// Find the index of the minimum element in the unsorted part of the array
		for j = i; j < n; j++ {
			if A[j] < A[mini] {
				mini = j
			}
		}
		// Swap the found minimum element with the first element of the unsorted part
		t = A[i]
		A[i] = A[mini]
		A[mini] = t
		// Increment the swap counter if a swap was made
		if i != mini {
			sw++
		}
	}

	// Step 5: Printing the sorted array
	for i = 0; i < n; i++ {
		if i > 0 {
			fmt.Print(" ")
		}
		fmt.Print(A[i])
	}
	fmt.Println()

	// Step 6: Printing the number of swaps
	fmt.Println(sw)
}

