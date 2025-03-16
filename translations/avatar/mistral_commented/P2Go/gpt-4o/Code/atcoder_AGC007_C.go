package main

import (
	"fmt"
	"os"
)

func main() {
	// Reading input as three integers: N, d, and x
	var N int
	var d float64
	var x float64
	fmt.Fscanf(os.Stdin, "%d %f %f", &N, &d, &x)

	// Initializing the result variable to 0
	ret := 0.0

	// Loop continues as long as N is greater than 0
	for N > 0 {
		// Adding the current term to the result
		ret += d + (float64(N)-0.5)*x

		// Updating the value of d for the next iteration
		d += d/float64(N) + (5*x)/(2*float64(N))

		// Updating the value of x for the next iteration
		x += 2*x/float64(N)

		// Decrementing the value of N for the next iteration
		N--
	}

	// Printing the final result
	fmt.Println(ret)
}

// <END-OF-CODE>
