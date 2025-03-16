package main

import (
	"fmt"
)

func main() {
	// Declare variables
	var a [10000]int
	var min, max, n int
	var sum int64 = 0

	// Read the number of elements in the array
	fmt.Print("Enter the number of elements in the array: ")
	fmt.Scan(&n)

	// Initialize a for loop to read elements into the array and calculate sum
	for i := 0; i < n; i++ {
		// Read each element into the array
		fmt.Printf("Enter element %d: ", i+1)
		fmt.Scan(&a[i])

		// Add the current element to the sum
		sum += int64(a[i])
	}

	// Initialize min and max with the first element of the array
	min = a[0]
	max = a[0]

	// Initialize a for loop to find minimum and maximum elements in the array
	for i := 1; i < n; i++ {
		if a[i] > max {
			max = a[i]
		}
		if a[i] < min {
			min = a[i]
		}
	}

	// Print the minimum, maximum, and sum
	fmt.Printf("Minimum element is %d\n", min)
	fmt.Printf("Maximum element is %d\n", max)
	fmt.Printf("Sum of all elements is %d\n", sum)
}

// <END-OF-CODE>
