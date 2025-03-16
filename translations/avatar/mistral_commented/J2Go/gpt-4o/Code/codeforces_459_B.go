package main

import (
	"fmt"
	"sort"
)

func main() {
	var N int
	fmt.Scan(&N) // Read the number of elements N from the standard input
	A := make([]int, N) // Create a slice A of size N to store the elements

	// Use a for loop to read each element from the standard input and store it in the corresponding index of the slice A
	for n := 0; n < N; n++ {
		fmt.Scan(&A[n])
	}

	// Use the sort package to sort the elements in the slice A in ascending order
	sort.Ints(A)

	// Initialize two variables, min and max, to store the minimum and maximum elements in the slice A, respectively
	min := A[0]
	max := A[N-1]

	mins, maxs := 0, 0 // Initialize counters for min and max occurrences

	// Use a for loop to iterate through each element in the slice A and perform some checks
	for _, value := range A {
		if value == min {
			mins++ // Increment the count for minimum element
		}
		if value == max {
			maxs++ // Increment the count for maximum element
		}
	}

	// Check if the minimum and maximum elements are the same
	if min == max {
		result := int64(max-min) + 1 // Calculate the difference between the minimum and maximum elements, plus 1
		result *= int64(mins) // Multiply the result by the number of occurrences of the minimum element
		result -= int64(mins * (mins - 1) / 2) // Subtract the number of combinations of pairs of minimum elements
		fmt.Println(result) // Print the output
	} else {
		result := int64(max - min) // Calculate the difference between the minimum and maximum elements
		result *= int64(mins) // Multiply the result by the number of occurrences of the minimum element
		result *= int64(maxs) // Multiply the result by the number of occurrences of the maximum element
		fmt.Println(result) // Print the output
	}
}

// <END-OF-CODE>
