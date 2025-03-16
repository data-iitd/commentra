package main

import (
	"fmt"
)

func main() {
	var N int
	fmt.Scan(&N) // Read the number of elements N from the user
	x := make([]float64, N) // Initialize the slice to store the values
	u := make([]string, N) // Initialize the slice to store the currencies

	// Read the values into the slices x and u
	for i := 0; i < N; i++ {
		fmt.Scan(&x[i], &u[i])
	}

	// Call the solve function and print the result
	fmt.Println(solve(x, u))
}

// Define the solve function to calculate the total value based on the currency
func solve(x []float64, u []string) float64 {
	total := 0.0
	for i := 0; i < len(x); i++ {
		if u[i] == "JPY" {
			total += x[i]
		} else {
			total += x[i] * 380000
		}
	}
	return total
}

// <END-OF-CODE>
