package main

import (
	"fmt"
	"os"
)

func main() {
	// Read input values for N, d, and x
	var N int
	var d, x float64
	fmt.Fscanf(os.Stdin, "%d %f %f", &N, &d, &x)

	// Initialize the result variable to accumulate the final value
	ret := 0.0

	// Loop until N becomes zero
	for N > 0 {
		// Update the result by adding the current d and a calculated value based on N and x
		ret += d + (float64(N)-0.5)*x

		// Update d based on its current value, N, and x
		d = d + (d/float64(N)) + (5*x)/(2*float64(N))

		// Update x based on its current value and N
		x += 2*x/float64(N)

		// Decrement N to move to the next iteration
		N--
	}

	// Print the accumulated result
	fmt.Println(ret)
}

// <END-OF-CODE>
