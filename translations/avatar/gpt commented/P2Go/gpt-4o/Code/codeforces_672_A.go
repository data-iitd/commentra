package main

import (
	"fmt"
)

func main() {
	// Initialize an empty slice to store the results
	var li []int

	// Loop through numbers from 1 to 370
	for i := 1; i <= 370; i++ {
		// Initialize a temporary slice to hold digits
		var temp []int
		// Assign the current number to p and q for processing
		p, q := i, i
		// Initialize a count variable to track the number of digits
		count := 0

		// Count the number of digits in the current number i
		for p != 0 {
			p /= 10 // Remove the last digit
			count++ // Increment the digit count
		}

		// If the number has 1 digit, add it directly to the slice
		if count == 1 {
			li = append(li, i)
		}

		// If the number has 2 digits
		if count == 2 {
			temp = []int{} // Reset the temporary slice
			// Extract digits of the number q
			for q != 0 {
				x := q % 10 // Get the last digit
				q /= 10     // Remove the last digit
				temp = append(temp, x) // Append the digit to the temporary slice
			}
			// Add the digits in reverse order to the main slice
			for j := len(temp) - 1; j >= 0; j-- {
				li = append(li, temp[j])
			}
		}

		// If the number has 3 digits
		if count == 3 {
			temp = []int{} // Reset the temporary slice
			// Extract digits of the number q
			for q != 0 {
				x := q % 10 // Get the last digit
				q /= 10     // Remove the last digit
				temp = append(temp, x) // Append the digit to the temporary slice
			}
			// Add the digits in reverse order to the main slice
			for j := len(temp) - 1; j >= 0; j-- {
				li = append(li, temp[j])
			}
		}
	}

	// Remove the last two elements from the slice
	li = li[:len(li)-2]

	// Take user input for the index
	var n int
	fmt.Scan(&n)
	// Print the n-th element from the slice (1-based index)
	fmt.Println(li[n-1])
}

// <END-OF-CODE>
