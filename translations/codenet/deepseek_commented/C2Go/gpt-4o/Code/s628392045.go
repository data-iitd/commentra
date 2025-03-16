package main // Declare the main package

import (
	"fmt" // Import the fmt package for formatted I/O
)

func main() {
	var n int // Declare a variable for the number of elements
	var max int = -1 // Initialize max to -1 to store the maximum height found
	var flag int = 0 // Initialize flag to 0 to indicate whether the condition is met

	fmt.Scan(&n) // Read the number of elements from standard input

	h := make([]int, n) // Create a slice to store heights of elements

	// Loop to read heights and update the maximum height found
	for i := 0; i < n; i++ {
		fmt.Scan(&h[i]) // Read the height of the i-th element
		if max < h[i] {
			max = h[i] // Update max if the current height is greater than max
		}

		if max-h[i] >= 2 {
			flag = 1 // Check if the difference between max and current height is at least 2
		}
	}

	if flag == 1 {
		fmt.Println("No") // Print "No" if the condition is met
	} else {
		fmt.Println("Yes") // Print "Yes" if the condition is not met
	}
}

// <END-OF-CODE>
