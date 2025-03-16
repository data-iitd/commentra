package main

import (
	"fmt"
	"math"
)

// Include necessary packages: These packages provide essential functionalities
// such as input/output operations and mathematical functions.

func gcd(a, b int) int {
	if a < b {
		a, b = b, a
	}
	for b != 0 {
		a, b = b, a%b
	}
	return a
}

// Define gcd function: This function computes the greatest common divisor
// of two integers using the Euclidean algorithm.

func main() {
	var n int
	fmt.Scan(&n)

	// Read the number of integers.

	var ans int
	fmt.Scan(&ans)

	// Read the first integer and initialize the answer.

	for i := 1; i < n; i++ {
		var a int
		fmt.Scan(&a)
		ans = gcd(ans, a)
	}

	// Read the remaining integers, compute their GCD with the current answer,
	// and update the answer accordingly.

	fmt.Println(ans)

	// Print the final result, which is the GCD of all the input integers.
}

