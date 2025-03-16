package main

import (
	"fmt"
	"sort"
)

func main() {
	var N int // Number of elements in the slice

	// Taking input of N from the user
	fmt.Scan(&N)

	// Declaring two slices X and Y of size N
	X := make([]int, N)
	Y := make([]int, N)

	// Filling the slices X and Y with user input
	for i := 0; i < N; i++ {
		fmt.Scan(&X[i]) // Taking input of X[i] from the user
		Y[i] = X[i]     // Assigning X[i] to Y[i]
	}

	// Sorting the slice Y in ascending order
	sort.Ints(Y)

	// Finding the middle element of sorted slice Y
	y := Y[N/2]

	// Iterating through the slice X and printing the middle element of Y based on the condition
	for i := 0; i < N; i++ {
		if X[i] < Y[N/2] { // Checking if X[i] is less than the middle element of Y
			fmt.Println(Y[N/2]) // If true, print the middle element of Y
		} else { // If X[i] is greater than or equal to the middle element of Y
			fmt.Println(Y[N/2-1]) // Print the middle element of Y - 1
			break                  // Exit the loop as we have found the required element
		}
	}
}

// <END-OF-CODE>
