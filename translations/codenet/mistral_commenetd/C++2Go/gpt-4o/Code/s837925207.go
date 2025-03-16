package main

import (
	"fmt"
)

func main() {
	var x, ans int // Initialize x and ans to zero

	// Read input value of x from the user
	fmt.Scan(&x)

	// Calculate the answer using the given formula
	ans = x + x*x + x*x*x

	// Output the answer to the user
	fmt.Println(ans)
}

// <END-OF-CODE>
