package main

import (
	"fmt"
)

func main() {
	var n, m int
	// Reading the first integer 'n' from the standard input
	fmt.Scan(&n)
	// Reading the second integer 'm' from the standard input
	fmt.Scan(&m)

	// Checking if 'n' is equal to zero
	if n == 0 {
		// If 'm' is not equal to zero, print "Impossible"
		if m != 0 {
			fmt.Println("Impossible")
		} else { // If 'm' is also zero, print '0' space '0'
			fmt.Println(0, 0)
		}
		// Returning from the main method
		return
	}

	// Checking if 'm' is less than or equal to 'n'
	if m <= n {
		// If 'm' is zero, assign it the value 1
		if m == 0 {
			m = 1
		}
		// Printing 'n' and the sum of 'm' and 'n' minus one
		fmt.Print(n, " ", m+n-1)
		// Returning from the main method
		return
	}

	// If 'm' is greater than 'n', print 'm' and the sum of 'm' and 'n' minus one
	fmt.Print(m, " ", m+n-1)
}

// <END-OF-CODE>
