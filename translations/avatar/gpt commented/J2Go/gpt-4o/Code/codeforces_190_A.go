package main

import (
	"fmt"
)

func main() {
	var n, m int
	// Read two integers n and m from the input
	fmt.Scan(&n, &m)

	// Check if n is zero
	if n == 0 {
		// If m is not zero, print "Impossible" since we cannot form a valid output
		if m != 0 {
			fmt.Println("Impossible")
		} else {
			// If m is also zero, print "0 0" as the valid output
			fmt.Println(0, 0)
		}
		return
	}

	// Check if m is less than or equal to n
	if m <= n {
		// If m is zero, set it to one to ensure valid output
		if m == 0 {
			m = 1
		}
		// Print n and the adjusted value of m
		fmt.Print(n, " ", m+n-1)
		return
	}

	// If m is greater than n, print m and the adjusted value of m
	fmt.Print(m, " ", m+n-1)
}

// <END-OF-CODE>
