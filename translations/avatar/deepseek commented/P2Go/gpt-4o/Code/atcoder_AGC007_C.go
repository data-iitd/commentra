package main

import (
	"fmt"
	"os"
)

func main() {
	var N int
	var d, x float64

	// Reading the values of N, d, and x from standard input
	_, err := fmt.Scanf("%d %f %f", &N, &d, &x)
	if err != nil {
		fmt.Fprintln(os.Stderr, "Error reading input:", err)
		return
	}

	// Calling the function to calculate the result
	result := calculate(N, d, x)

	// Printing the result
	fmt.Println(result)
}

// Defining the function to calculate a result based on N, d, and x
func calculate(N int, d, x float64) float64 {
	ret := 0.0 // Initializing the result variable to accumulate the result
	for N > 0 { // Running the loop while N is greater than 0
		// Incrementing ret by the sum of d and (N - 0.5) * x
		ret += d + (float64(N)-0.5)*x

		// Updating the value of d using a complex formula
		d = d + (d/float64(N)) + (5*x)/(2*float64(N))

		// Updating the value of x using another formula
		x += 2*x/float64(N)

		// Decrementing N by 1
		N--
	}

	// Returning the accumulated result
	return ret
}

// <END-OF-CODE>
