package main

import (
	"fmt"
)

func G(a, b int) int {
	// Calculate the greatest common divisor (GCD) of a and b using the Euclidean algorithm
	for a%b != 0 {
		a, b = b, a%b
	}
	return b
}

func L(a, b int) int {
	// Calculate the least common multiple (LCM) of a and b using the relationship between GCD and LCM
	return a * b / G(a, b)
}

func main() {
	var x, y, a, b int
	// Read four integers x, y, a, and b from the input
	fmt.Scan(&x, &y, &a, &b)

	// Calculate the LCM of x and y
	lcm := L(x, y)

	// Compute the number of integers in the range from a to b that are divisible by lcm
	// and print the result
	result := b/lcm - (a-1)/lcm
	fmt.Println(result)
}

// <END-OF-CODE>
