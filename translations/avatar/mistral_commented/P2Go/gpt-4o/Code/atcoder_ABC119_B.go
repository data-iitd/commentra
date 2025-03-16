package main

import (
	"fmt"
	"strconv"
	"strings"
)

func main() {
	// Ask the user for the number of inputs
	var N int
	fmt.Scan(&N)

	// Create a slice 'x' of size 'N'
	x := make([]float64, N)

	for i := 0; i < N; i++ {
		var input string
		fmt.Scan(&input)

		// Replace 'JPY' and 'BTC' with their respective multipliers
		input = strings.ReplaceAll(input, "JPY", "* 1.0")
		input = strings.ReplaceAll(input, "BTC", "* 380000.0")

		// Evaluate the expression
		result, err := eval(input)
		if err != nil {
			fmt.Println("Error evaluating input:", err)
			return
		}
		x[i] = result
	}

	// Print the sum of all the elements in the slice 'x'
	sum := 0.0
	for _, value := range x {
		sum += value
	}
	fmt.Println(sum)
}

// eval function to evaluate the mathematical expression
func eval(expr string) (float64, error) {
	// Replace the eval logic with a simple parser or use a library
	// For simplicity, we will use a basic implementation here
	// This is a placeholder for actual evaluation logic
	// You can use a library like "github.com/Knetic/govaluate" for real evaluation

	// For now, we will just convert the expression to a float64
	// This is not a real implementation and should be replaced with actual logic
	parts := strings.Fields(expr)
	if len(parts) != 3 {
		return 0, fmt.Errorf("invalid expression")
	}

	left, err := strconv.ParseFloat(parts[0], 64)
	if err != nil {
		return 0, err
	}

	operator := parts[1]
	right, err := strconv.ParseFloat(parts[2], 64)
	if err != nil {
		return 0, err
	}

	switch operator {
	case "*":
		return left * right, nil
	default:
		return 0, fmt.Errorf("unsupported operator")
	}
}
