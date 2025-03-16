package main

import (
	"fmt"
)

func main() {
	var n, m int
	fmt.Scan(&n) // Read the first integer input
	fmt.Scan(&m) // Read the second integer input

	// Check if n is 0
	if n == 0 {
		if m != 0 { // If n is 0 but m is not 0, print "Impossible"
			fmt.Println("Impossible")
		} else { // If both n and m are 0, print "0 0"
			fmt.Println(0, 0)
		}
		return // Exit the program
	}

	// If n is not 0, check if m is less than or equal to n
	if m <= n {
		if m == 0 { // If m is 0, set m to 1
			m = 1
		}
		fmt.Print(n, " ", m+n-1) // Print the values of n and m + n - 1
		return // Exit the program
	}

	// If m is greater than n, print the values of m and m + n - 1
	fmt.Print(m, " ", m+n-1)
}

// <END-OF-CODE>
