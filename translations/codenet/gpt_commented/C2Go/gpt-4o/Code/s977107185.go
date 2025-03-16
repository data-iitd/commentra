package main

import (
	"fmt"
)

func main() {
	// Declare variables
	var N int
	var A [100]int
	var tmp, count int

	// Read the number of elements to be sorted
	fmt.Scan(&N)

	// Input the elements into the array A
	for i := 0; i < N; i++ {
		fmt.Scan(&A[i])
	}

	// Perform bubble sort on the array A
	for i := 0; i < N-1; i++ {
		for j := N - 1; j > i; j-- {
			// Compare adjacent elements and swap if they are in the wrong order
			if A[j] < A[j-1] {
				tmp = A[j]
				A[j] = A[j-1]
				A[j-1] = tmp

				// Increment the swap count
				count++
			}
		}
	}

	// Output the sorted array
	for i := 0; i < N; i++ {
		fmt.Print(A[i])

		// Print a space between elements, but not after the last element
		if i < N-1 {
			fmt.Print(" ")
		}
	}

	// Print a newline after the sorted array
	fmt.Println()

	// Print the total number of swaps made during sorting
	fmt.Println(count)
}

// <END-OF-CODE>
