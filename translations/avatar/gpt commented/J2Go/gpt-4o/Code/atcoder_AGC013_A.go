package main

import (
	"fmt"
)

func main() {
	// Reading the number of elements N from user input
	var N int
	fmt.Scan(&N)

	// Initializing a slice A to store the input integers
	A := make([]int, N)

	// Loop to read N integers from user input and store them in slice A
	for i := 0; i < N; i++ {
		fmt.Scan(&A[i])
	}

	// Initializing a counter to keep track of the number of segments
	count := 0

	// Loop through the slice to identify segments of increasing or decreasing values
	for i := 0; i < N; i++ {
		// If we are at the last element, increment the count
		if i == N-1 {
			count++
		} else if A[i] == A[i+1] {
			// No action needed, just continue
		} else if A[i] < A[i+1] {
			// Find the end of the increasing segment
			for A[i] <= A[i+1] {
				i++ // Move to the next element
				// Break if we reach the end of the slice
				if i == N-1 {
					break
				}
			}
			// Increment the count for the found segment
			count++
		} else {
			// Find the end of the decreasing segment
			for A[i] >= A[i+1] {
				i++ // Move to the next element
				// Break if we reach the end of the slice
				if i == N-1 {
					break
				}
			}
			// Increment the count for the found segment
			count++
		}
	}

	// Output the total number of segments found
	fmt.Println(count)
}

// <END-OF-CODE>
