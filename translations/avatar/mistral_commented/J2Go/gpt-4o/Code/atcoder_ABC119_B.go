package main

import (
	"fmt"
)

func main() {
	var N int // Declaring an integer variable 'N' to store the number of elements

	// Reading the number of elements from the user input
	fmt.Scan(&N)

	x := make([]float64, N) // Declaring and initializing a slice 'x' of size 'N' to store the float64 values
	u := make([]string, N)  // Declaring and initializing a slice 'u' of size 'N' to store the currency strings

	// Reading the float64 values and currency strings from the user input and storing them in respective slices
	for i := 0; i < N; i++ {
		fmt.Scan(&x[i])
		fmt.Scan(&u[i])
	}

	// Calling the 'solve' function to find the sum of products of float64 values and their respective currency conversion factors
	fmt.Println(solve(x, u))
}

func solve(x []float64, u []string) float64 {
	sum := 0.0 // Variable to store the sum of products

	for i := 0; i < len(x); i++ {
		if u[i] == "JPY" {
			sum += x[i] // If currency is JPY, add the value directly
		} else {
			sum += x[i] * 380000 // Otherwise, multiply by the conversion factor
		}
	}

	return sum // Returning the total sum
}

// <END-OF-CODE>
