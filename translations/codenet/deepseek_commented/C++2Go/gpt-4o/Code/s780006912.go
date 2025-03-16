package main

import (
	"fmt"
)

func main() {
	// Step 1: Include the necessary packages.
	// We need to import the fmt package to use input and output functions.
	var n int
	var array [100]int

	// Step 2: Declare the necessary variables.
	// We need to declare a variable to store the number of elements in the array and an array to store the elements.

	// Step 3: Read the number of elements and the elements of the array.
	// We need to read the number of elements from the user and then read the elements of the array from the user.
	fmt.Scan(&n)
	for i := 0; i < n; i++ {
		fmt.Scan(&array[i])
	}

	// Step 4: Calculate the sum of the products of all pairs of elements in the array.
	// We need to use nested loops to iterate through all pairs of elements in the array and calculate their products.
	sum := 0
	for i := 0; i < n-1; i++ {
		for j := i + 1; j < n; j++ {
			sum += array[i] * array[j]
		}
	}

	// Step 5: Print the result.
	// Finally, we need to print the calculated sum.
	fmt.Println(sum)
}

// <END-OF-CODE>
