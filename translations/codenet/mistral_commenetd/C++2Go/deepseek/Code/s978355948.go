package main

import (
	"fmt"
)

func main() {
	// Initialize variables N and X with user input
	var N, X int
	fmt.Scan(&N, &X)

	// Create a slice L of size N to store the elements
	L := make([]int, N)

	// Read elements of slice L from user input
	for i := 0; i < N; i++ {
		fmt.Scan(&L[i])
	}

	// Initialize variable i and d to zero
	i, d := 0, 0

	// Loop through the slice L until the sum d exceeds X
	for ; i < N && d <= X; i++ {
		// Add the current element of slice L to the sum d
		d += L[i]
	}

	// Print the index of the last element in the slice L that was added to the sum d
	fmt.Println(i + 1)
}

