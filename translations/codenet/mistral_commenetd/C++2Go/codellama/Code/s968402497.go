
package main

import (
	"fmt"
)

func main() {
	var tc, n, m, fl int // Declare variables

	// Read input
	fmt.Scan(&tc, &n, &m)
	// Check if 'n' is greater than 'm' and swap them if necessary
	if n > m {
		n, m = m, n
	}
	// Iterate through each possible value of 'i' from 1 to 'm'
	for i := 1; i <= m; i++ {
		// Check if 'i' multiplied by 'tc' is within the range of 'n' to 'm'
		if i*tc >= n && i*tc <= m {
			// If so, print "OK" and set the flag 'fl' to 1
			fmt.Println("OK")
			fl = 1
			// Break out of the loop since we have found the answer
			break
		}
	}
	// If the flag 'fl' is still 0, print "NG"
	if fl == 0 {
		fmt.Println("NG")
	}
}

