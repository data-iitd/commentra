package main

import "fmt"

func main() {
	// Read three integers r, D, and x from input
	var r, D, x int
	fmt.Scan(&r, &D, &x)

	// Loop from 2 to 11 (inclusive)
	for i := 2; i <= 11; i++ {
		// Calculate the value using the given formula and print the integer result
		result := int((r ** (i - 1)) * (x + D / (1 - r)) - D / (1 - r))
		fmt.Println(result)
	}
}

