package main

import (
	"fmt"
	"strings"
	"strconv"
)

func main() {
	// Read the number of currency inputs from the user
	var N int
	fmt.Scan(&N)

	// Create a slice to hold the converted currency values
	x := make([]float64, N)

	// For each input, replace 'JPY' with its equivalent in float and 'BTC' with its equivalent in float
	for i := 0; i < N; i++ {
		var input string
		fmt.Scan(&input)

		// Replace 'JPY' and 'BTC' with their respective multipliers
		input = strings.ReplaceAll(input, "JPY", "* 1.0")
		input = strings.ReplaceAll(input, "BTC", "* 380000.0")

		// Evaluate the expression
		value, err := eval(input)
		if err != nil {
			fmt.Println("Error evaluating expression:", err)
			return
		}
		x[i] = value
	}

	// Calculate and print the total sum of the converted currency values
	total := 0.0
	for _, value := range x {
		total += value
	}
	fmt.Println(total)
}

// eval function to evaluate the expression
func eval(expr string) (float64, error) {
	// Replace the multiplication operator for evaluation
	expr = strings.ReplaceAll(expr, "*", " * ")
	parts := strings.Fields(expr)

	// Initialize result
	result := 1.0
	for _, part := range parts {
		if part == "*" {
			continue
		}
		num, err := strconv.ParseFloat(part, 64)
		if err != nil {
			return 0, err
		}
		result *= num
	}
	return result, nil
}
