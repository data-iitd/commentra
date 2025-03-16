package main

import (
	"fmt"
)

// substract function to perform the subtraction operation
func substract(a, b int) int {
	// Check if a is greater than b
	if a > b {
		total := 0 // Initialize the total count of subtractions
		// Loop to subtract b from a until one of them becomes zero
		for a > 0 && b > 0 {
			total += a / b // Count how many times b can be subtracted from a
			a = a % b     // Update a to the remainder of a divided by b
			if a > 0 {
				total += b / a // Count how many times a can be subtracted from b
				b = b % a     // Update b to the remainder of b divided by a
			}
		}
		return total // Return the total count of subtractions
	}

	// If a is less than b, perform similar operations but subtract a from b
	if a < b {
		total := 0 // Initialize the total count of subtractions
		for a > 0 && b > 0 {
			total += b / a // Count how many times a can be subtracted from b
			b = b % a     // Update b to the remainder of b divided by a
			if b > 0 {
				total += a / b // Count how many times b can be subtracted from a
				a = a % b     // Update a to the remainder of a divided by b
			}
		}
		return total // Return the total count of subtractions
	}

	// If a and b are equal, return 1
	if a == b {
		return 1
	}

	return 0 // Default return, should not reach here
}

func main() {
	var n int
	fmt.Scan(&n) // Read the number of pairs of integers
	lst := []int{} // Initialize a list to store the results

	// Read n pairs of integers and compute the result using the substract function
	for i := 0; i < n; i++ {
		var a, b int
		fmt.Scan(&a, &b)
		lst = append(lst, substract(a, b))
	}

	// Print each element in the list
	for _, i := range lst {
		fmt.Println(i)
	}
}
