package main

import (
	"fmt"
)

func main() {
	// Declare an array to hold up to 100 integers and other necessary variables
	var A [100]int
	var n, i, j, t, sw, mini int

	// Read the number of elements to be sorted
	fmt.Scan(&n)

	// Read the elements into the array A
	for i := 0; i < n; i++ {
		fmt.Scan(&A[i])
	}

	// Selection sort algorithm to sort the array A
	for i := 0; i < n; i++ {
		mini = i // Assume the minimum is the first element of the unsorted part
		// Find the index of the minimum element in the unsorted part
		for j := i; j < n; j++ {
			if A[j] < A[mini] {
				mini = j // Update mini if a smaller element is found
			}
		}
		// Swap the found minimum element with the first element of the unsorted part
		t = A[i]
		A[i] = A[mini]
		A[mini] = t

		// Count the number of swaps made
		if i != mini {
			sw++
		}
	}

	// Print the sorted array
	for i := 0; i < n; i++ {
		if i > 0 {
			fmt.Print(" ") // Print a space before each element except the first
		}
		fmt.Print(A[i]) // Print the current element
	}
	fmt.Println() // Print a newline after the array

	// Print the total number of swaps made during sorting
	fmt.Println(sw)

	return // End of the program
}

// <END-OF-CODE>
