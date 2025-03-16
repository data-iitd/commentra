package main

import (
	"fmt"
)

const (
	mod  = 1000000007
	mod9 = 998244353
	INF  = 0x3f3f3f3f
)

func main() {
	var tc, n, m int
	var fl int = 0

	// Read input
	fmt.Scanf("%d%d%d", &tc, &n, &m)

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

// <END-OF-CODE>
