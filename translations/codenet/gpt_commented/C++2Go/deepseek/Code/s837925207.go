package main

import (
	"fmt"
)

func main() {
	var x int
	var ans int

	// Read an integer input from the user
	fmt.Scan(&x)

	// Calculate the result as the sum of x, x squared, and x cubed
	ans = x + x*x + x*x*x

	// Output the calculated result to the console
	fmt.Println(ans)
}

