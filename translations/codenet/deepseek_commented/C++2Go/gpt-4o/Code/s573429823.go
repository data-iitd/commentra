package main

import (
	"fmt"
)

func main() {
	// Declare a variable to store the input number
	var n uint64

	// Read the value of n from the standard input
	fmt.Scan(&n)

	// Initialize a boolean variable to false
	flg := false

	// Check if n is less than 4. If so, print "No" and exit.
	if n < 4 {
		fmt.Println("No")
	} else {
		// Check all possible combinations of 4s and 7s that sum up to n
		for i := uint64(0); i <= n/4; i++ {
			for j := uint64(0); j <= n/7; j++ {
				if (i*4 + j*7) == n {
					flg = true
					break
				}
			}
			if flg {
				break
			}
		}

		// Check the value of flg and print "Yes" or "No" accordingly
		if flg {
			fmt.Println("Yes")
		} else {
			fmt.Println("No")
		}
	}
}

// <END-OF-CODE>
