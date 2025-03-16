
package main

import "fmt"

func main() {
	// Initialize variables N and R to zero
	var N, R int = 0, 0

	// Read two integers from the standard input using fmt.Scanf function
	fmt.Scanf("%d %d", &N, &R)

	// Check if N is greater than or equal to 10
	if N >= 10 {
		// If condition is true, print the value of R
		fmt.Printf("%d\n", R)
	} else {
		// If condition is false, print the value of R plus 100 times the difference between 10 and N
		fmt.Printf("%d\n", R + 100*(10-N))
	}
}

