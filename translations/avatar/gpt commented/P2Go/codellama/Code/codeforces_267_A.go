package main

import (
	"fmt"
	"strconv"
	"strings"
)

func substract(a, b int) int {
	// Check if 'a' is greater than 'b'
	if a > b {
		total := 0 // Initialize total to accumulate results
		// Loop until either 'a' or 'b' becomes zero
		for a > 0 && b > 0 {
			// Add the integer division of 'a' by 'b' to total
			total += int(a / b)
			// Update 'a' to the remainder of 'a' divided by 'b'
			a = a % b
			// If 'a' is still greater than zero, calculate further
			if a > 0 {
				// Add the integer division of 'b' by 'a' to total
				total += int(b / a)
				// Update 'b' to the remainder of 'b' divided by 'a'
				b = b % a
			}
		}
		return total // Return the accumulated total
	}

	// Check if 'a' is less than 'b'
	if a < b {
		total := 0 // Initialize total to accumulate results
		// Loop until either 'a' or 'b' becomes zero
		for a > 0 && b > 0 {
			// Add the integer division of 'b' by 'a' to total
			total += int(b / a)
			// Update 'b' to the remainder of 'b' divided by 'a'
			b = b % a
			// If 'b' is still greater than zero, calculate further
			if b > 0 {
				// Add the integer division of 'a' by 'b' to total
				total += int(a / b)
				// Update 'a' to the remainder of 'a' divided by 'b'
				a = a % b
			}
		}
		return total // Return the accumulated total
	}

	// If 'a' is equal to 'b', return 1
	if a == b {
		return 1
	}

	return 0
}

func main() {
	// Read an integer input 'n' which represents the number of pairs
	var n int
	fmt.Scan(&n)
	lst := make([]int, 0) // Initialize an empty list to store results

	// Loop to read 'n' pairs of integers
	for i := 0; i < n; i++ {
		var a, b int
		fmt.Scan(&a, &b) // Read a pair of integers
		lst = append(lst, substract(a, b)) // Call the substract function and store the result
	}

	// Loop to print each result stored in the list
	for i := 0; i < len(lst); i++ {
		fmt.Println(lst[i])
	}
}

