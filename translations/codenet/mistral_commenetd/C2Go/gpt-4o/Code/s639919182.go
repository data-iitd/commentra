package main

import (
	"fmt"
)

func main() {
	// Declare an integer slice 'v' of size 10 and an integer variable 'sum' to store the sum of array elements.
	v := make([]int, 10) // Declare an integer slice 'v' of size 10.
	sum := 0             // Declare an integer variable 'sum' and initialize it to zero.

	// Read 10 integers from the user and store them in the slice 'v'.
	for i := 0; i < 10; i++ {
		fmt.Printf("Enter the value for index %d: ", i)
		fmt.Scan(&v[i])
		// Read an integer value from the user and store it in the current index of the slice 'v'.
	}

	// Calculate the sum of all elements in the slice 'v'.
	for i := 0; i < 10; i++ {
		sum += v[i]
		// Add the value of the current element in the slice 'v' to the variable 'sum'.
	}

	// Print the sum of all elements in the slice 'v'.
	fmt.Println(sum)
	// Display the sum of all elements in the slice 'v'.
}

// Indicate successful termination of the program.
