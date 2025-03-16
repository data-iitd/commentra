package main

import (
	"fmt"
)

func main() {
	// Read input as two integers n and m
	var n, m int
	fmt.Scan(&n, &m)

	// Check if both n and m are less than 1
	if n < 1 {
		// If yes, check if m is also less than 1
		if m < 1 {
			// Print n and m and exit the program
			fmt.Println(n, m)
			return
		}
		// If not, print "Impossible" and exit the program
		fmt.Println("Impossible")
		return
	}

	// Check if m is greater than n
	if m > n {
		// If yes, calculate the minimum and maximum values
		min := m
		max := n + m - 1
		// Print the minimum and maximum values
		fmt.Println(min, max)
		return
	}

	// If m is less than or equal to n
	if m <= n {
		// Calculate the minimum and maximum values
		min := n
		max := n + m - 1
		// If m is 0, adjust the maximum value accordingly
		if m == 0 {
			max = n
		}
		// Print the minimum and maximum values
		fmt.Println(min, max)
	}
}

// <END-OF-CODE>
