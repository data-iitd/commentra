package main

import (
	"fmt"
)

func main() {
	var N, D int // N, D are integers between 1 and 20
	var ans, rem int

	// Read two integers from standard input
	fmt.Scan(&N, &D)

	// Calculate the number of groups that can be formed
	ans = N / (D*2 + 1)
	rem = N % (D*2 + 1)

	// If there are remaining items, increment the number of groups
	if rem != 0 {
		ans++
	}

	// Print the result to standard output
	fmt.Println(ans)
}

// <END-OF-CODE>
