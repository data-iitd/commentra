
package main

import (
	"fmt"
	"sort"
)

func main() {
	var N int // Number of elements in the vector

	// Taking input of N from the user
	fmt.Scan(&N)

	// Declaring two vectors X and Y of size N
	X := make([]int, N)
	Y := make([]int, N)

	// Filling the vectors X and Y with user input
	for i := 0; i < N; i++ {
		fmt.Scan(&X[i]) // Taking input of X[i] from the user
		Y[i] = X[i]     // Assigning X[i] to Y[i]
	}

	// Sorting the vector Y in ascending order
	sort.Ints(Y)

	// Finding the middle element of sorted vector Y
	y := Y[N/2]

	// Iterating through the vector X and printing the middle element of Y based on the condition
	for i := 0; i < N; i++ {
		if X[i] < y { // Checking if X[i] is less than the middle element of Y
			fmt.Println(y) // If true, print the middle element of Y
		} else { // If X[i] is greater than or equal to the middle element of Y
			fmt.Println(y - 1) // Print the middle element of Y - 1
			break              // Exit the loop as we have found the required element
		}
		fmt.Println() // Print a newline after each element
	}

	// End of main function
}

