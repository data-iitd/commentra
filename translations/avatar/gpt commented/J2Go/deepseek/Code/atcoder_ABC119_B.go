package main

import (
	"fmt"
)

func main() {
	// Create a Scanner object to read input from the console
	var N int
	fmt.Scan(&N)
	
	// Initialize arrays to hold the amounts and their corresponding currency units
	x := make([]float64, N)
	u := make([]string, N)
	
	// Loop to read each amount and its currency unit
	for i := 0; i < N; i++ {
		fmt.Scan(&x[i]) // Read the amount
		fmt.Scan(&u[i]) // Read the currency unit
	}
	
	// Calculate the total value in a standard currency and print the result
	fmt.Println(solve(x, u))
}

// Method to solve the currency conversion problem
func solve(x []float64, u []string) float64 {
	// Convert each amount to a standard currency and sum them up
	var total float64
	for i := 0; i < len(x); i++ {
		if u[i] == "JPY" {
			total += x[i]
		} else {
			total += x[i] * 380000
		}
	}
	return total
}

