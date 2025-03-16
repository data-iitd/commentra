package main

import (
	"fmt"
)

// Function to find the difference between two numbers using Euclidean algorithm
func substract(a, b int) int {
	// Check if 'a' is greater than 'b'
	if a > b {
		total := 0
		for a > 0 && b > 0 {
			total += a / b
			a = a % b
			if a > 0 {
				total += b / a
				b = b % a
			}
		}
		return total
	} else if a < b {
		total := 0
		for a > 0 && b > 0 {
			total += b / a
			b = b % a
			if b > 0 {
				total += a / b
				a = a % b
			}
		}
		return total
	} else {
		return 1
	}
}

func main() {
	// Take the number of test cases as input
	var n int
	fmt.Scan(&n)

	// Initialize an empty list to store the differences
	var lst []int

	// Iterate through each test case
	for i := 0; i < n; i++ {
		// Take two numbers as input
		var a, b int
		fmt.Scan(&a, &b)
		// Append the difference between 'a' and 'b' to the list
		lst = append(lst, substract(a, b))
	}

	// Print each difference in the list
	for _, i := range lst {
		// Print the difference
		fmt.Println(i)
	}
}
