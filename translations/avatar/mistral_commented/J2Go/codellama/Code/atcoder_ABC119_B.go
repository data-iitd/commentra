
package main

import (
	"fmt"
	"strconv"
)

func main() {
	var N int // Declaring an integer variable 'N' to store the number of elements

	// Reading the number of elements from the user input
	fmt.Scan(&N)

	x := make([]float64, N) // Declaring and initializing an array 'x' of size 'N' to store the double values
	u := make([]string, N) // Declaring and initializing an array 'u' of size 'N' to store the currency strings

	// Reading the double values and currency strings from the user input and storing them in respective arrays
	for i := 0; i < N; i++ {
		fmt.Scan(&x[i])
		fmt.Scan(&u[i])
	}

	// Calling the 'solve' method to find the sum of products of double values and their respective currency conversion factors
	fmt.Println(solve(x, u))
}

func solve(x []float64, u []string) float64 {
	var sum float64 = 0 // Declaring a variable 'sum' to store the sum of products

	// Iterating over the indices of the 'x' array and multiplying the double value at index 'i' with the conversion factor based on the currency string
	for i := 0; i < len(x); i++ {
		if u[i] == "JPY" {
			sum += x[i]
		} else {
			sum += x[i] * 380000
		}
	}

	return sum // Returning the sum of products
}

