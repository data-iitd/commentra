package main

import (
	"fmt"
)

const N = 2000

// Declare global variables
var num1 int
var math [N + 1]int

func main() {
	var a, num2, ans, sum int // Declare variables for input and calculations

	// Initialize the first element of the math array to 1
	math[0] = 1

	// Read the number of elements for the first set
	fmt.Scan(&num1)

	// Loop to read each element and update the possible sums
	for i := 0; i < num1; i++ {
		fmt.Scan(&a) // Read the current element
		sum += a    // Update the total sum

		// Update the math array to reflect the new possible sums
		for j := sum - a; j >= 0; j-- {
			if math[j] == 1 {
				math[j+a] = 1 // Mark the new sum as possible
			}
		}
	}

	// Read the number of queries for possible sums
	fmt.Scan(&num2)

	// Loop to check if each queried sum is possible
	for i := 0; i < num2; i++ {
		fmt.Scan(&ans) // Read the queried sum
		// Check if the queried sum is possible and print the result
		if math[ans] == 1 {
			fmt.Println("yes")
		} else {
			fmt.Println("no")
		}
	}
}

// <END-OF-CODE>
